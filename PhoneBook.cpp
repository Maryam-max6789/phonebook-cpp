#include "PhoneBook.h"
#include <fstream>
#include <iostream>
#include <algorithm>
using namespace std;

PhoneBook::PhoneBook(){
    loadFromFile();
}

void PhoneBook::loadFromFile(){
    loadFromFile();
}
void PhoneBook::loadFromFile(){
    ifstream file(filename);
    string line;
    contacts.clear();

    while (getline(file,line)){
        if(!line.empty()){
            contacts.push_back(Contact::fromString(line));
        }
    }
}

void PhoneBook::saveToFile() const{
    ofstream file(filename);

    for(const auto& c : contacts){
        file << c.toString()<<endl;
    }
}

void PhoneBook::addContact(const Contact& c){
    contacts.push_back(c);
    saveToFile();
    cout<<"Contact added successfully.\n";
}

void PhoneBook::showContacts() const{
    if(contacts.empty()){
        cout<<"Phone book is empty .\n";
        return;
    }

    cout<<"\n---Contact ---\n";
    for(const auto& c : contacts){
        cout<<"Name: "<<c.getName()<<",Phone :"<<c.getPhone() << "\n";
    }
}

bool PhoneBook::searchContact(const string& name) const{
    bool found = false;
    for(const auto& c : contacts){
        if(c.getName().find(name) != string::npos){
            cout<<"Found : "<<c.getName().find(name)<< "-"<<c.getPhone()<<"\n";
            found = true;
        }
    }
    if(!found){
        cout<<"No contact found with name containing\""<<name<<"\"\n";
    }
    return found;
}
bool PhoneBook::deleteContact(const string& name){
    auto it = remove_if(contacts.begin(),contacts.end(),[&](const Contact& c){return c.getName() == name;});

if (it != contacts.end()){
    contacts.erase(it,contacts.end());
    saveToFile();
    cout<<"Contact deleted successfully.\n";
    return true;
}else{
    cout<<"No contact found with the exact name \""<<name<<"\"\n";
    return false;
}
}