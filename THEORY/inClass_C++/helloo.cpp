#include <iostream>
#include <string>

using namespace std;

const int MAX_DATABASES = 10; // Maximum number of databases
const int MAX_STUDENTS_PER_DB = 100; // Maximum students per database

class StudentInfo 
{
    public:
    int rollNo;
    string name;
};

class Database 
{
private:
    StudentInfo students[MAX_STUDENTS_PER_DB]; // Array to store student information
    int numStudents; // Number of students currently added

public:
    Database() : numStudents(0) {} // Initialize numStudents to 0 in constructor

    void addStudent() 
    {
        if (numStudents == MAX_STUDENTS_PER_DB) 
        {
            cout << "Database full! Cannot add more students." << endl;
            return;
        }

        StudentInfo student;
        cout << "Enter Roll Number: ";
        cin >> student.rollNo;
        cout << "Enter Student Name: ";
        cin.ignore(); // Clear input buffer after reading roll number (optional)
        getline(cin, student.name); // Use getline for potentially multi-word names

        students[numStudents++] = student; // Add student to the array
    }

    void printStudents() {
        if (numStudents == 0) {
            cout << "No students added to this database." << endl;
            return;
        }

        cout << "** Database Students **" << endl;
        for (int i = 0; i < numStudents; ++i) {
            cout << "Roll Number: " << students[i].rollNo << endl;
            cout << "Student Name: " << students[i].name << endl;
            cout << endl;
        }
    }
};

int main() {
    int choice, numDatabases;
    Database obj[MAX_DATABASES];

    cout << "<< user interface >>>" << endl << endl;
    cout << "[1] Add Data-base" << endl;
    cout << "[2] Display the names"<<endl;
    cout << "[3] Display all the Data-base"<<endl;
    cout << "[4] Exit the program"<<endl;
    // ... Include options for Delete, Reset (if applicable), and Exit
    cin >> choice;

    while (true) {
        switch (choice) 
        {
            case 1:
                cout << "Enter number of databases to create (up to " << MAX_DATABASES << "): ";
                cin >> numDatabases;

                if (numDatabases > 0 && numDatabases <= MAX_DATABASES) {
                    for (int i = 0; i < numDatabases; ++i) 
                    {
                        cout << "\n** Database " << (i + 1) << " **" << endl;
                        obj[i].addStudent(); // Add student(s) to each database
                    }
                } 
                else 
                {
                    cout << "Invalid number of databases. Please enter a value between 1 and " << MAX_DATABASES << "." << endl;
                }

            break;

            case 2:
                cout << "Enter database number to print students (1-" << numDatabases << "): ";
                int dbChoice;
                cin >> dbChoice;

                if (dbChoice >= 1 && dbChoice <= numDatabases) 
                {
                    obj[dbChoice - 1].printStudents(); // Print all student information
                } 
                else 
                {
                    cout << "Invalid database number." << endl;
                }
            break;

            // Implement other functionalities (optional)

            case 4:
                cout << "Exiting program..." << endl;
            return 0;

            default:
                cout << "Invalid choice. Please try again." << endl;
            break;
        }

        cout << "<< user interface >>>" << endl << endl;
        cout << "[1] Add Data-base" << endl;
        cout << "[2] Show all the names"<<endl;
        cout << "[4] Exit the program"<<endl;
        // ... Include options for Delete, Reset (if applicable), and Exit
        cin >> choice;
    }

    return 0;
}
