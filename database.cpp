#include "database.h"
#include <string>
#include <QDate>
using namespace std;
//database constructor which makes the database connection
database::database()
{
    //connect to the database
    db = QSqlDatabase::addDatabase("QMYSQL");
    db.setHostName("localhost");
    db.setPort(3306);
    db.setDatabaseName("ResortBooking");
    db.setUserName("root");
    db.setPassword("w8080#$#$ons@");

    try
    {
        if(db.open())
        {
            qDebug() << "Successfully connected to database!";

        }
        else
        // Lets the program know that it didnt connect to the server
        {
            QString error = db.lastError().text();
            throw error.toStdString().c_str();
        }


    }
    catch(const char * message)  //catches the exception as a char pointer
    {
        QMessageBox messagebox;
        messagebox.about(NULL,"Connection to database failed!",message);
        qFatal("Connection to database failed!");
    }
}



//database destructor
database::~database() {
    /*db.close();
    QSqlDatabase::removeDatabase(QSqlDatabase::defaultConnection); //so this removes the database
    return;*/
}


///Function to verify a user that is logging into the program////
QStringList database::VerifyUser(QString userName, QString Passrd) {
    QStringList UserData;

    QSqlQuery query;
    query.prepare("SELECT * FROM User WHERE username = ? AND password = ?");
    query.bindValue(0, userName);
    query.bindValue(1, Passrd);

    if (!query.exec()) {
        qDebug() << "Error executing query:" << query.lastError().text();
        //return false; // Database query failed
    }

    if (query.next()) {
        //int count = query.value(0).toInt();
        //return count == 1; // Return true if there's exactly one matching user
        UserData << query.value("UserID").toString();
        UserData << query.value("FirstName").toString();
        UserData << query.value("LastName").toString();
        UserData << query.value("UserName").toString();
        UserData << query.value("Password").toString();
        UserData << query.value("DateOfBirth").toString();
        UserData << query.value("PhoneNum").toString();
        UserData << query.value("Email").toString();
        //UserData << query.value("IsAdmin").toBool();
        UserData << (query.value("IsAdmin").toBool() ? "true" : "false");
    }

    return UserData;//returns the users data
}



///Function that adds a user to the database////
bool database::addUser(QString firstname, QString lastname, QString username, QString Password, QString phonenum, QString Email, QString dob, bool isadmin) {
    // execute the sql query to insert the new user into the database
    QSqlQuery query;
    query.prepare("INSERT INTO User (FirstName, LastName, UserName, Password, DateOfBirth, PhoneNum, Email, IsAdmin) "
                  "VALUES (:fname, :lname, :usrname, :pw, :dateofbirth, :phone, :mail, :admin)");
    query.bindValue(":fname", firstname);
    query.bindValue(":lname", lastname);
    query.bindValue(":usrname", username);
    query.bindValue(":pw", Password);
    query.bindValue(":phone", phonenum);
    query.bindValue(":mail", Email);
    query.bindValue(":dateofbirth", dob);
    query.bindValue(":admin", isadmin);

    if (!query.exec()) {
        qDebug() << "Error adding user:" << query.lastError().text();
        return false; // the database insertion failed
    }

    // the User added successfully
    return true;
}


///this function will update the user informatin after it was changed by the admin in the ui////
bool database::editUser(QString firstname, QString lastname, QString username, QString password, QString phonenum, QString email, QString dob, bool isadmin) {
    QSqlQuery query;
    query.prepare("UPDATE User SET FirstName = :firstName, LastName = :lastName, UserName = :username, Password = :password, "
                  "DateOfBirth = :dateOfBirth, PhoneNum = :Phonenum, Email = :email, IsAdmin = :admin WHERE UserID = :userId");

    query.bindValue(":firstName", firstname);
    query.bindValue(":lastName", lastname);
    query.bindValue(":username", username);
    query.bindValue(":password", password);
    query.bindValue(":dateOfBirth", dob);
    query.bindValue(":Phonenum", phonenum);
    query.bindValue(":email", email);
    query.bindValue(":admin", isadmin);
    //query.bindValue(":userId", UserId); ///WE DO NEED THE ID TO EDIT BUT IDK HOW WE GONE GET THAT.

    if (!query.exec()) {
        qDebug() << "Error executing query:" << query.lastError().text();
        return false;
    }

    return true;
}

bool database::deleteUser(int userid) {
    QSqlQuery query;
    query.prepare("DELETE FROM User WHERE UserID = :id");
    query.bindValue(":id", userid);

    if (!query.exec()) {
        qDebug() << "Error deleting room:" << query.lastError().text();
        return false; // the database deletion failed
    }

    // the Room deleted successfully
    return true;
}


//this function will add the room into the database
bool database::addRoom(int roomnumber, QString Roomtype, int capacity, double pricepernight, bool availability) {
    QSqlQuery query;
    query.prepare("INSERT INTO Room (RoomNumber, RoomType, Capacity, Price_Per_Night, Is_Available) "
                   "VALUES (:roomnumber, :Roomtype, :capacity, :pricepernight, :avilable)");
    query.bindValue(":roomnumber", roomnumber);
    query.bindValue("Roomtype",Roomtype);
    query.bindValue(":capacity", capacity);
    query.bindValue("pricepernight",pricepernight);
    query.bindValue(":available", availability);

    if (!query.exec()) {
        qDebug() << "Error adding user:" << query.lastError().text();
        return false; // the database insertion failed
    }

    // the Room added successfully
    return true;
}


//this function will update the room information after it is changed in the ui
bool database::editRoom(int roomnumber, QString roomtype, int capacity, double pricepernight, bool availability) {

    if (!db.isValid()) {
        qDebug() << "Database connection is invalid.";
        return false;
    }

    if (!db.isOpen()) {
        qDebug() << "Database connection is not open.";
        return false;
    }

    QSqlQuery query;
    query.prepare("UPDATE Room SET RoomNumber = :roomNumber, RoomType = :roomType, Capacity = :capacity, "
                  "Price_Per_Night = :pricePerNight, Is_Available = :isAvailable WHERE room_id = :roomId");

    query.bindValue(":roomNumber", roomnumber);
    query.bindValue(":roomType", roomtype);
    query.bindValue(":capacity", capacity);
    query.bindValue(":pricePerNight", pricepernight);
    query.bindValue(":isAvailable", availability);
    //query.bindValue(":roomId", roomId); ////I DON'T KNOW ABOUT THESE SINCE WHEN THEY GET INSERTED INTO THE DATABASE THERE ID'S ARE AUTO INCREMENTED

    if (!query.exec()) {
        qDebug() << "Error executing query:" << query.lastError().text();
        return false;
    }

    return true;
}


//delete a room from the database
bool database::deleteRoom(int RoomId) {
    QSqlQuery query;
    query.prepare("DELETE FROM Room WHERE RoomID = :id");
    query.bindValue(":id", RoomId);

    if (!query.exec()) {
        qDebug() << "Error deleting room:" << query.lastError().text();
        return false; // the database deletion failed
    }

    // the Room deleted successfully
    return true;
}

//This function will add an amenity to database when the admin adds an amenity
bool database::addAmenity(QString name, QString description, double price) {
    QSqlQuery query;
    query.prepare("INSERT INTO Amenity (Amenity_Name, Description, Price) "
                  "VALUES (:amenity_name, :description, :price)");
    query.bindValue(":amenity_name", name);
    query.bindValue("description",description);
    query.bindValue(":price", price);

    if (!query.exec()) {
        qDebug() << "Error adding user:" << query.lastError().text();
        return false; // the database insertion failed
    }

    // the Amenity added successfully
    return true;
}

//this function will edit/update the amenity into the database when the user updates the amenity in the ui
bool database::editAmenitity(QString name, QString description, double price) {

    if (!db.isValid()) {
        qDebug() << "Database connection is invalid.";
        return false;
    }

    if (!db.isOpen()) {
        qDebug() << "Database connection is not open.";
        return false;
    }

    QSqlQuery query;
    query.prepare("UPDATE Amenity SET Amenity_Name = :Name, Description = :desc, Price = :price WHERE amenity_id = :amenityId");

    //query.bindValue(":amenityId", amenity_id); //NEED TO FIGURE THIS OUT AS WELL
    query.bindValue(":Name", name);
    query.bindValue(":desc", description);
    query.bindValue(":price", price);

    if(!query.exec()) {
        qDebug() << "Error executing query:" << query.lastError().text();
        return false;
    }

    return true;
}


//////////////////////////////////////////////// CODE TO GET DATA FROM DATABASE FOR TABLE VIEWS///////////////////////
//gets all the rooms in the database
QSqlQueryModel *database::getRooms() {
    QSqlQueryModel *model = new QSqlQueryModel();
    model->setQuery("SELECT * FROM Room");
    return model;
}


//query for from the database to get all the people that are in the database
QSqlQueryModel *database::getUsers() {
    QSqlQueryModel *model = new QSqlQueryModel();
    model->setQuery("SELECT * FROM User");
    return model;
}
//get a specific user from the database
/*QSqlQueryModel *database::getUser(int userID) {
    QSqlQueryModel *model = new QSqlQueryModel();
    model->setQuery("SELECT * FROM User WHERE UserID = " + QString::number(userID));
    //pointer to fistname
   string*firstname= *model->setQuery("SELECT FirstName FROM User WHERE UserID = " + QString::number(userID));
    return model;
}*/
//get all rooms in the database number ,descritpion  and price
QSqlQueryModel *database::getRoomdetails() {
    QSqlQueryModel *model = new QSqlQueryModel();
    model->setQuery("SELECT Room_Number, Room_Type, Price_Per_Night FROM Room");
    return model;

}
    //queries for the database to a specific user in the database first name , last name, user name, phone number, email, date of birth, and if they are an admin
/*QSqlQueryModel *database::getuserfirstname( int userID) {
        QSqlQueryModel *model = new QSqlQueryModel();
        model->setQuery("SELECT FirstName FROM User WHERE UserID = " + QString::number(userID));
        return model;
}*/

/////////////////////////////////////ALL THE GETS /////////////////////////////////
int database::getuserID(int UserID) {
    QSqlQuery query;
    query.prepare("SELECT UserID FROM User WHERE UserID = :userID");
    query.bindValue(":userID", UserID);

    if (!query.exec()) {
        qDebug() << "Error executing query:" << query.lastError().text();
        return -1; // Return an invalid ID if the query fails
    }

    if (query.next()) {
        return query.value("UserID").toInt();
    } else {
        qDebug() << "User not found for ID:" << UserID;
        return -1; // Return an invalid ID if no user is found for the given ID
    }
}
QString database::getuserfisrtname(int userID) {
    QSqlQuery query;
    query.prepare("SELECT FirstName FROM User WHERE UserID = :userID");
    query.bindValue(":userID", userID);

    if (!query.exec()) {
        qDebug() << "Error executing query:" << query.lastError().text();
        return ""; // Return an empty string if the query fails
    }

    if (query.next()) {
        QString firstName = query.value("FirstName").toString();
        return firstName;
    } else {
        qDebug() << "User not found for ID:" << userID;
        return ""; // Return an empty string if no user is found for the given ID
    }
}

QString database::getuserlastname(int userID) {
    QSqlQuery query;
    query.prepare("SELECT LastName FROM User WHERE UserID = :userID");
    query.bindValue(":userID", userID);

    if (!query.exec()) {
        qDebug() << "Error executing query:" << query.lastError().text();
        return ""; // Return an empty string if the query fails
    }

    if (query.next()) {
        QString lastname = query.value("LastName").toString();
        return lastname;
    } else {
        qDebug() << "User not found for ID:" << userID;
        return ""; // Return an empty string if no user is found for the given ID
    }
}


QString database::getuserUserName(int userID) {
    QSqlQuery query;
    query.prepare("SELECT UserName FROM User WHERE UserID = :userID");
    query.bindValue(":userID", userID);

    if (!query.exec()) {
        qDebug() << "Error executing query:" << query.lastError().text();
        return ""; // Return an empty string if the query fails
    }

    if (query.next()) {
        QString username = query.value("UserName").toString();
        return username;
    } else {
        qDebug() << "User not found for ID:" << userID;
        return ""; // Return an empty string if no user is found for the given ID
    }
}


QString database::getuserpassword(int userID) {
    QSqlQuery query;
    query.prepare("SELECT Password FROM User WHERE UserID = :userID");
    query.bindValue(":userID", userID);

    if (!query.exec()) {
        qDebug() << "Error executing query:" << query.lastError().text();
        return ""; // Return an empty string if the query fails
    }

    if (query.next()) {
        QString password = query.value("Password").toString();
        return password;
    } else {
        qDebug() << "User not found for ID:" << userID;
        return ""; // Return an empty string if no user is found for the given ID
    }
}


QDate database::getuserDateofBirth(int userID){
    QSqlQuery query;
    query.prepare("SELECT DateOfBirth FROM User WHERE UserID = :userID");
    query.bindValue(":userID", userID);

    if (!query.exec()) {
        qDebug() << "Error executing query:" << query.lastError().text();
        return QDate(); // Return a default QDate object if the query fails
    }

    if (query.next()) {
        QString dateOfBirthString = query.value("DateOfBirth").toString();
        // Log the retrieved string for debugging
        qDebug() << "Retrieved date of birth string:" << dateOfBirthString;

        // Convert the date string to a QDate object
        QDate dateOfBirth = QDate::fromString(dateOfBirthString, "yyyy-MM-dd");

        // Check if the conversion is successful
        if (!dateOfBirth.isValid()) {
            qDebug() << "Invalid date format retrieved from the database:" << dateOfBirthString;
        } else {
            qDebug() << "Valid date of birth retrieved:" << dateOfBirth.toString("yyyy-MM-dd");
        }

        return dateOfBirth;
    } else {
        qDebug() << "User not found for ID:" << userID;
        return QDate(); // Return a default QDate object if no user is found for the given ID
    }
}

QString database::getuserPhoneNum(int userID) {
    QSqlQuery query;
    query.prepare("SELECT PhoneNum FROM User WHERE UserID = :userID");
    query.bindValue(":userID", userID);

    if (!query.exec()) {
        qDebug() << "Error executing query:" << query.lastError().text();
        return ""; // Return an empty string if the query fails
    }

    if (query.next()) {
        QString phonenumber = query.value("PhoneNum").toString();
        return phonenumber;
    } else {
        qDebug() << "User not found for ID:" << userID;
        return ""; // Return an empty string if no user is found for the given ID
    }
}

QString database::getuserEmail(int userID) {
    QSqlQuery query;
    query.prepare("SELECT Email FROM User WHERE UserID = :userID");
    query.bindValue(":userID", userID);

    if (!query.exec()) {
        qDebug() << "Error executing query:" << query.lastError().text();
        return ""; // Return an empty string if the query fails
    }

    if (query.next()) {
        QString mail = query.value("Email").toString();
        return mail;
    } else {
        qDebug() << "User not found for ID:" << userID;
        return ""; // Return an empty string if no user is found for the given ID
    }
}

bool database::getuseradmin(int userID) {
    QSqlQuery query;
    query.prepare("SELECT IsAdmin FROM User WHERE UserID = :userID");
    query.bindValue(":userID", userID);

    if (!query.exec()) {
        qDebug() << "Error executing query:" << query.lastError().text();
        return ""; // Return an empty string if the query fails
    }

    if (query.next()) {
        bool admin = query.value("IsAdmin").toBool();
        return admin;
    } else {
        qDebug() << "User not found for ID:" << userID;
        return ""; // Return an empty string if no user is found for the given ID
    }
}


/////////////////////////GET FOR ROOMS///////////////////////
int database::getroomNumber(int roomID) {
    QSqlQuery query;
    query.prepare("SELECT RoomNumber FROM Room WHERE RoomID = :roomID");
    query.bindValue(":roomID", roomID);

    if (!query.exec()) {
        qDebug() << "Error executing query:" << query.lastError().text();

        return 0; // Return an empty string if the query fails
    }

    if (query.next()) {
        bool ok;
        int roomnumber = query.value("RoomNumber").toInt(&ok);
        if (!ok) {
            qDebug() << "Error converting RoomNumber to int";
            return 0;
        }
        return roomnumber;
    } else {
        qDebug() << "room not found for ID:" << roomID;
        return 0; // Return an empty string if no user is found for the given ID
    }
    return 0;
}

QString database::getRoomType(int roomID) {
    QSqlQuery query;
    query.prepare("SELECT RoomType FROM Room WHERE RoomID = :roomID");
    query.bindValue(":roomID", roomID);

    if (!query.exec()) {
        qDebug() << "Error executing query:" << query.lastError().text();
        return ""; // Return an empty string if the query fails
    }

    if (query.next()) {
        QString Roomtype = query.value("RoomType").toString();
        return Roomtype;
    } else {
        qDebug() << "room not found for ID:" << roomID;
        return ""; // Return an empty string if no user is found for the given ID
    }
    return "";
}

int database::getroomCapacity(int roomID) {
    QSqlQuery query;
    query.prepare("SELECT Capacity FROM Room WHERE RoomID = :roomID");
    query.bindValue(":roomID", roomID);

    if (!query.exec()) {
        qDebug() << "Error executing query:" << query.lastError().text();
        return 0; // Return an empty string if the query fails
    }

    if (query.next()) {
        bool ok ;

        int  capacity = query.value("Capacity").toInt(&ok);
        if (ok)
        {
            return capacity;}
    } else {
        qDebug() << "room not found for ID:" << roomID;
        return 0; // Return an empty string if no user is found for the given ID
    }
    return 0;
}


double database::getroomprice(int roomID) {
    QSqlQuery query;
    query.prepare("SELECT Price_Per_Night FROM Room WHERE RoomID = :roomID");
    query.bindValue(":roomID", roomID);

    if (!query.exec()) {
        qDebug() << "Error executing query:" << query.lastError().text();
        return 0.0; // Return 0.0 if the query fails
    }

    if (query.next()) {
        bool ok;
        double price = query.value("Price_Per_Night").toDouble(&ok);
        if (ok) {
            return price;
        } else {
            qDebug() << "Conversion error: Price_Per_Night is not a valid double";
            return 0.0; // Return 0.0 if conversion fails
        }
    } else {
        qDebug() << "Room not found for ID:" << roomID;
        return 0.0; // Return 0.0 if no room is found for the given ID
    }

 // return statement
    return 0.0;
}



/////////////////////////////////////GETS FOR AMENITIES/////////////////////
QString database::getAmenityname(int AmenityID) {
    QSqlQuery query;
    query.prepare("SELECT Amenity_Name FROM Amenity WHERE AmenityID = :AmenityID");
    query.bindValue(":AemnityID", AmenityID);

    if (!query.exec()) {
        qDebug() << "Error executing query:" << query.lastError().text();
        return ""; // Return an empty string if the query fails
    }

    if (query.next()) {
        QString amenityName = query.value("Amenity_Name").toString();
        return amenityName;
    } else {
        qDebug() << "Amenity not found for ID:" << AmenityID;
        return ""; // Return an empty string if no user is found for the given ID
    }
    return "";
}

QString database::getAmnityDescription(int amenityID) {
    QSqlQuery query;
    query.prepare("SELECT Description FROM Amenity WHERE AmenityID = :amenityID");
    query.bindValue(":amenityID", amenityID);

    if (!query.exec()) {
        qDebug() << "Error executing query:" << query.lastError().text();
        return ""; // Return an empty string if the query fails
    }

    if (query.next()) {
        QString description = query.value("Description").toString();
        return description;
    } else {
        qDebug() << "Amenity not found for ID:" << amenityID;
        return ""; // Return an empty string if no user is found for the given ID
    }
    return "";
}


double database::getAmenityPrice(int amenityID) {
    QSqlQuery query;
    query.prepare("SELECT Price FROM Amenity WHERE AmenityID = :amenityID");
    query.bindValue(":amenityID", amenityID);

    if (!query.exec()) {
        qDebug() << "Error executing query:" << query.lastError().text();
        return 0.0; // Return an empty string if the query fails
    }

    if (query.next()) {
        bool ok;
        double price = query.value("Price").toDouble(&ok);
        if (!ok) {
            qDebug() << "Error converting Price to double";
            return 0.0;
        }
        return price;
    } else {
        qDebug() << "amenity not found for ID:" << amenityID;
        return 0.0; // Return an empty string if no user is found for the given ID
    }
    return 0.0;
}


/////////////////////////GET FOR RESERVATION///////////////////////

int database::getBookings( int userID) {
    QSqlQuery query;

    query.prepare("SELECT BookingID FROM Reservation WHERE UserID = :userID");
    query.bindValue(":userID", userID);

    if (!query.exec()) {
        qDebug() << "Error executing query:" << query.lastError().text();
        return 0; // Return 0 if the query fails
    }

    if (query.next()) {
        bool ok;
        int bookingID = query.value("BookingID").toInt(&ok);
        if (!ok) {
            qDebug() << "Error converting BookingID to int";
            return 0;
        }
        return bookingID;
    } else {
        qDebug() << "Booking not found for ID:" << userID;
        return 0; // Return 0 if no booking is found for the given ID
    }

}


