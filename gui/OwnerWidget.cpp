#include "OwnerWidget.hpp"
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QMessageBox>
#include <QInputDialog>
#include <QHeaderView>

OwnerWidget::OwnerWidget(Workspace *ws, QWidget *parent) 
    : QWidget(parent), workspace(ws), currentOwner(nullptr) {
    
    QVBoxLayout *mainLayout = new QVBoxLayout(this);

    welcomeLabel = new QLabel("Owner Dashboard", this);
    mainLayout->addWidget(welcomeLabel);

    roomTable = new QTableWidget(this);
    roomTable->setColumnCount(8);
    roomTable->setHorizontalHeaderLabels({"ID", "Workspace", "Type", "Capacity", "Occupied", "Price", "Details", "Available"});
    roomTable->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    roomTable->setSelectionBehavior(QAbstractItemView::SelectRows);
    roomTable->setEditTriggers(QAbstractItemView::NoEditTriggers);
    mainLayout->addWidget(roomTable);

    QHBoxLayout *btnLayout = new QHBoxLayout();
    addButton = new QPushButton("Add Room", this);
    editButton = new QPushButton("Edit Selected Room", this);
    deleteButton = new QPushButton("Delete Selected Room", this);
    logoutButton = new QPushButton("Logout", this);

    btnLayout->addWidget(addButton);
    btnLayout->addWidget(editButton);
    btnLayout->addWidget(deleteButton);
    btnLayout->addWidget(logoutButton);

    mainLayout->addLayout(btnLayout);

    connect(addButton, &QPushButton::clicked, this, &OwnerWidget::onAddRoom);
    connect(editButton, &QPushButton::clicked, this, &OwnerWidget::onEditRoom);
    connect(deleteButton, &QPushButton::clicked, this, &OwnerWidget::onDeleteRoom);
    connect(logoutButton, &QPushButton::clicked, this, &OwnerWidget::onLogout);
}

void OwnerWidget::setupOwner(const QString& username) {
    welcomeLabel->setText("Welcome, Owner " + username);
    if (currentOwner) {
        delete currentOwner;
    }
    currentOwner = new Owner(username.toStdString(), username.toStdString(), "", "Owner");
    refreshTable();
}

void OwnerWidget::refreshTable() {
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

void OwnerWidget::onAddRoom() {
    bool ok;
    int id = QInputDialog::getInt(this, "Add Room", "Enter Room ID:", 0, 0, 10000, 1, &ok);
    if (!ok) return;

    QString name = QInputDialog::getText(this, "Add Room", "Enter Workspace Name:", QLineEdit::Normal, "", &ok);
    if (!ok) return;

    QString type = QInputDialog::getText(this, "Add Room", "Enter Room Type:", QLineEdit::Normal, "", &ok);
    if (!ok) return;

    double price = QInputDialog::getDouble(this, "Add Room", "Enter Price:", 0, 0, 10000, 2, &ok);
    if (!ok) return;

    QString details = QInputDialog::getText(this, "Add Room", "Enter Details:", QLineEdit::Normal, "", &ok);
    if (!ok) return;

    int capacity = QInputDialog::getInt(this, "Add Room", "Enter Capacity:", 1, 1, 1000, 1, &ok);
    if (!ok) return;

    Room newRoom(id, name.toStdString(), type.toStdString(), true, price, details.toStdString(), capacity, 0);
    string res = currentOwner->addRoom(*workspace, newRoom);
    QMessageBox::information(this, "Add Room", QString::fromStdString(res));
    refreshTable();
}

void OwnerWidget::onEditRoom() {
    int row = roomTable->currentRow();
    if (row < 0) {
        QMessageBox::warning(this, "Error", "Please select a room to edit.");
        return;
    }
    int roomId = roomTable->item(row, 0)->text().toInt();

    bool ok;
    double newPrice = QInputDialog::getDouble(this, "Edit Room", "Enter New Price:", 0, 0, 10000, 2, &ok);
    if (!ok) return;

    QString newDetails = QInputDialog::getText(this, "Edit Room", "Enter New Details:", QLineEdit::Normal, "", &ok);
    if (!ok) return;

    string res = currentOwner->editRoom(*workspace, roomId, newPrice, newDetails.toStdString());
    QMessageBox::information(this, "Edit Room", QString::fromStdString(res));
    refreshTable();
}

void OwnerWidget::onDeleteRoom() {
    int row = roomTable->currentRow();
    if (row < 0) {
        QMessageBox::warning(this, "Error", "Please select a room to delete.");
        return;
    }
    int roomId = roomTable->item(row, 0)->text().toInt();
    
    QMessageBox::StandardButton reply = QMessageBox::question(this, "Delete Room", "Are you sure you want to delete this room?", QMessageBox::Yes|QMessageBox::No);
    if (reply == QMessageBox::Yes) {
        string res = currentOwner->deleteRoom(*workspace, roomId);
        QMessageBox::information(this, "Delete Room", QString::fromStdString(res));
        refreshTable();
    }
}

void OwnerWidget::onLogout() {
    if (currentOwner) {
        delete currentOwner;
        currentOwner = nullptr;
    }
    emit logoutRequested();
}
