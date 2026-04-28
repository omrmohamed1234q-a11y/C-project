#include "Room.hpp"


Room::Room() {
    id = 0;
    workspaceName = "";
    type = "";
    Available = true;
    details = "";
    price = 0.0;
}

Room::Room(int tag, string name, string t, bool situation, double p, string detail) {
    id = tag;
    workspaceName = name;
    type = t;
    Available = situation;
    price = p;
    details = detail;
}

void Room::setAvailable(bool av) {
    Available = av;
}

bool Room::isAvailable() const {
    return Available;
}

void Room::setId(int tag) {
    id = tag;
}

void Room::setPrice(double p) {
    price = p;
}

void Room::setDetails(string detail) {
    details = detail;
}

void Room::setWorkspaceName(string name) {
    workspaceName = name;
}

void Room::setType(string t) {
    type = t;
}

int Room::getId() const {
    return id;
}

double Room::getPrice() const {
    return price;
}

string Room::getWorkspaceName() const {
    return workspaceName;
}

string Room::getType() const {
    return type;
}

string Room::getDetails() const {
    return details;
}

bool Room::book() {
    if (Available) {
        Available = false;
        cout << "room " << id << " booked successfully \n";
        return true;
    } else {
        cout << "room " << id << " is already booked \n";
        return false;
    }
}

bool Room::cancelBooking() {
    if (!Available) {
        Available = true;
        cout << "room " << id << " is canceled \n";
        return true;
    } else {
        cout << "room " << id << " is not booked \n";
        return false;
    }
}

double Room::calculatePrice(double hour) const {
    return price * hour;
}

void Room::displayInfo() const {
    cout << "Room ID: " << id << ", Name: " << workspaceName << ", Type: " << type << ", Price per hour: " << price << ", Details: " << details << ", Available: " << (Available ? "Yes" : "No") << endl;
}
