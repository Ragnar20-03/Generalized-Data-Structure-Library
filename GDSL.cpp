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
    void Insert ( T value );
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
void SLL < T > :: Insert ( T value)
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
        Insert(value);
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
        void Insert (T value);
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
void SCL <T> :: Insert ( T value)
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
        Insert(value);
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
        void Insert(T value);
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
void DLL <T> :: Insert( T value)
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
        Insert(value);
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
        void Insert(T value);
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
void DCL <T> :: Insert( T value)
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
        Insert(value);
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

//          Binary Search Tree         //
//                          Roshan Patl ( 28 July)

// /////////////////////////////////////////////////////////////////////////////////////////
// /////////////////////////////////////////////////////////////////////////////////////////
// /////////////////////////////////////////////////////////////////////////////////////////

template <class T>
struct Binary
{
    struct Binary  * rchild ; 
    struct Binary  * lchild ; 
    T  Data;   

    public:
    Binary(T value)
    {
        rchild = nullptr;
        lchild = nullptr;
        Data = value;
    }
};

template <class T>
class BST 
{
    private :
    int iCount;

    public : 
    struct Binary <T>* Head ; 
    BST ();
    void Insert(T value);
    int CountNodes();
    int CountLeaf(struct Binary <T> * );
    int CountParent(struct Binary <T> *);
    bool Search (struct Binary  <T>* temp , T);
    void DisplayPreorder(struct Binary <T> * );
    void DisplayInorder(struct Binary <T> * );
    void DisplayPostorder(struct Binary <T> * );
};

template <class T>
BST <T> :: BST()
{
    Head = NULL;
    iCount = 0 ; 
}

template <class T>
void BST <T> :: Insert(T value)
{   
    struct Binary <T> * newn = new Binary(value);
    struct Binary <T> * temp = Head;
    if (Head == NULL)
    {
        Head = newn;
    }
    else 
    {
        while (temp != nullptr)
        {
            if ( value == temp -> Data)
            {
                printf("Duplicate Elemet Found \n");
                return ;
            }
            if ( value > temp -> Data)
            {
                if ( temp -> rchild == nullptr)
                {
                    temp -> rchild = newn;
                    break;
                }
                else 
                {
                    temp = temp -> rchild;
                }
            }
            else if ( value < temp -> Data)
            {
                if ( temp -> lchild == nullptr)
                {
                    temp -> lchild = newn ;
                    break;
                }
                else 
                {
                    temp = temp -> lchild;
                }
            }
        }
    }
    iCount++;

}

template <class T>
int BST <T> :: CountNodes()
{
    return iCount;
}

template <class T>
int BST <T> :: CountLeaf(struct Binary <T>* temp )
{
    static int iCountL = 0 ;
    if ( temp != nullptr)
    {
        if ( temp -> rchild == nullptr && temp -> lchild == nullptr)
        {
            iCountL++;
        }
        CountLeaf (temp -> lchild);
        CountLeaf(temp-> rchild);
    }
    return iCountL;
}

template <class T>
int BST <T> :: CountParent(struct Binary <T>* temp)
{
    static int iCountP = 0 ; ;
    if ( temp != NULL)
    {
        if ( temp -> lchild != nullptr && temp -> rchild != nullptr)
        {
            iCountP ++;
        }
        CountParent ( temp -> lchild);
        CountParent ( temp -> rchild);
    }

    return iCountP;
}

template <class T>
bool BST <T> :: Search(struct Binary<T> * temp ,  T value)
{   
    bool bFlag = false;
    
    if ( temp == nullptr)
    {
        printf("Linked List is Empty \n");
        return false;
    }
    else 
    {
        while (temp != nullptr)
        {
            if ( temp -> Data == value)
            {
                bFlag = true;
                break;
            }
            else if (value < temp -> Data)
            {
                temp  = temp -> lchild;
            }
            else if ( value > temp -> Data)
            {
                temp  = temp -> rchild;
            }
        }

    }
    return bFlag;
}


template <class T>
void BST < T > ::  DisplayPreorder( struct Binary <T>  * temp  )
{
    if ( temp != nullptr)
    {
        cout<<temp -> Data <<"\t";
        DisplayPreorder(temp -> lchild);
        DisplayPreorder(temp -> rchild);
    }  
}

template <class T>
void BST < T > ::  DisplayPostorder( struct Binary  <T> *temp  )
{
    if ( temp != nullptr)
    {
        DisplayPostorder(temp -> lchild);
        DisplayPostorder(temp -> rchild);
        cout<<temp -> Data << "\t";
    }
}

template <class T>
void BST < T > ::  DisplayInorder( struct Binary <T> *  temp  )
{
        if ( temp != nullptr)
    {
        DisplayInorder(temp -> lchild);
        cout<<temp -> Data << "\t";
        DisplayInorder(temp -> rchild);
    }
}


// /////////////////////////////////////////////////////////////////////////////////////////
// /////////////////////////////////////////////////////////////////////////////////////////
// /////////////////////////////////////////////////////////////////////////////////////////

//          Starter Function         //

// /////////////////////////////////////////////////////////////////////////////////////////
// /////////////////////////////////////////////////////////////////////////////////////////
// /////////////////////////////////////////////////////////////////////////////////////////


int main()
{
    BST < char > lobj;
    lobj.Insert('A');
    lobj.Insert ( 'B');
    lobj.Insert ( 'D');
    lobj.Insert('C' );
    lobj.Insert ( 'E');
    lobj.Insert ( 'F');
    lobj.Insert ( 'G');
    lobj.Insert ( 'H');
    lobj.Insert ( 'I');
    lobj.Insert ( 'J');

    cout<<lobj.CountNodes()<<endl;
    lobj.DisplayPreorder(lobj.Head);
    cout<<lobj.CountParent(lobj.Head)<<endl;
    lobj.DisplayPreorder(lobj.Head);
    // cout<<lobj.Count()<<endl;
    lobj.DisplayPreorder(lobj.Head);
    lobj.DisplayPreorder(lobj.Head);

    return 0;
}