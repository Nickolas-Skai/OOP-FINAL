#include "booking.h"

Booking::Booking() {}

//setters
void Booking::setAmenityID(int id) {
    AmenityID = id;
}

void Booking::setGuestID(int id) {
    GuestID = id;
}

void Booking::setRoomID(int id) {
    RoomID = id;
}

void Booking::setCheckInDate(QString checkinDate) {
    check_in_date = checkinDate;
}

void Booking::setCheckOutDate(QString checkoutdate) {
    check_out_date = checkoutdate;
}

void Booking::setTotalPrice(double price) {
    Total_Price = price;
}

void Booking::setIsPaid(bool paid) {
    IsPaid = paid;
}

void Booking::setBooking_Date(QString BookingDate) {
    Booking_date = BookingDate;
}

//getters

int Booking::getBookingID() {
    return BookingID;
}

int Booking::getGuestID() {
    return GuestID;
}

int Booking::getRoomID() {
    return RoomID;
}

int Booking::getAmenitiyID() {
    return AmenityID;
}

QString Booking::getCheckInDate() {
    return check_in_date;
}

QString Booking::getCheckOutDate() {
    return check_out_date;
}

double Booking::getTotalPrice() {
    return Total_Price;
}

bool Booking::getIsPaid() {
    return IsPaid;
}

QString Booking::getBookingDate() {
    return Booking_date;
}
