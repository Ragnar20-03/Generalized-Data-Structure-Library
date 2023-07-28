#include "GDSB.cpp"
#include<iostream>

int main()
{
    DCL <int > obj ;
    obj.InsertFirst(10);
    obj.InsertFirst(20);
    obj.InsertLast (50);
    obj.InsertAtPos(30 ,3);
    obj.InsertAtPos(30 ,4);
    obj.InsertFirst(9);
    obj.InsertFirst(8);
    obj.InsertLast (100);
    obj.Display();
    obj.DisplayRev
    
    ();

    obj.DeleteFirst();
    obj.DeleteLast();
    obj.Display();
    obj.DisplayRev
    
    ();
    obj.DeleteAtPos(3);
    obj.Display();
    obj.DisplayRev
    
    ();
    cout<<"Count is \t"<<obj.Count()<<endl;;
    return 0;

}