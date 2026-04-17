#ifndef USERS_H
#define USERS_H
# include <iostream>
# include <string>
using namespace std;
class Users {
private:
    string email;
    string password;
    string role;
public:
    Users();
    Users(string e, string p, string r);
    void setEmail(string e);
    void setPassword(string p);
    void setRole(string r);
    string getEmail() const;
    string getPassword() const;
    string getRole() const;
    void displayUser() const;

};
#endif