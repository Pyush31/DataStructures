#include<iostream>
#include<conio.h>
using namespace std;

template<typename T>
class LowerTriangal
{
private:
    int size;
    int dim;
    T *l;
public:
    LowerTriangal(int dim)
    {
        this->dim = dim;
        if (dim > 0)
        {
            size = ((dim+1)*dim)/2;
            cout<<size;
            l = new T[size];
            for(int i = 0; i < size; i++)
            {
                l[i] = 0;
            }
        }
        else
        {
            l = 0;
        }
    }
    ~LowerTriangal()
    {
        delete[] l;
    }

    void print()
    {
        for(int i = 1; i <= dim; i++)
        {
            for(int j = 1; j <= dim; j++)
            {
                if(i >= j)
                {
                    int k = (i*(i-1))/2 + j;
                    cout<<l[k-1]<<" ";
                }
                else
                {
                    cout<<0<<" ";
                }
            }
            cout<<endl;
        }
    }

    void insert(int i, int j)
    {
        if((i <= dim) && (j <= dim))
        {
            if(i >= j)
            {
                T x = 0;
                cout<<"Enter value : "; cin>>x;    
                int k = (i*(i-1))/2 + j;
                l[k-1] = x;
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
        if(i <= dim && j <= dim)
        {
            if(i >= j)
            { 
                int k = (i*(i-1))/2 + j; 
                return l[k-1];
            }
        }
        return 0;
    }
};

int main()
{
    int size;
    int ch;
    cout<<"\n<<<<<< LOWER TRIANGLE >>>>>";
    cout<<"\n Enter size of matrix "; cin>>size;
    LowerTriangal<int> *L = new LowerTriangal<int>(size);
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
            L->insert(i,j);
            break;
        case 2 : cout<<"\n Enter Index "; cin>>i>>j;
                 L->retrieve(i,j);
            break;
        case 3 : L->print();
            break;
        default: if(ch != 4) cout<<"\n Invalid choice";
            break;
        }
    } while (ch != 4);
    return 0;
}
