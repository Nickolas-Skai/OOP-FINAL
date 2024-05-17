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


    ////////////////////////////////USER DATABASE FUNCTIONS//////////////////////////
    //verifying the user
    QStringList VerifyUser(QString Username, QString password);
    //adding a user
    bool addUser(QString firstname, QString lastname, QString username, QString Password, QString phonenum, QString Email, QString dob, bool isadmin);
    //edit/update user information
    bool editUser(QString firatname, QString lastname, QString, QString password, QString phoneum, QString email, QString dob, bool isadmin);
    //delete a user
    bool deleteUser(int userId);
    //////////////////////////////////ROOM BOOKING DATABASE FUNCTIONS//////////////////

    //add a room to the database
    bool addRoom(int roomnumber, QString Roomtype, int capacity, double pricepernight, bool availability);

    //update room information in database
    bool editRoom(int roomnumber, QString roomtype, int capacity, double pricepernight, bool availability);

    //delete a room from the database
    bool deleteRoom(int RoomId);
    //////////////////////////////////////////////////////////////////////////////


    ////////////////////////AMENITY DATABASE FUNCTIONS/////////////////////////////////

    //add an amenities to the database
    bool addAmenity(QString name, QString description, double price);

    //update amenity information into the database
    bool editAmenitity(QString name, QString description, double price);
    ///////////////////////////////////////////////////////////////////////////


    /////////////////////////////BOOKING DATABASE FUNCTIONS///////////////////////

    /*To insert into the booking table*/
    bool InsertBooking(int guestId, int roomId, int amenityId, const QDate& checkInDate, const QDate& checkOutDate, double totalPrice, bool isPaid, const QDateTime& bookingDate);

    /*UPDATE THE BOOKING TABLE*/
    bool EditBooking(int bookingId, int guestId, int roomId, int amenityId, const QDate& checkInDate, const QDate& checkOutDate, double totalPrice, bool isPaid, const QDateTime& bookingDate);
    ///////////////////////////////////////////////////////////////////////

    ///////////////////////////////TO POPULATE THE TABLEVIEWS*/
    //gets all the rooms from the database
    QSqlQueryModel *getRooms();

    //get all the users from the database
    QSqlQueryModel *getUsers();


};
#endif // DATABASE_H
