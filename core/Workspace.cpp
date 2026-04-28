#include "Workspace.hpp"

Workspace::Workspace() {
    name = "";
    roomCount = 0;
    serviceCount = 0;
    feedbackCount = 0;
}

Workspace::Workspace(string n) {
    name = n;
    roomCount = 0;
    serviceCount = 0;
    feedbackCount = 0;
}

void Workspace::setName(string n) {
    name = n;
}

string Workspace::getName() const {
    return name;
}

void Workspace::addRoom(Room room) {
    if (roomCount < 100) {
        rooms[roomCount] = room;
        roomCount++;
        cout << "room added successfully \n";
    } else {
        cout << "no space for more rooms \n";
    }
}

void Workspace::removeRoom(int id) {
    for (int i = 0; i < roomCount; i++) {
        if (rooms[i].getId() == id) {
            for (int j = i; j < roomCount - 1; j++) {
                rooms[j] = rooms[j + 1];
            }
            roomCount--;
            cout << "room removed successfully \n";
            return;
        }
    }
    cout << "room not found \n";
}

Room* Workspace::searchRooms(int id) {
    for (int i = 0; i < roomCount; i++) {
        if (rooms[i].getId() == id) {
            return &rooms[i];
        }
    }
    return NULL;
}

void Workspace::getRooms() const {
    if (roomCount == 0) {
        cout << "no rooms found \n";
        return;
    }

    for (int i = 0; i < roomCount; i++) {
        rooms[i].displayInfo();
    }
}

void Workspace::addService(string service) {
    if (serviceCount < 100) {
        services[serviceCount] = service;
        serviceCount++;
    }
}

void Workspace::addFeedback(string feedback) {
    if (feedbackCount < 100) {
        feedbacks[feedbackCount] = feedback;
        feedbackCount++;
    }
}

void Workspace::displayWorkspace() const {
    cout << "Workspace Name: " << name << endl;
    cout << "Rooms: " << roomCount << endl;
    cout << "Services: " << serviceCount << endl;
    cout << "Feedbacks: " << feedbackCount << endl;
}
