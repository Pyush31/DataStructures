#include<iostream>
#include<stdlib.h>
#include<iomanip>

using namespace std;

class Node
{
public:
    int data;
    Node *next;

    Node (int data =0, Node *next=0)
    {
        this->data = data;
        this->next = next;
    }
    ~Node()
    {
        this->data;
    }
};

class SinglyLinkedlist
{
private:
    Node *head,*tail,*temp;
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
        Node * nextptr;
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

};

int SinglyLinkedlist :: total_no_nodes()
{
    if(No_nodes==0)
        return 0;
    else return No_nodes;
}

void SinglyLinkedlist :: ins_at_start()
{
    //creating new object for node
    temp = new Node();
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

void SinglyLinkedlist :: ins_at_end()
{
    temp = new Node();
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

void SinglyLinkedlist :: ins_at_loc()
{
    //taking location input
    int loc;
    cout<<"\n Enter location ";
    cin>>loc;
    temp = new Node();
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
        Node *reqNode = head;
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

void SinglyLinkedlist :: del_at_start()
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

void SinglyLinkedlist :: del_at_end()
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

void SinglyLinkedlist:: del_at_loc()
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
        Node *reqNode = head;
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

void SinglyLinkedlist :: traverse()
{
    if (head == 0)\
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

void SinglyLinkedlist :: locate()
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

void SinglyLinkedlist :: inverted()
{
    if (total_no_nodes())
    {
        temp = head;
        Node *prev = 0;
        Node *next2 = 0;
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

int main()
{
        system("cls");
    SinglyLinkedlist* S = new SinglyLinkedlist();
    char ch;
    int a;
    do
    {

        cout<<setw(40)<<setfill(' ')<<"\n LINKED LIST ";
        cout<<setw(80)<<setfill('*')<<endl;
        cout<<"\n 1. Insert at start of list "
            <<"\n 2. Insert at end of list "
            <<"\n 3. Insert at some location of list "
            <<"\n 4. Delete at start of list "
            <<"\n 5. Delete at end of list "
            <<"\n 6. Delete at some location of list "
            <<"\n 7. Reverse the list "
            <<"\n 8. Search data in the list "
            <<"\n 9. Display the list "
            <<"\n 10. EXIT ";
        cout<<"\n enter your choice ";
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
            case 7 : S->inverted();
                    break;
            case 8 : S->locate();
                    break;
            case 9 : S->traverse();
                    break;
            case 10 : exit(0);
        }
        cout<<"\n ONCE MORE (y/n) ";
        cin>>ch;
        if(ch=='n') cout<<"\n THANK YOU "
                        <<"\n BYE ";
    }
    while(ch=='y');
    delete S;
    return 0;
}

