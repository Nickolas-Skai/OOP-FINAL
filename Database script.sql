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



