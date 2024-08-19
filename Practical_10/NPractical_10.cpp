#include <iostream>
#include <string>
#include <cstring>
using namespace std;
class prac10_tasks
{
    public:
    int a, b = 0;
    string x, c[5], d[5];
    bool y[5],z[5];

    prac10_tasks()
    {}

    void operator + (prac10_tasks &obj2)
    {
        cout << "Enter 2 numbers: ";
        cin >> a >> obj2.a;
        task(a, obj2.a);
    }

    void operator - (prac10_tasks &obj2)
    {
        cout << "Enter 2 strings: ";
        cin >> x >> obj2.x;
        task(x, obj2.x);
    }

    void operator > (prac10_tasks &obj)
    {
        for (int i = 0; i < 5; i++)
        {
            y[i] = c[i] > obj.c[i];
        }
    }

    void operator < (prac10_tasks &obj)
    {
        for (int i = 0; i < 5; i++)
        {
            z[i] = c[i] < obj.c[i];
        }
    }

    void task (int &a, int &b)
    {
        cout << endl << "Sum of 2 number = " << (a+b);
    }

    void task (string &a, string &b)
    {
        cout << endl << "Concatenation of 2 strings = " << a << " " << b;
    }

    void task (prac10_tasks &obj3, prac10_tasks &obj4)
    {
        obj3 > obj4;
        obj3 < obj4;
        for (int i = 0; i < 5 ; i++)
        {
            if (y[i])
            {
                cout << endl << obj3.c[i] << " is greater than " << obj4.c[i];
            }
            else if (z[i])
            {
                cout << endl << obj4.c[i] << " is greater than " << obj3.c[i];
            }
            else
            {
                cout << endl << obj3.c[i] << " and " << obj4.c[i] << ", both are equal";
            }
        }
    }

    void getStrings(prac10_tasks &obj)
    {
        cout << "Enter 5 Strings:-";
        for (int i = 0; i < 5; i++)
        {
            cout << endl << i+1 << ") ";

            cin >> obj.c[i];
            obj.d[i] = obj.c[i];
        }
    }

    void display(prac10_tasks &obj)
    {
        for (int i = 0; i < 5; i++)
        {
            cout << endl << i+1 << ") " << obj.c[i];
        }
    }

    void revDisplay(prac10_tasks &obj)
    {
        for (int i = 0; i < 5; i++)
        {
            cout << endl << i+1 << ") " << obj.c[4-i];
        }
    }

    void sortAscending(prac10_tasks &obj)
    {
        string dummy;
        for (int i = 0; i < 5; i++)
        {
            for (int j = 0; j < 4; j++)
            {
                if (obj.c[j] > obj.c[j + 1])
                {
                    dummy = obj.c[j + 1];
                    obj.c[j + 1] = obj.c[j];
                    obj.c[j] = dummy;
                }
            }
        }
    }

    void search(prac10_tasks &obj)
    {
        string str;
        cout << endl << "Enter the string you want to find: ";
        cin >> str;

        for (int i = 0; i < 5; i++)
        {
            if (str == obj.d[i])
            {
                cout << endl << "M A T C H F O U N D";
                cout << endl << "The searched word " << str << " is present in the search array";
                return;
            }
        }
        cout << endl << "M A T C H N O T F O U N D";
        cout << endl << "The searched word " << str << " is present in the search array";
    }

};

int main()
{
    prac10_tasks obj1, obj2, obj3, obj4; //3 and 4 is for string mangment
    int choice, exit = 1;
    cout << endl;
    obj3.getStrings(obj3);
    obj4.getStrings(obj4);

    while (exit != 0)
    {

        cout <<" \n";
        cout << "Press < 1 > :- to Add 2 Number" << endl;
        cout << "Press < 2 > :- to Add 2 Strings" << endl;
        cout << "Press < 3 > :- to Compare 5 pair of strings" << endl;
        cout << "Press < 4 > :- to Display Both Strings Arrays" << endl;
        cout << "Press < 5 > :- to Search in String Array of object 3" << endl;
        cout << "Press < 6 > :- to Search in String Array of object 4" << endl;
        cout << "Press < 7 > :- to Display both Strings Arrays in Ascending Order" << endl;
        cout << "Press < 8 > :- to Display both Strings Arrays in Descending Order" << endl;
        cout << "Press < 0 > :- to Exit" << endl << endl;
        cout << endl << "Enter Your Choice: ";
        cin >> choice;


        switch (choice)
        {
            case 1:
                obj1 + obj2;
                
            break;

            case 2:
                obj1 - obj2;
                
            break;

            case 3:
                obj3.task(obj3, obj4);
                
            break;

            case 4:
                cout << endl << "String Array of object 3:";
                obj3.display(obj3);
                cout << endl;
                cout << endl << "String Array of object 4:";
                obj4.display(obj4);
                
            break;

            case 5:
                cout << "Search a string in String Array of Object 3 :-";
                obj3.search(obj3);
                
            break;

            case 6:
                cout << "Search a string in String Array of Object 4 :-";
                obj4.search(obj4);
                
            break;

            case 7:
                cout << endl << "String Array of object 3:";
                obj3.sortAscending(obj3);
                obj3.display(obj3);
                cout << endl;
                cout << endl << "String Array of object 4:";
                obj4.sortAscending(obj4);
                obj4.display(obj4);
                
            break;

            case 8:
                cout << endl << "String Array of object 3:";
                obj3.sortAscending(obj3);
                obj3.revDisplay(obj3);
                cout << endl;
                cout << endl << "String Array of object 4:";
                obj4.sortAscending(obj4);
                obj4.revDisplay(obj4);
                
            break;

            case 0:
                cout << endl << "Program exited successfully";
                exit = 0;
            break;

            default:
                cout<<"Wrong data Input(Enter right number)"<<endl;
                
            break;

        }        
    }
}