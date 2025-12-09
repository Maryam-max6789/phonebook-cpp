#ifndef CONTACT_H
#define CONTACT_H
#include <string>
using namespace std;
class Contact{
private:
string name;
string phone;

public:
//Constructors
Contact(){
}
Contact(const string& name, const string& phone);
//Getter
string getName() const;
string getPhone() const;
//Setter
void setName(const string& name);
void setPhone(const string& phone);
//for saving as string
string toString() const;
static Contact FromString(const string& line);


#endif
};