#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "database.h"
#include <QDateEdit>
#include <QMainWindow>
#include <QCalendarWidget>
#include <QDateTimeEdit>
#include <QPixmap>
#include <QLabel>
#include <QListView>
#include <QStandardItemModel>
#include <QStandardItem>


QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:


    void on_loginbutton_clicked();

    void on_signupbutton_clicked();

    void on_login_clicked();

    void on_signup_clicked();

private:
    Ui::MainWindow *ui;
    //create a list view model
    QStandardItemModel *model;
    QStandardItem *item;
    database db;

};
#endif // MAINWINDOW_H
