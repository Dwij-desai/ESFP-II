#include <iostream>
#include <string>
#include <fstream>

using namespace std;

class Student {
public:
    int Sid;
    string Sname;
    string Course;
    string Branch;
    int Semester;
    double CourseFee;

    Student() {}

    friend void recordStudentInformation(Student& student);
    friend void displayStudentRecords(Student& student);
    friend void updateStudentRecord(Student& student);
    friend void deleteStudentRecords(Student& student);
    friend void searchStudentRecords(Student& student);

    friend void printStudentInfo(Student& student);
};

void recordStudentInformation(Student& student) {
    
    ofstream manage;
    manage.open("student.txt", ios::app);
    manage << "Student ID: " << student.Sid << endl;
    manage << "Student Name: " << student.Sname << endl;
    manage << "Course: " << student.Course << endl;
    manage << "Branch: " << student.Branch << endl;
    manage << "Semester: " << student.Semester << endl;
    manage << "Course Fee: " << student.CourseFee << endl;
    manage << "--------------------------" << endl;
    manage.close();
}

void updateStudentRecord(Student& student) {
    bool found = false;
    int id;
    cout << "Enter the Student ID to update: ";
    cin >> id;

    ifstream manage;
    ofstream temp;
    manage.open("student.txt");
    temp.open("temp.txt");

    string content;
    while (getline(manage, content)) {
        if (content.find("Student ID: " + to_string(id)) != string::npos) {
            found = true;
            cout << "Enter new Student Name: ";
            cin.ignore();
            getline(cin, student.Sname);

            cout << "Enter new Course: ";
            getline(cin, student.Course);

            cout << "Enter new Branch: ";
            getline(cin, student.Branch);

            cout << "Enter new Semester: ";
            cin >> student.Semester;

            cout << "Enter new Course Fee: ";
            cin >> student.CourseFee;

            temp << "Student ID: " << student.Sid << endl;
            temp << "Student Name: " << student.Sname << endl;
            temp << "Course: " << student.Course << endl;
            temp << "Branch: " << student.Branch << endl;
            temp << "Semester: " << student.Semester << endl;
            temp << "Course Fee: " << student.CourseFee << endl;
            temp << "--------------------------" << endl;
        } else {
            temp << content << endl;
        }
    }

    manage.close();
    temp.close();

    remove("student.txt");
    rename("temp.txt", "student.txt");

    if (found) {
        cout << "Student record updated successfully!" << endl;
    } else {
        cout << "Student record not found!" << endl;
    }
}

void displayStudentRecords(Student& student) {
    ifstream manage;
    manage.open("student.txt");
    string content;
    while (getline(manage, content)) {
        cout << content << endl;
    }
    manage.close();
}


void deleteStudentRecords(Student& student) {
    bool found = false;
    int id;
    cout << "Enter the Student ID to delete: ";
    cin >> id;

    ifstream manage;
    ofstream temp;
    manage.open("student.txt");
    temp.open("temp.txt");

    string content;
    while (getline(manage, content)) {
        if (content.find("Student ID: " + to_string(id)) != string::npos) {
            found = true;
            continue;
        }
        temp << content << endl;
    }

    manage.close();
    temp.close();

    remove("student.txt");
    rename("temp.txt", "student.txt");

    if (found) {
        cout << "Student record deleted successfully!" << endl;
    } else {
        cout << "Student record not found!" << endl;
    }
}


void searchStudentRecords(Student& student) {
    bool found = false;
    int id;
    cout << "Enter the Student ID to search: ";
    cin >> id;

    ifstream manage;
    manage.open("student.txt");
    string content;
    while (getline(manage, content)) {
        if (content.find("Student ID: " + to_string(id)) != string::npos) {
            found = true;
            cout << "Student record found!" << endl;
            cout << content << endl;
            break;
        }
    }

    manage.close();

    if (!found) {
        cout << "Student record not found!" << endl;
    }
}


void printStudentInfo(Student& student) {
    cout << "Student ID: " << student.Sid << endl;
    cout << "Student Name: " << student.Sname << endl;
    cout << "Course: " << student.Course << endl;
    cout << "Branch: " << student.Branch << endl;
    cout << "Semester: " << student.Semester << endl;
    cout << "Course Fee: " << student.CourseFee << endl;
}

void takeStudentInfo(Student& student) {
    cout << "Enter Student ID: ";
    cin >> student.Sid;
    cin.ignore();

    cout << "Enter Student Name: ";
    getline(cin, student.Sname);

    cout << "Enter Course: ";
    getline(cin, student.Course);

    cout << "Enter Branch: ";
    getline(cin, student.Branch);

    cout << "Enter Semester: ";
    cin >> student.Semester;

    cout << "Enter Course Fee: ";
    cin >> student.CourseFee;
}

int main() {
    Student student;

    int choice;
    cout<<"1. Add Student Records"<<endl;
    cout<<"2. Display Student Records"<<endl;
    cout<<"3. Update Student Record "<<endl;
    cout<<"4. Delete Student Records"<<endl;
    cout<<"5. Search Student Records"<<endl<<endl;
    cout << "Enter your choice: ";
    cin >> choice;

    switch (choice) {
        case 1:
            for(int i=0;i<5;i++){
                takeStudentInfo(student);
                recordStudentInformation(student);
            }
            break;
        case 2:
            displayStudentRecords(student);
            break;
        case 3:
            updateStudentRecord(student);
            break;
        case 4:
            deleteStudentRecords(student);
            break;
        case 5:
            searchStudentRecords(student);
            break;
        default:
            cout << "Invalid choice!" << endl;
            break;
    }

    return 0;
}