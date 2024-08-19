#include <iostream>

using namespace std;

namespace number
{
    int user_input = 0;
    int fare = 0;
    int n,digit,rev = 0;
    int originalNum, remainder, result = 0;

    int data_input()
    {

        cout << "Enter any 5 digit integer\n";
        cin >> user_input;
    }

    int palindrome()
    {

        data_input();

            n=user_input;
    
        do
        {
            digit = user_input % 10;
            rev = (rev * 10)+ digit;
            user_input = user_input / 10;
    
        } while(user_input != 0);

        cout << "The reverse of the number is: " << rev << endl;

        if (n == rev)
            cout << "The number is a palindrome.\n\n";
        else
        {
            cout << "The number is not a palindrome.\n\n";
        }

    }

    int Armstrong()
    {
        data_input();
        
        originalNum = user_input;

        while (originalNum != 0) 
        {
        // remainder contains the last digit
        remainder = originalNum % 10;
        
        result += remainder * remainder * remainder;
        
        // removing last digit from the orignal number
        originalNum /= 10;
        }

        if (result == user_input)
        {
            cout << user_input << " is an Armstrong number.\n\n";
        }
        else
        {
            cout << user_input << " is not an Armstrong number.\n\n";
        }

    }
};

int main()
{
    using std::cout;
    using std::cin;
    int opition;

    for(;;)
    {
        cout<<"Enter <1> for Palindrome\nEnter <2> for Armstrong\nEnter <3> to exit\n";
        cin>>opition;

        switch (opition)
        {
            case 1:
                number :: palindrome();
            break;

            case 2:
                number :: Armstrong();
            break;
            
            case 3:
                return 1;
            break;

            default:
                cout<<"Enter right number\n";
            break;
        }
    }
    return 0;

}