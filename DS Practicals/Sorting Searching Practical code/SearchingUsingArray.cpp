/* 2. Given a list of N elements, which follows no particular arrangement, you are required to search an
element x in the list. The list is stored using array data structure. If the search is successful, the output
should be the index at which the element occurs, otherwise returns -1 to indicate that the element is
not present in the list. Assume that the elements of the list are all distinct. Write a program to perform
the desired task.
*/

#include <iostream>
#include <conio.h>
using namespace std;

int main()
{
    int n;
    int x;
    int *A = new int[n];
    for (int i = 0; i < n ; i++)
    {
        A[i] = 0;
    }
    cout<<"\n       <<<<<SEARCH>>>>>      ";
    cout<<"\n Enter the size of array   "; cin>>n;
    cout<<"\n Enter the Elements of array "<<endl;
    for (int i = 0; i < n; i++)
    {
        cin>>A[i];
    }
    cout<<"\n Enter the element you want to search  ";cin>>x;
    for (int i = 0; i < n; i++)
    {
        if (A[i] == x)
        {
            cout<<"\n Element found at index "<<i;
            return 0;
        }
    }
    cout<<"\n Element not found";
    return -1;
}