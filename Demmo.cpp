#include<iostream>
using namespace std;

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


int main()
{
    BST <int> bobj;
    bobj.Insert(11);
    bobj.Insert(21);
    bobj.Insert(3);
    bobj.Insert(1);
    int iRet = bobj.CountLeaf(bobj.Head);
    printf("Count Leaf is %d :\n" , iRet);
   iRet =  bobj.CountNodes();
   printf("Node are : %d \n" , iRet);
   iRet =  bobj.CountParent(bobj.Head);
   printf("Parent Node are : %d \n" , iRet);

   printf("%d \n " , bobj.Search(bobj.Head ,178));

    bobj.DisplayPreorder(bobj.Head);
    printf("\n");
    bobj.DisplayInorder(bobj.Head);
    printf("\n");
    bobj.DisplayPostorder(bobj.Head);

    return 0;
}