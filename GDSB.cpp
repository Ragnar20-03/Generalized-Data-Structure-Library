#include<iostream>
#include<stdlib.h>
#include<string>
using namespace std;

// /////////////////////////////////////////////////////////////////////////////////////////
// /////////////////////////////////////////////////////////////////////////////////////////
// /////////////////////////////////////////////////////////////////////////////////////////

//          Singly Linear Linked List        //
//                          Roshan Patl ( 28 July)

// /////////////////////////////////////////////////////////////////////////////////////////
// /////////////////////////////////////////////////////////////////////////////////////////
// /////////////////////////////////////////////////////////////////////////////////////////

template <class T>
 struct SINGLY 
{
    T Data ; 
    struct SINGLY<T> * next ;
    public : 
    SINGLY(T value)
    {
        Data = value;
        next = NULL;
    } 
};


template <class T>
class SLL
{   
    private : 
    struct SINGLY <T>* Head ; 
    int iCount  ; 

    public : 
    SLL();

    int Count();
    void Display();
    void InsertFirst( T value ) ; 
    void InsertLast ( T value );
    void InsertAtPos ( T value , int Pos);
    void DeleteFirst();
    void DeleteLast();
    void DeleteAtPos(int Pos);
    
};

template <class T >
SLL <T> :: SLL()
{
    Head = nullptr;
    iCount = 0;
}

template <class T>
void SLL <T> :: Display()
{
    printf("Elememts of Linked List Are : \n");
    struct SINGLY < T >  * temp = Head;
    while (temp != nullptr)
    {
        cout<<temp -> Data <<"\t";
        temp  = temp -> next;
    }
    printf("\n");
}

template <class T > 
int  SLL <T> :: Count()
{
    
    return iCount;
}

template <class T>
void SLL <T> :: InsertFirst(T value)
{
    struct SINGLY <T> *  newn  = new SINGLY(value);

    if ( Head == nullptr)
    {
        Head = newn;
    }
    else 
    {
        newn -> next =  Head;
        Head =  newn;
    }
    iCount++;

}

template <class T >
void SLL < T > :: InsertLast ( T value)
{
    SINGLY  < T > * newn = new SINGLY(value);
    if ( Head == nullptr)
    {
        Head = newn;
    }
    else 
    {
        struct SINGLY < T > * temp = Head;
        while ( temp -> next != nullptr)
        {
            temp = temp -> next;
        }
        temp -> next = newn;
    }
    iCount++;
}

template <class T > 
void SLL < T > :: InsertAtPos( T value , int Pos)
{
    if ( (Pos > iCount + 1 ) || ( Pos < 1))
    {
        printf("InValid Position \n ");
        return ;
    }
     if ( Pos == 1)
    {
        InsertFirst(value);
    }
    else if ( Pos == iCount+1)
    {
        InsertLast(value);
    }
    else 
    {
        struct SINGLY <T> * newn  =  new SINGLY(value);
        struct SINGLY <T > * temp = Head;
        for (int iCnt= 1 ; iCnt < Pos - 1 ; iCnt ++)
        {
            temp = temp -> next;
        }
        newn -> next = temp -> next;
        temp -> next = newn ;
        iCount++;
    }
}

template <class T > 
void SLL <T> :: DeleteFirst ()
{
    if ( Head == nullptr)
    {
        printf("Linked List Is Empty\n");
        return ;
    }
    else if ( Head -> next == nullptr )
    {
        delete Head -> next;
        Head = nullptr;
    }
    else 
    {
        struct SINGLY <T> * temp = Head;
        Head = Head -> next;
        delete temp;
    }
    iCount--;
}

template < class T >
void SLL <T> :: DeleteLast()
{
    if (Head == nullptr)
    {
        printf("Linked List is Empty : ");
        return ;
    }
    else if ( Head -> next == nullptr)
    {
        delete Head -> next;
        Head = nullptr;
    }
    else 
    {
        struct SINGLY < T > * temp = Head;
        while ( temp -> next -> next != nullptr)
        {
            temp = temp -> next;  
        }
        delete temp -> next;
        temp ->next = nullptr;
    }
    iCount--;
}

template <class T > 
void SLL < T > :: DeleteAtPos ( int Pos)
{
    if (( Pos < 1  )  | ( Pos > iCount) )
    {
        printf("Invalid Position \n");
        return ;
    }
    if ( Pos == 1)
    {
        DeleteFirst();
    }
    else if ( Pos == iCount)
    {
        DeleteLast();
    }
    else 
    {
        struct SINGLY < T > * temp = Head;
        for ( int iCnt = 1 ; iCnt < Pos - 1 ; iCnt++)
        {
            temp = temp -> next;
        }
        struct SINGLY<T> * tempX = temp -> next;
        temp -> next = temp -> next -> next;
        delete tempX;
        iCount--;
    }
}

// /////////////////////////////////////////////////////////////////////////////////////////
// /////////////////////////////////////////////////////////////////////////////////////////
// /////////////////////////////////////////////////////////////////////////////////////////

//          Singly Circular Linked List        //
//                          Roshan Patl ( 28 July)

// /////////////////////////////////////////////////////////////////////////////////////////
// /////////////////////////////////////////////////////////////////////////////////////////
// /////////////////////////////////////////////////////////////////////////////////////////



template <class T>
class SCL 
{
    private : 
        int iCount ;
        struct SINGLY <T > * Head ;
        SINGLY <T> * Tail = nullptr;  
    
    public : 
        SCL();
        void Display();
        int Count();
        void InsertFirst (T value);
        void InsertLast (T value);
        void InsertAtPos (T value , int Pos);
        void DeleteFirst ();
        void DeleteLast ();
        void DeleteAtPos (int Pos);
};

template <class T >
SCL <T> :: SCL()
{
    this-> iCount = 0 ; 
    this->Head = nullptr;
}

template <class T >
void SCL <T> :: Display()
{
    struct SINGLY <T> * temp = Head;
    if ( Head != nullptr)
    {
        printf("Elements of Linked List Are\n");
        do {
            cout<<temp -> Data <<"\t";
            temp = temp -> next;
        }while ( temp != Head);
    }
    printf("\n");
}


template <class T > 
int SCL <T> :: Count()
{
    return iCount;
}

template <class T>
void SCL <T> :: InsertFirst ( T value)
{
    struct SINGLY <T> * newn = new SINGLY ( value);
    
    if (Head == nullptr && Tail == nullptr)
    {
        Head = newn ;
        Tail = newn;
    }
    else
    {
        newn -> next = Head -> next;
        Head = newn ;
    }

    Tail -> next = Head;
    this-> iCount++;
}

template <class T > 
void SCL <T> :: InsertLast ( T value)
{
    struct SINGLY <T> * newn = new SINGLY ( value);
    if ( Head == nullptr && Tail == nullptr)
    {
        Head = newn ;
        Tail = newn ;
    }
    else 
    {
        Tail -> next = newn ;
        Tail = Tail -> next;
    }
    Tail -> next = Head;
    this -> iCount ++;
}

template <class T >
void SCL <T> :: InsertAtPos (T value , int Pos)
{
    if ( (Pos < 1)  ||  ( Pos > iCount + 1))
    {
        printf("Invalid Number of Arguments \n");
        return ;
    }
    if ( Pos == 1)
    {
        InsertFirst(value);
    }
    else if ( Pos == iCount + 1)
    {
        InsertLast(value);
    }
    else 
    {
        struct SINGLY <T> * newn = new SINGLY ( value);
        struct SINGLY <T> * temp = Head;

        for ( int iCnt = 1 ; iCnt < Pos - 1 ; iCnt ++)
        {
            temp = temp -> next;
        }
        newn -> next = temp -> next;
        temp -> next = newn ;
        iCount++;
    }
}

template <class T>
void SCL <T> :: DeleteFirst()
{
    if ( Head == nullptr && Tail == nullptr)
    {
        return ;
    }
    else if ( Head == Tail)
    {
        delete Head ; 
        Head = nullptr ; 
        Tail = nullptr;
    }
    else 
    {
        Head = Head -> next;
        delete Tail -> next;
    }
    Tail -> next = Head;
}

template <class T >
void SCL <T> :: DeleteLast ()
{
    if ( Head == nullptr && Tail == nullptr)
    {
        return;
    }
    else if ( Head == Tail)
    {
        delete Tail;
        Head = nullptr;
        Tail = nullptr;
    }
    else 
    {
        struct SINGLY <T> * temp = Head;
        while ( temp -> next -> next != Head)
        {
            temp = temp -> next;
        }
        
        Tail = temp;
        delete temp -> next;
        Tail -> next = Head;
    }
    iCount--;
}

template <class T >
void SCL <T> :: DeleteAtPos( int Pos)
{
    if ( Pos < 1 && Pos > iCount)
    {
        return;
    }
    if ( Pos == 1)
    {
        DeleteFirst();
    }
    else if ( Pos == iCount)
    {
        DeleteLast();
    } 
    else
    {
        struct SINGLY <T> * temp = Head;
        for ( int iCnt = 1 ; iCnt < Pos -1 ; iCnt ++)
        {
            temp = temp -> next;
        }
        struct SINGLY <T> * tempX = temp -> next;
        temp -> next = temp -> next -> next;
        delete tempX;
        iCount--;
    }
}

// /////////////////////////////////////////////////////////////////////////////////////////
// /////////////////////////////////////////////////////////////////////////////////////////
// /////////////////////////////////////////////////////////////////////////////////////////

//          Doubly Linear Linked List         //
//                          Roshan Patl ( 28 July)

// /////////////////////////////////////////////////////////////////////////////////////////
// /////////////////////////////////////////////////////////////////////////////////////////
// /////////////////////////////////////////////////////////////////////////////////////////

template <class T >
struct DOUBLY
{
    T Data ; 
    DOUBLY <T> * next;
    DOUBLY <T>* prev ;
    public : 
    DOUBLY (  T value )
    {
        next = nullptr;
        prev= nullptr;
        Data = value;
    }
};

template < class T>
class DLL
{
    private : 
        int iCount;
        struct DOUBLY <T> * Head;
        struct DOUBLY <T> * Tail;

    public : 
        DLL();
        void Display ();
        void DisplayRev ();
        int Count();
        void InsertFirst(T value);
        void InsertLast(T value);
        void InsertAtPos(T value , int Pos);
        void DeleteAtPos(  int Pos);
        void DeleteFirst ( );
        void DeleteLast ();
};

template <class T>
DLL <T> :: DLL()
{
    iCount = 0 ; 
    this-> Head = nullptr;
}

template <class T>
int  DLL <T> :: Count()
{
    return iCount;
} 

template <class T >
void DLL <T> :: Display()
{
    if ( Head != nullptr && Tail != nullptr)
    {
        struct DOUBLY <T> * temp = Head; 
        printf("Elements of Linked List Are  : \n");
        while ( temp != nullptr )
        {
            cout<<temp-> Data <<"\t";
            temp = temp -> next;
        }
    }
    cout<<endl;
}

template <class T >
void DLL <T> :: DisplayRev()
{
    if ( Head != nullptr && Tail != nullptr)
    {
        struct DOUBLY <T> * temp = Tail; 
        printf("Elements of Linked List Are  : \n");
        while ( temp != nullptr )
        {
            cout<<temp-> Data <<"\t";
            temp = temp -> prev;
        }
    }
    cout<<endl;
}

template <class T >
void DLL <T> :: InsertFirst(T value)
{
    struct DOUBLY <T> *  newn  = new DOUBLY(value);

    if ( Head == nullptr)
    {
        Head = newn;
        Tail = newn;
    }
    else 
    {
        newn -> next =  Head;
        Head -> prev = newn ;
        Head =  newn;
    }
    

    iCount++;
} 

template <class T>
void DLL <T> :: InsertLast( T value)
{
    struct DOUBLY <T> *  newn  = new DOUBLY(value);

    if ( Head == nullptr)
    {
        Head = newn;
        Tail = newn;
    }
    else 
    {
        Tail -> next = newn ;
        newn -> prev = Tail;
        Tail = Tail -> next;
    }
    iCount++;
}

template <class T>
void DLL <T> :: InsertAtPos( T value , int Pos)
{
    if ( (Pos > iCount + 1 ) || ( Pos < 1))
    {
        printf("InValid Position \n ");
        return ;
    }
     if ( Pos == 1)
    {
        InsertFirst(value);
    }
    else if ( Pos == iCount+1)
    {
        InsertLast(value);
    }
    else 
    {
        struct DOUBLY <T> * newn  =  new DOUBLY(value);
        struct DOUBLY <T > * temp = Head;
        for (int iCnt= 1 ; iCnt < Pos - 1 ; iCnt ++)
        {
            temp = temp -> next;
        }

        newn -> next  =  temp -> next;
        temp -> next -> prev = newn;

        temp -> next = newn ;
        newn -> prev = temp;

        iCount++;
    }
}

template <class T >
void DLL  < T> :: DeleteFirst()
{
    if ( Head == nullptr && Tail == nullptr)
    {
        printf("Linked List Is Empty\n");
        return ;
    }
    else if ( Head == Tail)
    {
        delete Head ; 
        Head = nullptr ; 
        Tail = nullptr;
    }
    else 
    {
        Head = Head -> next;
        delete Head -> prev;
        Head -> prev = nullptr;
    }

    Tail -> next = Head;
    iCount--;
}

template <class T >
void DLL <T> :: DeleteLast()
{
    if ( Head == nullptr && Tail == nullptr)
    {
        printf("Linked List Is Empty\n");
        return ;
    }
    else if ( Head == Tail)
    {
        delete Head ; 
        Head = nullptr ; 
        Tail = nullptr;
    }
    else 
    {
        Tail = Tail -> prev ; 
        delete Tail -> next;
        Tail -> next = nullptr;
        
    }
    iCount--;
}

template <class T>
void DLL <T> :: DeleteAtPos ( int Pos)
{
    if (( Pos < 1  )  | ( Pos > iCount) )
    {
        printf("Invalid Position \n");
        return ;
    }
    if ( Pos == 1)
    {
        DeleteFirst();
    }
    else if ( Pos == iCount)
    {
        DeleteLast();
    }
    else 
    {
        struct DOUBLY < T > * temp = Head;
        for ( int iCnt = 1 ; iCnt < Pos - 1 ; iCnt++)
        {
            temp = temp -> next;
        }

        temp -> next = temp -> next -> next;
        delete temp -> next -> prev;
        temp -> next -> prev = temp;

        iCount--;
    }
}
// /////////////////////////////////////////////////////////////////////////////////////////
// /////////////////////////////////////////////////////////////////////////////////////////
// /////////////////////////////////////////////////////////////////////////////////////////

//          Doubly Linear Linked List         //
//                          Roshan Patl ( 28 July)

// /////////////////////////////////////////////////////////////////////////////////////////
// /////////////////////////////////////////////////////////////////////////////////////////
// /////////////////////////////////////////////////////////////////////////////////////////


template < class T>
class DCL
{
    private : 
        int iCount;
        struct DOUBLY <T> * Head;
        struct DOUBLY <T> * Tail;

    public : 
        DCL();  
        void Display ();
        void DisplayRev ();
        int Count();
        void InsertFirst(T value);
        void InsertLast(T value);
        void InsertAtPos(T value , int Pos);
        void DeleteAtPos(  int Pos);
        void DeleteFirst ( );
        void DeleteLast ();
};

template <class T>
DCL <T> :: DCL()
{
    iCount = 0 ; 
    this-> Head = nullptr;
}

template <class T>
int  DCL <T> :: Count()
{
    return iCount;
} 

template <class T >
void DCL <T> :: Display()
{
    if ( Head != nullptr && Tail != nullptr)
    {
        struct DOUBLY <T> * temp = Head; 
        printf("Elements of Linked List Are  : \n");
        do 
        {
            cout<<temp -> Data<<"\t";
            temp = temp -> next;
        }while ( temp != Head);
    }
    cout<<endl;
}

template <class T>
void DCL <T> :: DisplayRev()
{
    if ( Head != nullptr && Tail != nullptr)
    {
        struct DOUBLY <T> * temp = Tail; 
        printf("Elements of Linked List Are  : \n");
        do 
        {
            cout<<temp -> Data<<"\t";
            temp = temp -> prev;
        }while ( temp != Tail);
    }
    cout<<endl;
}
template <class T >
void DCL <T> :: InsertFirst(T value)
{
    struct DOUBLY <T> *  newn  = new DOUBLY(value);

    if ( Head == nullptr)
    {
        Head = newn;
        Tail = newn;
    }
    else 
    {
        newn -> next =  Head;
        Head -> prev = newn ;
        Head = newn ;
    }
    Head -> prev = Tail;
    Tail -> next = Head;

    iCount++;
} 

template <class T>
void DCL <T> :: InsertLast( T value)
{
    struct DOUBLY <T> *  newn  = new DOUBLY(value);

    if ( Head == nullptr)
    {
        Head = newn;
        Tail = newn;
    }
    else 
    {
        Tail -> next = newn ;
        newn -> prev = Tail;
        Tail = Tail -> next;
    }
    Tail -> next = Head;
    Head -> prev = Tail;
    iCount++;
}

template <class T>
void DCL <T> :: InsertAtPos( T value , int Pos)
{
    if ( (Pos > iCount + 1 ) || ( Pos < 1))
    {
        printf("InValid Position \n ");
        return ;
    }
     if ( Pos == 1)
    {
        InsertFirst(value);
    }
    else if ( Pos == iCount+1)
    {
        InsertLast(value);
    }
    else 
    {
        struct DOUBLY <T> * newn  =  new DOUBLY(value);
        struct DOUBLY <T > * temp = Head;
        for (int iCnt= 1 ; iCnt < Pos - 1 ; iCnt ++)
        {
            temp = temp -> next;
        }

        newn -> next  =  temp -> next;
        temp -> next -> prev = newn;

        temp -> next = newn ;
        newn -> prev = temp;

        iCount++;
    }
}

template <class T >
void DCL  < T> :: DeleteFirst()
{
    if ( Head == nullptr && Tail == nullptr)
    {
        printf("Linked List Is Empty\n");
        return ;
    }
    else if ( Head == Tail)
    {
        delete Head ; 
        Head = nullptr ; 
        Tail = nullptr;
    }
    else 
    {
        Head = Head -> next;
        delete Tail -> next;
    }
    Head -> prev = Tail;
    Tail -> next = Head;
    iCount--;
}

template <class T >
void DCL <T> :: DeleteLast()
{
    if ( Head == nullptr && Tail == nullptr)
    {
        printf("Linked List Is Empty\n");
        return ;
    }
    else if ( Head == Tail)
    {
        delete Head ; 
        Head = nullptr ; 
        Tail = nullptr;
    }
    else 
    {
        Tail = Tail -> prev ; 
        delete Head -> prev;    
    }
    Tail -> next = Head;
    Head -> prev = Tail;
    iCount--;
}

template <class T>
void DCL <T> :: DeleteAtPos ( int Pos)
{
    if (( Pos < 1  )  | ( Pos > iCount) )
    {
        printf("Invalid Position \n");
        return ;
    }
    if ( Pos == 1)
    {
        DeleteFirst();
    }
    else if ( Pos == iCount)
    {
        DeleteLast();
    }
    else 
    {
        struct DOUBLY < T > * temp = Head;
        for ( int iCnt = 1 ; iCnt < Pos - 1 ; iCnt++)
        {
            temp = temp -> next;
        }

        temp -> next = temp -> next -> next;
        delete temp -> next -> prev;
        temp -> next -> prev = temp;

        iCount--;
    }
}


// /////////////////////////////////////////////////////////////////////////////////////////
// /////////////////////////////////////////////////////////////////////////////////////////
// /////////////////////////////////////////////////////////////////////////////////////////

//          Starter Function         //

// /////////////////////////////////////////////////////////////////////////////////////////
// /////////////////////////////////////////////////////////////////////////////////////////
// /////////////////////////////////////////////////////////////////////////////////////////


// int main()
// {
//     DLL < char > lobj;
//     lobj.InsertFirst('A');
//     lobj.InsertLast ( 'B');
//     lobj.InsertLast ( 'D');
//     lobj.InsertAtPos('C' , 3);
//     lobj.InsertLast ( 'E');
//     lobj.InsertLast ( 'F');
//     lobj.InsertLast ( 'G');
//     lobj.InsertLast ( 'H');
//     lobj.InsertLast ( 'I');
//     lobj.InsertLast ( 'J');

//     cout<<lobj.Count()<<endl;
//     lobj.Display();
//     lobj.DeleteFirst();
//     lobj.DeleteLast();
//     cout<<lobj.Count()<<endl;
//     lobj.Display();
//     lobj.DeleteAtPos(4);
//     cout<<lobj.Count()<<endl;
//     lobj.Display();
//     lobj.DisplayRev();

//     return 0;
// }