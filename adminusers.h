#ifndef ADMINUSERS_H
#define ADMINUSERS_H
#include <iostream>
#include <users.h>


class Adminusers : public users //derived class of users class
{
public:
    Adminusers();
    Adminusers(int id, QString fname, QString lname, QString username, QString pswd, QString Dob, QString phn_num, QString mail, bool admin);

    //admin being able to add user
    QString Add_User(QString fname, QString lname, QString username, QString passwd, QString date_ofBrith, QString Phon_num, QString mail, bool admin);

    //being able to edit a user
    QString Edit_User(QString fname, QString lname, QString username, QString paswd, QString date_ofbirth, QString phon, QString email, bool admin);

    //being able to delete a user
    //this might change and the delete will happen in the table view using
    //the simple delete table view method
    QString Delete_User(int Userid);


    //being able to add a room
    QString Add_Room(int roomnumber, QString Roomtype, int capacity, double pricepernight, bool availability);

    //being able to edit a room
    QString Edit_Room(int roomnumber, QString roomtype, int capacity, double pricepernight, bool availability);

    //bieng able to delete a room
    //this might change and the delete will happen in the table view using
    //the simple delete table view method
    QString delete_Room(int roomID);

    //being able to add a amenitie
    QString Add_Amenitie(QString name, QString description, double price);

    //being able to edit an amenitie
    QString Edit_Amenities(QString name, QString description, double price);

    //being able to delete/remove an amenitie
    //this might change and the delete will happen in the table view using
    //the simple delete table view method
    QString Delete_Amenitie();
};

#endif // ADMINUSERS_H
