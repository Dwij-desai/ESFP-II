#include <iostream>
#include <string>
#include <cstring>

using namespace std;

class overload
{
    private:
    string name1[5] , name2[5];

    public:

    overload()
    {}

    void info5(overload &sender1)
    {
        for(int i=0; i<2 ; i++)
        {
            cout<<endl<<"Enter any 5 values (group"<<i+1<<"): "<<endl;

            for (int ii = 0 ; ii<5 ; ii++)
            {
                cout<<ii+1<<". ";
                if(i == 0)
                {
                    cin>>sender1.name1[i];
                }
                else
                {
                    cin>>sender1.name2[i]; 
                }
            }
        }
    } 

};

int main()
{
    overload obj[2]; //making object array(2 objects)
    int choice=0;

    while(true == 1)
    {
        cout<<endl<<endl<<"<<< User INTERFACE >>>"<<endl<<endl;
        cout<<"[1] Input for 5 names in 2 groups"<<endl;
        cout<<"[0] Exit the program"<<endl<<endl;

        cout<<"Enter number here:  ";
        cin>>choice;
        cin.ignore();

        switch (choice)
        {
        case 1:
            obj[0].info5(obj[0]);
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