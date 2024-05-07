#ifndef ADMINUSERS_H
#define ADMINUSERS_H
#include <iostream>
#include "database.h"


class Adminusers //derived class of users class
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
    QString Add_Room();

    //being able to edit a room
    QString Edit_Room();

    //being able to add a amenitie
    QString Add_Amenitie();

    //being able to edit an amenitie
    int Edit_Amenities();

    //being able to delete/remove an amenitie
    int Delete_Amenitie();
};

#endif // ADMINUSERS_H
