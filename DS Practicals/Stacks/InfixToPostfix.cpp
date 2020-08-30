// Q. Conversion from Infix to Postfix

#include<iostream>
#include<string>
#include<iomanip>
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

        int TopElement()
        {
            if(top == -1) return S[top];
            else return 0;
        }
};

void Conversion(string s)
{
    Stack<char> C;
    string P = "";
    char temp;
    for(int i = 0; i<s.length(); i++)
    {
        temp = s[i];
        if(isdigit(temp))
        {
            P += temp;
        }
        else
        {
            switch(temp)
            {
                case '+':
                    if(C.TopElement() == '*' || C.TopElement() == '/')
                    {
                        do
                        {
                            if(P.back() != ' ')
                                P += ' ';
                            P += C.Pop();
                        }
                        while(C.TopElement() == '*' || C.TopElement() == '/');
                    }
                    C.Push(temp);
                    break;
                case '-':
                    if(C.TopElement() == '*' || C.TopElement() == '/')
                    {
                        do
                        {
                            if(P.back() != ' ')
                                P += ' ';
                            P += C.Pop();
                        }
                        while(C.TopElement() == '*' || C.TopElement() == '/');
                    }
                    C.Push(temp);
                    break;
                case '*':
                case '/':
                case '(':
                    C.Push(temp);
                    break;
                case ')':
                    while(C.Top() != -1 && C.TopElement() != '(')
                    {
                        if(P.back() != ' ')
                            P += ' ';
                        P += C.Pop();
                    }
                    C.Pop();
                    break;
                case ' ':
                    if(P.back() != ' ')
                        P += ' ';
                    break;
                default : cout<<"\n Invalid choice ";
            }
        }
    }

    while(C.Top() != -1)
        {
            if(P.back() != ' ') P += ' ';
            temp = C.Pop();
            P += temp;
        } cout<<" : "<<P;
}

int main()
{
    cout<<"\n CONVERSION INFIX TO POSTFIX ";
    cout<<"\n Warning : Press Enter at the end of the Expression only"
        <<"\n         : Also Give space between two characters "<<endl;

    string s;
    cout<<"\n Enter the Expression ";
    getline(cin,s);
    Conversion(s);
    return 0;
}
