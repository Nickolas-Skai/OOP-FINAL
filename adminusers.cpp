#include "adminusers.h"

Adminusers::Adminusers() {

}


Adminusers::Adminusers(int id, QString fname, QString lname, QString username, QString pswd, QString Dob, QString phn_num, QString mail, bool admin)
    :users( id, fname, lname, username, pswd, Dob, phn_num, mail, admin)
{

}


//function will be called in the mainwindow and inside the function we call teh database funciton
//to place in the information/data into the database
QString Adminusers::Add_User(QString fname, QString lname, QString username, QString passwd, QString date_ofBrith, QString Phon_num, QString mail, bool admin) {
    if(!getAdmin()) {
        return "Error: only admins can add user.";
    }

    //call the adduser from the database class
    try
    {
        if(db.addUser(fname, lname, username, passwd, date_ofBrith, Phon_num, mail, admin)){
            throw ("User Edited Successfully!");
        }
        else{
            throw ("An error occured while saving to the database!");
        }
    }
    catch(const char * message)
    {
        return message;
    }
}


QString Adminusers::Edit_User(QString fname, QString lname, QString username, QString paswd, QString date_ofbirth, QString phon, QString email, bool admin) {

}

QString Adminusers::Add_Room(int roomnumber, QString Roomtype, int capacity, double pricepernight, bool availability) {

}

QString Adminusers::Edit_Room(int roomnumber, QString roomtype, int capacity, double pricepernight, bool availability) {

}

QString Adminusers::Add_Amenitie(QString name, QString description, double price) {

}

QString Adminusers::Edit_Amenities(QString name, QString description, double price) {

}
