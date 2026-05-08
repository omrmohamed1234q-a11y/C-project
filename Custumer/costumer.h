#ifndef COSTUMER_H
#define COSTUMER_H
# include <iostream>
# include <string>
#include <vector>
#include "../users/users.h"
#include "../core/Workspace.hpp"

using namespace std;
class Custumer : public Users {
    vector<int> bookings;
public:
    Custumer();
    Custumer(string e, string p, string r);
    Custumer(string n, string e, string p, string r);

    void bookRoom(Workspace& workspace, int roomId);
    void cancelBooking(Workspace& workspace, int roomId);
    void viewBookings() const;
    void updateProfile(string n, string e, string p, string r);
    void loadBookings(const string& filePath, const string& userEmail);
    void saveBookings(const string& filePath, const string& userEmail) const;
};
#endif
