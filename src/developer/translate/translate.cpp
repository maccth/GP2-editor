#include "translate.hpp"
#include "globals.h"
#include "error.h"
#include <sstream>	// for stringstream

namespace Developer {

// Internal helper functions
std::string ListToString(std::vector<atom_t> list);
std::vector<atom_t> translateValues(List* list);
std::vector<node_t> translateNodes(List* nodes);
std::vector<edge_t> translateEdges(List* edges);
void reverseConditionAST(GPCondition *condition);
void reverseRuleAST(GPRule *rule);

/*
 * Translates a GPAtom AST into an atom_t structure
 * Integer constants are represented by 'int' C values
 * String constants are represented by *quoted* C strings - e.g. "abc"
 * Variables are represented by their name and are C strings - e.g. a, b, c
 * Everything else is represented by a C string
 */
atom_t 			translateAtom(GPAtom* atom)
{
	atom_t result;
	if (!atom) return result;
  switch(atom->type)
	{
		case VARIABLE:					result = std::string( atom->variable.name ); break;

		case INTEGER_CONSTANT:	result = atom->number; break;
		case STRING_CONSTANT:		
				{std::stringstream s;
				s << "\"" << atom->string << "\"";
				result = s.str(); 
				break;}

		case NEG:								
				{std::stringstream s;
				s << "-" << translateAtom(atom->neg_exp);
				result = s.str(); 
				break;}

		case LENGTH:						
				{std::stringstream s;
				s << "length(" << std::string( atom->variable.name ) << ")";
				result = s.str(); 
				break;}
		case INDEGREE:				
				{std::stringstream s;
				s << "indeg(" << atom->node_id << ")";
				result = s.str(); 
				break;}
		case OUTDEGREE:			
				{std::stringstream s;
				s << "outdeg(" << atom->node_id << ")";
				result = s.str(); 
				break;}
		case ADD:	
				{std::stringstream s;
				s << translateAtom(atom->bin_op.left_exp) << "+" << translateAtom(atom->bin_op.right_exp);
				result = s.str(); 
				break;}
		case SUBTRACT:
				{std::stringstream s;
				s << translateAtom(atom->bin_op.left_exp) << "-" << translateAtom(atom->bin_op.right_exp);
				result = s.str(); 
				break;}
		case MULTIPLY:
				{std::stringstream s;
				s << translateAtom(atom->bin_op.left_exp) << "*" << translateAtom(atom->bin_op.right_exp);
				result = s.str(); 
				break;}
		case DIVIDE:
				{std::stringstream s;
				s << translateAtom(atom->bin_op.left_exp) << "/" << translateAtom(atom->bin_op.right_exp);
				result = s.str(); 
				break;}
		case CONCAT:
				{std::stringstream s;
				s << translateAtom(atom->bin_op.left_exp) << "." << translateAtom(atom->bin_op.right_exp);
				result = s.str(); 
				break;}

		default: print_to_console("Unknown conversion of GPAtom (in translate): %d", atom->type); break;

	}

  return result;
}

/*  Translates a GPLabel AST into a label_t struct
 *  A label_t struct has a vector of atom values, which represents a GP2 list, and an optional mark
 *  The mark is represented by a C string
 *  The list is represented by a std::vector of atom_t values
 */
label_t 		translateLabel(GPLabel* label)
{
	label_t result;
	if (label==NULL) return result;
	switch (label->mark)
	{
		case NONE: result.mark = "";break;
  	case RED:  result.mark = "red";break;
		case GREEN: result.mark = "green";break;
		case BLUE: result.mark = "blue";break;
		case GREY: result.mark = "grey";break;
		case DASHED: result.mark = "dashed";break;
		case ANY:	  result.mark = "any";break;
		
		default: break;
	}
	result.values = translateValues(label->gp_list);

	return result;
}

/*  Translates a GPNode AST into a node_t struct
 *  A node_t struct has an id, a label_t label, canvas positions (double xPos, double yPos), and an optional isRoot flag
 *  The id is represented by a C string
 *  The label is represented by a label_t structure
 *  The root flag is a bool
 */
node_t 			translateNode(GPNode* node)
{	
	node_t result;
	if (node == NULL) return result;

	result.id = node->name;
	result.label = translateLabel(node->label);
	result.isRoot = node->root;

	return result;
}

/*  Translates a GPNode AST into a edge_t struct
 *  A edge_t struct has an id, a label_t label, source and target nodes, and an optional isBidirectional flag
 *  The id is represented by a C string
 *  The source and target nodes are represented by C strings holding the respective node ids
 *  The bidirectional flag is a bool
 */
edge_t 			translateEdge(GPEdge* edge)
{
	edge_t result;
	if (edge == NULL) return result;

	result.id = edge->name;
	result.label = translateLabel(edge->label);
	result.from = edge->source;
	result.to = edge->target;
	result.isBidirectional = edge->bidirectional;

	return result;
}




/* Translates a GPGraph AST into a graph_t struct
 * A graph_t has two collections of nodes and edges, and a canvas size specification
 */
graph_t 		translateGraph(GPGraph* graph)
{
	graph_t result;
	if (graph == NULL) return result;

	result.nodes = translateNodes(graph->nodes);
	result.edges = translateEdges(graph->edges);

	return result;
}

// Expects a comma-separated list of node ids
/* Translates a List of node(/edge) ids into an interface_t struct
 * An interface_t struct has a vector of elements, represented by their C string ids.
*/
interface_t translateInterface(List* interface)
{
	interface_t result;
	if (interface == NULL || (interface->type != INTERFACE_LIST)) return result;

	std::vector<std::string> elements;
	List* current_node = interface;

	while (current_node != NULL)
	{
		elements.push_back(current_node->node_id);
		current_node = current_node->next;
	}

	result.elements = elements;
	return result;
}

/*  Translates a list of variables of the same type into a param_t struct
 *  A param_t has a type and a collection of variables
 *  The type is represented by a C string
 *  The collection of variables is represented by a vector of strings
 */
param_t translateVariables(List* variables, std::string type)
{
	param_t result;
	if (variables == NULL) return result;
	result.type = type;

	std::vector<std::string> vvar;
	List* current_var = variables;
	while (current_var != NULL)
	{
		vvar.push_back(std::string(current_var->variable_name));
		current_var = current_var->next;
	}

	result.variables = vvar;
	return result;
}

/*  Translates a list of variables collections into a collection of param_t structs
 *  Each variables collection is a list of variables of a specific GP type (int, atom ..)
 */
std::vector<param_t> 		translateVariablesList(List* variables)
{
	std::vector<param_t> result;
	if (variables == NULL) return result;

	List* current_list = variables;

	while (current_list != NULL)
	{
		switch (current_list->type)
		{
			case INT_DECLARATIONS:	
					result.push_back( translateVariables( current_list->variables , "int" ) ); 
					break;
			case CHAR_DECLARATIONS:	
					result.push_back( translateVariables( current_list->variables , "char" ) ); 
					break;
			case STRING_DECLARATIONS:	
					result.push_back( translateVariables( current_list->variables , "string" ) ); 
					break;
			case ATOM_DECLARATIONS:	
					result.push_back( translateVariables( current_list->variables , "atom" ) ); 
					break;
			case LIST_DECLARATIONS:	
					result.push_back( translateVariables( current_list->variables , "list" ) ); 
					break;

			default: print_to_console("Unknown conversion of Variables list: %d", current_list->type); break;
		}
		current_list = current_list->next;
	}

	return result;
}

/* Returns a C string representation of a GP list appearing in a rule's condition
 */
std::string translateConditionList(List* condition)
{
	return ListToString(translateValues(condition));
}

/* Translates a GPCondition AST into its underlying string representation
 * This is needed because rule_t structures have conditions as plain C strings
 */
std::string translateCondition(GPCondition* condition)
{
	std::string result;
	if (condition == NULL) return result;
	switch(condition->type)
	{
		case INT_CHECK: 		result = "int( "; result+= condition->var; result += " )" ; break;
		case CHAR_CHECK: 		result = "char( "; result+= condition->var; result += " )" ; break; 
		case STRING_CHECK: 	result = "string( "; result+= condition->var; result += " )" ; break; 
		case ATOM_CHECK: 		result = "atom( "; result+= condition->var; result += " )" ; break; 

		case EQUAL:  				
				result =  translateConditionList(condition->list_cmp.left_list); 
				result+= "="; 
				result+= translateConditionList(condition->list_cmp.right_list); 
				break;
 
		case NOT_EQUAL: 
				result =  translateConditionList(condition->list_cmp.left_list); 
				result+= "!="; 
				result+= translateConditionList(condition->list_cmp.right_list); 
				break; 

		case GREATER: 
				{ std::stringstream s;
				s << translateAtom(condition->atom_cmp.left_exp); 
				s << ">"; 
				s << translateAtom(condition->atom_cmp.right_exp);
        result = s.str(); }
				break;

		case GREATER_EQUAL: 
				{ std::stringstream s;
				s << translateAtom(condition->atom_cmp.left_exp); 
				s << ">="; 
				s << translateAtom(condition->atom_cmp.right_exp);
        result = s.str(); }
				break;

		case LESS: 
				{ std::stringstream s;
				s << translateAtom(condition->atom_cmp.left_exp); 
				s << "<"; 
				s << translateAtom(condition->atom_cmp.right_exp);
        result = s.str(); }
				break;

		case LESS_EQUAL: 
				{ std::stringstream s;
				s << translateAtom(condition->atom_cmp.left_exp); 
				s << "<="; 
				s << translateAtom(condition->atom_cmp.right_exp);
        result = s.str(); }
				break;
 
		case BOOL_NOT: 			result = "not "; result+= translateCondition(condition->not_exp); break;
		case BOOL_OR: 
				result = translateCondition(condition->bin_exp.left_exp); 
				result+= " or "; 
				result+= translateCondition(condition->bin_exp.right_exp); 
				break;

		case BOOL_AND: 
				result = translateCondition(condition->bin_exp.left_exp); 
				result+= " and "; 
				result+= translateCondition(condition->bin_exp.right_exp); 
				break;

		case EDGE_PRED: 
				result = " edge( "; 
				result+= condition->edge_pred.source; 
				result += " , "; 
				result+= condition->edge_pred.target;
				if (condition->edge_pred.label != NULL) 
					result+= ListToString((translateLabel(condition->edge_pred.label)).values); 
				result += " ) "; 
				break;

		default: break;
	}
	return result;
}

/* Translates a GPRule AST into a rule_t struct 
 * A rule_t has documentation, an identifier, a list of variables, LHS and RHS graphs, an interface and a condition
 * The documentation is a C string
 * The rule id is a C string
 * The list of variables is a vector of param_t structs - each param_t is a collection of variables of the same type
 * The LHS and RHS are graph_t structs
 * The interface is an interface_t struct
 * The condition is a C string
 */
rule_t 			trasnlateRule(GPRule* rule)
{
	rule_t result;
	result.documentation = std::string("");		// The GPRule AST doesn't store comments
	result.id = std::string(rule->name);
	result.parameters = translateVariablesList(rule->variables);
	result.lhs = translateGraph(rule->lhs);
	result.rhs = translateGraph(rule->rhs);
	result.interface = translateInterface(rule->interface);
	result.condition = translateCondition(rule->condition);

	return result;
}

/* 
 * The implementation of the helper functions
 */

// Expects a list of atom values
std::vector<atom_t> translateValues(List* list)
{
	std::vector<atom_t> result;
	if (list == NULL || (list->type != GP_LIST)) return result;

	result.reserve(getASTListLength(list));

	List *value = list;
	while (value != NULL)
	{
		result.push_back(translateAtom(value->atom));
		value = value->next;
	}

	return result;
}

std::string ListToString(std::vector<atom_t> list)
{
	std::stringstream s;

	for (std::vector<atom_t>::iterator it = list.begin(); it != list.end(); ++it)
	{
			s << *it;
			if (it != (list.end() - 1)) s << ":";
	}

	return s.str();
}
/*  Translates a List of nodes into a vector of node_t
 */
std::vector<node_t> translateNodes(List* nodes)
{
	std::vector<node_t> result;
	if (nodes == NULL || (nodes->type != NODE_LIST )) return result;

	result.reserve(getASTListLength(nodes));
	List* current_node = nodes;
	node_t n;
	while (current_node != NULL)
	{
		n = translateNode(current_node->node);
		result.push_back(n);

		current_node = current_node->next;
	}	

	return result;
}


/*  Translates a List of edges into a vector of edge_t
 */
std::vector<edge_t> translateEdges(List* edges)
{
	std::vector<edge_t> result;
	if (edges == NULL || (edges->type != EDGE_LIST )) return result;

	result.reserve(getASTListLength(edges));
	List* current_edge = edges;
	edge_t e;
	while (current_edge != NULL)
	{
		e = translateEdge(current_edge->edge);
		result.push_back(e);

		current_edge = current_edge->next;
	}	

	return result;
}

/* Extra AST functionality - the Bison parser grammar is left-recursive so all lists are in reverse order */

/* 
 * Reverses the lists pointed to by a GPCondition AST
 */
void reverseConditionAST(GPCondition *condition)
{
	switch(condition->type)
	{
		case INT_CHECK: 
    case CHAR_CHECK: 
    case STRING_CHECK: 
    case ATOM_CHECK: break;

    case EDGE_PRED: 
				// struct GPLabel has a pointer (to a List) called gp_list
				condition->edge_pred.label->gp_list = reverse(condition->edge_pred.label->gp_list);
				break;

    case EQUAL: 
    case NOT_EQUAL: 
				condition->list_cmp.left_list = reverse(condition->list_cmp.left_list);
				condition->list_cmp.right_list = reverse(condition->list_cmp.right_list);
				break;

    case BOOL_NOT: 
				reverseConditionAST(condition->not_exp);

    case BOOL_OR: 
    case BOOL_AND:
				reverseConditionAST(condition->bin_exp.left_exp);
				reverseConditionAST(condition->bin_exp.right_exp);
				break;

    case GREATER: 
    case GREATER_EQUAL: 
    case LESS: 
    case LESS_EQUAL: 

		default: break;
	}

}


/* 
 * Reverses a GPRule AST - it has a list of variables, a list of interface nodes/edges, a condition (which also may have lists in it) and ASTs for LHS and RHS graphs.
 */
void reverseRuleAST(GPRule *rule)
{
	if (rule->variables) rule->variables = reverse(rule->variables);
	if (rule->interface) rule->interface = reverse(rule->interface);

	if (rule->condition) reverseConditionAST(rule->condition);
	if (rule->lhs) reverseGraphAST(rule->lhs);
	if (rule->rhs) reverseGraphAST(rule->rhs);
}

}
