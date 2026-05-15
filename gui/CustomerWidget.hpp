#pragma once
#include <QWidget>
#include <QTableWidget>
#include <QPushButton>
#include <QLabel>
#include "../core/Workspace.hpp"
#include "../Custumer/costumer.h"

class CustomerWidget : public QWidget {
    Q_OBJECT

public:
    CustomerWidget(Workspace *ws, QWidget *parent = nullptr);
    void setupCustomer(const QString& username);

signals:
    void logoutRequested();

private slots:
    void refreshTable();
    void onBookRoom();
    void onCancelBooking();
    void onViewMyBookings();
    void onLogout();

private:
    Workspace *workspace;
    Custumer *currentCustomer;
    QString customerUsername;

    QLabel *welcomeLabel;
    QTableWidget *roomTable;
    QPushButton *bookButton;
    QPushButton *cancelButton;
    QPushButton *viewBookingsButton;
    QPushButton *logoutButton;
};
