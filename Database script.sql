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

CREATE TABLE IF NOT EXISTS `Booking` (
    BookingID INT AUTO_INCREMENT PRIMARY KEY,
    UserID INT NOT NULL,
    RoomID INT NOT NULL,
    CheckInDate DATE NOT NULL,
    CheckOutDate DATE NOT NULL, 
    TotalPrice DECIMAL(10,2) NOT NULL,
    IsPaid BOOL NOT NULL, 
    BookingDate DATE NOT NULL,
    FOREIGN KEY(UserID) REFERENCES User(UserID),
    FOREIGN KEY(RoomID) REFERENCES RoomO(RoomID)
);

-- BookedAmenities table
CREATE TABLE IF NOT EXISTS `BookedAmenities` (
    BookedAmenityID INT AUTO_INCREMENT PRIMARY KEY,
    BookingID INT NOT NULL,
    AmenityID INT NOT NULL,
    FOREIGN KEY(BookingID) REFERENCES Booking(BookingID),
    FOREIGN KEY(AmenityID) REFERENCES Amenities(AmenityID)
);
CREATE TABLE IF NOT EXISTS `Payment` (
PaymentID int auto_increment Primary Key,
BookingID int NOT NULL, 
Amount decimal(10,2) NOT NULL,
PaymentDate date NOT NULL,
PaymentMethod text NOT NULL
);

select * from User;
/*Inseting a user with admin*/
INSERT INTO User(UserID, FirstName, LastName, UserName, Password, DateOfBirth, PhoneNum, Email, IsAdmin)
VALUES(3, 'Seo', 'Requena', 'Seor', '12345', '2005-05-09', '242-3542', 'seo@gmail.com', 1);

/*insert into amenities*/
INSERT INTO Amenity(AmenityID, Amenity_Name, Description, Price)
VALUES(1, 'Netflix', 'Access to Netflix while you stay', 50.00);

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

