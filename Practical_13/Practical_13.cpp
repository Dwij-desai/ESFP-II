#include <iostream>
#include <string>
using namespace std;

const int MAX_STUDENTS = 100;

class StudentManager;
class StudentDatabase;

class Student {
    friend class StudentManager;
    friend class StudentDatabase;

private:
    string Name;
    int enroll_no;
    int sem;
    bool isPresent;
    string course;

public:
    Student() : isPresent(false) {}
    ~Student() {
        cout << "Destroying student: " << Name << endl;
    }

    void markAttendance(bool present) {
        isPresent = present;
        if (!isPresent) {
            sem--;  // Decrement semester for absent students
        }
    }

    void resetSem() {
        sem = 0;
    }

    void increaseSem(int amount) {
        sem += amount;
    }

    bool operator>(const Student& stu) {
        return Name > stu.Name;
    }

    bool operator<(const Student& stu) {
        return enroll_no < stu.enroll_no;
    }

    bool operator==(const Student& stu) {
        return sem == stu.sem;
    }

    friend ostream& operator<<(ostream& out, const Student& stu) {
        out << "Name: " << stu.Name << endl;
        out << "Enrollment Number: " << stu.enroll_no << endl;
        out << "Semester: " << stu.sem << endl;
        out << "Course: " << stu.course << endl;
        return out;
    }

    friend istream& operator>>(istream& in, Student& stu) {
        cout << "Enter student name: ";
        in >> stu.Name;
        cout << "Enter enrollment number: ";
        in >> stu.enroll_no;
        cout << "Enter semester: ";
        in >> stu.sem;
        cout << "Enter course: ";
        in >> stu.course;
        return in;
    }

    void setCourse(const string& crs) {
        course = crs;
    }

    string getAttendanceStatus() const {
        return isPresent ? "Present" : "Absent";
    }
};

class StudentManager {
private:
    Student students[MAX_STUDENTS];
    int numStudents;

public:
    StudentManager() : numStudents(0) {}
    ~StudentManager() {
        cout << "Destroying StudentManager..." << endl;
    }

    int getNumStudents() const {
        return numStudents;
    }

    const Student& getStudent(int index) const {
        return students[index];
    }

    void addStudent(const Student& stu) {
        if (numStudents < MAX_STUDENTS) {
            students[numStudents] = stu;
            numStudents++;
        } else {
            cout << "Maximum number of students reached." << endl;
        }
    }

    void markAttendance(int enroll, bool present) {
        for (int i = 0; i < numStudents; ++i) {
            if (students[i].enroll_no == enroll) {
                students[i].markAttendance(present);
                cout << "Attendance marked for student with Enrollment Number " << enroll << endl;
                return;
            }
        }
        cout << "Student not found with Enrollment Number " << enroll << endl;
    }

    void resetSem(int enroll) {
        for (int i = 0; i < numStudents; ++i) {
            if (students[i].enroll_no == enroll) {
                students[i].resetSem();
                cout << "Semester reset for student with Enrollment Number " << enroll << endl;
                return;
            }
        }
        cout << "Student not found with Enrollment Number " << enroll << endl;
    }

    void increaseSem(int enroll, int amount) {
        for (int i = 0; i < numStudents; ++i) {
            if (students[i].enroll_no == enroll) {
                students[i].increaseSem(amount);
                cout << "Semester increased for student with Enrollment Number " << enroll << endl;
                return;
            }
        }
        cout << "Student not found with Enrollment Number " << enroll << endl;
    }
};

class StudentDatabase {
public:
    void displayByCategory(const StudentManager& stuManager) {
        int choice;
        cout << "Display students by category:" << endl;
        cout << "1. Computer Science" << endl;
        cout << "2. Mechanical Engineering" << endl;
        cout << "3. Electrical Engineering" << endl;
        cout << "Enter choice: ";
        cin >> choice;

        cout << "Students:" << endl;
        for (int i = 0; i < stuManager.getNumStudents(); ++i) {
            const Student& student = stuManager.getStudent(i);
            if (choice == 1 && student.course == "Computer Science") {
                cout << student << "Attendance: " << student.getAttendanceStatus() << endl;
            } else if (choice == 2 && student.course == "Mechanical Engineering") {
                cout << student << "Attendance: " << student.getAttendanceStatus() << endl;
            } else if (choice == 3 && student.course == "Electrical Engineering") {
                cout << student << "Attendance: " << student.getAttendanceStatus() << endl;
            }
        }
    }
};

int main() {
    StudentManager stuManager;
    StudentDatabase stuDatabase;

    int choice;

    do {
        cout << "\nStudent Management System\n";
        cout << "1. Enter Student Details\n";
        cout << "2. Display All Students\n";
        cout << "3. Mark Attendance\n";
        cout << "4. Reset Semester\n";
        cout << "5. Increase Semester\n";
        cout << "6. Display Students by Category\n";
        cout << "7. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1: {
            Student stu;
            cin >> stu;
            stuManager.addStudent(stu);
            break;
        }
        case 2: {
            cout << "\nStudent Details:" << endl;
            for (int i = 0; i < stuManager.getNumStudents(); ++i) {
                cout << stuManager.getStudent(i) << "Attendance: " << stuManager.getStudent(i).getAttendanceStatus() << endl;
            }
            break;
        }
        case 3: {
            int studentEnroll;
            bool present;
            cout << "\nEnter student enrollment number to mark attendance: ";
            cin >> studentEnroll;
            cout << "Enter 1 for present, 0 for absent: ";
            cin >> present;
            stuManager.markAttendance(studentEnroll, present);
            break;
        }
        case 4: {
            int studentEnroll;
            cout << "\nEnter student enrollment number to reset semester: ";
            cin >> studentEnroll;
            stuManager.resetSem(studentEnroll);
            break;
        }
        case 5: {
            int studentEnroll;
            int amount;
            cout << "\nEnter student enrollment number to increase semester: ";
            cin >> studentEnroll;
            cout << "Enter amount to increase: ";
            cin >> amount;
            stuManager.increaseSem(studentEnroll, amount);
            break;
        }
        case 6: {
            stuDatabase.displayByCategory(stuManager);
            break;
        }
        case 7: {
            cout << "Exiting program..." << endl;
            break;
        }
        default:
            cout << "Invalid choice. Please try again." << endl;
        }

    } while (choice != 7);

    return 0;
}