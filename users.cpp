#include "users.h"

users::users() {}


users::users(QString fname, QString lname, QString username, QString pswd, QString Dob, QString phn_num, QString mail, bool admin) {
    //don't know if to use sets to or datamembers

}

//setter functions
void users::setFirstname(QString firstname) {
    Firstname = firstname;
}

void users::setLastname(QString lastname) {
    Lastname = lastname;
}

void users::setUsername(QString username) {
    Username = username;
}

void users::setPassword(QString password) {
    Password = password;
}

void users::setDOB(QString date_of_brith) {
    DateofBirth = date_of_brith;
}

void users::setPhonenumber(QString phone_number) {
    PhoneNum = phone_number;
}

void users::setEmail(QString email) {
    Email = email;
}

void users::setadmin(bool admin) {
    isAdmin = admin;
}


//getter functions

QString users::getFirstname() {
    return Firstname;
}

QString users::getLastname() {
    return Lastname;
}

QString users::getUsername() {
    return Username;
}

QString users::getPassword() {
    return Password;
}

QString users::getDateOfBrith() {
    return DateofBirth;
}

QString users::getPhoneNumber() {
    return PhoneNum;
}

QString users::getEmail() {
    return Email;
}

QString users::getAdmin() {
    return isAdmin;
}
