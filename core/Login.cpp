#include"Login.hpp"
#include <iostream>
#include <fstream>  
#include <string>

using namespace std;
 
Login::Login(string filePath){
    file = filePath;
}

void Login::registerUser(){
    string username;
    string password;
    string role;
    cout << "enter username : " ;
    cin >> username;
    cout << "enter password : ";
    cin >> password;
    cout << "enter role : ";
    cin >> role;

    ofstream data(file, ios::app);

    if(!data){
        cout << "No file \n";
        return;
    }
    data << username << "," << password << "," << role << "\n";

    cout << "done";
    data.close();
    
}

bool Login::login(){
    string username;
    string password;
    cout << "enter username : " ;
    cin >> username;
    cout << "enter password : ";
    cin >> password;

    ifstream data(file);

    if(!data){
        cout << "No users found. Please register first \n";
        return false;
    }

    string read;
    bool done = false;

    while(getline(data,read)){
        int x = read.find(",");
        int x2 = read.find(',',x+1);
        string usr = read.substr(0,x);
        string pass = read.substr(x+1, x2-x-1);
        string role = read.substr(x2 + 1);

        if(usr == username && pass == password){
            done = true;
            break;
        }
    }

    if(done){
        cout << "Welcome " << username << "!\n" ;
    } else {
        cout << "Invalid username or password!\n";
    }
    
    data.close();
    return done;
}