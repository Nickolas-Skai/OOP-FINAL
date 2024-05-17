#ifndef ROOMDISPLAY_H
#define ROOMDISPLAY_H

#include <QWidget>
#include <QLabel>
#include <QVBoxLayout>

class RoomDisplay : public QWidget {
    Q_OBJECT

public:
    explicit RoomDisplay(QWidget *parent = nullptr);
    void setRoomDetails(const QString &roomType, const QString &roomDescription, const QString &price);

private:
    QLabel *roomTypeLabel;
    QLabel *roomDescriptionLabel;
    QLabel *priceLabel;
};

#endif // ROOMDISPLAY_H
