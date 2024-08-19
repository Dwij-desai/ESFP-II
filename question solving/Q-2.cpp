#include<iostream>
#include<string.h>
using namespace std;
class student
{
    private:
        int roll_no; string name;
    public:
        student(int rno, string name)
        {
            roll_no=102;
            name="Priyanshu";
            cout<<roll_no<<"\t"<<name;
        }

        void display()
        {
            cout<<"\n"<<roll_no <<" " <<name;
        }
};
int main() 
{
    const student obj2(101,"John");
    return 0;
}