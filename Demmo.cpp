#include<iostream>

using namespace std;


int main()
{
    Stack <char> sobj;
    sobj.push('A');
    sobj.push('B');
    sobj.push('C');
    sobj.push('D');
     
     sobj.Display();

    cout<<sobj.top()<<endl;
     sobj.Display();

    return 0;
}