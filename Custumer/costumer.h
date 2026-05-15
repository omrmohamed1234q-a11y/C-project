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
    vector<int> getBookings() const { return bookings; }
    Custumer();
    Custumer(string e, string p, string r);
    Custumer(string n, string e, string p, string r);

    string bookRoom(Workspace& workspace, int roomId);
    string cancelBooking(Workspace& workspace, int roomId);
    void viewBookings() const;
    void updateProfile(string n, string e, string p, string r);
    void loadBookings(const string& filePath, const string& userEmail);
    void saveBookings(const string& filePath, const string& userEmail) const;
};
#endif
