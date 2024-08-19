// #include <iostream>
// #include <string>

// using namespace std;

// class A
// {
//     protected:
//             int a;
//             string b;
//     public:
//        void abc(){
//         cin>>a>>b;
//         cout<<a<<endl<<b;
//        }
        
//        friend class B;
//        friend void xy(A ob){
//         ob.a=10;
//         ob.b="Sumit"; 
//         cout<<endl<<ob.a<<endl<<ob.b;
//        }
// };
// class B{
//     public:
//     A obj1;

//     void R()
//     {
//         obj1.a=23;
//         obj1.b="Helloo";
//         cout<<obj1.a<<endl<<obj1.b;
//     }
// };

// int main()
// {
//     A obj;
//     B obj2;
//     obj2.R();
//     xy(obj);
//     return 0;
// }

#include <iostream>
using namespace std;

int main() {
    int choice;

start:
    cout << "Select an option:" << endl;
    cout << "1. Print 'Hello'" << endl;
    cout << "2. Print 'World'" << endl;
    cout << "3. Exit" << endl;
    cout << "Enter your choice: ";
    cin >> choice;

    switch (choice) {
        case 1:
            cout << "Hello" << endl;
            break;
        case 2:
            cout << "World" << endl;
            break;
        case 3:
            cout << "Exiting..." << endl;
            break;
        default:
            cout << "Invalid choice. Try again." << endl;
            goto start; // jump back to 'start' label
    }

    return 0;
}
