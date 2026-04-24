#ifndef OWNER_H
#define OWNER_H
#include <iostream>
#include <string>
#include "../users/users.h"
using namespace std;
class Owner : public Users {
public:
    Owner();
    Owner(string e, string p, string r);

    void addRoom();
    void editRoom();
    void deleteRoom();
    void viewStats()const;
};
#endif