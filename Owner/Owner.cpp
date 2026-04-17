# include "Owner.h"
Owner::Owner():Users(){};
Owner::Owner(string e, string p, string r) : Users(e, p, r) {
}
void Owner::addRoom() {
    cout << "Owner added a room." << endl;
}

void Owner::editRoom() {
    cout << "Owner edited a room." << endl;
}

void Owner::deleteRoom() {
    cout << "Owner deleted a room." << endl;
}

void Owner::viewStats() const {
    cout << "Owner is viewing stats." << endl;
}