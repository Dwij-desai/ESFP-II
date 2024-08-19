#include <iostream>
#include <string>

using namespace std;

// Base class
class Student {
protected:
    string name;
    int semester;
    int enrollmentNumber;
public:
    Student(string n, int sem, int enroll) : name(n), semester(sem), enrollmentNumber(enroll) {}

    // Function to display basic information
    void displayInfo() {
        cout << "Name: " << name << endl;
        cout << "Semester: " << semester << endl;
        cout << "Enrollment Number: " << enrollmentNumber << endl;
    }
};

// Derived class
class Marksheet : public Student {
private:
    int totalMarks;
public:
    Marksheet(string n, int sem, int enroll, int total) : Student(n, sem, enroll), totalMarks(total) {}

    // Function to display marksheet
    void displayMarksheet() {
        displayInfo(); // Display basic information
        cout << "Total Marks: " << totalMarks << endl;
    }
};

int main() {
    // Create an object of the Marksheet class
    Marksheet student("John Doe", 5, 123456, 450);

    // Display the marksheet
    student.displayMarksheet();

    return 0;
}
