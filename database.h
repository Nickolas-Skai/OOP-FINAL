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

     //get a specific user from the database
    QSqlQueryModel *getUser(int userId);

    //room details
    QSqlQueryModel *getRoomdetails();

    //getuser details
    //QSqlQueryModel *getuserfisrtname(int userID);

    /////////////////////////////////GETS FOR USER SO THEY CAN BE DISPLAYED ON THE FIELDS WHEN BEING EDITED////////////////////////////////
    int getuserID(int UserID);
    QString getuserfisrtname(int userID);

    QString getuserlastname(int userID);
    QString getuserUserName(int userID);
    QString getuserpassword(int userID);
    QDate getuserDateofBirth(int userID);
    QString getuserPhoneNum(int userID);
    QString getuserEmail(int userID);
    //get the bool
    bool getuseradmin(int userID);

    ///////////////////////////////GETS FOR ROOMS SO THEY CAN BE DISPLAYED ON THE FIELDS WHEN BEING EDITED///////////////////////////////
    int getroomNumber(int roomID);
    QString getRoomType(int roomID);
    int getroomCapacity(int roomID);
    double getroomprice(int rooomID);

    //QString getavailabitlity(int roomID);


    //////////////////////////////////////////GETS FOR AMENITIES SO THEY CAN BE DISPLAYED ON THE FIELDS WHEN BEING EDITED////////////////////
    QString getAmenityname(int AmenityID);
    QString getAmnityDescription(int amenityID);
    double getAmenityPrice(int amenityID);
//get room booking

   int getBookings(int userID);


};
#endif // DATABASE_H
