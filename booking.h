#ifndef BOOKING_H
#define BOOKING_H
#include "database.h"


class Booking
{
private:
    int BookingID;
    int GuestID;
    int RoomID;
    int AmenityID;
    QString check_in_date;
    QString check_out_date;
    double Total_Price;
    bool IsPaid;
    QString Booking_date;
public:
    Booking();

    //setters
    void setBookingID(int id);
    void setGuestID(int id);
    void setRoomID(int id);
    void setAmenityID(int id);
    void setCheckInDate(QString checkinDate);
    void setCheckOutDate(QString checkoutdate);
    void setTotalPrice(double price);
    void setIsPaid(bool paid);
    void setBooking_Date(QString BookingDate);

    //getters
    int getBookingID();
    int getGuestID();
    int getRoomID();
    int getAmenitiyID();
    QString getCheckInDate();
    QString getCheckOutDate();
    double getTotalPrice();
    bool getIsPaid();
    QString getBookingDate();

};

#endif // BOOKING_H
