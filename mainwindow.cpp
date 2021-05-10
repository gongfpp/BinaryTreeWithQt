#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QPainter"
#include "QDebug"
#include "QtMath"
#include "QVector"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::paintEvent(QPaintEvent *)
{
    static int num = 0;
    num ++;
    qDebug() <<"graph frame:" <<num;
//    QRect rec(x_node*(recWidth+5),y_node*(recHeight+2),recWidth,recHeight);
    QPainter painter(this);
    QFont font("微软雅黑",18);
    painter.setFont(font);

    if(root!=nullptr)
        drawNode(root,0,0,&painter);
//    painter.setPen(QPen(Qt::blue,3));//设置画笔形式  或者Qpen pen; pen.setColor(QColor(40, 115, 216)); pen.setWidth(2);
//    painter.drawRect(rec);
//    painter.setPen(QPen(Qt::black));

//    painter.drawText(rec,Qt::AlignCenter,val);

//    painter.drawRect(400,400,4+num,4+num);
}


void MainWindow::on_addNode_clicked()
{
    int value = ui->NodeInput->text().toInt();
    qDebug() << "value:" << value;
    if(root == nullptr){
        root = new Node(value);
        qDebug()  << "add a root:"<< value;
//        root->preOrderTraversal();
        ui->NodeInput->setText("");
        update();
        return ;

    }
    root->addNode(value);
//    root->preOrderTraversal();
    qDebug() <<"add a node:" << value;
    ui->NodeInput->setText("");
    update();
}

//x,y start at 0
void MainWindow::drawNode(Node* node,int x_node  ,int y_node,QPainter* painter){
//    const int rate_height = 7;
//    const int rate_width = 10;

//    const int rec_width = this->width()/rate_width-5;
//    const int rec_height = this->height()/rate_height-4;
    if(node==nullptr)
        return ;
    QPoint point(getRecPos(y_node,x_node));

    QRect rec(point,size);
//    QRect rec(x_node*(recWidth+5),y_node*(recHeight+2),recWidth,recHeight);
    painter->setPen(QPen(Qt::blue,3));//设置画笔形式  或者Qpen pen; pen.setColor(QColor(40, 115, 216)); pen.setWidth(2);
    painter->drawRect(rec);
    painter->setPen(QPen(Qt::black));

    QFont font("微软雅黑",18);
    painter->setFont(font);
    painter->drawText(rec,Qt::AlignCenter,QString::number(node->value()));
    qDebug() << "drawNode:"<< node->value() << y_node << x_node;

    if(y_node >= 1){
        if(x_node & 1){
            QPoint p1(getRecPos(y_node,x_node));
            QPoint p2(getRecPos(y_node-1,(x_node-1)/2));
            p1+=QPoint(recWidth/2,0);
            p2+=QPoint(recWidth/2,recHeight);
            painter->drawLine(p1,p2);
        }

        else {
            QPoint p1(getRecPos(y_node,x_node));
            QPoint p2(getRecPos(y_node-1,x_node/2));
            p1+=QPoint(recWidth/2,0);
            p2+=QPoint(recWidth/2,recHeight);
            painter->drawLine(p1,p2);
        }
    }

    if(node->left!=nullptr)
        drawNode(node->left,x_node*2,y_node+1,painter);
    if(node->right!= nullptr)
        drawNode(node->right,x_node*2+1,y_node+1,painter);

}

//y x start at 0
QPoint MainWindow::getRecPos(int y_node, int x_node)
{

    //第y层节点和空隙的数量和,用于计算rec的方位
    int numX = qPow(2,y_node) + 1;
    int blockWidth = this->width() / numX;

    try {
        if(x_node>=qPow(2,y_node))
            throw 1;
        if(blockWidth<recWidth)
            throw 2;
    } catch (int e) {
        switch (e) {
        case 1:qDebug() << "Error:x_node >= 2^y_node x,y wrong";break;
        case 2:qDebug() << "Warning:blockWidth<recWidth ,try bigger widget or small tree";break;

        }
    }
    qDebug() << x_node*blockWidth*2+blockWidth << menuBarHeight+y_node*(recHeight+5);
    return QPoint(x_node*blockWidth+blockWidth,\
           menuBarHeight+y_node*(recHeight+levelMagin));

}

void MainWindow::on_preOrderTraversal_clicked()
{

    qDebug() << "用来输出提示信息";


}

void MainWindow::on_deleteNode_clicked()
{

    int value = ui->NodeInput->text().toInt();
    qDebug() << "value:" << value;
    if(root == nullptr){
        ui->NodeInput->setText("");
        update();
        return ;

    }
    root->deleteNode(root,value);
//    root->preOrderTraversal();
    ui->NodeInput->setText("");
    update();
}
