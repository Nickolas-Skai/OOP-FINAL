#include "roomdisplay.h"

    RoomDisplay::RoomDisplay(QWidget *parent) : QWidget(parent) {
    QVBoxLayout *layout = new QVBoxLayout(this);

    roomTypeLabel = new QLabel(this);
    roomDescriptionLabel = new QLabel(this);
    priceLabel = new QLabel(this);

    layout->addWidget(roomTypeLabel);
    layout->addWidget(roomDescriptionLabel);
    layout->addWidget(priceLabel);

    setLayout(layout);
}

void RoomDisplay::setRoomDetails(const QString &roomType, const QString &roomDescription, const QString &price) {
    roomTypeLabel->setText("Room Type: " + roomType);
    roomDescriptionLabel->setText("Description: " + roomDescription);
    priceLabel->setText("Price: " + price);
}
