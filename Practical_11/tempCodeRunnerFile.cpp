#include <iostream>
#include <string>

using namespace std;

// Abstract base class
class DataRecord {
protected:
    string name;
    int age;

public:
    DataRecord(string n, int a) : name(n), age(a) {}
    virtual void readData() = 0;
    virtual void displayData() = 0;
    virtual void deleteData() = 0;
    virtual void updateData() = 0;
    virtual void searchData() = 0;
    virtual void displayAllData() = 0;
    virtual ~DataRecord() { cout << "Destructor called for DataRecord." << endl; }
};

// Forward declaration of the Person class
class Person;

// Derived class
class Person : public DataRecord {
private:
    string occupation;
    static const int MAX_PEOPLE = 100;
    int numPeople;
    static Person people[MAX_PEOPLE];

public:
    Person(string n, int a, string o) : DataRecord(n, a), occupation(o), numPeople(0) {}

    void readData() override {
        string name, occupation;
        int age;
        cout << "Enter name: ";
        cin >> name;
        cout << "Enter age: ";
        cin >> age;
        cout << "Enter occupation: ";
        cin >> occupation;
        people[numPeople++] = Person(name, age, occupation);
    }

    void displayData() override {
        for (int i = 0; i < numPeople; i++) {
            cout << "Name: " << people[i].name << ", Age: " << people[i].age << ", Occupation: " << people[i].occupation << endl;
        }
    }

    void deleteData() override {
        string name;
        cout << "Enter name to delete: ";
        cin >> name;
        for (int i = 0; i < numPeople; i++) {
            if (people[i].name == name) {
                for (int j = i; j < numPeople - 1; j++) {
                    people[j] = people[j + 1];
                }
                numPeople--;
                break;
            }
        }
    }

    void updateData() override {
        string name, newOccupation;
        cout << "Enter name to update: ";
        cin >> name;
        cout << "Enter new occupation: ";
        cin >> newOccupation;
        for (int i = 0; i < numPeople; i++) {
            if (people[i].name == name) {
                people[i].occupation = newOccupation;
                break;
            }
        }
    }

    void searchData() override {
        string name;
        cout << "Enter name to search: ";
        cin >> name;
        bool found = false;
        for (int i = 0; i < numPeople; i++) {
            if (people[i].name == name) {
                cout << "Name: " << people[i].name << ", Age: " << people[i].age << ", Occupation: " << people[i].occupation << endl;
                found = true;
                break;
            }
        }
        if (!found) {
            cout << "Person not found." << endl;
        }
    }

    void displayAllData() override {
        Person sortedPeople[MAX_PEOPLE];
        for (int i = 0; i < numPeople; i++) {
            sortedPeople[i] = people[i];
        }
        for (int i = 0; i < numPeople - 1; i++) {
            for (int j = 0; j < numPeople - i - 1; j++) {
                if (sortedPeople[j].name > sortedPeople[j + 1].name) {
                    Person temp = sortedPeople[j];
                    sortedPeople[j] = sortedPeople[j + 1];
                    sortedPeople[j + 1] = temp;
                }
            }
        }
        for (int i = 0; i < numPeople; i++) {
            cout << "Name: " << sortedPeople[i].name << ", Age: " << sortedPeople[i].age << ", Occupation: " << sortedPeople[i].occupation << endl;
        }
    }

    ~Person() { cout << "Destructor called for Person." << endl; }
};

// Initialize the static member 'people'
Person Person::people[MAX_PEOPLE];

int main() {
    Person personData("", 0, "");
    int choice;
    do {
        cout << "\nMenu:\n";
        cout << "1. Read data\n2. Display data\n3. Delete data\n4. Update data\n5. Search data\n6. Display all data\n7. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                personData.readData();
                break;
            case 2:
                personData.displayData();
                break;
            case 3:
                personData.deleteData();
                break;
            case 4:
                personData.updateData();
                break;
            case 5:
                personData.searchData();
                break;
            case 6:
                personData.displayAllData();
                break;
            case 7:
                break;
            default:
                cout << "Invalid choice. Try again." << endl;
        }
    } while (choice != 7);

    return 0;
}