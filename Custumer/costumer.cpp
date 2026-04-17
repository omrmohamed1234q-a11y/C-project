# include "costumer.h"
Custumer::Custumer():Users(){};
Custumer::Custumer(string e, string p, string r) : Users(e, p, r) {
}
void Custumer::bookRoom() {
    cout << "Customer booked a room." << endl;
}

void Custumer:: cancelBooking() {
    cout<<"Cancel Booking"<<endl;
}
void Custumer::viewBookings() const {
    cout << "View Bookings" << endl;
}
void Custumer::updateProfile(string e, string p, string r) {
    setEmail(e);
    setPassword(p);
    setRole(r);
}