#include <iostream>
#include <string>
#include "core/Login.hpp"
#include "core/Room.hpp"
#include "core/Workspace.hpp"
#include "users/users.h"
#include "Custumer/costumer.h"
#include "Owner/Owner.h"

using namespace std;

void displayMainMenu() {
    cout << "\n==========  Booked & Beyond  ==========\n";
    cout << "1. Register\n";
    cout << "2. Login\n";
    cout << "3. Exit\n";
    cout << "Enter your choice: ";
}

void displayUserMenu() {
    cout << "\n========== CUSTOMER MENU ==========\n";
    cout << "1. View Available Rooms\n";
    cout << "2. Book a Room\n";
    cout << "3. Cancel Booking\n";
    cout << "4. View My Bookings\n";
    cout << "5. Logout\n";
    cout << "Enter your choice: ";
}

void displayOwnerMenu() {
    cout << "\n========== OWNER MENU ==========\n";
    cout << "1. View System Stats & Rooms\n";
    cout << "2. Add a Room\n";
    cout << "3. Edit a Room\n";
    cout << "4. Delete a Room\n";
    cout << "5. Logout\n";
    cout << "Enter your choice: ";
}

int main() {
    string usersPath = "C:/Users/HP/CLionProjects/C-project-1/data/users.txt";
    string roomsPath = "C:/Users/HP/CLionProjects/C-project-1/data/rooms.txt";
    string bookingsPath = "C:/Users/HP/CLionProjects/C-project-1/data/bookings.txt";

    Login login(usersPath);
    Workspace mainWorkspace("Main Workspace", roomsPath);
    mainWorkspace.loadRooms();

    int mainChoice;

    while (true) {
        displayMainMenu();
        cin >> mainChoice;

        if (cin.fail()) {
            cin.clear();
            cin.ignore(10000, '\n');
            cout << "Invalid input. Please enter a number.\n";
            continue;
        }

        switch (mainChoice) {
        case 1: {
            cout << "\n--- Registration ---\n";
            login.registerUser();
            break;
        }
        case 2: {
            cout << "\n--- Login ---\n";
            string username, role;
            if (!login.login(username, role)) {
                break; // login failed
            }

            bool loggedIn = true;
            
            if (role == "Customer" || role == "customer") {
                Custumer currentCustomer(username, username, "", role); // Using username as email/id here
                currentCustomer.loadBookings(bookingsPath, username);
                
                while (loggedIn) {
                    displayUserMenu();
                    int userChoice;
                    cin >> userChoice;
                    if (cin.fail()) { cin.clear(); cin.ignore(10000, '\n'); continue; }

                    switch (userChoice) {
                        case 1: {
                            mainWorkspace.getRooms();
                            break;
                        }
                        case 2: {
                            int roomId;
                            cout << "Enter Room ID to book: ";
                            cin >> roomId;
                            currentCustomer.bookRoom(mainWorkspace, roomId);
                            currentCustomer.saveBookings(bookingsPath, username);
                            break;
                        }
                        case 3: {
                            int roomId;
                            cout << "Enter Room ID to cancel: ";
                            cin >> roomId;
                            currentCustomer.cancelBooking(mainWorkspace, roomId);
                            currentCustomer.saveBookings(bookingsPath, username);
                            break;
                        }
                        case 4: {
                            currentCustomer.viewBookings();
                            break;
                        }
                        case 5: {
                            cout << "Logging out...\n";
                            loggedIn = false;
                            break;
                        }
                        default:
                            cout << "Invalid choice. Try again.\n";
                    }
                }
            } else if (role == "Owner" || role == "owner") {
                Owner currentOwner(username, username, "", role);
                
                while (loggedIn) {
                    displayOwnerMenu();
                    int ownerChoice;
                    cin >> ownerChoice;
                    if (cin.fail()) { cin.clear(); cin.ignore(10000, '\n'); continue; }

                    switch (ownerChoice) {
                        case 1: {
                            currentOwner.viewStats(mainWorkspace);
                            break;
                        }
                        case 2: {
                            int id, capacity;
                            double price;
                            string name, type, details;
                            cout << "Enter Room ID: "; cin >> id;
                            cout << "Enter Workspace Name: "; cin >> name;
                            cout << "Enter Room Type: "; cin >> type;
                            cout << "Enter Price: "; cin >> price;
                            cout << "Enter Details: "; cin >> details;
                            cout << "Enter Capacity: "; cin >> capacity;
                            
                            Room newRoom(id, name, type, true, price, details, capacity);
                            currentOwner.addRoom(mainWorkspace, newRoom);
                            break;
                        }
                        case 3: {
                            int id;
                            double newPrice;
                            string newDetails;
                            cout << "Enter Room ID to edit: "; cin >> id;
                            cout << "Enter New Price: "; cin >> newPrice;
                            cout << "Enter New Details: "; cin >> newDetails;
                            currentOwner.editRoom(mainWorkspace, id, newPrice, newDetails);
                            break;
                        }
                        case 4: {
                            int id;
                            cout << "Enter Room ID to delete: "; cin >> id;
                            currentOwner.deleteRoom(mainWorkspace, id);
                            break;
                        }
                        case 5: {
                            cout << "Logging out...\n";
                            loggedIn = false;
                            break;
                        }
                        default:
                            cout << "Invalid choice. Try again.\n";
                    }
                }
            } else {
                cout << "Unknown role: " << role << "\n";
            }
            break;
        }
        case 3: {
            cout << "Thank you for using Booked & Beyond. Goodbye!\n";
            return 0;
        }
        default:
            cout << "Invalid choice. Try again.\n";
        }
    }
    return 0;
}