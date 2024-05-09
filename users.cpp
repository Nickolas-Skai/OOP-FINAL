#include "users.h"

users::users() {}


users::users(int id, QString fname, QString lname, QString username, QString pswd, QString Dob, QString phn_num, QString mail, bool admin) {
    //don't know if to use sets to or datamembers
    //we don't have any validation but we could use the setters
    setUserID(id);
    setFirstname(fname);
    setLastname(lname);
    setUsername(username);
    setPassword(pswd);
    setDOB(Dob);
    setPhonenumber(phn_num);
    setEmail(mail);
    setadmin(admin);
}

//setter functions
void users::setUserID(int id) {
    UserId = id;
}

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
int users::getUserID() {
    return UserId;
}

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

bool users::getAdmin() {
    return isAdmin;
}
