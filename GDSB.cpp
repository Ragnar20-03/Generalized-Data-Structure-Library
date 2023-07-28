#include<iostream>
using namespace std;

template <class T>
struct SinglyLL 
{
    T Data ; 
    struct SinglyLL * Next ; 
};

template <class T>
class SinglyLinkedList
{   
    private : 
    struct SinglyLL <T>* Head ; 
    int iCount  ; 

    public : 
    SinglyLinkedList ( )
    {
        Head = NULL;
        iCount = 0; 
        Display();
    }

    int Count();
    void Display();
    void InsertFirst( T value ) ; 
    void InsertLast ( T value );
    void InsertAtPos ( T value , int Pos);
    void DeleteFirst();
    void DeleteLast();
    void DeleteAtPos(int Pos);
    
};

template <class T>
void SinglyLinkedList <T> :: Display()
{

}

template <class T > 
int  SinglyLinkedList <T> :: Count()
{
    
    return iCount;
}

template <class T>
void SinglyLinkedList <T> :: InsertFirst(T value)
{

}

template <class T >
void SinglyLinkedList < T > :: InsertLast ( T value)
{

}

template <class T > 
void SinglyLinkedList < T > :: InsertAtPos( T value , int Pos)
{

}

template <class T > 
void SinglyLinkedList <T> :: DeleteFirst ()
{

}

template < class T >
void SinglyLinkedList <T> :: DeleteLast()
{

}

template <class T > 
void SinglyLinkedList < T > :: DeleteAtPos ( int Pos)
{

}

int main()
{
    SinglyLinkedList <int > LOBJ;

    return 0;
}