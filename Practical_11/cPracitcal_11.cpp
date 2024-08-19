#include <iostream>
#include <string>
using namespace std;

const int MAX_STUDENTS = 100;

class Student {
public:
    string Name;
    int enroll_no;
    string course;
    int sem;

    virtual void readData() {
        cout << "Enter student name: ";
        getline(cin, Name);
        cout << "Enter enrollment number: ";
        cin >> enroll_no;
        cin.ignore();
        cout << "Enter course: ";
        getline(cin, course);
        cout << "Enter semester: ";
        cin >> sem;
    }

    virtual void displayData() const {
        cout << "Name: " << Name << endl;
        cout << "Enrollment Number: " << enroll_no << endl;
        cout << "Course: " << course << endl;
        cout << "Semester: " << sem << endl;
    }

    virtual void deleteData() {}
    virtual void updateData() {}
    virtual void searchData(int enroll_no) const {}
    virtual void displayAllData(bool ascending) const {}
};

class StudentManager : public Student {
private:
    Student students[MAX_STUDENTS];
    int numStudents;

public:
    StudentManager() : numStudents(0) {}

    void readData() override {
        if (numStudents < MAX_STUDENTS) {
            Student newStudent;
            newStudent.Student::readData();
            students[numStudents] = newStudent;
            numStudents++;
        } else {
            cout << "Maximum number of students reached." << endl;
        }
    }

    void displayData() const override {
        for (int i = 0; i < numStudents; i++) {
            students[i].displayData();
            cout << endl;
        }
    }

    void deleteData() override {
        int studentEnroll;
        cout << "Enter student enrollment number to delete: ";
        cin >> studentEnroll;

        for (int i = 0; i < numStudents; i++) {
            if (students[i].enroll_no == studentEnroll) {
                for (int j = i; j < numStudents - 1; j++) {
                    students[j] = students[j + 1];
                }
                numStudents--;
                cout << "Student deleted successfully." << endl;
                return;
            }
        }

        cout << "Student not found." << endl;
    }

    void updateData() override {
        int studentEnroll;
        cout << "Enter student enrollment number to update: ";
        cin >> studentEnroll;

        for (int i = 0; i < numStudents; i++) {
            if (students[i].enroll_no == studentEnroll) {
                Student updatedStudent;
                updatedStudent.readData();
                students[i] = updatedStudent;
                cout << "Student updated successfully." << endl;
                return;
            }
        }

        cout << "Student not found." << endl;
    }

    void searchData(int searchEnroll) const override {
        for (int i = 0; i < numStudents; i++) {
            if (students[i].enroll_no == searchEnroll) {
                students[i].displayData();
                return;
            }
        }

        cout << "Student not found." << endl;
    }

    void displayAllData(bool ascending) const override {
        Student sortedStudents[MAX_STUDENTS];
        for (int i = 0; i < numStudents; i++) {
            sortedStudents[i] = students[i];
        }

        for (int i = 0; i < numStudents - 1; i++) {
            for (int j = 0; j < numStudents - i - 1; j++) {
                if (ascending) {
                    if (sortedStudents[j].enroll_no > sortedStudents[j + 1].enroll_no) {
                        Student temp = sortedStudents[j];
                        sortedStudents[j] = sortedStudents[j + 1];
                        sortedStudents[j + 1] = temp;
                    }
                } else {
                    if (sortedStudents[j].enroll_no < sortedStudents[j + 1].enroll_no) {
                        Student temp = sortedStudents[j];
                        sortedStudents[j] = sortedStudents[j + 1];
                        sortedStudents[j + 1] = temp;
                    }
                }
            }
        }

        for (int i = 0; i < numStudents; i++) {
            sortedStudents[i].displayData();
            cout << endl;
        }
    }
};

int main() {
    StudentManager manager;

    int choice;
    do {
        cout << "\nStudent Management System\n";
        cout << "1. Read Student Data\n";
        cout << "2. Display Student Data\n";
        cout << "3. Delete Student Data\n";
        cout << "4. Update Student Data\n";
        cout << "5. Search Student Data\n";
        cout << "6. Display All Students (Ascending)\n";
        cout << "7. Display All Students (Descending)\n";
        cout << "8. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        cin.ignore();

        switch (choice) {
            case 1:
                manager.readData();
                break;
            case 2:
                manager.displayData();
                break;
            case 3:
                manager.deleteData();
                break;
            case 4:
                manager.updateData();
                break;
            case 5:
                {
                    int studentEnroll;
                    cout << "Enter student enrollment number to search: ";
                    cin >> studentEnroll;
                    manager.searchData(studentEnroll);
                    break;
                }
            case 6:
                manager.displayAllData(true);
                break;
            case 7:
                manager.displayAllData(false);
                break;
            case 8:
                cout << "Exiting program..." << endl;
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    } while (choice != 8);

    return 0;
}