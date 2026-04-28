#pragma once
#include <iostream>
#include <string>
#include "Room.hpp"
using namespace std;

class Workspace {
    private:
        string name;
        Room rooms[100];
        string services[100];
        string feedbacks[100];
        int roomCount;
        int serviceCount;
        int feedbackCount;

    public:
        Workspace();
        Workspace(string n);
        void setName(string n);
        string getName() const;
        void addRoom(Room room);
        void removeRoom(int id);
        Room* searchRooms(int id);
        void getRooms() const;
        void addService(string service);
        void addFeedback(string feedback);
        void displayWorkspace() const;
};
