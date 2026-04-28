#include "Users.h"

Users::Users() {
    name = "";
    email = "";
    password = "";
    role = "";
}
Users::Users(string e, string p, string r) {
    name = "";
    email = e;
    password = p;
    role = r;
}
Users::Users(string n, string e, string p, string r) {
    name = n;
    email = e;
    password = p;
    role = r;
}
void Users::setInfo(string n, string e, string p, string r) {
    name = n;
    email = e;
    password = p;
    role = r;
}
string Users::getName() const {
    return name;
}
string Users::getEmail() const {
    return email;
}
string Users::getPassword() const {
    return password;
}
string Users::getRole() const {
    return role;
}
void Users::setEmail(string e) {
    email = e;
}
void Users::setName(string n) {
    name = n;
}
void Users::setPassword(string p) {
    password = p;
}
void Users::setRole(string r) {
    role = r;
}

void Users::displayUser() const {
    cout << name << " " << email << " " << password << " " << role << endl;
}
