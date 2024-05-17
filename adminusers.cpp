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
    //did by seo idk what im doing tho
    if(!getAdmin()) {
        return "Error: only admins can edit user.";
    }

    try
    {
        if(db.editUser(fname, lname, username, paswd, date_ofbirth, phon, email, admin)){
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

QString Adminusers::Delete_User(int Userid) {
    if(!getAdmin()) {
        return "Error: only admins can edit room.";
    }

    try
    {
        if(db.deleteUser(Userid)){
            throw ("Room Deleted Successfully!");
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

/////////////////////////////////////////////////////////////ADMIN ROOM FUNCTION////////////////////////////////////////////
QString Adminusers::Add_Room(int roomnumber, QString Roomtype, int capacity, double pricepernight, bool availability) {

    if(!getAdmin()) {
        return "Error: only admins can add room.";
    }

    try
    {
        if(db.addRoom(roomnumber, Roomtype, capacity, pricepernight, availability)){
            throw ("Room Added Successfully!");
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

QString Adminusers::Edit_Room(int roomnumber, QString roomtype, int capacity, double pricepernight, bool availability) {

    if(!getAdmin()) {
        return "Error: only admins can edit room.";
    }

    try
    {
        if(db.editRoom(roomnumber, roomtype, capacity, pricepernight, availability)){
            throw ("Room Edited Successfully!");
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

QString Adminusers::delete_Room(int roomID) {
    if(!getAdmin()) {
        return "Error: only admins can edit room.";
    }

    try
    {
        if(db.deleteRoom(roomID)){
            throw ("Room Deleted Successfully!");
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
//////////////////////////////////////////////////////////////////////////////////////////////////////////////

QString Adminusers::Add_Amenitie(QString name, QString description, double price) {

    if(!getAdmin()) {
        return "Error: only admins can add amenitie.";
    }

    try
    {
        if(db.addAmenity(name, description, price)){
            throw ("Amenitie Added Successfully!");
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

QString Adminusers::Edit_Amenities(QString name, QString description, double price) {

    if (!getAdmin()) {
        return "Error: only admins can edit amenities.";
    }
    try
    {

        if(db.editAmenitity(name, description, price)){
            throw ("Amenities Edited Successfully!");
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

