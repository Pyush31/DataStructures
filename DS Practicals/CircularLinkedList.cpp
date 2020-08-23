// Q.12.	Implement Circular Linked List using templates. Include functions for insertion, deletion and search of a number, reverse the list.

#include<iostream>
#include<iomanip>

using namespace std;

template< typename T >

class Node
{
public:
    int data;
    Node *next;

    Node ( T data =0, Node *next=0)
    {
        this->data = data;
        this->next = next;
    }
    ~Node()
    {
        this->data;
    }
};

template < typename T >

class CircularLinkedList
{
private:
    Node<T> *head,*temp;
    int No_nodes;

public:
    CircularLinkedList()
    {
        head = temp = 0;
        No_nodes = 0;
    }
    ~CircularLinkedList()
    {
        temp = head;
        Node<T> * nextptr;
        cout<<"\n Destroying the Linked List";
        while(temp->next != head)
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

};

template < typename T >

void CircularLinkedList<T> :: ins_at_start()
{
    //creating new object for node
    temp = new Node<T>();
    cout<<"\n Enter the data of new node ";
    cin>>temp->data;
    if(head ==0)
    {
        head = temp;
        head->next = head;
        temp = 0;
    }
    else
    {
        Node<T>* tail = head;
        while(tail->next != head)
        {
            tail = tail->next;
        }
        temp->next = head;
        head = tail;
        tail->next = head;
        temp = tail = 0;
    }
    No_nodes++;
}

template < typename T >

void CircularLinkedList<T> :: ins_at_end()
{
    temp = new Node<T>();
    cout<<"\n Enter the data of new node ";
    cin>>temp->data;
    if(head ==0)
    {
        head = temp;
        head->next = head;
        temp = 0;
    }
    else
    {
        Node<T>* tail = head;
        while(tail->next != head)
        {
            tail = tail->next;
        }
        tail->next = temp;
        tail->next->next = head;
        temp = tail = 0;
    }
    No_nodes++;
}

template < typename T >

void CircularLinkedList<T> :: ins_at_loc()
{
    //taking location input
    int loc;
    cout<<"\n Enter location ";
    cin>>loc;
    temp = new Node<T>();
    cout<<"\n Enter the data of new node ";
    cin>>temp->data;
    temp->next = 0;
    if(loc < 0 || loc > No_nodes)
    {
        cout<<"\n Location not valid ";
    }
    else if(loc==1)
    {
        Node<T>* tail = head;
        while(tail->next = 0)
        {
            tail = tail->next;
        }
        temp->next = head;
        head = temp;
        tail->next = head;
        tail = temp = 0;
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
        reqNode->next = temp;
        reqNode = temp = 0;
        No_nodes++;
    }
}

template < typename T >

void CircularLinkedList<T> :: del_at_start()
{
    if(No_nodes > 0)
    {
        if(head->next == head)
        {
            temp = head;
            delete temp;
            head = temp = 0;
        }
        else
        {
            Node<T>* tail = head;
            while(tail->next != head)
            {
                tail = tail->next;
            }
            temp = head;
            head = head->next;
            tail->next = head;
            delete temp;
            temp =0;
        }
        No_nodes--;
    }
    else cout<<"\n Nothing to delete ";
}

template < typename T >

void CircularLinkedList<T> :: del_at_end()
{
    if(No_nodes > 0)
    {
        if(head->next == head)
        {
            temp = head;
            delete temp;
            head = temp = 0;
        }
        else
        {
            temp = head;
            while(temp->next->next != head)
            {
                temp = temp->next;
            }
            delete temp->next;
            temp->next = head;
            temp = 0;
        }
        No_nodes--;
    }
    else
    {
        cout<<"\n Nothing to delete";
    }
}

template < typename T >

void CircularLinkedList<T>:: del_at_loc()
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
        Node<T>* tail = head;
        while(tail->next != head)
        {
            tail = tail->next;
        }
        if(No_nodes == 1)
        {
            head =0;
        }
        else
        {
            head = head->next;
            tail->next = head;
        }
        delete temp;
        No_nodes--;
    }
    else
    {
        int pointer = 1;
        Node<T> *reqNode = head;
        // going to the node of given location
        while( pointer != (loc-1))
        {
            reqNode = reqNode->next;
            pointer++;
        }
        temp = reqNode->next;
        if(temp->next == head)
        {
            reqNode->next = head;
        }
        reqNode->next = temp->next;
        delete temp;
        temp = reqNode = 0;
        No_nodes--;
    }
}

template < typename T >

void CircularLinkedList<T> :: traverse()
{
    if (head == 0)
    {
        cout<<"\n List is Empty ";
    }
    else
    {
        temp = head;
        do
        {
            cout<<temp->data<<"  ";
            temp = temp->next;
        }while(temp != head);
        cout<<endl;
        temp = 0;
    }
}

template < typename T >

void CircularLinkedList<T> :: locate()
{
    if(No_nodes > 0)
    {
        int value;
        int pointer = 1;
        cout<<"\n Enter the data you want to search ";
        cin>>value;
        temp = head;
        do
        {
            if (temp->data == value)
            {
                cout<<"\n Found at position - "<<pointer;
                return;
            }
            temp = temp->next;
            pointer++;
        }while(temp != head);
        cout<<"\n Not Found ";
    }
    else
    {
        cout<<"\n List is Empty ";
    }
}

template < typename T >

void CircularLinkedList<T> :: inverted()
{
    if (No_nodes > 0)
    {
        temp = head;
        Node<T> *prev = 0;
        Node<T> *next2 = 0;
        do
        {
            next2 = temp->next;
            temp->next = prev;
            prev = temp;
            temp = next2;
        }while(temp != head);
        head->next = prev;
        head = prev;
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
    CircularLinkedList<int>* C = new CircularLinkedList<int>();

    char ch;
    int a;
    do
    { system("cls");

        cout<<setw(59)<<setfill(' ')<<" LINKED LIST ";
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
            case 1 : C->ins_at_start();
                    break;
            case 2 : C->ins_at_end();
                    break;
            case 3 : C->ins_at_loc();
                    break;
            case 4 : C->del_at_start();
                    break;
            case 5 : C->del_at_end();
                    break;
            case 6 : C->del_at_loc();
                    break;
            case 7 : C->inverted(); C->traverse();
                    break;
            case 8 : C->locate();
                    break;
            case 9 : C->traverse();
                    break;
            default : cout<<"\n Invalid choice ";
        }
        cout<<"\n ONCE MORE (y/n) ";
        cin>>ch;
        if(ch=='n') cout<<"\n THANK YOU "
                        <<"\n BYE ";
    }
    while(ch=='y');
    delete C;
    return 0;
}
