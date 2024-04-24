#ifndef DATABASE_H
#define DATABASE_H
#include <QtSql/QSqlQueryModel>
#include <QDebug>
#include <QMessageBox>
#include <QSqlError>
#include <QSqlQuery>

class database
{
private:
    QSqlDatabase db;
public:
    database();
    //destrucor
    ~database();


    //verifying the user
    bool VerifyUser(QString Username, QString password);
    //adding a user
    bool addUser(QString firstname, QString lastname, QString username, QString Password, QString phonenum, QString Email, QString dob, bool isadmin);


};
#endif // DATABASE_H
