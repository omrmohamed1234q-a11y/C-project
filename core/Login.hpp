#pragma once 
#include <iostream>
#include <string>
#include <fstream>

using namespace std;

class Login {
    private:  
        string file ;
        
    public:
      Login(string filePath);
      bool login(const string& username, const string& password, string& outRole);
      bool registerUser(const string& username, const string& password, const string& role);
};