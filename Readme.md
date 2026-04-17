# Workspace Booking System

> A modular object-oriented system that allows users to search, filter, and book workspace rooms, while enabling owners to manage rooms, services, and track bookings and revenue.

---

## Overview

The Workspace Booking System is designed to simplify the process of booking shared workspaces. Users can easily browse available rooms, apply filters, and make bookings based on their preferences.

Workspace owners can manage rooms, services, and monitor system performance through booking statistics and revenue insights.

The system is built using Object-Oriented Programming principles to ensure scalability, maintainability, and clean architecture.

---

## Features

### User Features

* Register and login to the system
* Search rooms by name or type
* Filter rooms based on price, type, and services
* Book and cancel rooms
* View booking history
* Update profile information

### Owner Features

* Add, edit, and delete rooms
* Manage workspace services
* View booking statistics and revenue
* Monitor room usage

---

## Installation

```bash
# 1. Clone the repository
git clone https://github.com/omrmohamed1234q-a11y/C-project.git

# 2. Navigate into the project directory
cd workspace-booking-system

# 3. Compile the project (example for C++)
g++ main.cpp -o app

# 4. Run the application
./app
```

> Note: Adjust compilation commands based on your project structure and compiler.

---

## Usage

1. Launch the application
2. Register a new account or login
3. Navigate through the menu system
4. Search and filter available rooms
5. Book or cancel reservations
6. Owners can manage rooms and view statistics

---

## Project Structure

```
workspace-booking-system/
│
├── core/              # Core classes (Workspace, Room, etc.)
├── users/             # User-related classes (User, Customer, Owner)
├── ui/                # User Interface handling
├── managers/          # Functionality modules (Booking, Login, etc.)
├── models/            # Supporting classes (Booking, TimeSlot, Service)
├── main.cpp           # Entry point
└── README.md
```
