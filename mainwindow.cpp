#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "database.h"
#include "users.h"
#include <QPixmap>
#include <QPalette>
#include <QBrush>
#include <QColor>
#include <QDate>
#include <QDateEdit>
#include <QCalendarWidget>
#include <QDateTimeEdit>
#include <QMessageBox>

/*ADMIN HOME PAGE IS NUMBER 6*/



//cate a instance of the database
MainWindow::MainWindow(QWidget *pant)
    : QMainWindow(pant)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

populateRoomList();
    //help me do this part please. I am not su how to do this
/*
    //cate a instance of the standard table model to display data from the database
    model = new QStandardItemModel(this);
    //set the table view to the model
    ui->personview->setModel(model);
    //create the table view
    model->setColumnCount(8);
    model->setHorizontalHeaderLabels(QStringList() << "ID" << "First Name" << "Last Name" << "Username" << "Password" << "Date of Birth" << "Phone Number" << "Email");

    //query the database for the users
    QSqlQueryModel *users = db.getUsers();
    //populate the table view with the users
    for(int i = 0; i < users->rowCount(); i++){
        model->setItem(i, 0, new QStandardItem(users->record(i).value("ID").toString()));
        model->setItem(i, 1, new QStandardItem(users->record(i).value("First Name").toString()));
        model->setItem(i, 2, new QStandardItem(users->record(i).value("Last Name").toString()));
        model->setItem(i, 3, new QStandardItem(users->record(i).value("Username").toString()));
        model->setItem(i, 4, new QStandardItem(users->record(i).value("Password").toString()));
        model->setItem(i, 5, new QStandardItem(users->record(i).value("Date of Birth").toString()));
        model->setItem(i, 6, new QStandardItem(users->record(i).value("Phone Number").toString()));
        model->setItem(i, 7, new QStandardItem(users->record(i).value("Email").toString()));
    }

    */



}

MainWindow::~MainWindow()
{



}


void MainWindow::populateRoomList() {
    // Assuming ui->roomListWidget is your QListWidget
    ui->listWidget->clear();
    //query the database for the rooms
    QSqlQueryModel *rooms = db.getRoomdetails();
    //populate the list widget with the rooms for every room
    QListWidgetItem *item;
    for(int i = 0; i < rooms->rowCount(); i++){
        item = new QListWidgetItem();
       QString roomnumber = rooms->query().value("roomnumber").toString();
       QString roomtype = rooms->query().value("roomtype").toString();
       QString roomdescription = rooms->query().value("roomdescription").toString();
        ui->listWidget->addItem(item);
    }


}
//change the page to the login page and load rooms to be displayed
void MainWindow::on_loginbutton_clicked()
{
    //will go to the login page in the stack
    ui->stackedWidget->setCurrentIndex(2);

    //for every record in the database add the room to the list adding it to an apporiate widget to display

    //query the database for the rooms
    QSqlQueryModel *rooms = db.getRoomdetails();

    //populate the list widget with the rooms for every room
    QListWidgetItem *item;
    for(int i = 0; i < rooms->rowCount(); i++){
        item = new QListWidgetItem();
       QString roomnumber = rooms->query().value("roomnumber").toString();
       QString roomtype = rooms->query().value("roomtype").toString();
       QString roomdescription = rooms->query().value("roomdescription").toString();
        ui->listWidget->addItem(item);
    }



}




void MainWindow::on_signupbutton_clicked()
{
ui->stackedWidget->setCurrentIndex(1);
}


//Login in function
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
//users userinstance(userid, fname, lname, usernam, pswd, date_of_birht, phone_number, email, admin);
//currentusers = users(userid, fname, lname, usernam, pswd, date_of_birht, phone_number, email, admin);

//check if its admin by checking if its true at 8
if(admin == true) {
    //create teh admin user intance
    Adminuser = Adminusers(userid, fname, lname, usernam, pswd, date_of_birht, phone_number, email, admin);
    //give a message for now that says admin is in, for now this will be shown:
    QMessageBox::information(this,"Admin login", "Admin has logged in");
    ui->stackedWidget->setCurrentIndex(6);
    //give access to the admin users to certain pages

} else if(admin == false){
    //give the regular users the booking features
    //and create that instance of the base user
    Currentusers =  users(userid, fname, lname, usernam, pswd, date_of_birht, phone_number, email, admin);
    // Proceed with the login process...
    ui->stackedWidget->setCurrentIndex(5);
    //this is to hide all the other buttons that the user should not see only admins

    ui->backtodashboard->hide();

    ////LOAD ROOMS TO BE BOOKED IN THE
    // NAME OF TABLEVIEW: listWidget
    //ui->listWidget->setModel(db.getRooms());

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


//////////////////////////////////////////////////////////////ALL BACK BUTTONS TO GO BACK TO ADMIN MENU PAGE////////////////////////////
//BACK BUTTON TO GO BACK TO ADMIN MENU PAGE
void MainWindow::on_b2menu_clicked()
{
    //this will take a user back to the admin menu page
    ui->stackedWidget->setCurrentIndex(6);
}

//BACK BUTTON TO GO BACK TO ADMIN MENU PAGE
void MainWindow::on_b2menu_2_clicked()
{
    //this will take a user back to the admin menu page
    ui->stackedWidget->setCurrentIndex(6);
}

//BACK BUTTON TO GO BACK TO ADMIN MENU PAGE
void MainWindow::on_b2menu_3_clicked()
{
    //this will take a user back to the menu page
    ui->stackedWidget->setCurrentIndex(6);
}

//BACK BUTTON TO GO BACK TO ADMIN MENU PAGE
void MainWindow::on_b2menu_4_clicked()
{
    //this will take a user back to the menu page
    ui->stackedWidget->setCurrentIndex(6);
}
void MainWindow::on_backtodashboard_clicked()
{
    //this is will go to the admin menu page
    ui->stackedWidget->setCurrentIndex(6);
}


////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////




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


////////////DELETE BUTTON ON THE EDIT/DELETE ROOM PAGE//////////
void MainWindow::on_Delete_Room_clicked()
{

//delete room
    // Get the selected room ID
    QModelIndexList selectedRows = ui->Room_view->selectionModel()->selectedRows();
    if (selectedRows.isEmpty()) {
        // No room selected
        QMessageBox::warning(this, "Delete Room", "Please select a room to delete.");
        return;
    }

    int roomID = selectedRows.at(0).data().toInt();

    // Ask the user if they are sure they want to delete the room
    int ret = QMessageBox::question(this, "Delete Room", "Are you sure you want to delete this room?", QMessageBox::Yes | QMessageBox::No);
    if (ret == QMessageBox::Yes) {
        // Delete the room from the database
        QString result = Adminuser.delete_Room(roomID);

        // Check if the deletion was successful
        if (result == "Room Deleted Successfully!") {
            // Room deleted successfully
            QMessageBox::information(this, "Delete Room", "Room deleted successfully.");

            // Refresh the table view
            ui->Room_view->setModel(db.getRooms());
        } else {
            // Error deleting room
            QMessageBox::critical(this, "Delete Room", result);
        }
    }
}


/////////////////////////////ALL BUTTONS THAT ARE IN THE ADMIN OPTION PAGE/////////////////////////////////////////


//the Edit/Delete PERSON button on the ADMIN OPTION PAGE
void MainWindow::on_Editperson_2_clicked()
{
    ui->stackedWidget->setCurrentIndex(9);
    //when clicked it will fill up the table view with the users data
    ui->personview->setModel(db.getUsers());
}

//THE EDIT/DELETE ROOM BUTTON on the ADMIN OPTION PAGE
void MainWindow::on_editroom_clicked()
{
    ui->stackedWidget->setCurrentIndex(8);
    //when clicked it will fill up the table view with the users data
    ui->Room_view->setModel(db.getRooms());
}

//THE ADD ROOM BUTTON ON THE ADMIN MENU OPTION PAGE
void MainWindow::on_Addroom_clicked()
{
    ui->stackedWidget->setCurrentIndex(7);
}

//THE ADD PERSON BUTTON ON THE ADMIN OPTION PAGE
void MainWindow::on_addperson_clicked()
{
    ui->stackedWidget->setCurrentIndex(10);
}


/////////////////////////////////////////////////////ADD USER BUTTON FOR ADMINS///////////////////////////
void MainWindow::on_CreateUser_clicked()
{
    //store the values entered in the form:
    QString firstName = ui->fristNameLineEdit_2->text();
    QString Lastname = ui->lastNameLineEdit_2->text();
    QString userName = ui->usernameLineEdit_2->text();
    QString pswd = ui->passwordLineEdit_2->text();
    QString phnNum = ui->phoneNumberLineEdit_2->text();
    QString mail = ui->emailLineEdit_2->text();
    QDate dobDate = ui->dateEdit_3->date();
    bool admin= ui->AdminCheckBox->isChecked();
    if (!dobDate.isValid()) {
        // Handle incase date of birth is not valid
        qDebug() << "Date of birth is not valid";
    }

    // Convert QDate object back to a formatted QString the database will be able to take
    QString formattedDateOfBirth = dobDate.toString("yyyy-MM-dd");
    //REMOVE THIS ONCE SEO ADDS THE ADMIN OPTION

    // Check if any of the fields are empty
    if (firstName.isEmpty() || Lastname.isEmpty() || userName.isEmpty() || pswd.isEmpty() || phnNum.isEmpty() || mail.isEmpty()) {
        // Show error message using QMessageBox
        QMessageBox::critical(this, ("Error"), ("All fields must be filled."));
        return; // Exit the function early
    }


    // Call the addUser function to add the user to the database
    QString newuser = Adminuser.Add_User(firstName, Lastname, userName, pswd, phnNum, mail, formattedDateOfBirth, admin);
    // Check if the deletion was successful
    if (newuser == "Room Deleted Successfully!") {
        // Room deleted successfully
        QMessageBox::information(this, "Delete Room", "Room deleted successfully.");

        // Refresh the table view
        ui->personview->setModel(db.getUsers());
    } else {
        // Error deleting room
        QMessageBox::critical(this, "Delete Room", newuser);
    }
}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////


void MainWindow::on_Checkbookings_clicked()
{
    //will go to view bookings page

    ui->stackedWidget->setCurrentIndex(11);
}


void MainWindow::on_Editperson_clicked()
{

    //check if a user is selected
    QModelIndexList selectedRows = ui->personview->selectionModel()->selectedRows();
    if (selectedRows.isEmpty()) {
        // No user selected
        QMessageBox::warning(this, "Edit User", "Please select a user to edit.");
        return;
    }
    //if user is selected then go to the edit page
    ui->stackedWidget->setCurrentIndex(10);
    //it will change the label to edit user
    ui->title_signup_2->setText("Edit User:");
    //this will hide the create user button
    ui->CreateUser->hide();
    //edit user button will be shown
    ui->Edituserconfim->show();
    //edit user botton will have slot to edit user
    ui->Edituserconfim->setText("Edit User");
    int userID = selectedRows.at(0).data().toInt();
    db.getUser(userID);


    //idk man

    //this will fill up the form with the users data
    const User& user = db.getUser(userID);
    ui->fristNameLineEdit_2->setText(user.getFirstName());
    ui->lastNameLineEdit_2->setText(user.getLastName());
    ui->usernameLineEdit_2->setText(user.getUsername());
    ui->passwordLineEdit_2->setText(user.getPassword());
    ui->phoneNumberLineEdit_2->setText(user.getPhoneNumber());
    ui->emailLineEdit_2->setText(user.getEmail());
    ui->dateEdit_3->setDate(user.getDateOfBirth());
    ui->AdminCheckBox->setChecked(user.getAdmin());
    //this will fill up the form with the users data


    ///this will go into the edit user slot
/*    QString firstName = ui->fristNameLineEdit_2->text();
    QString Lastname = ui->lastNameLineEdit_2->text();
    QString userName = ui->usernameLineEdit_2->text();
    QString pswd = ui->passwordLineEdit_2->text();
    QString phnNum = ui->phoneNumberLineEdit_2->text();
    QString mail = ui->emailLineEdit_2->text();
    QDate dobDate = ui->dateEdit_3->date();
    bool admin= ui->AdminCheckBox->isChecked();
    if (!dobDate.isValid()) {
        // Handle incase date of birth is not valid
        qDebug() << "Date of birth is not valid";
    }

    // Convert QDate object back to a formatted QString the database will be able to take
    QString formattedDateOfBirth = dobDate.toString("yyyy-MM-dd");

    // Check if any of the fields are empty
    if (firstName.isEmpty() || Lastname.isEmpty() || userName.isEmpty() || pswd.isEmpty() || phnNum.isEmpty() || mail.isEmpty()) {
        // Show error message using QMessageBox
        QMessageBox::critical(this, ("Error"), ("All fields must be filled."));
        return; // Exit the function early
    }
    */
       /////////



};




////////////////////////Button
void MainWindow::on_addperson_adminview_clicked()
{
    //this will go to the add person page
    ui->stackedWidget->setCurrentIndex(10);
}


void MainWindow::on_Deleteperson_clicked()
{
    //delete Person
    // Get the selected room ID
    QModelIndexList selectedRows = ui->personview->selectionModel()->selectedRows();
    if (selectedRows.isEmpty()) {
//person selected
        QMessageBox::warning(this, "Delete Person", "Please select a person to delete.");
        return;
    }

    int userID = selectedRows.at(0).data().toInt();

    // Ask the user if they are sure they want to delete the room
    int ret = QMessageBox::question(this, "Delete Person", "Are you sure you want to delete this person?", QMessageBox::Yes | QMessageBox::No);
    if (ret == QMessageBox::Yes) {
        // Delete the room from the database
        QString result = Adminuser.Delete_User(userID);

        // Check if the deletion was successful
        if (result == "Person Deleted Successfully!") {
            // Room deleted successfully
            QMessageBox::information(this, "Delete Person", "Person deleted successfully.");
            //clears the view person view
            ui->personview->clearSpans();

            // Refresh the table view
            ui->personview->setModel(db.getUsers());

        } else {
            // Error deleting room
            QMessageBox::critical(this, "Delete Person", result);
        }
    }
}




