#include <iostream>
#include <conio.h>
#include <iomanip>
using namespace std;

class Node
{
    public:
        int data;
        Node *next;
        //constructor
        Node(int data, Node* nextNode)
        {
            this->data = data;
            this->next = nextNode;
        }
        //destructor
        ~Node()
        {
           this->data;
        }
};

class QUEUE
{
    private:
        Node *head, *tail, *temp;
        int No_nodes;
    public:
        //constructor
        QUEUE()
        {
           head = tail = temp = 0;
           No_nodes = 0; 
        }
        //destructor
        ~QUEUE()
        {
            temp = head;
            Node* nextPtr = 0;
            while (temp != 0) 
            {
                nextPtr = temp->next;
                delete temp;
                temp = nextPtr;
            }
            temp = nextPtr = 0;          
        }
        //member functions
        void Enqueue(int x) //to insert a value
        {
            temp = new Node(x,0);
            if(tail == 0)
            {
                head = tail = temp;
            }
            else
            {
                tail->next = temp;
                tail = temp;
            }
            temp = 0;
            No_nodes++;
        }
        void Dequeue() //to delete a value
        {
            if(No_nodes == 0)
            {
                cout<<"\n QUEUE is Empty";
                getch();
            }
            else
            {
                if(head == tail)
                {
                    temp = head;
                    head = tail = 0;
                }
                else
                {
                    temp = head;
                    head = head->next;
                }
                cout<<temp->data;
                delete temp;
                temp = 0;
                No_nodes--;
            }
        }
        void Display()
        {
            if(No_nodes >0)
            {
                temp = head;
                while (temp != 0)
                {
                    cout<<temp->data<<" ";
                    temp = temp->next;
                }cout<<endl;
                temp = 0;                
            }
            else
            {
                cout<<"\n Empty";
            }
            
        }
};

int main()
{
    QUEUE *Q = new QUEUE();
    int ch;
    char c;
    do
    {
        cout<<"\n*****QUEUE*****"
            <<"\n 1. Enter element"
            <<"\n 2. Delete element"
            <<"\n 3. Display Queue"
            <<"\n Enter your choice";
        cin>>ch;
        switch (ch)
        {
        case 1 : int temp;
        cout<<"\n Enter the element ";
        cin>>temp;
        Q->Enqueue(temp);
            break;
        
        case 2 : Q->Dequeue();
            break;
        
        case 3 : Q->Display();
            break;
        
        default: cout<<"\n Invalid choice";
            break;
        }cout<<"\n Again(y/n)";
        cin>>c;
    } while (c == 'y');
    delete Q;
    return 0;
}