#include "mainwindow.h"
#include "database.h"
#include "users.h"
#include "adminusers.h"
#include "ui_mainwindow.h"
#include <QPixmap>
#include <QPalette>
#include <QBrush>
#include <QColor>
#include <QDate>
#include <QDateEdit>
#include <QCalendarWidget>
#include <QDateTimeEdit>
#include <QMessageBox>

//create a instance of the database
database db;
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

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
    //go to the listingPage if login credentials are correct

    //get user input
QString usrname = ui->user_input->text();
QString passrd = ui->pass_input->text();
   // ui->stackedWidget->setCurrentIndex(3);

//to store the users credentials that are retrieved from the
//the verify function
QStringList usercredentials = db.VerifyUser(usrname, passrd);

//if the user's credentials are empty then give an error
if (usercredentials.isEmpty()) {
    QMessageBox::warning(this, "Login Failed", "Invalid username or password.");
    return;
}

//and extract the information
int userid = usercredentials.at(0).toInt();
QString fname = usercredentials.at(1);
QString lname = usercredentials.at(2);
QString usernam = usercredentials.at(3);
QString pswd = usercredentials.at(4);
QString date_of_birht = usercredentials.at(5);
QString phone_number = usercredentials.at(6);
QString email = usercredentials.at(7);
bool admin = usercredentials.at(8) == "true";

//create an instance of the user through the constructor of user
users userinstance(userid, fname, lname, usernam, pswd, date_of_birht, phone_number, email, admin);


//check if its admin by checking if its true at 8
if(admin == true) {
    //give the admin features such as edit and delete



} else {
    //give the regular users the booking features
    // Proceed with the login process...
    ui->stackedWidget->setCurrentIndex(5);
}

}

//this on click is what calls the add user function to add a user to the database
void MainWindow::on_signup_clicked()
{
    //store the values entered in the form:
    QString firstName = ui->fristNameLineEdit->text();
    QString Lastname = ui->lastNameLineEdit->text();
    QString userName = ui->usernameLineEdit->text();
    QString pswd = ui->passwordLineEdit->text();
    QString phnNum = ui->phoneNumberLineEdit->text();
    QString mail = ui->emailLineEdit->text();
    QDate dobDate = ui->dateEdit->date();
    if (!dobDate.isValid()) {
        // Handle incase date of birth is not valid
        qDebug() << "Date of birth is not valid";
    }

    // Convert QDate object back to a formatted QString the database will be able to take
    QString formattedDateOfBirth = dobDate.toString("yyyy-MM-dd");
    //the admin privelage is not showed and so the user will be given a admin = false always, and can only changed by admin
    bool admin = false;


    // Check if any of the fields are empty
    if (firstName.isEmpty() || Lastname.isEmpty() || userName.isEmpty() || pswd.isEmpty() || phnNum.isEmpty() || mail.isEmpty()) {
        // Show error message using QMessageBox
        QMessageBox::critical(this, ("Error"), ("All fields must be filled."));
        return; // Exit the function early
    }

    // Call the addUser function to add the user to the database
    bool userAdded = db.addUser(firstName, Lastname, userName, pswd, phnNum, mail, formattedDateOfBirth, admin);
    if (userAdded) {
        // User added successfully
        // Proceed to the login page
        ui->stackedWidget->setCurrentIndex(2); // Go to login page
    } else {
        // Error adding user to the database
        // display error message using QMessageBox
        QMessageBox::critical(this, tr("Error"), tr("Failed to add user to the database."));
    }
}


void MainWindow::on_Back2home_2_clicked()
{
    //this will retun the user to the home page
    ui->stackedWidget->setCurrentIndex(0);
}


void MainWindow::on_back2home_clicked()
{
    //this will return the user to the home page
    ui->stackedWidget->setCurrentIndex(0);
}


void MainWindow::on_Back_2List_clicked()
{
    //this will return the user to the listing page
    ui->stackedWidget->setCurrentIndex(3);
}


void MainWindow::on_Backtoroom_clicked()
{
    //this will take a user back to the room page
    ui->stackedWidget->setCurrentIndex(4);

}


void MainWindow::on_b2menu_clicked()
{
    //this will take a user back to the menu page
    ui->stackedWidget->setCurrentIndex(5);
}


void MainWindow::on_b2menu_2_clicked()
{
    //this will take a user back to the menu page
    ui->stackedWidget->setCurrentIndex(5);
}


void MainWindow::on_b2menu_3_clicked()
{
    //this will take a user back to the menu page
    ui->stackedWidget->setCurrentIndex(5);
}


void MainWindow::on_b2menu_4_clicked()
{
    //this will take a user back to the menu page
    ui->stackedWidget->setCurrentIndex(5);
}


void MainWindow::on_actionSign_out_Exit_triggered()
{
    //this will log you out and exit the program
    //ask if sure?
    //if yes is clicked then log out and exit
    int ret = QMessageBox::question(this, "Sign out", "Are you sure you want to sign out and exit?", QMessageBox::Yes | QMessageBox::No);
    if (ret == QMessageBox::Yes) {
        // Log out and exit
        ui->stackedWidget->setCurrentIndex(0);
        QApplication::quit();
    }


}


void MainWindow::on_actionSign_out_triggered()
{
    //this will log out the user
    //ask if sure?
    //if yes is clicked then log out
    int ret = QMessageBox::question(this, "Sign out", "Are you sure you want to sign out?", QMessageBox::Yes | QMessageBox::No);
    if (ret == QMessageBox::Yes) {
        // Log out
        ui->stackedWidget->setCurrentIndex(0);
        //database connection will be closed
        QMessageBox::information(this, "Sign out", "You have successfully signed out.");

    }

}

