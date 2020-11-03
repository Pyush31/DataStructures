#include<iostream>
#include<conio.h>
using namespace std;

template <typename T>
class SymmetricMatrix
{
private:
    int size;
    T *s;
public:
    SymmetricMatrix(int size)
    {
        this->size = size;
        if(size > 0)
        {
            size = (size*(size+1))/2;
            s = new T[size];
            for(int i = 0; i < size; i++)
            {
                s[i] = 0;
            }
        }
        else
        {
            s = 0;
        }
    }
    ~SymmetricMatrix()
    {
        delete[] s;
    }

    void store(int i, int j)
    {
        if(i <= size && j <=size)
        {
            T x = 0;
            int k = 0;
            cout<<"Enter value : "; cin>>x;    
            if(i >= j)
            {
                k = (i*(i-1))/2 + j;
            }
            else
            {
                k = (j*(j-1))/2 + i;
            }
            s[k-1] = x;
        }   
        else
        {
            cout<<"Out of Bounds\n";
        }
    }

    int retrieve(int i, int j)
    {
        if(i <= size && j <=size)
        {    
            int k = 0;
            if(i >= j)
            {
                k = (i*(i-1))/2 + j;
            }
            else
            {
                k = (j*(j-1))/2 + i;
            }
            return s[k-1];
        }   
        else
        {
            cout<<"Out of Bounds\n";
        }
    }

    void print()
    {
         for(int i = 1; i <= size; i++)
        {
            for(int j = 1; j <= size; j++)
            {
                int k = 0;
                if(i >= j)
                {
                    k = (i*(i-1))/2 + j;
                }
                else
                {
                    k = (j*(j-1))/2 + i;
                }
                cout<<s[k-1]<<" ";
            }
            cout<<endl;
        }
    }
};

int main()
{
    int size;
    int ch;
    cout<<"\n <<<<< SYMMETRICAL TRIANGULAR MATRIX >>>>>";
    cout<<"\n Enter size of matrix  ";
    cin>>size;
    SymmetricMatrix<int> *S = new SymmetricMatrix<int>(size);
    do
    {
        int i = 0;
        int j = 0;
        cout<<"\n 1. Store "
            <<"\n 2. Retrieve "
            <<"\n 3. Print Matrix "
            <<"\n 4. Exit"
            <<"\n Enter your choice ";
        cin>>ch;
        switch (ch)
        {
        case 1 : cout<<"\n Enter Index "; cin>>i>>j;
            S->store(i,j);
            break;
        case 2 : cout<<"\n Enter Index "; cin>>i>>j;
                 S->retrieve(i,j);
            break;
        case 3 : S->print();
            break;
        default: if(ch != 4) cout<<"\n Invalid choice";
            break;
        }
    } while (ch != 4);
    return 0;
}
