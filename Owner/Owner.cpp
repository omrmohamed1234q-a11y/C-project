# include "Owner.h"
#include "../core/Workspace.hpp"
Owner::Owner():Users(){};
Owner::Owner(string e, string p, string r) : Users(e, p, r) {
}
Owner::Owner(string n, string e, string p, string r) : Users(n, e, p, r) {
}
string Owner::addRoom(Workspace& workspace, Room room) {
    workspace.addRoom(new Room(room));
    return "Room added successfully.";
}

string Owner::editRoom(Workspace& workspace, int roomId, double newPrice, string newDetails) {
    Room* room = workspace.searchRooms(roomId);
    if (room == NULL) {
        return "Room not found.";
    }

    room->setPrice(newPrice);
    room->setDetails(newDetails);
    workspace.saveRooms();
    return "Room edited successfully.";
}

string Owner::deleteRoom(Workspace& workspace, int roomId) {
    workspace.removeRoom(roomId);
    return "Room deleted successfully (if it existed).";
}

void Owner::viewStats(const Workspace& workspace) const {
    cout << "Owner is viewing stats." << endl;
    workspace.displayWorkspace();
    workspace.getRooms();
}

