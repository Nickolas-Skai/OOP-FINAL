#ifndef BOOKING_H
#define BOOKING_H
#include "database.h"
#include <iostream>

using namespace std;

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
};

#endif // BOOKING_H
