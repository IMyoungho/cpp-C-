#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QGraphicsItem>
#include <QGraphicsPixmapItem>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QFile>
#include <QMessageBox>

bool collide(QGraphicsItem * moving_object, int dx, int dy);
void load_map(QString fileName);
bool check_clear();
QGraphicsScene *scene;
QGraphicsItem *hero;
QGraphicsItem * clear_tile;
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    scene = new QGraphicsScene;
    ui->graphicsView->setScene(scene);
    load_map("map.txt");
}

MainWindow::~MainWindow()
{
    delete ui;
}

void load_map(QString fileName)
{
    QFile file(fileName);
    file.open(QFile::ReadOnly);
    QString content(file.readAll());
    QStringList line_list = content.split(("\n"));
    int x, y;
    x = 0;
    y = 0;
    foreach (QString line, line_list) {
        QStringList cell_list = line.split(" ");
        foreach(QString cell, cell_list)
        {
            QPixmap pixmap;
            QString imgFile = "empty.png";
            int z;
            if(cell.contains(("0")))
            {
                imgFile = "tile.png";
                z = 0;
            }
            if(cell.contains(("1")))
            {
                imgFile = "object.png";
                z = 1;
            }
            if(cell.contains(("2")))
            {
                imgFile = "hero.png";
                z = 1;
            }
            if(cell.contains(("3")))
            {
                imgFile = "dest.png";
                z = 0;
            }
            pixmap.load(imgFile);
            QGraphicsItem * item = scene->addPixmap(pixmap);
            item->setPos(x*16, y*16);
            item->setZValue(z);
            if(imgFile.contains("hero"))
                hero = item;
            if(imgFile.contains("dest"))
                clear_tile = item;
            x++;
        }
        y++;
        x=0;
    }
}


bool collide(QGraphicsItem *moving_object, int dx, int dy){
    QPoint dest_post(moving_object->x()+dx,moving_object->y()+dy);
    QRect dest_rect(dest_post, QSize(16,16));
    QList<QGraphicsItem*> list =scene->items(dest_rect);
    foreach (QGraphicsItem * item, list) {
        if(item == moving_object)
            continue;
        else if(item->zValue() == moving_object->zValue())
            return true;
    }
    return false;
}
bool check_clear(){
    if(hero->pos() == clear_tile->pos())
        return true;
    return false;
}

void MainWindow::on_pushButton_5_clicked()
{
    if(collide(hero, 0, -16))
        return;
    hero->moveBy(0,-16);
    if(check_clear())
        QMessageBox::about(this,QString("CLEAR!!"), QString("YOU are ESCAPE !!"));
}

void MainWindow::on_pushButton_down_clicked()
{
    if(collide(hero, 0, 16))
        return;
    hero->moveBy(0, 16);
    if(check_clear())
        QMessageBox::about(this,QString("CLEAR!!"), QString("YOU are ESCAPE !!"));
}

void MainWindow::on_pushButton_left_clicked()
{
    if(collide(hero, -16, 0))
        return;
    hero->moveBy(-16,0);
    if(check_clear())
        QMessageBox::about(this,QString("CLEAR!!"), QString("YOU are ESCAPE !!"));
}

void MainWindow::on_pushButton_right_clicked()
{
    if(collide(hero, 16, 0))
        return;
    hero->moveBy(16,0);
    if(check_clear())
        QMessageBox::about(this,QString("CLEAR!!"), QString("YOU are ESCAPE !!"));
}
