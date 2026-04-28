#pragma once
#include <iostream>
#include <memory>
#include <string>
#include <vector>
#include "Room.hpp"
using namespace std;

class Workspace {
private:
    string name;
    vector<shared_ptr<Room> > rooms;
    vector<string> services;
    vector<string> feedback;

public:
    Workspace();
    Workspace(string n);

    void setName(string n);
    string getName() const;

    void addRoom(shared_ptr<Room> room);
    bool removeRoom(int id);
    shared_ptr<Room> searchRooms(int id) const;
    vector<shared_ptr<Room> > getRooms() const;

    void addService(string service);
    void addFeedback(string note);
    void displayWorkspace() const;
};
