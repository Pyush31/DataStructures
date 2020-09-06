#include <iostream>
#include <iomanip>
#include <conio.h>
using namespace std;

class QUEUE
{
    int size,front,rear;
    int* q;
    public:
        //constructor
        QUEUE(int size = 10)
        {
            front = rear = -1;
            this->size = size;
            q = new int[size];
            for(int i = 0; i < size ; ++i)
                q[i] = 0;
        }
        //destructor
        ~QUEUE()
        {
            delete[] q;
        } 

    public:

    void Enqueue()
    {
        int x; cout<<"\n enter value ";
        cin>>x;
        if(rear == -1)
        {
            front++; 
            rear++;
            q[front] = x;
        }
        else if(rear == size-1 )
        {
            cout<<"\n Queue is full";
        }
        else
        {
            q[++rear] = x;
        }
    }
    void Dequeue()
    {
        if(front == -1) cout<<"\n Queue is Empty";
        else if(front == rear) front = rear = -1;
        else front++;
    }
    void Display()
    {
        if(front == -1)
        {
            cout<<"\n queue is empty";
        }
        else 
        {
            for(int i = front; i <= rear ; i++)
            {
                cout<<q[i]<<" ";
            }
        }
    }
};

int main()
{
    QUEUE Q;
    int ch;
    do
    {
        cout<<"\n*****QUEUE*****"
            <<"\n 1. Enter element"
            <<"\n 2. Delete element"
            <<"\n 3. Display Queue"
            <<"\n 4, Exit"
            <<"\n Enter your choice ";
        cin>>ch;
        switch (ch)
        {
        case 1 : 
        Q.Enqueue();
            break;
        
        case 2 : Q.Dequeue();
            break;
        
        case 3 : Q.Display();
            break;
        case 4 : exit;
        default: cout<<"\n Invalid choice";
            break;
        }
    } while (ch != 4);
    
}