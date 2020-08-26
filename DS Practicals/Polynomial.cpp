// Q.13.	WAP to add two polynomials using linked list representation.

#include <iostream>
#include <iomanip>
#include <conio.h>
using namespace std;


//Polynomial Node Class
template <typename T>
class Poly
{
public:
    Poly *next;
    int p; //power of x
    T cf; //coefficient of x
    //constructor
    Poly(T p = 0, T cf = 0, Poly *next = 0)
    {
        this->p = p;
        this->cf = cf;
        this->next = next;
    }

};

template <typename T>
class Polynomial
{
private:
    //data members
    Poly<T> *head,*tail,*temp;
    int No_nodes;
public:
    //constructor
    Polynomial()
    {
        //initializing the head and tail pointers of Linked List to Null Pointer
        head = tail = temp = 0;
        No_nodes = 0;
    }
    //destructor
    ~Polynomial()
    {
        temp = head;
        Poly<T>* nextPtr;
        while(temp != 0)
        {
            nextPtr = temp->next;
            delete temp;
            temp = nextPtr;
        }
    }

    void Show()
    {
        if(head == 0)
        {
            cout<<"\n 0.x ";
        }
        else
        {
            temp = head;
            while(temp != 0)
            {
                cout<<temp->cf<<"x^"<<temp->p;
                temp = temp->next;
                if(temp != 0)
                    cout<<" + ";
            }
            cout<<"\n";
            temp = 0;
        }
    }


    void Get()
    {
        temp = new Poly<T>();
        cout<<"Enter the power of term : "; cin>>temp->p;
        cout<<"Enter the coefficient of term : "; cin>>temp->cf;
        if(head == 0)
        {
            head = tail = temp;
        }
        else if (temp->p == head->p)
        {
            head->cf += temp->cf;
        }
        else if(temp->p > tail->p)
        {
            tail->next = temp;
            tail = temp;
        }
        else if(temp->p < head->p)
        {
            temp->next = head;
            head = temp;
        }
        else
        {
            Poly<T>* requiredNode = head;
            while(requiredNode != 0)
            {
                if(requiredNode->next->p > temp->p)
                {
                    temp->next = requiredNode->next;
                    requiredNode->next = temp;
                    break;
                }
                else if(requiredNode->next->p == temp->p)
                {
                    requiredNode->next->cf += temp->cf;
                    break;
                }
                requiredNode = requiredNode->next;
            }
            requiredNode = 0;
        }
        temp = 0;
        No_nodes++;

    }


    void operator +(Polynomial<T>& l)
    {
        if(No_nodes > 0 && l.No_nodes > 0)
        {
                    temp = head;
        l.temp = l.head;
        Polynomial<T>* tempPoly = new Polynomial<T>();
        tempPoly->temp = new Poly<T>();
        if(temp->p > l.temp->p)
        {
            tempPoly->temp->p = l.temp->p;
            tempPoly->temp->cf = l.temp->cf;
            tempPoly->head = tempPoly->temp;
            l.temp = l.temp->next;

        }
        else if(temp->p < l.temp->p)
        {
            tempPoly->temp->p = temp->p;
            tempPoly->temp->cf = temp->cf;
            tempPoly->head = tempPoly->temp;
            temp = temp->next;
        }
        else if (temp->p == l.temp->p)
        {
            tempPoly->temp->p = temp->p + l.temp->p;
            tempPoly->temp->cf = temp->cf + l.temp->cf;
            tempPoly->head = tempPoly->temp;
            temp = temp->next;
            l.temp = l.temp->next;
        }
        tempPoly->temp = tempPoly->head;
        while(temp != 0 && l.temp != 0)
        {
            tempPoly->temp->next = new Poly<T>();
            tempPoly->temp = tempPoly->temp->next;
            if(temp->p == l.temp->p)
            {
                tempPoly->temp->p = temp->p + l.temp->p;
                tempPoly->temp->cf = temp->cf + l.temp->cf;
                temp = temp->next;
                l.temp = l.temp->next;
            }
            else if(temp->p < l.temp->p)
            {
                tempPoly->temp->p = temp->p;
                tempPoly->temp->cf = temp->cf;
                temp = temp->next;
            }
            else if(temp->p > l.temp->p)
            {
                tempPoly->temp->p = l.temp->p;
                tempPoly->temp->cf = l.temp->cf;
                l.temp = l.temp->next;
            }
        }
        if(temp != 0)
        {
            while(temp != 0)
            {
                tempPoly->temp->next = new Poly<T>();
                tempPoly->temp = tempPoly->temp->next;
                tempPoly->temp->p = temp->p;
                tempPoly->temp->cf = temp->cf;
                temp = temp->next;
            }
        }
        else if(l.temp != 0)
        {
            while(l.temp != 0)
            {
                tempPoly->temp->next = new Poly<T>();
                tempPoly->temp = tempPoly->temp->next;
                tempPoly->temp->p = l.temp->p;
                tempPoly->temp->cf = l.temp->cf;
                l.temp = l.temp->next;
            }
        }

        //Showing the node
        tempPoly->Show();
        }

    }
};


int main()
{

    Polynomial<int> *poly;
    Polynomial<int> *P1 = new Polynomial<int>();
    Polynomial<int> *P2 = new Polynomial<int>();

    int cp = 1;
    int ch;
    do
    {
        cout<<endl;
        cout<<setw(20)<<setfill(' ')<<" POLYNOMIAL ADDITION"<<endl;
        cout<<setw(60)<<setfill('*');
        cout<<"\n Polynomial 1 : "; P1->Show();
        cout<<"\n Polynomial 2 : "; P2->Show();
        cout<<"\n current polynomial is :"<<cp;
        cout<<"\n 1. Insert the polynomial "
            <<"\n 2. Switch polynomial "
            <<"\n 3. Add"
            <<"\n 4. Exit";
        cout<<"\n Enter What you want to do ? : ";
        cin>>ch;

        switch (ch)
        {
            case 1: poly->Get();
                break;
            case 2: cp = (cp == 1)? 2 : 1;
                    poly = (poly == P1)? P2: P1;
                break;
            case 3:
                cout<<setw(30)<<setfill('-')<<"\n";
                cout<<"ADDITION : "; *P1 + *P2;
                cout<<setw(30)<<setfill('-')<<"\n";
                cout<<"Press Enter to Continue ";
                getch();
                break;
            case 4: exit(0);

            default: cout<<"\n invalid choice ";

        }
    }while(ch != 4);

    delete P1;
    delete P2;
    return 0;
}
