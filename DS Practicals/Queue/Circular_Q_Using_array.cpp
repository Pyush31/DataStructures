#include<iostream>
#include<conio.h>
#include<iomanip>
using namespace std;

class CQueue
{
    int size,front,rear;
    int* q;

    public:
    CQueue(int size = 10)
        {
            front = rear = -1;
            this->size = size;
            q = new int[size];
            for(int i = 0; i < size ; ++i)
                q[i] = 0;
        }
     ~CQueue()
        {
            delete[] q;
        } 
    int Empty()
    {
       if(front == -1 && rear == -1)
        return 1;
       else return 0; 
    }

    int Full()
    {
        if((rear + 1) % size == front)
        return 1;
        else return 0;
    }

    void Enqueue()
    {
        int x; cout<<"\n enter value ";
        cin>>x;
        if(Empty())
        {
            front++;
            rear++;
            q[front] = x;
        }
        else if(Full())
        {
            cout<<"\n Queue is full";
        }      
        else
        {
            if(Full() == 0)
            {
                rear = (rear+1)%size;
                q[rear] = x;
            }
        }
    }
    void Dequeue()
    {
        if(Empty())
        {
            cout<<"\n Empty ";
        }
        else if(front == rear)
        {
            front = rear = -1;
        }
        else
        {
            front = (front+1)%size;
            return;
        }
    }
    void Display()
    {
        cout<<"\n QUEUE->";
        if(Empty() == 0)
        {
            if(front <= rear)
            {
                for(int i = front; i <= rear; i++)
                {
                    cout<<q[i]<<" ";
                }
            }
            else
            {
                for(int i = front; i < size; i++)
                {
                    cout<<q[i]<<" ";
                }
                for(int i = 0; i <= rear; i++)
                {
                    cout<<q[i]<<" ";
                }
            }
            
        }
        else
        {
            cout<<"\n Empty";
        }
    }
};

int main()
{
    CQueue Q;
    int ch;
    do
    {
        cout<<"\n*****CIRCULAR QUEUE*****"
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
    return 0;
}