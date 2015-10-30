/*!
 * \file
 */
#ifndef NODE_HPP
#define NODE_HPP

#include <QPointF>
#include <QObject>

#include "list.hpp"

namespace Developer {

class Graph;
class Edge;

/*!
 * \brief The Node class represents a node within a GP graph object
 */
class Node : public QObject
{
    Q_OBJECT

public:
    Node(const QString &nodeId, const List &nodeLabel = List(), const QString &nodeMark = QString("none"), bool isRoot = false,
         const QPointF &nodePos = QPointF(), Graph *parent = 0);

    QString id() const;
    List label() const;
    QPointF pos() const;
    qreal xPos() const;
    qreal yPos() const;
    bool isRoot() const;
    QString mark() const;
    bool isPhantomNode() const;

    std::vector<Edge *> edges() const;
    std::vector<Edge *> edgesFrom() const;
    std::vector<Edge *> edgesTo() const;

    bool hasEdgeIn() const;
    bool hasEdgeOut() const;

    Graph *parent() const;

    void setId(const QString &nodeId);
    void setLabel(const List &nodeLabel);
    void setPos(const QPointF &nodePos);
    void setPos(qreal x, qreal y);
    void setIsRoot(bool root);
    void setMark(const QString &mark);
    void setPhantom(bool phantom);

signals:
    void nodeChanged();
    void idChanged(QString id);
    void labelChanged(List label);
    void isRootChanged(bool root);
    void markChanged(QString mark);
    void isPhantomNodeChanged(bool phantom);

private:
    QString _id;
    List _label;
    QPointF _pos;
    bool _isRoot;
    QString _mark;
    Graph *_parent;
    bool _phantom;
};

}

#endif // NODE_HPP
