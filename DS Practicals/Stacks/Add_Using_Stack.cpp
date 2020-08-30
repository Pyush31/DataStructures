#include<iostream>
#include<iomanip>
#include<string>
#include<ctype.h>
using namespace std;

template <typename T>
class Stack
{
    private:
        T S[10];
        int size = 10;
        int top = -1;
    public:
        void Push(T x)
        {
            if(top != (size-1))
            {
                top++;
                S[top] = x;
            }
            else cout<<"\n Stack full ";
        }

        T Pop()
        {
            if(top != -1) return S[top--];
            else cout<<"\n Empty ";
        }
        int Top()
        {
            return top;
        }

        void Show()
        {
            if(top != -1)
            {
                for(int i = 0; i <= top; ++i)
                    {
                        cout<<S[i]<<" ";
                    }
            }
            else
            {
                cout<<"EMPTY";
            }
        }
};


void Add(string x, string y)
{
    int carry = 0, sum = 0, i=0 ;
    Stack<int> a,b;

    while(i != x.length())
    {
        string temp = "";
        temp +=x[i];
        a.Push(stoi(temp));
        i++;
    }
    i = 0;
    while(i != y.length())
    {
        string temp = "";
        temp +=y[i];
        b.Push(stoi(temp));
        i++;
    }
    Stack <int> c;
    while(a.Top() != -1 || b.Top() != -1)
    {
        sum = carry + a.Pop() + b.Pop();
        carry = sum/10;
        sum = sum%10;
        c.Push(sum);
        sum = 0;
    }
    if(carry != 0) c.Push(carry);
    while(c.Top() != -1)
    {
        i = c.Pop();
        cout<<i;
    }
}


int main()
{
    system("cls");
    string x , y;

    cout<<"\n Adding to large numbers "<<endl;
    cout<<"\n Enter the first number ";
    getline(cin,x);
    cout<<"\n Enter the second number ";
    getline(cin,y);
    cout<<"\n SUM = ";
    Add(x,y);
    return 0;

}
