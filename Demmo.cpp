#include<iostream>

using namespace std;

template <class T>
struct QUE
{
    T Data ; 
    struct QUE * next;

    QUE(T data)
    {
        this->Data = data;
        this->next = nullptr;
    }
};

template <class T >
class Queue 
{
    private : 
    int iCount ;
    struct QUE <T> * Head;

    public : 
    Queue();
    void enqueue(T  );
    T dequeue ( );
    void Display();
    int  Count(); 

};

template <class T>
Queue<T> :: Queue()
{
    this-> Head = nullptr;
    this -> iCount = 0;
}
template <class T>
void Queue <T> :: enqueue(T Data)
{
   struct  QUE <T>* newn = new QUE ( Data);
    if ( Head == nullptr)
    {
        printf("nnnn\n");
        Head = newn;
    }
    else
    {
        printf("mmm\n");
            newn -> next = Head;
            Head = newn;
    }
    iCount ++;
}

template <class T>
T Queue<T> :: dequeue()
{
        struct QUE <T> * temp = Head ; 

        T Value ;

     if ( Head != nullptr && iCount == 1 )
    {
        Value = Head -> Data;
        delete Head ; 
        Head = nullptr; 

    }
    else {
        while ( temp -> next -> next != nullptr)
        {
            temp = temp -> next;
        } 
        Value = temp -> next -> Data;
        delete temp -> next;
        temp -> next = nullptr;
    }
    return Value;
    iCount --;
}

template <class T>
int Queue<T> :: Count(){
    return iCount;
} 

template <class T>
void Queue<T> :: Display()
{
    if ( Head != nullptr)
    {
        struct QUE <T> * temp = Head ;  
        while (temp != nullptr )
        {
            cout<<temp-> Data<<endl;
            temp = temp -> next;
        }
    }
    printf("\n");
}



int main()
{
    Queue <char> sobj;
    sobj.enqueue('A');
    sobj.enqueue('B');
    sobj.enqueue('C');
    sobj.enqueue('D');
     
     sobj.Display();
    cout<<endl;
    cout<<sobj.dequeue()<<endl;
    cout<<endl;
     sobj.Display();

    return 0;
}