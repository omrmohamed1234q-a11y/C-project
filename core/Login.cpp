#include"Login.hpp"
#include <iostream>
#include <fstream>  
#include <string>

using namespace std;
 
Login::Login(string filePath){ // login class parametarized constructor
    file = filePath;
}
// the registration function
bool Login::registerUser(const string& username, const string& password, const string& role){ // passing variables by refrence to avoid copynig
    ofstream data(file, ios::app); // open the file in append mode
    if(!data){ // handling errors is data wasn't found
        return false;
    }
    data << username << "," << password << "," << role << "\n"; //writing user data in user data file
    data.close(); // closing file after appending the user data
    return true;
}
// the login function
bool Login::login(const string& username, const string& password, string& outRole){
    ifstream data(file); // opening the file in reading mode

    if(!data){ // handeling missing data errors
        return false;
    }

    string read;
    bool done = false; //initializing varaible done with false to be used later

    while(getline(data,read)){ // looping over file lines to chech if the user excist or not
        int x = read.find(",");  // finding the first comma index
        int x2 = read.find(',',x+1); // find the next comma index
        if(x == string::npos || x2 == string::npos) continue; // skip the line if any comma is missing
        string usr = read.substr(0,x); // extract the username supstring
        string pass = read.substr(x+1, x2-x-1); // extract the pass supstring
        string role = read.substr(x2 + 1); // extract the role substring

        if(usr == username && pass == password){ // check if the input data match the file data
            outRole = role; // set the outrole to role for future use
            done = true;// set done as true
            break;// stop the loop after finding the matched data
        }
    }

    data.close();
    return done;
}