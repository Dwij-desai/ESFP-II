#include <iostream>
#include <string>
#include <cstring>

using namespace std;

class overload
{
private:
    string name1[5];

public:

    overload()
    {}

    void getname(overload &sender1)
    {
        for (int i = 0; i < 5; i++)
        {
            cout << i + 1 << ".";
            cout << " "; // Add a space after the full stop
            cin >> sender1.name1[i];

        }
    }


    void DisplayName(overload &sender1)
    {
        for (int i = 0 ; i<5 ; i++)
        {
            cout << i+1 << ". " ;
            cout<<sender1.name1[i]<<endl;
        }
    }

};

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
    overload obj[2]; //making object array(2 objects)
    prac10_tasks obj1, obj2, obj3, obj4; //3 and 4 is for string mangment
    int choice, exit = 1;

    while (exit != 0)
    {
        cout<<endl<<endl<<"<<< User INTERFACE >>>"<<endl<<endl;
        cout<<"[1] Input for 5 names in 2 groups"<<endl;
        cout<<"[2] Display the 5 names for the 2 groups"<<endl;
        cout<<"[3] Add 2 Numbers"<<endl;
        cout<<"[4] Add 2 Strings"<<endl;
        cout<<"[5] Compare 5 pairs of strings"<<endl;
        cout<<"[6] Search in String Array of object 3"<<endl;
        cout<<"[7] Search in String Array of object 4"<<endl;
        cout<<"[8] Display both Strings Arrays in Ascending Order"<<endl;
        cout<<"[9] Display both Strings Arrays in Descending Order"<<endl;
        cout<<"[0] Exit the program"<<endl<<endl;

        cout<<"Enter number here:  ";
        cin>>choice;
        cin.ignore();

        switch (choice)
        {
            case 1:

                cout<<endl<<"Enter any 5 values (Of object 1)"<<endl;
                obj[0].getname(obj[0]);

                cout<<endl<<"Enter any 5 values (Of object 2)"<<endl;
                obj[1].getname(obj[1]);

            break;

            case 2:


                cout<<"Enter the object wanted \n\t[1] for object 1 \n\t[2] for object 2 "<<endl;
                cin>>choice;
                cin.ignore();

                switch (choice)
                {
                    case 1:
                        cout<<endl<<"Displaying 5 values from object 1:"<<endl;
                        obj[0].DisplayName(obj[0]);
                    break;

                    case 2:
                        cout<<endl<<"Displaying 5 values from object 2:"<<endl;
                        obj[1].DisplayName(obj[1]);
                    break;

                    default:
                        cout<<"ERROR { Wrong value entered }";
                    break;
                }

            break;

            case 3:
                obj1 + obj2;
            break;

            case 4:
                obj1 - obj2;
            break;

            case 3:
                obj3.task(obj3, obj1);
            break;

            case 6:
                cout << "Search a string in String Array of Object 3 :-";
                obj3.search(obj3);
            break;

            case 7:
                cout << "Search a string in String Array of Object 4 :-";
                obj4.search(obj4);
            break;

            case 8:
                cout << endl << "String Array of object 3:";
                obj3.sortAscending(obj3);
                obj3.display(obj3);
                cout << endl;
                cout << endl << "String Array of object 4:";
                obj4.sortAscending(obj4);
                obj4.display(obj4);
            break;

            case 9:
                cout << endl << "String Array of object 3:";
                obj3.sortAscending(obj3);
                obj3.revDisplay(obj3);
                cout << endl;
                cout << endl << "String Array of object 4:";
                obj4.sortAscending(obj4);
                obj4.revDisplay(obj4);
            break;

            case 0:
                cout<<endl<<"Exiting Program...";
                exit = 0;
            break;

            default:
                cout<<"\tPlace enter right Numaric value";
            break;
        }
    }
    return 0;
}
