// Q. Delimiter matching using stack

#include<iostream>
#include<string.h>
#include<iomanip>
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

void Delimiter(string s)
{
    Stack<char> st;
    for(int i = 0; i<s.length(); i++)
    {
        char temp = s[i];
         if(temp == '(' || temp == '{' || temp == '[')
        {
            st.Push(s[i]);
        }
        else if(temp == ')' || temp == '}' || temp == ']')
        {
            if(st.Top() == -1)
            {
                cout<<"Invalid Expression\n";
                return;
            }
            else
            {
                char check = st.Pop();
                switch(check)
                {
                    case '(':
                        if(temp != ')')
                        {
                            cout<<"Invalid Expression\n";
                            return;
                        }
                        break;
                    case '{':
                        if(temp != '}')
                        {
                            cout<<"Invalid Expression\n";
                            return;
                        }
                        break;
                    case '[':
                        if(temp != ']')
                        {
                            cout<<"Invalid Expression\n";
                            return;
                        }
                        break;
                    default:
                        break;
                }
            }

        }
    }
    if(st.Top() == -1)
    {
        cout<<"\n Expression is correct ";
        return;
    }
    cout<<"\n Expression Error ";
    return;
}

int main()
{
    cout<<" DELIMITER CHECKING "<<endl;
    string s;
    cout<<"\n Enter Expression ";
    getline(cin,s);
    Delimiter(s);
    return 0;
}

