#include "Room.hpp"


Room::Room() {
    id = 0;
    capacity = 0;
    occupied = 0;
    workspaceName = "";
    type = "";
    Available = true;
    details = "";
    price = 0.0;
}

Room::Room(int tag, string name, string t, bool situation, double p, string detail, int cap, int occ) {
    id = tag;
    workspaceName = name;
    type = t;
    Available = situation;
    price = p;
    details = detail;
    capacity = cap;
    occupied = occ;
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

void Room::setCapacity(int cap) {
    capacity = cap;
}

int Room::getId() const {
    return id;
}

int Room::getCapacity() const {
    return capacity;
}

void Room::setOccupied(int occ) {
    occupied = occ;
}

int Room::getOccupied() const {
    return occupied;
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
    if (capacity > 0) {
        if (occupied < capacity) {
            occupied++;
            if (occupied == capacity) {
                Available = false;
            }
            cout << "room " << id << " booked successfully \n";
            return true;
        } else {
            cout << "room " << id << " is full (capacity reached) \n";
            return false;
        }
    } else {
        if (Available) {
            Available = false;
            cout << "room " << id << " booked successfully \n";
            return true;
        } else {
            cout << "room " << id << " is already booked \n";
            return false;
        }
    }
}

bool Room::cancelBooking() {
    if (capacity > 0) {
        if (occupied > 0) {
            occupied--;
            Available = true;
            cout << "room " << id << " booking canceled \n";
            return true;
        } else {
            cout << "room " << id << " has no bookings to cancel \n";
            return false;
        }
    } else {
        if (!Available) {
            Available = true;
            cout << "room " << id << " is canceled \n";
            return true;
        } else {
            cout << "room " << id << " is not booked \n";
            return false;
        }
    }
}

double Room::calculatePrice(double hour) const {
    return price * hour;
}

void Room::displayInfo() const {
    cout << "Room ID: " << id << ", Name: " << workspaceName << ", Type: " << type << ", Capacity: " << capacity << ", Occupied: " << occupied << ", Price per hour: " << price << ", Details: " << details << ", Available: " << (Available ? "Yes" : "No") << endl;
}
