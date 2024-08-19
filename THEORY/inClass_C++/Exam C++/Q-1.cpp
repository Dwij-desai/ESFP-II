#include <iostream>

using namespace std;

class football
{
private:
    string Pname="";
    string Pposition;
    string PmasterSkill;
    int Page;
    string Pcontary;
public:
    football()
    {
        Pname="";
        Pposition="";
        PmasterSkill="";
        Page=0;
        Pcontary="";
    };

    void Playerinfo()
    {
        cout<<"Player-name  Player-position  Player-mastery-skill  Player-age  Player-contary\n";
        // cin>>Pname;
        // cout<<"\t";
        // cin>>Pposition;
        cin>>Pname>>Pposition>>PmasterSkill>>Page>>Pcontary;
        
    }

    void Display()
    {
        cout<<endl<<Pname<<"\t"<<Pposition<<"\t"<<PmasterSkill<<"\t"<<"\t"<<Page<<"\t"<<Pcontary;
    }

    friend void find(football &obj);
};

void find(football &obj)
{
    cout<<"Enter Player age";
    
    
        for(int i=0;i<5;i++)
        {
            cout<<"Enter the detail of player\n";
            player[i].Display();
            
        }
}


int main()
{
    int x=0;
    football player[5];

    cout<<"Enter 1 for input \n 2 for display";
    cin>>x;

    switch (x)
    {
    case 1:
            for(int i=0;i<5;i++)
    {
        cout<<"Enter the detail of player\n";
        player[i].Playerinfo();
    }
    break;

    case 2:
    //Display all the player    
    for(int i=0;i<5;i++)
    {
        cout<<"Enter the detail of player\n";
        player[i].Display();
    }
    break;

    case 3:

    break;
    
    default:

    cout<<"Enter right value";
        break;
    }




    

    return 0;
}