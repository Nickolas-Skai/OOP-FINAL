CREATE DATABASE ResortBooking;
USE ResortBooking;

CREATE TABLE IF NOT EXISTS `User` (
    UserID int auto_increment primary key,
    FirstName text NOT NULL,
    LastName text NOT NULL,
    UserName text NOT NULL,
    Password text NOT NULL,
    DateOfBirth date NOT NULL,
    PhoneNum text NOT NULL,
    Email text NOT NULL,
    IsAdmin bool
);

select * from User;
/*Inseting a user with admin*/
INSERT INTO User(UserID, FirstName, LastName, UserName, Password, DateOfBirth, PhoneNum, Email, IsAdmin)
VALUES(3, 'Seo', 'Requena', 'Seor', '12345', '2005-05-09', '242-3542', 'seo@gmail.com', 1);


CREATE TABLE IF NOT EXISTS `Room` (
    RoomID int auto_increment primary key,
    RoomNumber int NOT NULL,
    RoomType text NOT NULL,
    Capacity int NOT NULL,
    Price_Per_Night decimal(10,2) NOT NULL,
    Is_Available bool NOT NULL
);

CREATE TABLE IF NOT EXISTS `Amenity` (
    AmenityID int auto_increment primary key,
    Amenity_Name text NOT NULL,
    Description text NOT NULL,
    Price decimal(10,2) NOT NULL
);
