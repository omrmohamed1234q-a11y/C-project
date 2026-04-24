#include <iostream>
#include <string>
#include "core/Login.hpp"
#include "core/Room.hpp"
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
    cout << "\n========== USER MENU ==========\n";
    cout << "1. View Available Rooms\n";
    cout << "2. Book a Room\n";
    cout << "3. Cancel Booking\n";
    cout << "4. Logout\n";
    cout << "Enter your choice: ";
}

int main() {
    Login login("data/users.txt");

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

            if (!login.login()) {
                cout << "Login failed \n";
                break;
            }

            int userChoice;
            bool loggedIn = true;

            while (loggedIn) {

                displayUserMenu();
                cin >> userChoice;

                if (cin.fail()) {
                    cin.clear();
                    cin.ignore(10000, '\n');
                    cout << "Invalid input. Please enter a number.\n";
                    continue;
                }

                switch (userChoice) {

                case 1: {
                    Room room1(101, "Workspace A", "Office", true, 50.0, "Modern office with AC");
                    Room room2(102, "Workspace B", "Meeting", true, 30.0, "Meeting room for 10 people");
                    Room room3(103, "Workspace C", "Private", false, 45.0, "Private workspace");

                    if (room1.isAvailable()) {
                        cout << "Room " << room1.getId() << " - " << room1.getWorkspaceName()
                             << " | Price: $" << room1.getPrice()
                             << " | " << room1.getDetails() << endl;
                    }

                    if (room2.isAvailable()) {
                        cout << "Room " << room2.getId() << " - " << room2.getWorkspaceName()
                             << " | Price: $" << room2.getPrice()
                             << " | " << room2.getDetails() << endl;
                    }

                    if (room3.isAvailable()) {
                        cout << "Room " << room3.getId() << " - " << room3.getWorkspaceName()
                             << " | Price: $" << room3.getPrice()
                             << " | " << room3.getDetails() << endl;
                    } else {
                        cout << "Room 103 is not available\n";
                    }

                    break;
                }

                case 2: {
                    Room room(101, "Workspace A", "Office", true, 50.0, "Modern office with AC");

                    if (room.book()) {
                        cout << "Room booked successfully!\n";
                        room.setAvailable(false);
                    }

                    break;
                }

                case 3: {
                    Room room(101, "Workspace A", "Office", false, 50.0, "Modern office with AC");

                    if (room.cancelBooking()) {
                        cout << "Booking cancelled successfully!\n";
                        room.setAvailable(true);
                    }

                    break;
                }

                case 4: {
                    cout << "Logging out...\n";
                    loggedIn = false;
                    break;
                }

                default:
                    cout << "Invalid choice. Try again.\n";
                }
            }

            break;
        }

        case 3: {
            cout << "Thank you for using Booked & Beyond . Goodbye!\n";
            return 0;
        }

        default:
            cout << "Invalid choice. Try again.\n";
        }
    }

    return 0;
}