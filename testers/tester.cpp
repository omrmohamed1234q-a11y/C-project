#include "Room.hpp"
#include <iostream>

void printSeparator() {
    std::cout << "===============================\n";
}

int main() {
    // Test 1: Basic Room Creation and Display
    std::cout << "Test 1: Basic Room Creation\n";
    Room r1(1, "Ocean View", "VIP", true, 50.0, "Large room with sea view");
    r1.displayInfo();
    printSeparator();

    // Test 2: Booking and Cancellation
    std::cout << "Test 2: Booking and Cancellation\n";
    r1.book();
    r1.displayInfo();
    r1.cancelBooking();
    r1.displayInfo();
    printSeparator();

    // Test 3: Multiple Bookings (attempting to book already booked room)
    std::cout << "Test 3: Attempting double booking\n";
    r1.book();
    bool result = r1.book();
    std::cout << "Second booking attempt result: " << (result ? "Success" : "Failed (already booked)") << "\n";
    r1.displayInfo();
    r1.cancelBooking();
    printSeparator();

    // Test 4: Cancellation when not booked
    std::cout << "Test 4: Cancellation when not booked\n";
    bool cancelResult = r1.cancelBooking();
    std::cout << "Cancellation result: " << (cancelResult ? "Success" : "Failed (was not booked)") << "\n";
    printSeparator();

    // Test 5: Room with different types
    std::cout << "Test 5: Different room types\n";
    Room r2(2, "Mountain Cabin", "Standard", false, 100.0, "Cozy cabin");
    Room r3(3, "Deluxe Suite", "Deluxe", true, 200.0, "Premium suite");
    r2.displayInfo();
    printSeparator();
    r3.displayInfo();
    printSeparator();

    // Test 6: Price modification
    std::cout << "Test 6: Price modifications\n";
    r2.setPrice(120.0);
    r2.displayInfo();
    printSeparator();

    // Test 7: Availability modification
    std::cout << "Test 7: Change availability\n";
    r3.setAvailable(false);
    r3.displayInfo();
    r3.setAvailable(true);
    r3.displayInfo();
    printSeparator();

    // Test 8: Details modification
    std::cout << "Test 8: Details changes\n";
    r1.setDetails("Updated: Large room with sea view and balcony");
    r1.displayInfo();
    printSeparator();

    // Test 9: Workspace name modification
    std::cout << "Test 9: Workspace name changes\n";
    r2.setWorkspaceName("Mountain View Cabin");
    r2.displayInfo();
    printSeparator();

    // Test 10: Type modification
    std::cout << "Test 10: Type changes\n";
    r3.setType("Premium");
    r3.displayInfo();
    printSeparator();

    // Test 11: Copy constructor
    std::cout << "Test 11: Copy constructor\n";
    Room r4 = r1;
    std::cout << "Original room:\n";
    r1.displayInfo();
    std::cout << "\nCopied room:\n";
    r4.displayInfo();
    printSeparator();

    // Test 12: Assignment operator
    std::cout << "Test 12: Assignment operator\n";
    Room r5(10, "Temp Room", "Standard", true, 150.0, "Temporary");
    std::cout << "Before assignment:\n";
    r5.displayInfo();
    r5 = r2;
    std::cout << "\nAfter assignment:\n";
    r5.displayInfo();
    printSeparator();

    // Test 13: Calculate price function
    std::cout << "Test 13: Calculate price for hours\n";
    double price1hour = r1.calculatePrice(1);
    double price5hours = r1.calculatePrice(5);
    double price10hours = r1.calculatePrice(10);
    std::cout << "Price for 1 hour: " << price1hour << "\n";
    std::cout << "Price for 5 hours: " << price5hours << "\n";
    std::cout << "Price for 10 hours: " << price10hours << "\n";
    printSeparator();

    // Test 14: ID modification
    std::cout << "Test 14: ID changes\n";
    r1.setId(100);
    r1.displayInfo();
    printSeparator();

    // Test 15: Getters verification
    std::cout << "Test 15: Getters verification\n";
    std::cout << "r1 ID: " << r1.getId() << "\n";
    std::cout << "r1 Workspace Name: " << r1.getWorkspaceName() << "\n";
    std::cout << "r1 Price: " << r1.getPrice() << "\n";
    std::cout << "r1 Availability: " << (r1.isAvailable() ? "Yes" : "No") << "\n";
    std::cout << "r1 Details: " << r1.getDetails() << "\n";
    printSeparator();

    // Test 16: Default constructor
    std::cout << "Test 16: Default constructor\n";
    Room defaultRoom;
    defaultRoom.displayInfo();
    printSeparator();

    return 0;
}
