#ifndef AMENITIES_H
#define AMENITIES_H
#include <adminusers.h>

class Amenities
{
private:
    int AmenityID;
    QString Name;
    QString Description;
    double Price;
public:
    Amenities();

    //setters
    void setAmenitiID(int id);
    void setAmenitiyName(QString name);
    void setDescription(QString description);
    void setPrice(double price);

    //getters
    int getAmenityID();
    QString getAmenityName();
    QString getDescription();
    double getPrice();
};

#endif // AMENITIES_H
