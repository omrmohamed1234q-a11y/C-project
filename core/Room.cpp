#include "Room.hpp"


Room::Room() { // room default constructor
    id = 0;
    capacity = 0;
    occupied = 0;
    workspaceName = "";
    type = "";
    Available = true;
    details = "";
    price = 0.0;
}

Room::Room(int tag, string name, string t, bool situation, double p, string detail, int cap, int occ) { // room parametarized constructor
    id = tag;
    workspaceName = name;
    type = t;
    Available = situation;
    price = p;
    details = detail;
    capacity = cap;
    occupied = occ;
}

void Room::setAvailable(bool av) {// availabe setter
    Available = av;
}

bool Room::isAvailable() const { //available getter
    return Available;
}

void Room::setId(int tag) { // room id setter
    id = tag;
}

void Room::setPrice(double p) { // price setter
    price = p;
}

void Room::setDetails(string detail) { // room details setter
    details = detail;
}

void Room::setWorkspaceName(string name) { // workspace name setter
    workspaceName = name;
}

void Room::setType(string t) { // room type setter
    type = t;
}

void Room::setCapacity(int cap) { // room capacity setter
    capacity = cap;
}

int Room::getId() const { // room id getter
    return id;
}

int Room::getCapacity() const { // room capacity getter
    return capacity;
}

void Room::setOccupied(int occ) { // occupied seats setter
    occupied = occ;
}

int Room::getOccupied() const { // occupied seats getter
    return occupied;
}

double Room::getPrice() const { //price per seat getter
    return price;
}

string Room::getWorkspaceName() const { // workspace name getter
    return workspaceName;
}

string Room::getType() const {
    return type;
}

string Room::getDetails() const { // details getter
    return details;
}

bool Room::book() { // booking function definition
    if (capacity > 0) {// check if the capacity more than 0 before runnig the rest of code
        if (occupied < capacity) { // check for available seats
            occupied++; // occupied increament
            if (occupied == capacity) { // after booking is the room is fully occupied  set available to false
                Available = false;
            }
            cout << "room " << id << " booked successfully \n";
            return true;
        } else {
            cout << "room " << id << " is full (capacity reached) \n";
            return false;
        }
    } else {
        if (Available) { // if availabe is ture and the capacity is zero or less set available to false
            Available = false;
            cout << "room " << id << " booked successfully \n";
            return true;
        } else {
            cout << "room " << id << " is already booked \n";
            return false;
        }
    }
}

bool Room::cancelBooking() { // canceling booking function definition
    if (capacity > 0) {
        if (occupied > 0) { // if the capacity and occupied more than zero
            occupied--; // occupied decreament
            Available = true; // set availabe as true
            cout << "room " << id << " booking canceled \n";
            return true;
        } else { // if the capacity is greater than zero and there's  no occupied
            cout << "room " << id << " has no bookings to cancel \n";
            return false;
        }
    } else { // handeling capacity error if it is less than or equal to zero
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

double Room::calculatePrice(double hour) const { // calculating the booking price based on the room price per hour and the booked hours
    return price * hour;
}

void Room::displayInfo() const {
    cout << "Room ID: " << id << ", Name: " << workspaceName << ", Type: " << type << ", Capacity: " << capacity << ", Occupied: " << occupied << ", Price per hour: " << price << ", Details: " << details << ", Available: " << (Available ? "Yes" : "No") << endl;
}
