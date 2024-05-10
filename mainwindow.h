#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <database.h>
#include "users.h"
#include "adminusers.h"
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

    void on_Back2home_2_clicked();

    void on_back2home_clicked();

    void on_Back_2List_clicked();

    void on_Backtoroom_clicked();

    void on_b2menu_clicked();

    void on_b2menu_2_clicked();

    void on_b2menu_3_clicked();

    void on_b2menu_4_clicked();

    void on_actionSign_out_Exit_triggered();

    void on_actionSign_out_triggered();

private:
    Ui::MainWindow *ui;
    //create a list view model
    QStandardItemModel *model;
    QStandardItem *item;
    database db;
    //users users;
    //Adminusers Adminusers;

};
#endif // MAINWINDOW_H
