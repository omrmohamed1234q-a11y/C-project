#pragma once
#include <iostream>
#include <string>
#include <vector>
#include "Room.hpp"
using namespace std;

class Workspace {
    private:
        string name;
        vector<Room*> rooms;
        vector<string> services;
        vector<string> feedbacks;
        string filePath;

    public:
        Workspace();
        Workspace(string n, string path);
        ~Workspace();
        void setName(string n);
        string getName() const;
        void addRoom(Room* room);
        void removeRoom(int id);
        Room* searchRooms(int id);
        void getRooms() const;
        const vector<Room*>& getRoomsList() const;
        void addService(string service);
        void addFeedback(string feedback);
        void displayWorkspace() const;
        void loadRooms();
        void saveRooms() const;
};
