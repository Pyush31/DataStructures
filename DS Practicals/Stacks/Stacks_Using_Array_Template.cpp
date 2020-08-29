/*
5.Perform the following Stack operations using Array implementation using Templates:
    a)	Push
    b)	Pop
    c)	Clear
*/


#include <iostream>
#include <iomanip>
#include <conio.h>
using namespace std;

template <typename T>
class Stack
{
    private:
        T S[10];
        int size = 10;
        int top = -1;
    public:
        void Push()
        {
            T x;
            cout<<"\n Enter the element ";
            cin>>x;
            if(top != (size-1))
            {
                top++;
                S[top] = x;
            }
            else cout<<"\n Stack full ";
        }

        void Pop()
        {
            if(top != -1) S[top--];
            else cout<<"\n Empty ";
        }

        void Clear()
        {
            cout<<"\n clearing whole Stack ";
            top = -1;
        }

        void Show()
        {
            if(top != -1)
            {
                for(int i = 0; i <= top; ++i)
                    {
                        cout<<S[i]<<" ";
                    } getch();
            }
            else
            {
                cout<<"EMPTY";
            }
        }
};

int main()
{
    Stack<int> S;
    int ch;

    do
    {   system("cls");
        cout<<"\n STACK "<<endl;
        cout<<"\n Operations "
            <<"\n 1. Push "
            <<"\n 2. Pop "
            <<"\n 3. Clear "
            <<"\n 4. Display "
            <<"\n 5. Exit "
            <<"\n Enter your choice ";
        cin>>ch;
        switch(ch)
        {
            case 1 : S.Push();
                     break;
            case 2 : S.Pop();
                     break;
            case 3 : S.Clear();
                     break;
            case 4 : S.Show();
                     break;
            case 5 : exit(0);
            default: cout<<"\n Invalid choice ";
        }
    }while(ch != 5);
    return 0;
}

