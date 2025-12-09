#include <iostream>
#include "PhoneBook.h"
#include "Contact.h"
using namespace std;

bool isValidPhone(const string& phone){
    for(char c : phone){
        if(!isdigit(c) && c != '+' && c != '-'){
            return false;
        }
    }
    return !phone.empty();
}

int main(){
    PhoneBook phoneBook;
    int choice;
    do{
        cout<<"\n--Phone Book Menu--\n"
        <<"1.Add Contact\n"
        <<"2. SHOW Contacts\n"
        << "3. Search Contact\n"
        << "4. Delete Contact\n"
        << "5. Exit\n"
        <<"Choose an option: ";
        cin >>choice;
        cin.ignore();

        switch(choice){
            case 1:{
                string name,phone;
                cout<<"Enter name :";
                getline(cin,name);
                do {
                    cout << "Enter phone number (digits, +, - allowed): ";
                    getline(cin, phone);
                    if (!isValidPhone(phone)) {
                        cout << "Invalid phone number format. Try again.\n";
                    }
                } while (!isValidPhone(phone));

                Contact c(name, phone);
                phoneBook.addContact(c);
                break;
            }
            case 2:
                phoneBook.showContacts();
                break;
            case 3: {
                string name;
                cout << "Enter name to search: ";
                getline(cin, name);
                phoneBook.searchContact(name);
                break;
            }
            case 4: {
                string name;
                cout << "Enter exact name to delete: ";
                getline(cin, name);
                phoneBook.deleteContact(name);
                break;
            }
            case 5:
                cout << "Exiting...\n";
                break;
            default:
                cout << "Invalid option. Try again.\n";
        }
    } while (choice != 5);

    return 0;
            }
        