#include <iostream>
#include <string>

using namespace std;

class Person {
public:
    string name;
    string currentAddress;
    string permanentAddress;
    Person* prev;
    Person* next;

    Person(string n, string ca, string pa) : name(n), currentAddress(ca), permanentAddress(pa), prev(nullptr), next(nullptr) {}

    void display() {
        cout << "Name: " << name << endl;
        cout << "Current Address: " << currentAddress << endl;
        cout << "Permanent Address: " << permanentAddress << endl;
    }
};

class PersonList {
private:
    Person* head;
    Person* tail;

public:
    PersonList() : head(nullptr), tail(nullptr) {}

    void insert(string name, string currentAddress, string permanentAddress) {
        Person* newPerson = new Person(name, currentAddress, permanentAddress);
        if (!head) {
            head = newPerson;
            tail = newPerson;
        } else {
            tail->next = newPerson;
            newPerson->prev = tail;
            tail = newPerson;
        }
    }

    void displayAll() {
        Person* current = head;
        while (current) {
            current->display();
            current = current->next;
        }
    }

    void fillPermanentFromCurrent() {
        Person* current = head;
        while (current) {
            if (current->currentAddress == current->permanentAddress) {
                current->permanentAddress = current->currentAddress;
            }
            current = current->next;
        }
    }

    ~PersonList() {
        Person* current = head;
        while (current) {
            Person* next = current->next;
            delete current;
            current = next;
        }
    }
};

int main() {
    PersonList people;
    people.insert("John Doe", "123 Main St", "456 Elm St");
    people.insert("Jane Smith", "456 Elm St", "456 Elm St");
    people.insert("Alice Johnson", "789 Oak St", "789 Oak St");

    people.fillPermanentFromCurrent();
    people.displayAll();

    return 0;
}