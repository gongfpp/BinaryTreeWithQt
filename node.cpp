#include "node.h"
#include "QDebug"
Node::Node(QObject *parent) : QObject(parent)
{
    qDebug() << "no set value";
}

Node::Node(int value, QObject *parent):QObject(parent)
{
//    qDebug() << "set value:" << value;
    this->val = value;
    this->left = nullptr;
    this->right = nullptr;
//    qDebug() << "set value:" << value;
}

void Node::addNode(int value)
{
    if(this->val == value)
        return ;
    if(this->val < value){
        if(this->right == nullptr){
            this->right = new Node(value);
//            qDebug() << "add value:" << value  ;
        }
        else
            this->right->addNode(value);
    }else if(this->val > value){
        if(this->left == nullptr){
            this->left = new Node(value);
//            qDebug() << "add value:" << value  ;
        }
        else
            this->left->addNode(value);
    }

}

void Node::addNode(Node *node)
{
    if(this->val == node->val)
        return ;
    if(this->val < node->val){
        if(this->right == nullptr){
            this->right = node;
//            qDebug() << "add value:" << value  ;
        }
        else
            this->right->addNode(node);
    }else if(this->val > node->val){
        if(this->left == nullptr){
            this->left = node;
//            qDebug() << "add value:" << value  ;
        }
        else
            this->left->addNode(node);
    }
}

void Node::preOrderTraversal()
{
//    if(this->val)   return;

    qDebug() << this->val ;
    if(this->left != nullptr)
        this->left->preOrderTraversal();
    if(this->right != nullptr)
        this->right->preOrderTraversal();
}

void Node::deleteNode(Node* root,int value)
{
    if(this->val == value){
        if(this==root){
            root = nullptr;
            return ;
        }else {
            qDebug() << "deleteError";
            return ;
        }
    }
    if(this->val > value){
        if(this->left->val == value){
            Node* t1 = this->left->left;
            Node* t2 = this->left->right;
            this->left = nullptr;
            root->addNode(t1);
            root->addNode(t2);
        }else {
            this->left->deleteNode(root,value);
        }
    }else {
        if(this->right->val == value){
            Node* t1 = this->right->left;
            Node* t2 = this->right->right;
            this->right = nullptr;
            root->addNode(t1);
            root->addNode(t2);
        }else {
            this->right->deleteNode(root,value);
        }
    }


}

int Node::value()
{
    return this->val;
}

void Node::setValue(int value)
{
    this->val = value;
}
