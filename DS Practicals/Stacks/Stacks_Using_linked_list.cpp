/*
Q.4.Perform the following Stack operations using Linked List implementation.
    a)	Push
    b)	Pop
    c)	Clear
*/

#include<iostream>
#include<iomanip>
#include<conio.h>
using namespace std;

class Node
{
public:
    int data;
    Node *next, *nextNode;

    Node(int data = 0, Node *next = 0)
    {
        this->data = data;
        this->next = next;
    }

};


class StackUsingLinkedList
{
    Node *top,*temp;
    int No_nodes;
public:
    StackUsingLinkedList()
    {
        top = temp = 0;
        No_nodes = 0;
    }
    ~StackUsingLinkedList()
    {
            temp = top;
            Node *nextNode;
            while(temp != 0)
            {
                nextNode = temp->next;
                delete temp;
                temp = nextNode;
            }
    }

    void Push( int x)
    {
        temp = new Node(x,0);
        if(top == 0)
        {
            top = temp;
        }
        else
        {
            temp->next = top;
            top = temp;
        }
        temp = 0;
        No_nodes++;
    }

    void Pop()
    {
        if(top != 0)
        {
            temp = top;
            top = top->next;
            delete temp;
            temp = 0;
            No_nodes--;
        }
        else cout<<"\n Empty ";
    }

    void Clear()
    {
        cout<<"\n Clearing the stack Completely ";
        temp = top;
        Node *nextNode ;
        while(temp != 0)
        {
            nextNode = temp->nextNode;
            delete temp;
            temp = nextNode;
        }
        top = temp = 0;
        No_nodes--;
    }

    void Show()
    {
        if(No_nodes > 0)
        {
            temp = top;
            while(temp != 0)
            {
                cout<<temp->data<<" ";
                temp = temp->next;
                 cout<<endl;
            }
        }
        else cout<<"\n Empty ";
    }

};

int main()
{
    StackUsingLinkedList *S = new StackUsingLinkedList();
    int ch;
    do
    {
        system("cls");
        cout<<"\n STACK "<<endl;
        cout<<endl;S->Show();
        cout<<"\n Operations "
            <<"\n 1. Push "
            <<"\n 2. Pop "
            <<"\n 3. Clear "
            <<"\n 4. Exit "
            <<"\n Enter your choice ";
        cin>>ch;
        switch(ch)
        {
            case 1 : int x;
                     cout<<"\n enter the element ";
                     cin>>x;
                     S->Push(x);
                     break;
            case 2 : S->Pop();
                     break;
            case 3 : S->Clear();
                     break;
            case 4 : exit(0);
            default: cout<<"\n invalid choice ";
        }
    }while(ch != 4);
    delete S;
    return 0;
}
