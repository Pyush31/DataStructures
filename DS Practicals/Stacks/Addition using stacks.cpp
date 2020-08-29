// Q.8.	WAP to add two large integers using stack
//NOT COMPLETED YET STILL IN PROGRESS


#include <iostream>
#include <iomanip>
#include <string>
#include <ctype.h>
using namespace std;

class Stack
{
    int s[10];
    int S[10];
    int size;
    int top;
public:
    Stack()
    {
        int S[size] = {0};
        int size = 100;
        int top = -1;
        int s[size] = {0};
    }
    void push()
    {
        top++;
        cout<<"\n enter the element ";
        cin>>s[top];
    }
    void pop()
    {
        s[top--];
    }
    void show()
    {
        cout<<endl<<s[top];
    }
    Stack operator +(Stack &obj)
    {
        Stack S;
        S.s[top] = this->s[top] + obj.s[top];
        return (S);
    }

};


int main()
{
    Stack S, s1, s2;
    cout<<"\n first stack ";
    s1.push();
    cout<<"\n second stack ";
    s2.push();
    cout<<"\n addition ";
    S = s1 + s2;
    return 0;
}
