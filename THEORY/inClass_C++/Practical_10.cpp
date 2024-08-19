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

            for (int i = 0 ; i<5 ; i++)
            {
                cout << i+1 << ". " ;
                cin>>sender1.name1[i];            
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

int main()
{
    overload obj[2]; //making object array(2 objects)
    int choice=0;
    int choice2=0;

    while(true == 1)
    {
        cout<<endl<<endl<<"<<< User INTERFACE >>>"<<endl<<endl;
        cout<<"[1] Input for 5 names in 2 groups"<<endl;
        cout<<"[2] Display the 5 names for the 2 groups"<<endl;
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
                cin>>choice2;
                cin.ignore();

                switch (choice2)
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

            case 0:
                cout<<endl<<"Exiting Program...";
            return 0;
            
            default:
                cout<<"\tPlace enter right Numaric value";
            break;
        }
    }
    return 0;
}