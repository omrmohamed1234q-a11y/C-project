# include "costumer.h"
#include "../core/Workspace.hpp"
Custumer::Custumer():Users(){
    bookingCount = 0;
};
Custumer::Custumer(string e, string p, string r) : Users(e, p, r) {
    bookingCount = 0;
}
Custumer::Custumer(string n, string e, string p, string r) : Users(n, e, p, r) {
    bookingCount = 0;
}
void Custumer::bookRoom(Workspace& workspace, int roomId) {
    Room* room = workspace.searchRooms(roomId);
    if (room == NULL) {
        cout << "Room not found." << endl;
        return;
    }

    if (room->book()) {
        if (bookingCount < 100) {
            bookings[bookingCount] = roomId;
            bookingCount++;
        }
    }
}

void Custumer::cancelBooking(Workspace& workspace, int roomId) {
    Room* room = workspace.searchRooms(roomId);
    if (room == NULL) {
        cout << "Room not found." << endl;
        return;
    }

    for (int i = 0; i < bookingCount; i++) {
        if (bookings[i] == roomId) {
            if (room->cancelBooking()) {
                for (int j = i; j < bookingCount - 1; j++) {
                    bookings[j] = bookings[j + 1];
                }
                bookingCount--;
            }
            return;
        }
    }
    cout << "This customer has no booking for room " << roomId << "." << endl;
}
void Custumer::viewBookings() const {
    if (bookingCount == 0) {
        cout << "No bookings found." << endl;
        return;
    }

    cout << "Booked room IDs: ";
    for (int i = 0; i < bookingCount; i++) {
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
