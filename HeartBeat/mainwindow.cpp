#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<qdebug.h>
#include<qtimer.h>
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    m_bHear_on =false;
    timer_heart = new QTimer;
    connect(timer_heart,SIGNAL(timeout()),this,SLOT(timerOuttimer_heart()));
    timer_heart->start(100);
}

MainWindow::~MainWindow()
{
    delete ui;

    timer_heart->stop();
}
void MainWindow::timerOuttimer_heart(){

    //    ui->label_jogstate->setStyleSheet("background-color:green");
    static int i;
    if(m_bHear_on){
        qDebug()<<"=================i:"<<i;
        i++;
        if(i<10){
        ui->label->setStyleSheet("background-color:green");
        }
        else if((i>=10)&&(i<20)){
            ui->label->setStyleSheet("background-color:grey");
        }
        else if(i>=20){
            i=0;
        }
    }
    else{
        i=0;
        ui->label->setStyleSheet("background-color:red");
    }
}

void MainWindow::on_pushButton_pressed()
{
    m_bHear_on =true;
    qDebug()<<"on";
}

void MainWindow::on_pushButton_released()
{
    m_bHear_on =false;
    qDebug()<<"                     off";
}

