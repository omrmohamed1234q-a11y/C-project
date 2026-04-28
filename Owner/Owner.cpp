# include "Owner.h"
#include "../core/Workspace.hpp"
Owner::Owner():Users(){};
Owner::Owner(string e, string p, string r) : Users(e, p, r) {
}
Owner::Owner(string n, string e, string p, string r) : Users(n, e, p, r) {
}
void Owner::addRoom(Workspace& workspace, Room room) {
    workspace.addRoom(room);
    cout << "Owner added room " << room.getId() << "." << endl;
}

void Owner::editRoom(Workspace& workspace, int roomId, double newPrice, string newDetails) {
    Room* room = workspace.searchRooms(roomId);
    if (room == nullptr) {
        cout << "Room not found." << endl;
        return;
    }

    room->setPrice(newPrice);
    room->setDetails(newDetails);
    cout << "Owner edited room " << roomId << "." << endl;
}

void Owner::deleteRoom(Workspace& workspace, int roomId) {
    workspace.removeRoom(roomId);
    cout << "Owner deleted room " << roomId << "." << endl;
}

void Owner::viewStats(const Workspace& workspace) const {
    cout << "Owner is viewing stats." << endl;
    cout << "Workspace name: " << workspace.getName() << endl;
    workspace.getRooms();
}
