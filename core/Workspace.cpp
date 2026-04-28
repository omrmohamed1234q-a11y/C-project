#include "Workspace.hpp"

Workspace::Workspace() {
    name = "";
}

Workspace::Workspace(string n) {
    name = n;
}

void Workspace::setName(string n) {
    name = n;
}

string Workspace::getName() const {
    return name;
}

void Workspace::addRoom(shared_ptr<Room> room) {
    rooms.push_back(room);
}

bool Workspace::removeRoom(int id) {
    for (int i = 0; i < static_cast<int>(rooms.size()); i++) {
        if (rooms[i]->getId() == id) {
            rooms.erase(rooms.begin() + i);
            return true;
        }
    }
    return false;
}

shared_ptr<Room> Workspace::searchRooms(int id) const {
    for (int i = 0; i < static_cast<int>(rooms.size()); i++) {
        if (rooms[i]->getId() == id) {
            return rooms[i];
        }
    }
    return nullptr;
}

vector<shared_ptr<Room> > Workspace::getRooms() const {
    return rooms;
}

void Workspace::addService(string service) {
    services.push_back(service);
}

void Workspace::addFeedback(string note) {
    feedback.push_back(note);
}

void Workspace::displayWorkspace() const {
    cout << "Workspace: " << name << endl;
    cout << "Rooms count: " << rooms.size() << endl;
    cout << "Services count: " << services.size() << endl;
    cout << "Feedback count: " << feedback.size() << endl;
}
