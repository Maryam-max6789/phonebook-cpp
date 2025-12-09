#include "Contact.h"
#include <sstream>
#include <iostream>

//Constructor
Contact::Contact(const string& name, const string& phone): name(name),phone(phone){}

//Getters
string Contact::getName() const {
    return name;
}
string Contact::getPhone() const {
    return phone;
}
//Setter
void Contact::setName(const string& name){
    this->name = name;
}
void Contact::setPhone(const string& phone){
    this->phone = phone;
}
string Contact::toString() const{
    return name + "," + phone;
}
Contact Contact::fromString(const string& line){
    stringstream ss(line);
    string name, phone;

    getline(ss,name,',');
    getline(ss,phone,',');

    return Contact(name,phone);
}
