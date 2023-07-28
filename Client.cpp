#include "GDSB.cpp"
#include<iostream>

int main()
{
    SLL <int > obj ;
    obj.InsertFirst(1);
    obj.InsertFirst(1);
    obj.InsertFirst(1);
    obj.InsertFirst(1);
    obj.InsertFirst(1);
    obj.InsertFirst(1);
    obj.InsertFirst(1);
    obj.Display();
    cout<<"Count is \t"<<obj.Count()<<endl;;
    return 0;

}