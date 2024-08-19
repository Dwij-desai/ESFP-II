#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

using namespace std;

// Base class with file handling methods
class University {
protected:
    string filename;

public:
    University(const string& filename) : filename(filename) {}

    // Function to write data to file
    void writeToFile(const string& data) {
        ofstream file(filename, ios::app);
        if (file.is_open()) {
            file << data << endl;
            file.close();
        } else {
            cout << "Unable to open file." << endl;
        }
    }

    // Function to read data from file
    string readFromFile() {
        string data;
        ifstream file(filename);
        if (file.is_open()) {
            string line;
            while (getline(file, line)) {
                data += line + "\n";
            }
            file.close();
        } else {
            cout << "Unable to open file." << endl;
        }
        return data;
    }
};

// Class to represent a student
class Student {
public:
    string Name;
    int enroll_no;
    string course;
    int sem;

    // Friend function to allow input/output operations
    friend istream& operator>>(istream& is, Student& s);
    friend ostream& operator<<(ostream& os, const Student& s);
};

// Input/output operator overloads
istream& operator>>(istream& is, Student& s) {
    cout << "Enter Name: ";
    is >> s.Name;
    cout << "Enter Enrollment Number: ";
    is >> s.enroll_no;
    cout << "Enter Course: ";
    is >> s.course;
    cout << "Enter Semester: ";
    is >> s.sem;
    return is;
}

ostream& operator<<(ostream& os, const Student& s) {
    os << s.Name << " " << s.enroll_no << " " << s.course << " " << s.sem;
    return os;
}

// Template function module
class StudentModule : public University {
public:
    StudentModule(const string& filename) : University(filename) {}

    // Function to display data based on user's choice
    template <typename T>
    void displayData(const T& data) {
        cout << data << endl;
    }
};

// Template class module
template <typename T>
class TemplateClassModule : public University {
public:
    TemplateClassModule(const string& filename) : University(filename) {}

    // Function to manipulate data (example: sort)
    void manipulateData(T& data) {
        // Implementation based on T
    }
};

int main() {
    // File names for each module
    string templateFunctionFile = "template_function_data.txt";
    string templateClassFile = "template_class_data.txt";

    // Creating objects for each module
    StudentModule tfModule(templateFunctionFile);
    TemplateClassModule<Student> tcModule(templateClassFile);

    // Experimenting with minimum 5 data/records
    for (int i = 1; i <= 5; ++i) {
        // Example: Asking user for data and storing it using template function module
        Student s;
        cin >> s;
        string data = (ostringstream() << s).str();
        tfModule.writeToFile(data);

        // Example: Asking user for data and storing it using template class module
        tcModule.writeToFile(data);
    }

    // Displaying data according to user's choice
    cout << "Choose an option to display data:" << endl;
    cout << "1. Display data from template function module" << endl;
    cout << "2. Display data from template class module" << endl;
    int choice;
    cin >> choice;

    switch (choice) {
        case 1: {
            // Displaying data from template function module
            string data = tfModule.readFromFile();
            tfModule.displayData(data);
            break;
        }
        case 2: {
            // Displaying data from template class module
            string data = tcModule.readFromFile();
            istringstream iss(data);
            Student s;
            while (iss >> s) {
                cout << s << endl;
            }
            break;
        }
        default:
            cout << "Invalid choice." << endl;
    }

    return 0;
}