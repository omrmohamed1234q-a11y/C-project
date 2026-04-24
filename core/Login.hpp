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
      bool login();
      void registerUser();
};