#include "Workspace.hpp"
#include <fstream>
#include <sstream>

Workspace::Workspace() { // workspace default construnctor
    name = "";
    filePath = "";
}

Workspace::Workspace(string n, string path) { // parametarized cconstructor
    name = n;
    filePath = path;
}

Workspace::~Workspace() { // rooms elements destructor
    for (Room* room : rooms) {
        delete room;
    }
    rooms.clear();
}

void Workspace::setName(string n) { // workspace name setter
    name = n;
}

string Workspace::getName() const {// workspace name getter
    return name;
}

void Workspace::addRoom(Room* room) { // add room function definition take room memory address as parameter
    rooms.push_back(room); // add element of type Room in rooms vector
    saveRooms(); // call saveRooms function defined later
    cout << "room added successfully \n";
}

void Workspace::removeRoom(int id) {  // remove room definition takes the room id as parameter
    for (auto it = rooms.begin(); it != rooms.end(); ++it) {// auto autodefin the it type   . begin return itrator for the first element in rooms vector
        if ((*it)->getId() == id) {// if the element id equal to the id
            delete *it; // delete the element
            rooms.erase(it); // erase the elemnt from the vector
            saveRooms();//call saveRooms function
            cout << "room removed successfully \n";
            return;
        }
    }
    cout << "room not found \n";
}

Room* Workspace::searchRooms(int id) {// search for room by id function definition
    for (Room* room : rooms) { // loop over every element rooms vector
        if (room->getId() == id) {// if teh room id match the searched id return the room else return null
            return room;
        }
    }
    return NULL;
}

void Workspace::getRooms() const { // not real getter only display all rooms info in rooms vector
    if (rooms.empty()) {
        cout << "no rooms found \n";
        return;
    }
    for (Room* room : rooms) {// loop over every room in rooms vector and display the information
        room->displayInfo();
    }
}

const vector<Room*>& Workspace::getRoomsList() const { // room list getter that return  a const vector of room points by refrence
    return rooms;
}

void Workspace::addService(string service) {  // function to add service in services vector
    services.push_back(service);
}

void Workspace::addFeedback(string feedback) { //funciton to add feedback in feedbacks vector
    feedbacks.push_back(feedback);
}

void Workspace::displayWorkspace() const { // function to display the workspace details
    cout << "Workspace Name: " << name << endl;
    cout << "Rooms: " << rooms.size() << endl;
    cout << "Services: " << services.size() << endl;
    cout << "Feedbacks: " << feedbacks.size() << endl;
}

void Workspace::loadRooms() { // Function to load room data from a file into the workspace
    if (filePath.empty()) return; // If the file path is empty, there is no file to load from, so exit the function
    ifstream data(filePath);// open the file in reading mode
    if (!data) return;    // If the file failed to open, exit the function
    string read;
    while(getline(data, read)) {// Read the file line by line until the end of file
        if (read.empty()) continue;// If the line is empty, skip it and move to the next line
        stringstream ss(read);// Create a string stream to process the line as comma-separated values
        string id_s, workspaceName, type, avail_s, price_s, details, cap_s, occ_s;// Temporary string variables to store each field from the line
        getline(ss, id_s, ',');// Read room ID until comma
        getline(ss, workspaceName, ',');// Read workspace/room name until comma
        getline(ss, type, ',');
        getline(ss, avail_s, ',');
        getline(ss, price_s, ',');
        getline(ss, details, ',');
        getline(ss, cap_s, ',');
        getline(ss, occ_s, ',');
        if(id_s.empty()) continue; // If room ID is missing, skip this record because it's invalid
        
        int id = stoi(id_s);// Convert room ID from string to integer
        bool avail = (avail_s == "1");  // Convert availability "1" means true (available) anything else means false (not available)
        double price = stod(price_s); // string to double
        int cap = cap_s.empty() ? 0 : stoi(cap_s); // if the capacity is empty set it as 0 else convert it to int and assign it to cap
        int occ = occ_s.empty() ? 0 : stoi(occ_s);
        
        Room* room = new Room(id, workspaceName, type, avail, price, details, cap, occ);// Dynamically create a new Room object using the loaded data
        rooms.push_back(room);// Store the room pointer inside the rooms vector
    }
    data.close();
}


void Workspace::saveRooms() const { // Function that saves all room data into a file. const means this function does not modify the Workspace object.
    if (filePath.empty()) return; // If no file path is provided exit the function.
    ofstream data(filePath); // Create an output file stream object and open the file for writing.
    if (!data) return; // If the file failed to open, exit the function.
    for (Room* room : rooms) { // Loop through every room pointer stored in the rooms vector.
        data << room->getId() << "," << room->getWorkspaceName() << "," << room->getType() << ","// Save room ID, workspace name, and room type separated by commas.

             << (room->isAvailable() ? "1" : "0") << "," << room->getPrice() << ","
             // Save room availability If  = true, save "1" If false, save "0" Then save the room price.

             << room->getDetails() << "," << room->getCapacity() << "," << room->getOccupied() << "\n"; // Save room details, room capacity, and current occupied count. "\n" moves to the next line for the next room record.
    }

    data.close();
}