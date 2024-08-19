#include <iostream>
#include <string>

using namespace std;

int foo()
{
    int val = 42;
    return val;
}

int main()
{
    // Gets the value from foo()
    int val = foo();

    cout<<val;

    return 0;

}