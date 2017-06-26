#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QTimer>
#include <QDateTime>
#include <QMessageBox>

int cont=0;
int rest=10;

void MainWindow::fTimer(){

              ui->lcdNumber->display(cont++);
              ui->lcdRest->display(rest--);

              if(cont == 10)
              {
                  QMessageBox::warning(this,"Warning !", " Cronometer is equal to 10");
                  QPixmap picture_reload(":/new/prefix1/opensource.png");
                  ui->lblFigure->setPixmap(picture_reload.scaled(60,60, Qt::KeepAspectRatio));
                  QFile file(":/new/prefix1/test.txt");
                  file.open(QIODevice::ReadOnly | QIODevice::Text);
                  QString line = file.readAll();
                  ui->plainTextEdit->appendPlainText(line);


              }
              ui->label_2->setText(QDateTime::currentDateTime().toString());

}

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
  }

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_btnStart_clicked()
{
    // Counter and cronometer
    ui->lcdNumber->setFrameStyle(QFrame::NoFrame);

    QTimer *cronometro = new QTimer(this);
    connect(cronometro, SIGNAL(timeout()),this,SLOT(fTimer()));
    cronometro->start(1000);


}
