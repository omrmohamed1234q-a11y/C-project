#pragma once 
#include <iostream>
#include <string>
using namespace std;

class Room {
    private:
        int id ;
        int capacity;
        int occupied;
        double price;
        string details;
        string workspaceName;
        string type;
        bool Available ;
        
    public:
        Room();
        Room(int tag ,string name , string t ,bool situation ,double p ,string detail, int cap, int occ = 0);
        virtual ~Room() {}
        void setAvailable(bool av);
        bool isAvailable() const;
        void setId(int tag);
        void setPrice(double p);
        void setDetails(string detail);
        void setWorkspaceName(string name);
        void setType(string t);
        void setCapacity(int cap);
        void setOccupied(int occ);
        int getId()const;
        int getCapacity()const;
        int getOccupied()const;
        double getPrice()const;
        string getWorkspaceName()const;
        string getType() const;
        virtual string getDetails()const;
        bool book();
        bool cancelBooking();
        virtual double calculatePrice(double hour) const;
        virtual void displayInfo() const ;
};
