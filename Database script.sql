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

select * from User;
/*Inseting a user with admin*/
INSERT INTO User(UserID, FirstName, LastName, UserName, Password, DateOfBirth, PhoneNum, Email, IsAdmin)
VALUES(3, 'Seo', 'Requena', 'Seor', '12345', '2005-05-09', '242-3542', 'seo@gmail.com', 1);


/*dummy data for the room table*/
INSERT INTO Room(RoomID, RoomNumber, RoomType, Capacity, Price_Per_Night, Is_Available)
VALUES(1, 1, 'Single Bed', 1, 100.00, 1),
	(2, 2, 'Single Bed Room', 1, 100.00, 1),
    (3, 3, 'Double Bed Room', 2, 150.00, 1),
    (4, 4, 'Double Bed Room', 2, 150.00, 1),
    (5, 5, 'Single Bed Room', 1, 100.00, 1),
    (6, 6, 'Double Bed Room', 2, 150.00, 1),
    (7, 7, 'Single Bed Room', 1, 100.00, 1),
    (8, 8, 'Double Bed Room', 2, 150.00, 1),
    (9, 9, 'Private villa', 6, 1000.00, 1),
    (10, 10, 'Suit Room', 4, 550.00, 1);

select * from Room;
    


