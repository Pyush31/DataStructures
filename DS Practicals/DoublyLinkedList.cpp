// Q.11. Implement Doubly Linked List using templates. Include functions for insertion, deletion and search of a number, reverse the list.
#include<iostream>
#include<iomanip>

using namespace std;

template< typename T >

class Node
{
public:
    int data;
    Node *next, *prev ;

    Node ( T data =0, Node *next = 0, Node *prev = 0)
    {
        this->data = data;
        this->next = next;
        this->prev = prev;
    }
    ~Node()
    {
        this->data;
    }
};

template < typename T >

class DoublyLinkedList
{
private:
    Node<T> *head,*tail,*temp;
    int No_nodes;

public:
    DoublyLinkedList()
    {
        head = tail = temp = 0;
        No_nodes = 0;
    }
    ~DoublyLinkedList()
    {
        temp = head;
        Node<T> * nextptr;
        cout<<"\n Destroying the Linked List";
        while(temp != 0)
        {
            nextptr = temp->next;
            delete temp;
            temp = nextptr;
        }
    }
    //Member Functions for linked list
    void ins_at_end();
    void ins_at_start();
    void ins_at_loc();
    void del_at_end();
    void del_at_start();
    void del_at_loc();
    void traverse();//to display the list
    void locate(); //to search
    void inverted(); //to reverse the list
    int  total_no_nodes();// to count no of nodes
    void operator + (DoublyLinkedList &s);//to concatenate using operator overloading

};

template < typename T >

int DoublyLinkedList<T> :: total_no_nodes()
{
    if(No_nodes==0)
        return 0;
    else return No_nodes;
}

template < typename T >

void DoublyLinkedList<T> :: ins_at_start()
{
    //creating new object for node
    temp = new Node<T>();
    cout<<"\n Enter the data of new node ";
    cin>>temp->data;
    temp->next = 0;
    if(head !=0)
    {
        head->prev = temp;
        temp->next = head;
        head = temp;
    }
    else
    {
        head = tail = temp;
    }
    temp = 0;
    No_nodes++;
}

template < typename T >

void DoublyLinkedList<T> :: ins_at_end()
{
    temp = new Node<T>();
    cout<<"\n Enter the data of new node ";
    cin>>temp->data;
    if(head !=0)
    {
        tail->next = temp;
        temp->prev = tail;
        tail = temp;
    }
    else
    {
        head = tail = temp;
    }
    temp = 0;
    No_nodes++;
}

template < typename T >

void DoublyLinkedList<T> :: ins_at_loc()
{
    //taking location input
    int loc;
    cout<<"\n Enter location ";
    cin>>loc;
    temp = new Node<T>();
    cout<<"\n Enter the data of new node ";
    cin>>temp->data;
    if(loc < 0 || loc > No_nodes)
    {
        cout<<"\n Location not valid ";
    }
    else if(loc==1)
    {
        head->prev = temp;
        temp->next = head;
        head = temp;
        No_nodes++;
    }
    else
    {
        int pointer = 1;
        Node<T> *reqNode = head;
        //going to the node of given location
        while(pointer != (loc-1))
        {
            reqNode = reqNode->next;
            pointer++;
        }
        //connecting given location with temp in list
        temp->next = reqNode->next;
        temp->prev = reqNode;
        reqNode->next->prev = temp;
        reqNode->next = temp;
        No_nodes++;
    }
    temp = 0;
}

template < typename T >

void DoublyLinkedList<T> :: del_at_start()
{
    if(No_nodes > 0)
    {
        temp = head;
        head = head->next;
        head->prev = 0;
        delete temp;
        temp =0;
        No_nodes--;
    }
    else cout<<"\n Nothing to delete ";
}

template < typename T >

void DoublyLinkedList<T> :: del_at_end()
{
    if(No_nodes > 0)
    {
        if(head == tail)
        {
            delete head;
            head = tail = temp = 0;
            No_nodes--;
        }
        else
        {
            temp = tail;
            tail = tail->prev;
            tail->next = 0;
            temp = 0;
            No_nodes--;
        }
    }
    else
    {
        cout<<"\n Nothing to delete";
    }
}

template < typename T >

void DoublyLinkedList<T>:: del_at_loc()
{
    int loc;
    //taking location input
    cout<<"\n Enter the location you want to delete the node at";
    cin>>loc;
    if (loc < 0 || loc > No_nodes)
    {
        cout<<"\n Invalid Location ";
    }
    else if (loc == 1)
    {
        temp = head;
        if(No_nodes == 1)
        {
            head = tail =0;
        }
        else
        {
            head = head->next;
            head->prev = 0;
        }
        delete temp;
        temp = 0;
        No_nodes--;
    }
    else
    {
        int pointer = 1;
        temp = head;
        while(pointer != loc)
        {
            temp = temp->next;
            pointer++;
        }
        if (temp == tail)
        {
            tail = temp->prev;
            tail->next = 0;
        }
        else
        {
            temp->prev->next = temp->next;
            temp->next->prev = temp->prev;
        }
        delete temp;
        temp = 0;
        No_nodes--;
    }
}

template < typename T >

void DoublyLinkedList<T> :: traverse()
{
    if (head == 0)
    {
        cout<<"\n List is Empty ";
    }
    else
    {
        cout<<"\n LIST : ";
        temp = head;
        while(temp != 0)
        {
            cout<<temp->data<<"  ";
            temp = temp->next;
        }
        cout<<endl;
        temp = 0;
    }
}

template < typename T >

void DoublyLinkedList<T> :: locate()
{
    if(total_no_nodes() > 0)
    {
        int value;
        int pointer = 1;
        cout<<"\n Enter the data you want to search ";
        cin>>value;
        temp = head;
        while(temp != 0)
        {
            if (temp->data == value)
            {
                cout<<"\n Found at position - "<<pointer;
                return;
            }
            temp = temp->next;
            pointer++;
        }
        cout<<"\n Not Found ";
    }
    else
    {
        cout<<"\n List is Empty ";
    }
}

template < typename T >

void DoublyLinkedList<T> :: inverted()
{
    if (total_no_nodes() > 0)
    {
        temp = head;
        Node<T> *next2 = 0;
        while(temp != 0)
        {
            next2 = temp->next;
            temp->next = temp->prev;
            temp->prev = next2;
            temp = next2;
        }
        temp = tail;
        tail = head;
        head = temp;
        temp = 0;
    }
    else
    {
        cout<<"\n List is Empty ";
    }
}


int main()
{
        system("cls");
    DoublyLinkedList<int>* D = new DoublyLinkedList<int>();

    char ch;
    int a;
    do
    { system("cls");

        cout<<setw(53)<<setfill(' ')<<" DOUBLY LINKED LIST ";
        cout<<setw(149)<<setfill('*')<<endl;
        cout<<"\n 1. Insert at start of list "
            <<"\n 2. Insert at end of list "
            <<"\n 3. Insert at some location of list "
            <<"\n 4. Delete at start of list "
            <<"\n 5. Delete at end of list "
            <<"\n 6. Delete at some location of list "
            <<"\n 7. Reverse the list "
            <<"\n 8. Search data in the list "
            <<"\n 9. Display the list "
            <<"\n enter your choice ";
        cin>>a;

        switch(a)
        {
            case 1 : D->ins_at_start(); D->traverse();
                    break;
            case 2 : D->ins_at_end(); D->traverse();
                    break;
            case 3 : D->ins_at_loc(); D->traverse();
                    break;
            case 4 : D->del_at_start(); D->traverse();
                    break;
            case 5 : D->del_at_end(); D->traverse();
                    break;
            case 6 : D->del_at_loc(); D->traverse();
                    break;
            case 7 : D->inverted(); D->traverse();
                    break;
            case 8 : D->locate();
                    break;
            case 9 : D->traverse();
                    break;
            default : cout<<"\n Invalid choice ";
        }
        cout<<"\n ONCE MORE (y/n) ";
        cin>>ch;
        if(ch=='n') cout<<"\n THANK YOU "
                        <<"\n BYE ";
    }
    while(ch=='y');
    return 0;
}
