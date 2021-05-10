#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "QPainter"
#include "node.h"
#include "QSize"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();


private:
    Ui::MainWindow *ui;
    Node* root = nullptr;
    const int recWidth = 50;
    const int recHeight = 30;
    const QSize size = QSize(50,30);
    const int menuBarHeight = 30 ;
    const int levelMagin = 10;

protected:
    void paintEvent(QPaintEvent *event) override;
    void drawNode(Node* node,int x_node,int y_node,QPainter* painter);
    QPoint getRecPos(int y_node,int x_node);


private slots:
    void on_addNode_clicked();
    void on_preOrderTraversal_clicked();

    void on_deleteNode_clicked();
};
#endif // MAINWINDOW_H
