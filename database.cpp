#include "database.h"

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
                  "DateOfBrith = :dateOfBirth, PhoneNum = :Phonenum, Email = :email, IsAdmin = :admin WHERE UserID = :userId");

    query.bindValue(":firstName", firstname);
    query.bindValue(":lastName", lastname);
    query.bindValue(":username", username);
    query.bindValue(":password", password);
    query.bindValue(":dateOfBirth", dob);
    query.bindValue(":Phonenum", phonenum);
    query.bindValue(":email", email);
    query.bindValue(":admin", isadmin);
    //query.bindValue(":userId", userId); ///WE DO NEED THE ID TO EDIT BUT IDK HOW WE GONE GET THAT.

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
    query.prepare("INSERT INTO Room (Room_Number, Room_Type, Capacity, Price_Per_Night, Is_Available) "
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
QSqlQueryModel *database::getUser(int userID) {
    QSqlQueryModel *model = new QSqlQueryModel();
    model->setQuery("SELECT * FROM User WHERE UserID = " + QString::number(userID));
    return model;
}
//get all rooms in the database number ,descritpion  and price
QSqlQueryModel *database::getRoomdetails() {
    QSqlQueryModel *model = new QSqlQueryModel();
    model->setQuery("SELECT Room_Number, Room_Type, Price_Per_Night FROM Room");
    return model;

}
    //queries for the database to a specific user in the database first name , last name, user name, phone number, email, date of birth, and if they are an admin
QSqlQueryModel *database::getuserfisrtname(int userID) {
        QSqlQueryModel *model = new QSqlQueryModel();
        model->setQuery("SELECT FirstName FROM User WHERE UserID = " + QString::number(userID));
        return model;
    }
