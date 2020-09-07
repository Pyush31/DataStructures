template <typename T>
class Stack
{
    T *s;
    int size;
    int top;
    public:
    Stack()
    {
        size = 10;
        top = -1;
        s = new T[size];
        for(int i = 0; i < size; i++)
        {
            s[i] = 0;
        }
    }

    ~Stack()
    {
        delete[] s;
    }

    void push(T x)
    {
        if(top == (size-1))
        {
            size = size*2;
            T *a = new T[size];
            for (int i = 0; i < size; i++)
            {
                a[i] = s[i];
            }
            delete[] s;
            s = a;
        }
        s[++top] = x;
    }

    int pop()
    {
        if (top != -1)
        {
            return s[top--];
        }
    }
    void show()
    {
        if(top != -1)
        {
            for(int i = 0; i <= top; ++i)
            {
                cout<<s[i]<<" ";
            }
        }
        else
        {
            cout<<"EMPTY";
        }
        cout<<"\n";
    }

    int Top()
    {
        return top;
    }
};