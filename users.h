#ifndef USERS_H
#define USERS_H
#include <iostream>
#include "database.h"

class users
{
private:
    int UserId;
    QString Firstname;
    QString Lastname;
    QString Username;
    QString Password;
    QString DateofBirth;
    QString PhoneNum;
    QString Email;
    bool isAdmin;
public:
    users();
    users(int id, QString fname, QString lname, QString username, QString pswd, QString Dob, QString phn_num, QString mail, bool admin);

    //setters
    void setUserID(int id);
    void setFirstname(QString firstname);
    void setLastname(QString lastname);
    void setUsername(QString username);
    void setPassword(QString password);
    void setDOB(QString date_of_brith);
    void setPhonenumber(QString phone_number);
    void setEmail(QString email);
    void setadmin(bool admin);

    //getters
    int getUserID();
    QString getFirstname();
    QString getLastname();
    QString getUsername();
    QString getPassword();
    QString getDateOfBrith();
    QString getPhoneNumber();
    QString getEmail();
    bool getAdmin();

};

#endif // USERS_H
