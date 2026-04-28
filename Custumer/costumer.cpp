# include "costumer.h"
Custumer::Custumer():Users(){};
Custumer::Custumer(string e, string p, string r) : Users(e, p, r) {
}
Custumer::Custumer(string n, string e, string p, string r) : Users(n, e, p, r) {
}
void Custumer::bookRoom(Workspace& workspace, int roomId) {
    Room* room = workspace.searchRooms(roomId);
    if (room == NULL) {
        cout << "Room not found." << endl;
        return;
    }

    if (room->book()) {
        bookings.push_back(roomId);
    }
}

void Custumer::cancelBooking(Workspace& workspace, int roomId) {
    Room* room = workspace.searchRooms(roomId);
    if (room == NULL) {
        cout << "Room not found." << endl;
        return;
    }

    for (int i = 0; i < static_cast<int>(bookings.size()); i++) {
        if (bookings[i] == roomId) {
            if (room->cancelBooking()) {
                bookings.erase(bookings.begin() + i);
            }
            return;
        }
    }
    cout << "This customer has no booking for room " << roomId << "." << endl;
}
void Custumer::viewBookings() const {
    if (bookings.empty()) {
        cout << "No bookings found." << endl;
        return;
    }

    cout << "Booked room IDs: ";
    for (int i = 0; i < static_cast<int>(bookings.size()); i++) {
        cout << bookings[i] << " ";
    }
    cout << endl;
}
void Custumer::updateProfile(string n, string e, string p, string r) {
    setName(n);
    setEmail(e);
    setPassword(p);
    setRole(r);
}
