#include "amenities.h"

Amenities::Amenities() {}


//setters
void Amenities::setAmenitiID(int id) {
    AmenityID = id;
}

void Amenities::setAmenitiyName(QString name) {
    Name = name;
}

void Amenities::setDescription(QString description) {
    Description = description;
}

void Amenities::setPrice(double price) {
    Price = price;
}

//getters
int Amenities::getAmenityID() {
    return AmenityID;
}

QString Amenities::getAmenityName() {
    return Name;
}

QString Amenities::getDescription() {
    return Description;
}

double Amenities::getPrice() {
    return Price;
}
