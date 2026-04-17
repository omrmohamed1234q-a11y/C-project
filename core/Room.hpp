#pragma once 
#include <iostream>
#include <string>
using namespace std;

class Room {
    private:  
        int id ;
        double price;
        string details;
        string workspaceName;
        string type;
        bool Available ;
        
    public:
        Room();
        Room(int tag ,string name , string t ,bool situation ,double p ,string detail);
        void setAvailable(bool av);
        bool isAvailable();
        void setId(int tag);
        void setPrice(double p);
        void setDetails(string detail);
        void setWorkspaceName(string name);
        void setType(string t);
        int getId()const;
        double getPrice()const;
        string getWorkspaceName()const;
        string getDetails()const;
        bool book();
        bool cancelBooking();
        double calculatePrice(double hour);
        void displayInfo() const ;
};