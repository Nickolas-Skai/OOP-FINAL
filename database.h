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
    QStringList VerifyUser(QString Username, QString password);
    //adding a user
    bool addUser(QString firstname, QString lastname, QString username, QString Password, QString phonenum, QString Email, QString dob, bool isadmin);
    //edit/update user information
    bool editUser(QString firatname, QString lastname, QString, QString password, QString phoneum, QString email, QString dob, bool isadmin);


    //add a room to the database
    bool addRoom(int roomnumber, QString Roomtype, int capacity, double pricepernight, bool availability);

    //update room information in database
    bool editRoom(int roomnumber, QString roomtype, int capacity, double pricepernight, bool availability);

    //add an amenities to the database
    bool addAmenity(QString name, QString description, double price);

    //update amenity information into the database
    bool editAmenitity(QString name, QString description, double price);





};
#endif // DATABASE_H
