// Q.14. Menu driven program of ordered linked list with insertion, deletion and merging.

#include <iostream>
#include <iomanip>
#include <conio.h>
using namespace std;

//Node Class
template <typename T>
class Node
{
public:
    T data;
    Node* next;
    //constructor
    Node(T data = 0, Node* next = 0)
    {
        this->data = data;
        this->next = next;
    }
    //destructor
    ~Node()
    {
        cout<<"Destroying Node; DATA = <<"<<this->data<<"\n";
    }
};

template <typename T>
class OrderedLinkedList
{
private:
    //data members
    int No_nodes;
    Node<T> *head,*tail,*temp;
public:
    //constructor
    OrderedLinkedList()
    {
        head = tail = temp = 0;
        No_nodes = 0;
    }
    //destructor
    ~OrderedLinkedList()
    {
        temp = head;
        Node<T>* nextptr = 0;
        cout<<"Destroying The List\n";
        while(temp != 0)
        {
            nextptr = temp->next;
            delete temp;
            temp = nextptr;
        }
        cout<<"Done.\n";
    }

    //member functions
    //insert function
    void insert()
    {
        temp = new Node<T>();
        cout<<"Enter the Data : ";cin>>temp->data;
        if(head == 0)
        {
            head = tail = temp;
            No_nodes++;
        }
        else if(head->data == temp->data || tail->data == temp->data)
        {
            return;
        }
        else if(head->data > temp->data)
        {
            temp->next = head;
            head = temp;
            No_nodes++;
        }
        else if(tail->data < temp->data)
        {
            tail->next = temp;
            tail = temp;
            No_nodes++;
        }
        else
        {
            Node<T>* requiredNode = head;
            while(requiredNode->next->data < temp->data)
            {
                requiredNode = requiredNode->next;
            }
            if(requiredNode->next->data == temp->data)
            {
                //beacuse the Node Already Exists
                return;
            }
            else
            {
                if(requiredNode->next == tail)
                {
                    tail = temp;
                }
                temp->next = requiredNode->next;
                requiredNode->next = temp;
                No_nodes++;
            }

        }
        temp = 0;

    }

    //delete function
    void Delete()
    {
        int loc;
        cout<<"Enter the Location : "; cin>>loc;
        if(No_nodes > 0)
        {
            if(loc < 0 || loc > No_nodes)
            {
                cout<<"INVALID\n";
                cout<<"Press Enter to Continue ";
                getch();
            }
            else if(loc == 1)
            {
                temp = head;
                if(No_nodes == 1)
                {
                    head = tail = 0;
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
                int counter = 1;
                temp = head;
                while(counter != (loc-1))
                {
                    temp = temp->next;
                    counter++;
                }
                Node<T>* requiredNode = temp->next;
                temp->next = requiredNode->next;
                if(requiredNode == tail)
                {
                    temp->next = 0;
                    tail = temp;
                }
                delete requiredNode;
                temp = requiredNode = 0;
                No_nodes--;
            }

        }
    }
    //merge function
    void merge(OrderedLinkedList<T> &A,OrderedLinkedList<T> &B)
    {
        //temporary list
        OrderedLinkedList<T> *tempList = new OrderedLinkedList<T>();
        if(A.No_nodes > 0 && B.No_nodes > 0)
        {
            A.temp = A.head;
            B.temp = B.head;
            //setting the head of the temporary list
            tempList->temp = new Node<T>();
            tempList->No_nodes++;
            if(A.temp->data > B.temp->data)
            {
                tempList->temp->data = B.head->data;
                B.temp = B.temp->next;
            }
            else if (B.temp->data > A.temp->data)
            {
                tempList->temp->data = A.head->data;
                A.temp = A.temp->next;
            }
            else if(A.temp->data == B.temp->data)
            {
                tempList->temp->data = A.head->data;
                A.temp = A.temp->next;
                B.temp = B.temp->next;
            }
            //adding the head of the temporary list
            tempList->head = tempList->tail =  tempList->temp;
            while(A.temp != 0 && B.temp != 0)
            {
                tempList->temp->next = new Node<T>();
                tempList->temp = tempList->temp->next;
                if(A.temp->data > B.temp->data)
                {
                    tempList->temp->data = B.temp->data;
                    B.temp = B.temp->next;
                }
                else if(A.temp->data < B.temp->data)
                {
                    tempList->temp->data = A.temp->data;
                    A.temp = A.temp->next;
                }
                else if(A.temp->data == B.temp->data)
                {
                    tempList->temp->data = A.temp->data;
                    A.temp = A.temp->next;
                    B.temp = B.temp->next;
                }
            }
            if(A.temp != 0)
            {
                while(A.temp != 0)
                {
                    tempList->temp->next = new Node<T>();
                    tempList->temp = tempList->temp->next;
                    tempList->temp->data = A.temp->data;
                    A.temp = A.temp->next;
                }
            }
            else if(B.temp != 0)
            {
                while(B.temp != 0)
                {
                    tempList->temp->next = new Node<T>();
                    tempList->temp = tempList->temp->next;
                    tempList->temp->data = B.temp->data;
                    B.temp = B.temp->next;
                }
            }
            tempList->traverse();
            getch();
        }
    }
    //traverse function
    void traverse()
    {
        if(No_nodes > 0)
        {
            temp = head;
            while(temp != 0)
            {
                cout<<temp->data<<" ";
                temp = temp->next;
            }
            cout<<"\n";
            temp = 0;
        }
        else
        {
            cout<<"EMPTY\n";
        }

    }
};


int main()
{
    OrderedLinkedList<int>* list_1 = new OrderedLinkedList<int>();
    OrderedLinkedList<int>* list_2 = new OrderedLinkedList<int>();
    OrderedLinkedList<int>* list = list_1;
    int currentList = 1;
    int choice;
    do
    {
        cout<<"\n";
        cout<<setw(20)<<setfill(' ')<<"ORDERED LINKED LIST\n";
        cout<<setw(30)<<setfill('-')<<"\n";
        cout<<"LIST  1: "; list_1->traverse();
        cout<<"LIST  2: "; list_2->traverse();
        cout<<setw(30)<<setfill('-')<<"\n";
        cout<<"CURRENTLY SELECTED - > "<<currentList<<"\n";
        cout<<setw(30)<<setfill('-')<<"\n";
        cout<<"1. Insert \n"
            <<"2. Delete \n"
            <<"3. Merge \n"
            <<"4. Switch \n"
            <<"5. Exit\n";
        //getting user input
        cout<<"Enter What you want to do ? : ";
        cin>>choice;
        //switch cases
        switch (choice)
        {
            case 1:
                list->insert();
                break;
            case 2:
                list->Delete();
                break;
            case 3:
                list->merge(*list_1,*list_2);
                break;
            case 4:
                currentList = (currentList == 1) ? 2 : 1;
                list = (list == list_1) ? list_2 : list_1;
                break;
            case 5: exit(0);
            default:
                break;
        }
        system("CLS");

    }while(choice !=5);


}
