#include "room.h"

Room::Room() {}

//setters
void Room::setRoomID(int roomid) {
    RoomID = roomid;
}

void Room::setRoomNumber(int roomNumb) {
    Room_Number = roomNumb;
}

void Room::setRoomType(QString roomtype) {
    Room_Type = roomtype;
}

void Room::setCapacity(int capacity) {
    Capacity = capacity;
}

void Room::setPricePerNight(double price) {
    Price_Per_Night = price;
}

void Room::setAvailability(bool available) {
    Available = available;
}

//getters

int Room::getRoomID() {
    return RoomID;
}

int Room::getRoomNumber() {
    return Room_Number;
}

QString Room::getRoomType() {
    return Room_Type;
}

int Room::getRoomCapacity() {
    return Capacity;
}

double Room::getPricePerNight() {
    return Price_Per_Night;
}

bool Room::getAvailabiility() {
    return Available;
}
