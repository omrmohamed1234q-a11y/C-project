#ifndef OWNER_H
#define OWNER_H
#include <iostream>
#include <string>
#include "../users/users.h"
#include "../core/Workspace.hpp"
using namespace std;
class Owner : public Users {
public:
    Owner();
    Owner(string e, string p, string r);
    Owner(string n, string e, string p, string r);

    string addRoom(Workspace& workspace, Room room);
    string editRoom(Workspace& workspace, int roomId, double newPrice, string newDetails);
    string deleteRoom(Workspace& workspace, int roomId);
    void viewStats(const Workspace& workspace)const;
};
#endif
