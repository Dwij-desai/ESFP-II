// #include<iostream>
// using namespace std;

// namespace A 
// {
//     int a,b,c;
//     void sum() 
//     {
//         cout<<"Enter two number:";
//         cin>>a>>b;
//         c=a+b;
//         cout<<"Sum of two number:"<<c;
//     }
// }
// int main() 
// {
//     // wrong:- A.sum();
//     A :: sum();
//     return 0;
// }

// ---------------------------------------------------------------------------

#include<iostream>
int main() 
{
    //wrong:- using std::int;
    using std::string;
    using std::cout;
    using std::endl;
    string uname="Ganpat University";
    string caddress="City Office: Ahmedabad";
    //wrong:- cout<<collegeId<<endl;
    cout<<uname<<endl;
    cout<<caddress<<endl;
    return 0;
}
