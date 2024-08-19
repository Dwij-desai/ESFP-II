#include <iostream>
#include<string>
#include<algorithm>
using namespace std; class name
{
public:
string fname, sname;
int getInfo(){
fname="Vijay";
sname="VijayM";
cout<<fname.find('V');
cout<<sname.find('M');
cout<<sname.substr(sname.length()-2,1);
}
};
int main()
{
name ob;
ob.getInfo();
}