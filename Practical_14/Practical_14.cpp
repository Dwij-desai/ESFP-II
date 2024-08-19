#include <iostream>
#include <fstream>
#include <string>

using namespace std;

class Student
{
public:
    string Name;
    int enroll_no;
    string course;
    int sem;

public:
    void input()
    {
        cout << "Enter name: ";
        cin >> Name;
        cout << "Enter enrollment number: ";
        cin >> enroll_no;
        cout << "Enter course: ";
        cin >> course;
        cout << "Enter semester: ";
        cin >> sem;
    }

    void display()
    {
        cout << "Name: " << Name << endl;
        cout << "Enrollment Number: " << enroll_no << endl;
        cout << "Course: " << course << endl;
        cout << "Semester: " << sem << endl;
    }

    string getName()
    {
        return Name;
    }

    int getEnrollmentNumber()
    {
        return enroll_no;
    }

    string getCourse()
    {
        return course;
    }

    int getSemester()
    {
        return sem;
    }
};

void addData()
{
    Student stu;
    stu.input();

    ofstream file("data.bin", ios::app | ios::binary);
    if (file.is_open())
    {
        file << stu.getName() << " " << stu.getEnrollmentNumber() << " " << stu.getCourse() << " " << stu.getSemester() << endl;
        file.close();
        cout << "Data added successfully!" << endl;
    }
    else
    {
        cout << "Unable to open file." << endl;
    }
}

void viewData()
{
    ifstream file("data.bin", ios::binary);
    if (file.is_open())
    {
        string name;
        int enroll_no;
        string course;
        int sem;
        while (file >> name >> enroll_no >> course >> sem)
        {
            cout << "Name: " << name << ", Enrollment Number: " << enroll_no << ", Course: " << course << ", Semester: " << sem << endl;
        }
        file.close();
    }
    else
    {
        cout << "Unable to open file." << endl;
    }
}

void deleteData()
{
    string name;
    cout << "Enter name to delete: ";
    cin >> name;

    ifstream file("data.bin");
    if (file.is_open())
    {
        ofstream temp("temp.bin");
        string n;
        int enroll_no;
        string course;
        int sem;
        while (file >> n >> enroll_no >> course >> sem)
        {
            if (n != name)
            {
                temp << n << " " << enroll_no << " " << course << " " << sem << endl;
            }
        }
        file.close();
        temp.close();
        remove("data.bin");
        rename("temp.bin", "data.bin");
        cout << "Data deleted successfully!" << endl;
    }
    else
    {
        cout << "Unable to open file." << endl;
    }
}

void updateData()
{
    string name;
    cout << "Enter name to update: ";
    cin >> name;

    ifstream file("data.bin");
    if (file.is_open())
    {
        ofstream temp("temp.bin");
        string n;
        int enroll_no;
        string course;
        int sem;
        while (file >> n >> enroll_no >> course >> sem)
        {
            if (n != name)
            {
                temp << n << " " << enroll_no << " " << course << " " << sem << endl;
            }
            else
            {
                Student stu;
                stu.input();
                temp << stu.getName() << " " << stu.getEnrollmentNumber() << " " << stu.getCourse() << " " << stu.getSemester() << endl;
            }
        }
        file.close();
        temp.close();
        remove("data.bin");
        rename("temp.bin", "data.bin");
        cout << "Data updated successfully!" << endl;
    }
    else
    {
        cout << "Unable to open file." << endl;
    }
}

void searchData()
{
    string name;
    cout << "Enter name to search: ";
    cin >> name;

    ifstream file("data.bin");
    if (file.is_open())
    {
        string n;
        int enroll_no;
        string course;
        int sem;
        bool found = false;
        while (file >> n >> enroll_no >> course >> sem)
        {
            if (n == name)
            {
                cout << "Name: " << n << ", Enrollment Number: " << enroll_no << ", Course: " << course << ", Semester: " << sem << endl;
                found = true;
                break;
            }
        }
        file.close();
        if (!found)
        {
            cout << "Data not found." << endl;
        }
    }
    else
    {
        cout << "Unable to open file." << endl;
    }
}

int main() {
    int choice;
    do
    {
        cout << "1. Add data" << endl;
        cout << "2. View data" << endl;
        cout << "3. Delete data" << endl;
        cout << "4. Update data" << endl;
        cout << "5. Search data" << endl;
        cout << "6. Sort data" << endl;
        cout << "0. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        Student stu[10]; // Move the declaration and initialization here

        switch (choice)
        {
            case 1:
                addData();
            break;
            case 2:
                viewData();
            break;
            case 3:
                deleteData();
            break;
            case 4:
                updateData();
            break;
            case 5:
                searchData();
            break;
            case 6:
            {
                ifstream file("data.bin");
                if (file.is_open())
                {
                    Student stu[10];
                    int count = 0;

                    // Read data into array
                    while (count < 10 && file >> stu[count].Name >> stu[count].enroll_no >> stu[count].course >> stu[count].sem)
                    {
                        count++;
                    }
                    file.close();

                    // Sort the array based on name
                    int input;
                    cout << "1. Ascending." << endl;
                    cout << "2. Descending." << endl;
                    cout << "Enter choice: ";
                    cin >> input;

                    Student temp;
                    for (int i = 0; i < count; i++)
                    {
                        for (int j = i + 1; j < count; j++)
                        {
                            string comp = stu[i].Name;
                            string comp1 = stu[j].Name;
                            if ((comp.compare(comp1) > 0 && input == 1) || (comp.compare(comp1) < 0 && input == 2))
                            {
                                temp = stu[i];
                                stu[i] = stu[j];
                                stu[j] = temp;
                            }
                        }
                    }

                    // Display the sorted array
                    for (int i = 0; i < count; i++)
                    {
                        cout << "Name: " << stu[i].Name << ", Enrollment Number: " << stu[i].enroll_no << ", Course: " << stu[i].course << ", Semester: " << stu[i].sem << endl;
                    }
                }
                else
                {
                    cout << "Unable to open file." << endl;
                }
                break;
            }

            case 0:
                cout <<"Exiting..." << endl;
            break;
            default:
                cout << "Invalid choice. Please try again." << endl;
            break;
        }
    } while (choice != 0);
    return 0;
}