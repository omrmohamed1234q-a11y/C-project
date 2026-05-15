#include "costumer.h"
#include "../core/Workspace.hpp"
#include <fstream>
#include <sstream>

Custumer::Custumer():Users(){
};
Custumer::Custumer(string e, string p, string r) : Users(e, p, r) {
}
Custumer::Custumer(string n, string e, string p, string r) : Users(n, e, p, r) {
}

string Custumer::bookRoom(Workspace& workspace, int roomId) {
    Room* room = workspace.searchRooms(roomId);
    if (room == NULL) {
        return "Room not found.";
    }

    if (room->book()) {
        bookings.push_back(roomId);
        workspace.saveRooms();
        return "Room booked successfully.";
    }
    return "Room is fully booked or unavailable.";
}

string Custumer::cancelBooking(Workspace& workspace, int roomId) {
    Room* room = workspace.searchRooms(roomId);
    if (room == NULL) {
        return "Room not found.";
    }

    for (auto it = bookings.begin(); it != bookings.end(); ++it) {
        if (*it == roomId) {
            if (room->cancelBooking()) {
                bookings.erase(it);
                workspace.saveRooms();
                return "Booking canceled successfully.";
            }
            return "Failed to cancel room booking.";
        }
    }
    return "This customer has no booking for room " + to_string(roomId) + ".";
}

void Custumer::viewBookings() const {
    if (bookings.empty()) {
        cout << "No bookings found." << endl;
        return;
    }

    cout << "Booked room IDs: ";
    for (int id : bookings) {
        cout << id << " ";
    }
    cout << endl;
}

void Custumer::updateProfile(string n, string e, string p, string r) {
    setName(n);
    setEmail(e);
    setPassword(p);
    setRole(r);
}

void Custumer::loadBookings(const string& filePath, const string& userEmail) {
    ifstream data(filePath);
    if (!data) return;
    string read;
    while(getline(data, read)) {
        if (read.empty()) continue;
        stringstream ss(read);
        string email, id_s;
        getline(ss, email, ',');
        getline(ss, id_s, ',');
        if (email == userEmail) {
            bookings.push_back(stoi(id_s));
        }
    }
    data.close();
}

void Custumer::saveBookings(const string& filePath, const string& userEmail) const {
    // Read existing
    vector<string> lines;
    ifstream in(filePath);
    if (in) {
        string read;
        while(getline(in, read)) {
            if (read.empty()) continue;
            stringstream ss(read);
            string email;
            getline(ss, email, ',');
            if (email != userEmail) {
                lines.push_back(read);
            }
        }
        in.close();
    }
    
    // Write back non-user's bookings + user's new bookings
    ofstream out(filePath);
    for (const string& l : lines) {
        out << l << "\n";
    }
    for (int id : bookings) {
        out << userEmail << "," << id << "\n";
    }
    out.close();
}
