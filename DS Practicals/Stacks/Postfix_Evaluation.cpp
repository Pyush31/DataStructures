// Q.9. WAP to evaluate postfix expression using Stack

#include<iostream>
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

void PostfixEva(string s)
{
    Stack <int>S ;
    for(int i = 0; i < s.length(); ++i)
    {
        if(isdigit(s[i]))
        {
            S.Push((int)s[i]-48);
        }
        else if(s[i] == ' ')
        {
            i++;
            string temp;
            while (s[i] != ' ')
            {
                char c = s[i];
                temp += c;
                i++;
            }
            S.Push(stoi(temp));
        }
        else
        {
            int n1 = S.Pop();
            int n2 = S.Pop();
            switch(s[i])
            {
                case '+':
                    S.Push(n2 + n1);
                    break;
                case '-':
                    S.Push(n2 - n1);
                    break;
                case '*':
                    S.Push(n2 * n1);
                    break;
                case '/':
                    S.Push(n2 / n1);
                    break;
            }
        }
    }
    cout<<S.Pop();

}

int main()
{
    cout<<"\n POSTFIX EVALUATION ";
    cout<<endl<<"\n to enter more than one number press space instead of Enter";
    string s;
    cout<<"\n Enter the Expression ";
    getline(cin,s);
    PostfixEva(s);
    return 0;
}
