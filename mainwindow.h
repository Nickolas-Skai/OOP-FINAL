#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QDateEdit>
#include <QMainWindow>
#include <QCalendarWidget>
#include <QDateTimeEdit>
#include <QPixmap>
#include <QLabel>
#include <QListView>
#include <QStandardItemModel>
#include <QStandardItem>
#include <QTableView>
#include <QMessageBox>
#include <QListWidget>

#include <adminusers.h>

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

    void on_Delete_Room_clicked();

    void on_Editperson_2_clicked();

 //   void on_editroom_clicked();

    void on_Addroom_clicked();

    void on_addperson_clicked();

    void on_CreateUser_clicked();

    void on_backtodashboard_clicked();

    void on_Checkbookings_clicked();

    void on_Editperson_clicked();


    void on_addperson_adminview_clicked();

    void on_Deleteperson_clicked();

private:
    Ui::MainWindow *ui;
    //create a list view model
    QStandardItemModel *model;
    QStandardItem *item;
    database db;
    users Currentusers;
    Adminusers Adminuser;

private slots:

    void on_Edituserconfim_clicked();
    //void on_listWidget_currentItemChanged(QListWidgetItem *current, QListWidgetItem *previous);
    void on_continuetodetails_clicked();
    void on_actionView_bookings_triggered();

    void on_gotoroommadd_clicked();
    void on_editroom_2_clicked();
    void on_Roommanagment_clicked();
    void on_personmanagment_clicked();
    void on_ViewListings_clicked();
    void on_Createlisting_clicked();
    void on_pushButton_3_clicked();
};

#endif // MAINWINDOW_H

