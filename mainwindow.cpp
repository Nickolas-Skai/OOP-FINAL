#include "mainwindow.h"
#include "database.h"
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
    //go to the listingPage if login credentials are correct
QString usrname = ui->user_input->text();
QString passrd = ui->pass_input->text();
   // ui->stackedWidget->setCurrentIndex(3);

if(db.VerifyUser(usrname, passrd)) {
        ui->stackedWidget->setCurrentIndex(3);
}else{
        QMessageBox::warning(this, "Login Failed", "Invalid username or password.");
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
    } else {
        // Convert QDate object back to a formatted QString the database will be able to take
        QString formattedDateOfBirth = dobDate.toString("yyyy-MM-dd");
    }


    // Convert QDate object back to formatted QString
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

