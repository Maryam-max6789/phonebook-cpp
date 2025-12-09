#ifndef PHONEBOOK_H
#define PHONEBOOK_H

#include <vector>
#include "Contact.h"
class PhoneBook{ 
    private:
    vector<Contact> contacts;
    const string filename = "phonebook.txt";
    void loadFromFile();
    void saveToFile() const;
    public:
    PhoneBook();
    void addContact(const Contact& c) ;
    void showContacts() const;
    bool searchContact(const string& name) const;
    bool deleteContact(const string& name);
};

#endif