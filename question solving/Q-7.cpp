#include <iostream>
#include <string>

using namespace std;

class Person {
private:
    string name;
    string currentAddress;
    string permanentAddress;

public:
    // Constructor to initialize object information
    Person(string n, string curAddr, string permAddr) {
        name = n;
        currentAddress = curAddr;
        if (curAddr == permAddr) {
            permanentAddress = curAddr;
        } else {
            permanentAddress = permAddr;
        }
    }

    // Function to display person's information
    void displayInfo() {
        cout << "Name: " << name << endl;
        cout << "Current Address: " << currentAddress << endl;
        cout << "Permanent Address: " << permanentAddress << endl;
    }
};

int main() {
    string name, curAddr, permAddr;

    // Accepting input from user
    cout << "Enter name: ";
    getline(cin, name);
    cout << "Enter current address: ";
    getline(cin, curAddr);
    cout << "Enter permanent address: ";
    getline(cin, permAddr);

    // Creating object and passing input to constructor
    Person person(name, curAddr, permAddr);

    // Displaying person's information
    person.displayInfo();

    return 0;
}
