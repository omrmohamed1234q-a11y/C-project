#include "Users.h"
Users::Users() {
    email = "";
    password = "";
    role = "";
}
Users::Users(string e, string p, string r) {
    email = e;
    password = p;
    role = r;
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
void Users::setPassword(string p) {
    password = p;
}
void Users::setRole(string r) {
    role = r;
}
void Users::displayUser() const {
    cout << email << " " << password << " " << role << endl;
}