#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QPixmap>
#include <QPalette>
#include <QBrush>
#include <QColor>
#include <QDate>
#include <QDateEdit>
#include <QCalendarWidget>
#include <QDateTimeEdit>



MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QPixmap pix(":/.png/tropicalbg.png");
    QPixmap pix1(":/.png/icon.png");
    ui->bg_image->setPixmap(pix);
    ui->bgimg_login->setPixmap(pix);
    ui->bgimg_signup->setPixmap(pix);
    ui->Search_icon->setPixmap(pix1);
    ui->bg_image->setScaledContents(true);
    ui->bgimg_login->setScaledContents(true);
    ui->bgimg_signup->setScaledContents(true);
    ui->Search_icon->setScaledContents(true);

    //create a instance of the standard item model
    model = new QStandardItemModel(this);




}

MainWindow::~MainWindow()
{



}




void MainWindow::on_loginbutton_clicked()
{
    //will go to the login page in the stack
    ui->stackedWidget->setCurrentIndex(2);
//will make connections to the database
}




void MainWindow::on_signupbutton_clicked()
{
ui->stackedWidget->setCurrentIndex(1);
}

void MainWindow::on_login_clicked()
{
    //go to the listingPage ( stack may be out of order)
    ui->stackedWidget->setCurrentIndex(3);


}


void MainWindow::on_signup_clicked()
{
    //go to login page
    ui->stackedWidget->setCurrentIndex(2);
}

