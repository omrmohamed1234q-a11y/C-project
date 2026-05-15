#include "CustomerWidget.hpp"
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QMessageBox>
#include <QHeaderView>

CustomerWidget::CustomerWidget(Workspace *ws, QWidget *parent) 
    : QWidget(parent), workspace(ws), currentCustomer(nullptr) {
    
    QVBoxLayout *mainLayout = new QVBoxLayout(this);

    welcomeLabel = new QLabel("Customer Dashboard", this);
    mainLayout->addWidget(welcomeLabel);

    roomTable = new QTableWidget(this);
    roomTable->setColumnCount(8);
    roomTable->setHorizontalHeaderLabels({"ID", "Workspace", "Type", "Capacity", "Occupied", "Price", "Details", "Available"});
    roomTable->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    roomTable->setSelectionBehavior(QAbstractItemView::SelectRows);
    roomTable->setEditTriggers(QAbstractItemView::NoEditTriggers);
    mainLayout->addWidget(roomTable);

    QHBoxLayout *btnLayout = new QHBoxLayout();
    bookButton = new QPushButton("Book Selected Room", this);
    cancelButton = new QPushButton("Cancel Selected Room", this);
    viewBookingsButton = new QPushButton("View My Bookings", this);
    logoutButton = new QPushButton("Logout", this);

    btnLayout->addWidget(bookButton);
    btnLayout->addWidget(cancelButton);
    btnLayout->addWidget(viewBookingsButton);
    btnLayout->addWidget(logoutButton);

    mainLayout->addLayout(btnLayout);

    connect(bookButton, &QPushButton::clicked, this, &CustomerWidget::onBookRoom);
    connect(cancelButton, &QPushButton::clicked, this, &CustomerWidget::onCancelBooking);
    connect(viewBookingsButton, &QPushButton::clicked, this, &CustomerWidget::onViewMyBookings);
    connect(logoutButton, &QPushButton::clicked, this, &CustomerWidget::onLogout);
}

void CustomerWidget::setupCustomer(const QString& username) {
    customerUsername = username;
    welcomeLabel->setText("Welcome, Customer " + username);
    
    if (currentCustomer) {
        delete currentCustomer;
    }
    currentCustomer = new Custumer(username.toStdString(), username.toStdString(), "", "Customer");
    currentCustomer->loadBookings("C:/Users/HP/CLionProjects/C-project-1/data/bookings.txt", username.toStdString());
    
    refreshTable();
}

void CustomerWidget::refreshTable() {
    roomTable->setRowCount(0);
    const vector<Room*>& rooms = workspace->getRoomsList();
    for (size_t i = 0; i < rooms.size(); ++i) {
        Room* r = rooms[i];
        roomTable->insertRow(i);
        roomTable->setItem(i, 0, new QTableWidgetItem(QString::number(r->getId())));
        roomTable->setItem(i, 1, new QTableWidgetItem(QString::fromStdString(r->getWorkspaceName())));
        roomTable->setItem(i, 2, new QTableWidgetItem(QString::fromStdString(r->getType())));
        roomTable->setItem(i, 3, new QTableWidgetItem(QString::number(r->getCapacity())));
        roomTable->setItem(i, 4, new QTableWidgetItem(QString::number(r->getOccupied())));
        roomTable->setItem(i, 5, new QTableWidgetItem(QString::number(r->getPrice())));
        roomTable->setItem(i, 6, new QTableWidgetItem(QString::fromStdString(r->getDetails())));
        roomTable->setItem(i, 7, new QTableWidgetItem(r->isAvailable() ? "Yes" : "No"));
    }
}

void CustomerWidget::onBookRoom() {
    int row = roomTable->currentRow();
    if (row < 0) {
        QMessageBox::warning(this, "Error", "Please select a room to book.");
        return;
    }
    int roomId = roomTable->item(row, 0)->text().toInt();
    string result = currentCustomer->bookRoom(*workspace, roomId);
    currentCustomer->saveBookings("C:/Users/HP/CLionProjects/C-project-1/data/bookings.txt", customerUsername.toStdString());
    QMessageBox::information(this, "Booking", QString::fromStdString(result));
    refreshTable();
}

void CustomerWidget::onCancelBooking() {
    int row = roomTable->currentRow();
    if (row < 0) {
        QMessageBox::warning(this, "Error", "Please select a room to cancel.");
        return;
    }
    int roomId = roomTable->item(row, 0)->text().toInt();
    string result = currentCustomer->cancelBooking(*workspace, roomId);
    currentCustomer->saveBookings("C:/Users/HP/CLionProjects/C-project-1/data/bookings.txt", customerUsername.toStdString());
    QMessageBox::information(this, "Cancel Booking", QString::fromStdString(result));
    refreshTable();
}

void CustomerWidget::onViewMyBookings() {
    vector<int> b = currentCustomer->getBookings();
    QString msg = "You have booked the following Room IDs:\n";
    if (b.empty()) {
        msg = "You have no bookings.";
    } else {
        for (int id : b) {
            msg += QString::number(id) + "\n";
        }
    }
    QMessageBox::information(this, "My Bookings", msg);
}

void CustomerWidget::onLogout() {
    if (currentCustomer) {
        delete currentCustomer;
        currentCustomer = nullptr;
    }
    emit logoutRequested();
}
