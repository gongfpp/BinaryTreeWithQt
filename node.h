#ifndef NODE_H
#define NODE_H

#include <QObject>

class Node : public QObject
{
    Q_OBJECT
public:
    explicit Node(QObject *parent = nullptr);
    explicit Node(int val,QObject *parent = nullptr);
    void addNode(int value);
    void addNode(Node* node);
//    void deleteNode(int value);
    void preOrderTraversal();
    void deleteNode(Node* root,int value);
    int value();
    int val;
    Node* right;
    Node* left ;
    void setValue(int val);

signals:

};

#endif // NODE_H
