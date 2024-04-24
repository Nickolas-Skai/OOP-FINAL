#include "database.h"

database::database()
{
    QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL");
    db.setHostName("localhost");
    db.setUserName("root");
    db.setPassword("w8080#$#$ons@");
    db.setDatabaseName("ResortBooking");
    db.open();

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


database::~database() {
    db.close();
    QSqlDatabase::removeDatabase(QSqlDatabase::defaultConnection); //so this removes the database
    return;
}


bool database::VerifyUser(QString userName, QString Passrd) {
    QSqlQuery query;
    query.prepare("SELECT COUNT(*) FROM User WHERE username = ? AND password = ?");
    query.bindValue(0, userName);
    query.bindValue(1, Passrd);

    if (!query.exec()) {
        qDebug() << "Error executing query:" << query.lastError().text();
        return false; // Database query failed
    }

    if (query.next()) {
        int count = query.value(0).toInt();
        return count == 1; // Return true if there's exactly one matching user
    }

    return false; // No rows returned
}


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
