#include <iostream>
#include <string>

using namespace std;

int main() 
{
    string str = "Hello, world!";
    
    // Accessing characters using str.at(i)
    for (size_t i = 0; i < str.length(); ++i) 
    {
        cout << "Character at index " << i << ": " << str.at(i) << endl;
    }
    
    // Trying to access an out-of-bounds index
    try 
    {
        char c = str.at(20); // This will throw an exception
    } 
    catch (const out_of_range& e) 
    {
        cerr << "Exception caught: " << e.what() << endl;
    }

    return 0;
}

// #include<iostream>

// #include<string.h>

// using namespace std;

// int main()

// {

// string str1="Bhavin";

// string str2="Bhavin";

// cout<<str2.compare(str1) <<endl;

// return 0;

// }