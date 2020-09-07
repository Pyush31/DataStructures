#include<iostream>
#include<conio.h>
using namespace std;

class Node
{
    public:
        int data;
        Node *next;
        //constructor
        Node(int data, Node* next)
        {
            this->data = data;
            this->next = next;
        }
        //destructor
        ~Node()
        {
            cout<<" Deleted "<<this->data<<"\n";
        }
};

class CQueue
{
    private:
        Node *front, *rear, *temp;
        int No_nodes;
    public:
        //constructor
        CQueue()
        {
           front = rear = temp = 0;
           No_nodes = 0; 
        }
        //destructor
        ~CQueue()
        {
            temp = front;
            Node* nextPtr = 0;
            while(temp->next != front)
            {
                nextPtr = temp->next;
                delete temp;
                temp = nextPtr;
            }
            temp = nextPtr = 0;
            cout<<"Done\n";          
        }
        //member functions
        void Enqueue(int x);
        void Dequeue();
        void Front();
        int Empty();
        void Display();
};

int CQueue :: Empty()
{
    if(No_nodes == 0)
        return 1;
    return 0;
}


void CQueue :: Enqueue(int x)
{
    temp = new Node(x,0);
    if(rear == 0)
    {
        front = rear = temp;
        rear->next = front;
    }
    else
    {
        rear->next = temp;
        rear = temp;
        temp->next = front;
    }
    temp = 0;
    No_nodes++;
    
}

void CQueue :: Dequeue()
{
    if(Empty())
    {
        cout<<"Queue is Empty\n";
        getch();
    }
    else
    {
        if(front == rear)
        {
            temp = front;
            front = rear = 0;
        }
        else
        {
            temp = front;
            front = front->next;
            rear->next = front;
        }
        delete temp;
        temp = 0;
        No_nodes--;
    }
}


void CQueue :: Front()
{
    if(!Empty())
    {
        cout<<front->data<<"\n";
        getch();
    }
}

void CQueue :: Display()
{
    if(!Empty())
    {
        temp = front;
        do
        {
            cout<<temp->data<<" ";
            temp = temp->next;
        }
        while(temp != front);
        cout<<"\n";
        temp = 0;
    }
    else
    {
        cout<<"EMPTY\n";
    }
    
}

int main()
{
    CQueue *Q = new CQueue();
    int ch;
    do
    {
        cout<<"\n*****CIRCULAR QUEUE*****"
            <<"\nOperations :"
            <<"\n 1. Enqueue"
            <<"\n 2. Dequeue"
            <<"\n 3. Display"
            <<"\n 4. Exit"
            <<"\n Enter Your choice : ";
        cin>>ch;
        switch (ch)
        {
        case 1:
            int temp;
            cout<<"Enter the Element : ";  cin>>temp;
            Q->Enqueue(temp);
            break;
        case 2:
            Q->Dequeue();
            break;
        case 3: Q->Display();
            break;
        case 4: exit(0);
        default:
            cout<<"\n Invalid choice ";
        }
    } while (ch != 4);
    delete Q;
    return 0;
}