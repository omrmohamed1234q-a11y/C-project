#include "RoomTypes.hpp"

BasicRoom::BasicRoom() : Room() {}

BasicRoom::BasicRoom(int tag, string name, bool situation, double p, string detail)
    : Room(tag, name, "Basic", situation, p, detail) {
}

double BasicRoom::calculatePrice(double hour) const {
    return Room::calculatePrice(hour);
}

string BasicRoom::getDetails() const {
    return "Basic Room - " + Room::getDetails();
}

PrivateRoom::PrivateRoom() : Room() {}

PrivateRoom::PrivateRoom(int tag, string name, bool situation, double p, string detail)
    : Room(tag, name, "Private", situation, p, detail) {
}

double PrivateRoom::calculatePrice(double hour) const {
    return Room::calculatePrice(hour) + 15.0;
}

string PrivateRoom::getDetails() const {
    return "Private Room - " + Room::getDetails();
}

VIPRoom::VIPRoom() : Room() {}

VIPRoom::VIPRoom(int tag, string name, bool situation, double p, string detail)
    : Room(tag, name, "VIP", situation, p, detail) {
}

double VIPRoom::calculatePrice(double hour) const {
    return Room::calculatePrice(hour) * 1.5;
}

string VIPRoom::getDetails() const {
    return "VIP Room - " + Room::getDetails();
}

MeetingRoom::MeetingRoom() : Room() {}

MeetingRoom::MeetingRoom(int tag, string name, bool situation, double p, string detail)
    : Room(tag, name, "Meeting", situation, p, detail) {
}

double MeetingRoom::calculatePrice(double hour) const {
    return Room::calculatePrice(hour) + (hour * 10.0);
}

string MeetingRoom::getDetails() const {
    return "Meeting Room - " + Room::getDetails();
}

CustomRoom::CustomRoom() : Room() {}

CustomRoom::CustomRoom(int tag, string name, bool situation, double p, string detail)
    : Room(tag, name, "Custom", situation, p, detail) {
}

double CustomRoom::calculatePrice(double hour) const {
    return Room::calculatePrice(hour) + 25.0;
}

string CustomRoom::getDetails() const {
    return "Custom Room - " + Room::getDetails();
}
