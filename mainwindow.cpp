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
#include <QSqlRecord>

/*ADMIN HOME PAGE IS NUMBER 6*/



//cate a instance of the database
MainWindow::MainWindow(QWidget *pant)
    : QMainWindow(pant)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    //when you run the code it stack widget will be at 0 (welcome page)
    ui->stackedWidget->setCurrentIndex(0);
}

MainWindow::~MainWindow()
{



}



//change the page to the login page and load rooms to be displayed
void MainWindow::on_loginbutton_clicked()
{
    //will go to the login page in the stack
    ui->stackedWidget->setCurrentIndex(2);

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
    ui->stackedWidget->setCurrentIndex(3);
    //this is to hide all the other buttons that the user should not see only admins

    ui->backtodashboard->hide();
    //querye the database for the rooms

    ui->roomView->setModel(db.getRooms());




}
};



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
        ui->stackedWidget->setCurrentIndex(3); // Go to login page
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
    //clear the line edits
    ui->user_input->clear();
    ui->pass_input->clear();


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
    //it will change the label to edit use
    ui->CreateUser->hide();
    //edit user button will be shown
    ui->Edituserconfim->show();
    //hide user id label and line edit
    ui->useridLabel->hide();
    ui->useridLineEdit->hide();


    int userID = selectedRows.at(0).data().toInt();
    // Get the user details
    /*QSqlQuery query;
    query.prepare("SELECT * FROM Users WHERE UserID = :userID");
    query.bindValue(":userID", userID);
    query.exec();
    query.next();*/

    // Fill in the form with the user details

    ui->fristNameLineEdit_2->setText(db.getuserfisrtname(userID));
    ui->lastNameLineEdit_2->setText(db.getuserlastname(userID));
    ui->usernameLineEdit_2->setText(db.getuserUserName(userID));
    ui->passwordLineEdit_2->setText(db.getuserpassword(userID));
    ui->phoneNumberLineEdit_2->setText(db.getuserPhoneNum(userID));
    ui->emailLineEdit_2->setText(db.getuserEmail(userID));
    ui->dateEdit_3->setDate(db.getuserDateofBirth(userID));
    ui->AdminCheckBox->setChecked(db.getuseradmin(userID));





};




////////////////////////Button
void MainWindow::on_addperson_adminview_clicked()
{
    //this will go to the add person page
    ui->stackedWidget->setCurrentIndex(10);
    //hide the userid label and the user id line edit
    ui->useridLabel->hide();
    ui->useridLineEdit->hide();

 //it will clear all the fields
    ui->fristNameLineEdit_2->clear();
    ui->lastNameLineEdit_2->clear();
    ui->usernameLineEdit_2->clear();
    ui->passwordLineEdit_2->clear();
    ui->phoneNumberLineEdit_2->clear();
    ui->emailLineEdit_2->clear();
    ui->dateEdit_3->clear();
    ui->AdminCheckBox->setChecked(false);

    //it will change the label to add user
    ui->Edituserconfim->hide();
    //edit user button will be shown
    ui->CreateUser->show();

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





void MainWindow::on_Edituserconfim_clicked()
{
    int userID = ui->useridLineEdit->text().toInt();
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

    // Check if any of the fields are empty
    /*if (firstName.isEmpty() || Lastname.isEmpty() || userName.isEmpty() || pswd.isEmpty() || phnNum.isEmpty() || mail.isEmpty()) {
        // Show error message using QMessageBox
        QMessageBox::critical(this, ("Error"), ("All fields must be filled."));
        return; // Exit the function early
    }*/

    //call the funciton
    QString useredited = Adminuser.Edit_User(firstName, Lastname, userName, pswd, phnNum, mail, formattedDateOfBirth, admin);
    if (useredited == "User Edited Successfully!") {
        // Room deleted successfully
        QMessageBox::information(this, "User Edited", "User Edited Successfully!");

        // Refresh the table view
        ui->personview->setModel(db.getUsers());
        ui->stackedWidget->setCurrentIndex(9);
    } else {
        // Error deleting room
        QMessageBox::critical(this, "User Edited", useredited);
    }
}






void MainWindow::on_continuetodetails_clicked()
{
    // Check if a room is selected
    /*QModelIndexList selectedRows = ui->Room_view->selectionModel()->selectedRows();
    if (selectedRows.isEmpty()) {
        // No room selected
        QMessageBox::warning(this, "Edit Room", "Please select a room to edit.");
        return;
    }

    // If room is selected then go to the next page
    ui->stackedWidget->setCurrentIndex(5); // should be the if loaded

    // Get the selected room ID
    int roomID = selectedRows.at(0).data().toInt();

    // Query the room details
    QSqlQuery query;
    query.prepare("SELECT * FROM Rooms WHERE RoomID = :roomID");
    query.bindValue(":roomID", roomID);
    if (!query.exec()) {
        QMessageBox::warning(this, "Error", "Failed to execute room query: " + query.lastError().text());
        return;
    }

    if (query.next()) {
        // Fill the form with the room details
        ui->roomnumberhere->setText(query.value("RoomNumber").toString());
        ui->roomtype_2->setText(query.value("RoomType").toString());
        ui->ppernight->setText(query.value("Price").toString());
        ui->descinfo->setText(query.value("Description").toString());
        ui->roomstatus->setText(query.value("Status").toString());
    } else {
        QMessageBox::warning(this, "Error", "No room found with ID: " + QString::number(roomID));
        return;
    }

    // Query the amenities of the room
    QSqlQuery query2;
    query2.prepare("SELECT AmenityName FROM RoomAmenities WHERE RoomID = :roomID");
    query2.bindValue(":roomID", roomID);
    if (!query2.exec()) {
        QMessageBox::warning(this, "Error", "Failed to execute amenities query: " + query2.lastError().text());
        return;
    }

    // Fill the form with the room amenities
    QStringList amenities;
    while (query2.next()) {
        amenities << query2.value("AmenityName").toString();
    }
    ui->amenitiesloeadhere->setText(amenities.join(", "));*/



    // Check if a row is selected in the table view
    QModelIndexList selectedRows = ui->Room_view->selectionModel()->selectedRows();
    if (selectedRows.isEmpty()) {
        // No row selected
        QMessageBox::warning(this, "Room Details", "Please select a room to view details.");
        return;
    }

    // Get the selected room ID
    QModelIndex selectedIndex = selectedRows.at(0);
    int roomIDColumn = 0; // Assuming the room ID is in the first column
    QVariant roomIDData = selectedIndex.sibling(selectedIndex.row(), roomIDColumn).data();
    if (!roomIDData.isValid() || !roomIDData.canConvert<int>()) {
        QMessageBox::warning(this, "Error", "Selected room ID is invalid.");
        return;
    }
    int roomID = roomIDData.toInt();

    // Query the room details
    QSqlQuery query;
    query.prepare("SELECT * FROM Rooms WHERE RoomID = :roomID");
    query.bindValue(":roomID", roomID);
    if (!query.exec()) {
        QMessageBox::warning(this, "Error", "Failed to execute room query: " + query.lastError().text());
        return;
    }

    if (query.next()) {
        // Display the room details in the labels
        ui->roomnumberhere->setText(query.value("RoomNumber").toString());
        ui->roomtype_2->setText(query.value("RoomType").toString());
        ui->ppernight->setText(query.value("Price").toString());
        ui->descinfo->setText(query.value("Description").toString());
        ui->roomstatus->setText(query.value("Status").toString());
    } else {
        QMessageBox::warning(this, "Error", "No room found with ID: " + QString::number(roomID));
        return;
    }

    // Query the amenities of the room
    QSqlQuery query2;
    query2.prepare("SELECT AmenityName FROM RoomAmenities WHERE RoomID = :roomID");
    query2.bindValue(":roomID", roomID);
    if (!query2.exec()) {
        QMessageBox::warning(this, "Error", "Failed to execute amenities query: " + query2.lastError().text());
        return;
    }

    // Display the room amenities in the label
    QStringList amenities;
    while (query2.next()) {
        amenities << query2.value("AmenityName").toString();
    }
    ui->amenitiesloeadhere->setText(amenities.join(", "));
}
void MainWindow::on_actionView_bookings_triggered()
{/*
    //will go to view bookings page
    ui->stackedWidget->setCurrentIndex(11);

    //check if an admin is logged in
    if (admin) {
        // Admin is logged in
        // Load the table view with all bookings
        ui->Bookings_view->setModel(db.getBookings());
    } else {
        // User is logged in
        // Load the table view with bookings for the logged in user
        ui->Bookings_view->setModel(db.getBookings(userID));
    }

*/
}





void MainWindow::on_gotoroommadd_clicked()
{
    //will go to the add room page
    ui->stackedWidget->setCurrentIndex(7);

   //set the inner stack to 0 index
    ui->creatingaroom_SIAS->setCurrentIndex(0);

}


void MainWindow::on_editroom_2_clicked()
{
    //create a qfourm widget to pop out a message so that the user can select editthe room that they selected
    QMessageBox::information(this, "Edit Room", "Please select a room to edit.");
    // Check if a room is selected
    QModelIndexList selectedRows = ui->Room_view->selectionModel()->selectedRows();
    if (selectedRows.isEmpty()) {
        // No room selected
        QMessageBox::warning(this, "Edit Room", "Please select a room to edit.");
        return;
    }


    // If room is selected then it will create a pop up that has a area to edit the feild of the room
    ui->stackedWidget->setCurrentIndex(6);
}


void MainWindow::on_Roommanagment_clicked()
{
    ui->stackedWidget->setCurrentIndex(8);
    //when clicked it will fill up the table view with the users data
    ui->Room_view->setModel(db.getRooms());
}


void MainWindow::on_personmanagment_clicked()
{
ui->stackedWidget->setCurrentIndex(9);
    //when clicked it will fill up the table view with the users data
    ui->personview->setModel(db.getUsers());
}


void MainWindow::on_ViewListings_clicked()
{
//wil take you back to the room view page
    ui->stackedWidget->setCurrentIndex(3);

ui->roomView->setModel(db.getRooms());
}


void MainWindow::on_Createlisting_clicked()
{
    //get the data stored
    int roomnumber = ui->roomNumberLineEdit->text().toInt();
    QString roomtype = ui->roomTypeLineEdit->text();
    int capacity = ui->capinputLineEdit->text().toInt();
    double Price = ui->priceLineEdit->text().toDouble();
    bool availabilty = ui->availability_check->isChecked();

    QString newroom = Adminuser.Add_Room(roomnumber, roomtype, capacity, Price, availabilty);
    // Check if the deletion was successful
    if (newroom == "Room Created Successfully!") {
        // Room deleted successfully
        QMessageBox::information(this, "Create Room", "Room Created successfully.");

        // Refresh the table view
        //ui->Room_view->setModel(db.getRooms());
        //ui->stackedWidget->setCurrentIndex(8);
    } else {
        // Error deleting room
        QMessageBox::critical(this, "Create Room", newroom);
    }
}

