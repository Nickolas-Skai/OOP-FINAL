#ifndef ADMINUSERS_H
#define ADMINUSERS_H
#include <iostream>
#include "database.h"
#include <users.h>


class Adminusers : public users //derived class of users class
{
public:
    Adminusers();

    //admin being able to add user
    QString Add_User(QString fname, QString lname, QString username, QString passwd, QString date_ofBrith, QString Phon_num, QString mail, bool admin);

    //being able to edit a user
    QString Edit_User(QString fname, QString lname, QString username, QString paswd, QString date_ofbirth, QString phon, QString email, bool admin);

    //being able to delete a user
    QString Delete_User();

    //being able to add a room
    QString Add_Room(int roomnumber, QString Roomtype, int capacity, double pricepernight, bool availability);

    //being able to edit a room
    QString Edit_Room(int roomnumber, QString roomtype, int capacity, double pricepernight, bool availability);

    //bieng able to delete a room
    QString delete_Room(int roomnumber);

    //being able to add a amenitie
    QString Add_Amenitie(QString name, QString description, double price);

    //being able to edit an amenitie
    QString Edit_Amenities(QString name, QString description, double price);

    //being able to delete/remove an amenitie
    QString Delete_Amenitie();
};

#endif // ADMINUSERS_H
