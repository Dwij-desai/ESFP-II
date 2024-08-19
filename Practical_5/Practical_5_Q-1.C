#include <iostream>

using namespace std;

namespace Bus_fare
{
    int distance = 0;
    int fare = 0;

    int data_input()
    {
        cout << "What distance will you travel?\n";
        cin >> distance;

        if (distance >=0 && distance <= 20)
        {
            fare = distance * 1;

            cout << "\n" << "Your total fare is:" << "\t"<< fare;
        }
        else if (distance >=21 && distance <= 40)
        {
            fare = distance * 2;

            cout << "\n" << "Your total fare is:" << "\t"<< fare;
        }
        else if (distance >=41 && distance <= 60)
        {
            fare = distance * 3;

            cout << "\n" << "Your total fare is:" << "\t"<< fare;
        }
        else if (distance >=61 && distance <= 80)
        {
            fare = distance * 4;

            cout << "\n" << "Your total fare is:" << "\t"<< fare;
        }
        else if (distance >=81 && distance <= 100)
        {
            fare = distance * 5;

            cout << "\n" << "Your total fare is:" << "\t"<< fare;
        }
        else if (distance >=101)
        {
            fare = distance * 6;

            cout << "\n" <<"Your total fare is:" << "\t"<< fare;
        }
        
    }
}; // namespace Bus_fare;


int main()
{
    using namespace Bus_fare;
    data_input(); 
}