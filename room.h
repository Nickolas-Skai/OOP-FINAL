#ifndef ROOM_H
#define ROOM_H
#include <iostream>
#include "database.h"

using namespace std;

class Room
{
private:
    int RoomID;
    int Room_Number;
    QString Room_Type;
    int Capacity;
    double Price_Per_Night;
    bool Available;
public:
    Room();

    //setters
    void setRoomID(int roomid);
    void setRoomNumber(int roomNumb);
    void setRoomType(QString roomtype);
    void setCapacity(int capacity);
    void setPricePerNight(double price);
    void setAvailability(bool available);
    //getters
    int getRoomID();
    int getRoomNumber();
    QString getRoomType();
    int getRoomCapacity();
    double getPricePerNight();
    bool getAvailabiility();

};

#endif // ROOM_H
