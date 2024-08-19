#include<iostream>
using namespace std;

class student 
{
private:
    int x, y;
public:
    friend void display(const student &obj);

    student(int a, int b)
    { 
        x = a; 
        y = b; 
        cout << "\nvalue of x and y=" << x << "\t" << y; 
    }
};

void display(const student &obj)
{
    cout << "\nValue of x and y=" << obj.x << "\t" << obj.y; 
}

int main() 
{
    student obj(10, 20); 
    display(obj);
    return 0;
}

//---------------------------------------------------class------------------------------------------//

#include<iostream>
using namespace std;

class student 
{
private:
    int x, y;
public:
    student(int a, int b)
    { 
        x = a; 
        y = b; 
        cout << "\nvalue of x and y=" << x << "\t" << y; 
    }

    void display() const
    {
        cout << "\nValue of x and y=" << x << "\t" << y; 
    }
};

int main() 
{
    student obj(10, 20); 
    obj.display();
    return 0;
}
