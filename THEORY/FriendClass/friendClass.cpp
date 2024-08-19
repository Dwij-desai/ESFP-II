#include<iostream>

using namespace std;

class Efriend

{

private:

int x;

int y;

public:

void getData()

{

cout<<"Enter two number:";

cin>>x>>y;

cout<<"\n "<<x<<"\t"<<y;

}

friend void show(Efriend obj)

{

int z;

cout<<"\nEnter first number:\n";

cin>>obj.x;

cout<<"\n Enter second number:\n";

cin>>obj.y;

z=obj.x + obj.y;

cout<<obj.x<<"\t"<<obj.y<<“Result”<<z;

}

};

int main()

{

Efriend obj;

obj.getData();

show(obj);

return 0;

}