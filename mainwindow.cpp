#include "mainwindow.h"
#include <QMessageBox>
#include <QGridLayout>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    setWindowTitle("Projet INF1015");


    view = new QGraphicsView(this);
    board = new Board(view);

    view->setScene(board);
    view->setAlignment(Qt::AlignLeft | Qt::AlignTop);
    view->centerOn(0,0);
    view->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    view->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);


    setCentralWidget(view);
}

MainWindow::~MainWindow()
{

}

