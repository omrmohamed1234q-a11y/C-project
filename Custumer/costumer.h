#ifndef COSTUMER_H
#define COSTUMER_H
# include <iostream>
# include <string>
#include "../users/users.h"

using namespace std;
class Custumer : public Users {
public:
    Custumer();
    Custumer(string e, string p, string r);

    void bookRoom();
    void cancelBooking();
    void viewBookings() const;
    void updateProfile(string e, string p, string r);
};
#endif
