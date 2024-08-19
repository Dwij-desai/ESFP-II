#include <iostream>
#include <string>

using namespace std;

class Student {
private:
    string name;
public:
    Student() 
    {}

    Student(string n) : name(n) 
    {}

    string getName() const 
    {
        return name; 
    }

    void setName(string n) 
    { 
        name = n; 
    }
};

void swap(Student& a, Student& b) {
    Student temp = a;
    a = b;
    b = temp;
}

void sortNames(Student arr[], int n) 
{
    for (int i = 0; i < n-1; ++i) 
    {
        for (int j = 0; j < n-i-1; ++j)
        {
            if (arr[j].getName() > arr[j+1].getName()) 
            {
                swap(arr[j], arr[j+1]);
            }
        }
    }
}

int main() 
{
    const int SIZE = 5;
    Student students[SIZE];

    cout << "Enter " << SIZE << " names: ";
    for (int i = 0; i < SIZE; ++i)
    {
        string name;
        cin >> name;
        students[i].setName(name);
    }

    sortNames(students, SIZE);

    cout << "Names in ascending order: ";
    for (int i = 0; i < SIZE; ++i) 
    {
        cout << students[i].getName() << " ";
    }
    cout << endl;

    cout << "Names in descending order: ";
    for (int i = SIZE - 1; i >= 0; --i) 
    {
        cout << students[i].getName() << " ";
    }
    cout << endl;

    return 0;
}
