#include <iostream>
using namespace std;

int main()
{
    int n,x;
    cout<<"\n<<<<<<<<<<<<< Ascending Array Search >>>>>>>>>>>>>>>>";
    int *A = new int [n];
    for (int i = 0; i < n; i++)
    {
        A[i] = 0;
    }
    cout<<"\n Enter the size of array   ";cin>>n;
    cout<<"\n Enter the elements of the array :"<<endl;
    for (int i = 0; i < n; i++)
    {
        cin>>A[i];
    }

    for (int i = 0; i < n; i++)
    {
        int key = A[i];
        int j = i-1;
        while(j >= 0 && A[j] > key)
        {
            A[j+1] = A[j];4
            j--;
        }
        A[j+1] = key;
    }
    cout<<"\n Sorted Array"<<endl;
    for (int i = 0; i < n; i++)
    {
        cout<<A[i]<<" ";
    }
    cout<<"\n Enter the Element you want to search  ";cin>>x;
    for (int i = 0; i < n; i++)
    {
        if (A[i] == x)
        {
            cout<<"\n Element found at index "<<i;
            return 0;
        }
    }
    cout<<"\n Element not found ";
    return -1;
}