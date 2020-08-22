//Q. 10. Implementation Linked List using templates. Include functions for insertion, deletion and search of a number,
//       reverse the list and concatenate two linked lists (include a function and also overload operator +).
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

class SinglyLinkedlist
{
private:
    Node<T> *head,*tail,*temp;
    int No_nodes;

public:
    SinglyLinkedlist()
    {
        head = tail = temp = 0;
        No_nodes = 0;
    }
    ~SinglyLinkedlist()
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
    void operator + (SinglyLinkedlist &s);//to concatenate using operator overloading

};

template < typename T >

int SinglyLinkedlist<T> :: total_no_nodes()
{
    if(No_nodes==0)
        return 0;
    else return No_nodes;
}

template < typename T >

void SinglyLinkedlist<T> :: ins_at_start()
{
    //creating new object for node
    temp = new Node<T>();
    cout<<"\n Enter the data of new node ";
    cin>>temp->data;
    temp->next = 0;
    if(head !=0)
    {
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

void SinglyLinkedlist<T> :: ins_at_end()
{
    temp = new Node<T>();
    cout<<"\n Enter the data of new node ";
    cin>>temp->data;
    temp->next = 0;
    if(head !=0)
    {
        tail->next = temp;
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

void SinglyLinkedlist<T> :: ins_at_loc()
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
        reqNode->next = temp;
        No_nodes++;
    }
    temp = 0;
}

template < typename T >

void SinglyLinkedlist<T> :: del_at_start()
{
    if(No_nodes > 0)
    {
        temp = head;
        head = head->next;
        delete temp;
        temp =0;
        No_nodes--;
    }
    else cout<<"\n Nothing to delete ";
}

template < typename T >

void SinglyLinkedlist<T> :: del_at_end()
{
    if(No_nodes > 0)
    {
        if(head == tail)
        {
            delete head;
            head = tail = temp;
            No_nodes--;
        }
        else
        {
            temp = head;
            while(temp->next != tail)
            {
                temp = temp->next;
            }
            delete tail;
            temp->next = 0;
            tail = temp;
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

void SinglyLinkedlist<T>:: del_at_loc()
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
        }
        delete temp;
        temp = 0;
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
        reqNode->next = temp->next;
        if(temp == tail)
        {
            tail = reqNode;
            reqNode->next = 0;
        }
        delete temp;
        temp = 0;
        No_nodes--;
    }
}

template < typename T >

void SinglyLinkedlist<T> :: traverse()
{
    if (head == 0)
    {
        cout<<"\n List is Empty ";
    }
    else
    {
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

void SinglyLinkedlist<T> :: locate()
{
    if(total_no_nodes())
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

void SinglyLinkedlist<T> :: inverted()
{
    if (total_no_nodes())
    {
        temp = head;
        Node<T> *prev = 0;
        Node<T> *next2 = 0;
        while(temp != 0)
        {
            next2 = temp->next;
            temp->next = prev;
            prev = temp;
            temp = next2;
        }
        tail = head;
        head = prev;
        temp = 0;
    }
    else
    {
        cout<<"\n List is Empty ";
    }
}

template < typename T >

void SinglyLinkedlist<T> :: operator +(SinglyLinkedlist<T> &s)
{
    if( this->No_nodes > 0 && s.No_nodes > 0 )
    {
        this->temp = tail;
        Node<T> *newnode = 0;
        s.temp = s.head;
        while (s.temp != 0)
        {
            newnode = new Node<T>(s.temp->data,0);
            this->No_nodes++;
            this->temp->next = newnode;
            this->temp = this->temp->next;
            s.temp = s.temp->next;
        }
        this->tail = newnode;
        this->temp = s.temp = newnode = 0;
    }
}

int main()
{
        system("cls");
    SinglyLinkedlist<int>* first_list = new SinglyLinkedlist<int>();
    SinglyLinkedlist<int>* second_list = new SinglyLinkedlist<int>();
    SinglyLinkedlist<int>* S = first_list;

    int which_list = 1;
    char ch;
    int a;
    do
    { system("cls");

        cout<<setw(59)<<setfill(' ')<<" LINKED LIST ";
        cout<<setw(149)<<setfill('*')<<endl;
        cout<<"\n YOU ARE CURRENTLY WORKING ON LIST NUMBER : "<<which_list;
        cout<<"\n 1. Insert at start of list "
            <<"\n 2. Insert at end of list "
            <<"\n 3. Insert at some location of list "
            <<"\n 4. Delete at start of list "
            <<"\n 5. Delete at end of list "
            <<"\n 6. Delete at some location of list "
            <<"\n 7. Reverse the list "
            <<"\n 8. Search data in the list "
            <<"\n 9. Display the list "
            <<"\n 10. Switch List "
            <<"\n 11. Add second list at the end of first list "
            <<"\n 12. Add first list at the end of second list "
            <<"\n enter your choice ";
        cin>>a;

        switch(a)
        {
            case 1 : S->ins_at_start();
                    break;
            case 2 : S->ins_at_end();
                    break;
            case 3 : S->ins_at_loc();
                    break;
            case 4 : S->del_at_start();
                    break;
            case 5 : S->del_at_end();
                    break;
            case 6 : S->del_at_loc();
                    break;
            case 7 : S->inverted(); S->traverse();
                    break;
            case 8 : S->locate();
                    break;
            case 9 : S->traverse();
                    break;
            case 10 : if( which_list == 1)
                        {
                            which_list = 2;
                            S = second_list;
                            cout<<"\n List Switched to second ";
                        }
                        else
                        {
                            which_list = 1;
                            S = first_list;
                            cout<<"\n List Switched to first ";
                        }
                        break;
            case 11 : *first_list + *second_list; first_list->traverse();
                      break;
            case 12 : *second_list + *first_list; second_list->traverse();
                      break;
            default : cout<<"\n Invalid choice ";
        }
        cout<<"\n ONCE MORE (y/n) ";
        cin>>ch;
        if(ch=='n') cout<<"\n THANK YOU "
                        <<"\n BYE ";
    }
    while(ch=='y');
    delete first_list;
    delete second_list;
    return 0;
}

