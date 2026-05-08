#include "Workspace.hpp"
#include <fstream>
#include <sstream>

Workspace::Workspace() {
    name = "";
    filePath = "";
}

Workspace::Workspace(string n, string path) {
    name = n;
    filePath = path;
}

Workspace::~Workspace() {
    for (Room* room : rooms) {
        delete room;
    }
    rooms.clear();
}

void Workspace::setName(string n) {
    name = n;
}

string Workspace::getName() const {
    return name;
}

void Workspace::addRoom(Room* room) {
    rooms.push_back(room);
    saveRooms();
    cout << "room added successfully \n";
}

void Workspace::removeRoom(int id) {
    for (auto it = rooms.begin(); it != rooms.end(); ++it) {
        if ((*it)->getId() == id) {
            delete *it;
            rooms.erase(it);
            saveRooms();
            cout << "room removed successfully \n";
            return;
        }
    }
    cout << "room not found \n";
}

Room* Workspace::searchRooms(int id) {
    for (Room* room : rooms) {
        if (room->getId() == id) {
            return room;
        }
    }
    return NULL;
}

void Workspace::getRooms() const {
    if (rooms.empty()) {
        cout << "no rooms found \n";
        return;
    }
    for (Room* room : rooms) {
        room->displayInfo();
    }
}

void Workspace::addService(string service) {
    services.push_back(service);
}

void Workspace::addFeedback(string feedback) {
    feedbacks.push_back(feedback);
}

void Workspace::displayWorkspace() const {
    cout << "Workspace Name: " << name << endl;
    cout << "Rooms: " << rooms.size() << endl;
    cout << "Services: " << services.size() << endl;
    cout << "Feedbacks: " << feedbacks.size() << endl;
}

void Workspace::loadRooms() {
    if (filePath.empty()) return;
    ifstream data(filePath);
    if (!data) return;
    string read;
    while(getline(data, read)) {
        if (read.empty()) continue;
        stringstream ss(read);
        string id_s, workspaceName, type, avail_s, price_s, details, cap_s, occ_s;
        getline(ss, id_s, ',');
        getline(ss, workspaceName, ',');
        getline(ss, type, ',');
        getline(ss, avail_s, ',');
        getline(ss, price_s, ',');
        getline(ss, details, ',');
        getline(ss, cap_s, ',');
        getline(ss, occ_s, ',');
        if(id_s.empty()) continue;
        
        int id = stoi(id_s);
        bool avail = (avail_s == "1");
        double price = stod(price_s);
        int cap = cap_s.empty() ? 0 : stoi(cap_s);
        int occ = occ_s.empty() ? 0 : stoi(occ_s);
        
        Room* room = new Room(id, workspaceName, type, avail, price, details, cap, occ);
        rooms.push_back(room);
    }
    data.close();
}

void Workspace::saveRooms() const {
    if (filePath.empty()) return;
    ofstream data(filePath);
    if (!data) return;
    for (Room* room : rooms) {
        data << room->getId() << "," << room->getWorkspaceName() << "," << room->getType() << "," 
             << (room->isAvailable() ? "1" : "0") << "," << room->getPrice() << "," 
             << room->getDetails() << "," << room->getCapacity() << "," << room->getOccupied() << "\n";
    }
    data.close();
}
