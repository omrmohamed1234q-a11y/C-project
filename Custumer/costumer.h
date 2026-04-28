#ifndef COSTUMER_H
#define COSTUMER_H
# include <iostream>
# include <string>
#include "../users/users.h"
#include "../core/Workspace.hpp"

using namespace std;
class Custumer : public Users {
private:
    int bookings[100];
    int bookingCount;
public:
    Custumer();
    Custumer(string e, string p, string r);
    Custumer(string n, string e, string p, string r);

    void bookRoom(Workspace& workspace, int roomId);
    void cancelBooking(Workspace& workspace, int roomId);
    void viewBookings() const;
    void updateProfile(string n, string e, string p, string r);
};
#endif
