// 1. Write a program, using templates, to sort a list of n elements. Give user the option to perform sorting
// using Insertion sort, Bubble sort or Selection sort.

#include <iostream>
#include <conio.h>
using namespace std;

template <typename T>
class sorting
{
private:
    int size = 10;
    T* L;
public:
    sorting(int size = 10)
    {
        this->size = size;
        this->L = new T[size];
        for (int i = 0; i < size; i++)
        {
            L[i] = 0;
        }
    }
    
    void insert()
    {
        for (int i = 0; i < size; i++)
        {
            cin>>L[i];
        }
    }

    void show()
    {
        for (int i = 0; i < size; i++)
        {
            cout<<L[i]<<" ";
        }
    }

    void insertionSort()
    {
        for (int i = 0; i < size; i++)
        {
            int key = L[i];
            int j = i-1;
            while((j >= 0) && (key < L[j]))
            {
                L[j+1] = L[j];
                j--;
            }
            L[j+1] = key;
        }
    }

    void bubbleSort()
    {
        for (int i = 0; i < size; i++)
        {
            for (int j = 0; j < size-1; j++)
            {
                if (L[j] > L[j+1])
                {
                    T temp = L[j];
                    L[j] = L[j+1];
                    L[j+1] = temp;
                }
            }
        }
    }

    void selectionSort()
    {
        for (int i = 0; i < size-1; i++)
        {
            int min = i;
            for (int j = 0; j < size; j++)
            {
                if (L[j] < L[min])
                {
                    min = j;
                }
            }
            if(min != i)
            {
                T temp = L[i];
                L[i] = L[min];
                L[min] = temp;  
            }
        }        
    }

};

int main()
{
    int s;
    int ch;
        
    do
    {
        cout<<"\n Enter the size of list    ";
        cin>>s;
        sorting<int> *S = new sorting<int>(s);
        cout<<"\n ENter the list"<<endl;
        S->insert();
        cout<<"\n       <<<<<<SORTING>>>>>>     "
            <<"\n 1. INSERTION SORT"
            <<"\n 2. BUBBLE SORT"
            <<"\n 3. SELECTION SORT"
            <<"\n 4. Exit"
            <<"\n Enter Your Choice How do you want to sort the list.   ";
        cin>>ch;
        switch (ch)
        {
        case 1: S->insertionSort(); 
            break;
        case 2: S->bubbleSort();
            break;
        case 3: S->selectionSort(); 
            break;
        case 4 : ch = 4;
            break;
        default:cout<<"\n Invalid choice";
            break;
        }
        S->show();
        delete S;
    } while (ch != 4);
    
    return 0;
}