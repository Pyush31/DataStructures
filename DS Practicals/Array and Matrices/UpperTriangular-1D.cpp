#include<iostream>
#include<conio.h>
using namespace std;

template <typename T>
class UpperTriangular
{
private:
    int size;
    T *u;
public:
    UpperTriangular(int size)
    {
        this->size = size;
        if(size > 0)
        {
            size = ((size+1)*size)/2;
            u = new T[size];
            for(int i = 0; i < size; i++)
            {
                u[i] = 0;
            }
        }
        else
        {
            u = 0;
        }
    }
    ~UpperTriangular()
    {
        delete[] u;
    }

    void print()
    {
        for(int i = 1; i <= size; i++)
        {
            for(int j = 1; j <= size; j++)
            {
                if(i <= j)
                {
                    int k = size - (j*(j-1)/2) + (i-j);
                    cout<<u[k-1]<<" ";
                }
                else
                {
                    cout<<0<<" ";
                }
            }
            cout<<"\n";
        }
    }

    void store(int i, int j)
    {
        if((i <= size) && (j <= size))
        {
            if(i <= j)
            {
                T temp = 0;
                cout<<"Enter value : "; cin>>temp;    
                int k = size - (j*(j-1)/2) + (i-j);
                u[k-1] = temp;
            }       
        }
        else
        {
            cout<<"Out of Bounds\n";
            return;
        }
    }

    int retrieve(int i, int j)
    {
      if(i <= size && j <= size)
        {
            if(i <= j)
            { 
                int k = size - (j*(j-1)/2) + (i-j); 
                return u[k-1];
            }
        }
        return 0;  
    }
};

int main()
{
    int size;
    int ch;
    cout<<"\n <<<<< UPPER TRIANGULAR MATRIX >>>>> ";
    cout<<"\n Enter size of matrix  ";
    cin>>size;
    UpperTriangular<int> *U = new UpperTriangular<int>(size);
    do
    {
        int i = 0;
        int j = 0;
        cout<<"\n 1. Insert "
            <<"\n 2. Retrieve "
            <<"\n 3. Print Matrix "
            <<"\n 4. Exit"
            <<"\n Enter your choice ";
        cin>>ch;
        switch (ch)
        {
        case 1 : cout<<"\n Enter Index "; cin>>i>>j;
            U->store(i,j);
            break;
        case 2 : cout<<"\n Enter Index "; cin>>i>>j;
                 U->retrieve(i,j);
            break;
        case 3 : U->print();
            break;
        default: if(ch != 4) cout<<"\n Invalid choice";
            break;
        }
    } while (ch != 4);
    return 0;
}
