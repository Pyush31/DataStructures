#include<iostream>
#include<conio.h>
using namespace std;
#include"Stack.h"


class Queue
{
public:
    int *q;
    int size,front,rear;
    Stack<int> *s1;
    Stack<int> *s2;
    Queue(int size = 10)
    {
        front = rear = -1;
        this->size = size;
        s1 = new Stack<int>();
        s2 = new Stack<int>();
    }
    ~Queue()
    {
        delete s1;
        delete s2;
    }

    void Enqueue(int x)
    {
        if(rear == (size-1))
        {
            cout<<"\n Queue is full";
        }
        else if(front == -1 && rear == -1)
        {
            s1->push(x);
            front++;
            rear++;
        }
        else
        {
            while (s1->Top() != -1)
            {
                s2->push(s1->pop());
            }
            s1->push(x);
            while (s2->Top() != -1)
            {
                s1->push(s2->pop());
            }
            rear++;
        }
    }

    void Dequeue()
    {
        if (front == -1 && rear == -1)
        {
            cout<<"\n Empty";
        }
        else if (front == rear)
        {
            front = rear = -1;
            cout<<"\n Deleting "<<s1->pop();
        }
        else
        {
            front++;
            cout<<"\n Deleting "<<s1->pop();
        }
    }

    void Display()
    {
        cout<<"\n QUEUE--> ";
        s1->show();
    }
};

int main()
{
    Queue *Q = new Queue();
    int ch;
    do
    {
        cout<<"\n ***QUEUE***"
            <<"\n 1. Enqueue"
            <<"\n 2. Dequeue"
            <<"\n 3. Display"
            <<"\n 4. Exit"
            <<"\n Enter your choice ";
            cin>>ch;
        switch (ch)
        {
        case 1:
            int x;
            cout<<"\n Enter the element ";
            cin>>x; Q->Enqueue(x);
            break;
        
        case 2:
            Q->Dequeue();
            break;
        
        case 3:
            Q->Display();
            break;
        default: cout<<"\n invalid choice";
            break;
        }
    } while (ch != 4);
    delete Q;
    return 0;
}
