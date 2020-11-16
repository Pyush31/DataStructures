#include <iostream>
#include <conio.h>
using namespace std;

class Heap
{
    public:
        int heapsize;
        int arraySize = 10;
        int *heap;
        Heap(int arraySize = 10)
        {
            heapsize = 0;
            heap = new int[arraySize];
            for(int i = 0; i < arraySize; i++)
            {
                heap[i] = 0;
            }
        }
        ~Heap()
        {
            delete[] heap;
        }
        int parent(int i){ return int((i-1)/2); }
        int left(int i){ return 2*i+1; }
        int right(int i){ return (2*i)+2; }
        void display();
        void insert(Heap* A,int a);
        void maxHeapify(Heap* A, int i);
        void minHeapify(Heap* A, int i);
        void buildMaxHeap(Heap *A);
        void buildMinHeap(Heap *A);
        void heapsort();
};

void Heap :: display()
{
    for(int i = 0; i < heapsize; i++)
    {
        cout<<heap[i]<<" ";
    }
    cout<<"\n";
}

void Heap :: maxHeapify(Heap* A, int i)
{
    int largest = i;
    int l = left(i);
    int r = right(i);
    if(l < heapsize && A->heap[l] > A->heap[i])
    {
        largest = l;
    }
    
    if(r < heapsize && A->heap[r] > A->heap[largest])
    {
        largest = r;
    }

    if(i != largest)
    {
        int temp = A->heap[i];
        A->heap[i] = A->heap[largest];
        A->heap[largest] = temp;
        maxHeapify(A,largest);
    }    
}

void Heap :: minHeapify(Heap* A, int i)
{
    int smallest = i;
    int l = left(i);
    int r = right(i);
    //finding the smallest among Parent, Left and Right
    if(l < heapsize && A->heap[l] < A->heap[i])
    {
        smallest = l;
    }
    
    if(r < heapsize && A->heap[r] < A->heap[smallest])
    {
        smallest = r;
    }

    if(i != smallest)
    {
        int temp = A->heap[i];
        A->heap[i] = A->heap[smallest];
        A->heap[smallest] = temp;
        minHeapify(A,smallest);
    }    
}

void Heap :: buildMaxHeap(Heap* A)
{
    for(int i = int((heapsize-1)/2); i >= 0; i--)
    {
        maxHeapify(A,i);
    }
}

void Heap :: buildMinHeap(Heap* A)
{
    for(int i = int((heapsize-1)/2); i >= 0; i--)
    {
        minHeapify(A,i);
    }
}

void Heap :: insert(Heap* A,int a)
{
    if(heapsize == arraySize)
    {
        int *temp = new int[2*arraySize];
        for(int i = 0; i < 2*arraySize; i++)
        {
            temp[i] = 0;
        }
        for(int i = 0; i < arraySize; i++)
        {
            temp[i] = heap[i];
        }
        delete heap;
        heap = temp;
        temp = 0;
    }
    heap[heapsize++] = a;
}

void Heap :: heapsort()
{
    buildMaxHeap(this);
    int heapsizeTemp = heapsize;
    int temp = 0;
    //lopping from last index to second index
    for(int i = (heapsize-1); i > 0; i--)
    {
        temp = heap[0];
        heap[0] = heap[i];
        heap[i] = temp;
        heapsize--;
        maxHeapify(this,0);
    }
    heapsize = heapsizeTemp;
    display();
    buildMaxHeap(this);
}

class PriorityQueue{

    private:
        Heap* h;
    public:
        PriorityQueue()
        {
            h = new Heap();
        }
        ~PriorityQueue()
        {
            delete h;
        }
        void display();
        void heap_increase_key(int i,int key);
        void heap_decrease_key(int i,int key);
        void max_heap_insert(int key);
        void min_heap_insert(int key);
        int heap_maximum();
        int heap_minimum();
        int heap_extract_max();
        int heap_extract_min();
};

void PriorityQueue :: display()
{
    h->display();
}

void PriorityQueue :: heap_increase_key(int i,int key)
{

    if(i < 0 || i > (h->heapsize - 1))
    {
        cout<<"Invalid Index\n";
        return;
    }
    if(key < h->heap[i])
    {
        cout<<"New Key is smaller than the Curent Key\n";
        return;
    }
    else
    {
        h->heap[i] = key;
        while (i > 0 && (h->heap[h->parent(i)] < h->heap[i]))
        {
            int temp = h->heap[i];
            h->heap[i] = h->heap[h->parent(i)];
            h->heap[h->parent(i)] = temp;
            i = h->parent(i);
        }   
    }
}

void PriorityQueue :: max_heap_insert(int key)
{
    h->insert(h,key);
    h->buildMaxHeap(h);
}

int PriorityQueue :: heap_maximum()
{
    if(h->heapsize > 0)
    {
        return h->heap[0];
    }
    else
    {
        cout<<"Queue Empty\n";
    }
}

int PriorityQueue :: heap_extract_max()
{
    if(h->heapsize < 0)
    {
        cout<<"Heap Underflow\n";
    }
    else
    {
        int max = h->heap[0];
        h->heap[0] = h->heap[--(h->heapsize)];
        h->maxHeapify(h,0);
        return max;
    }    
}

void PriorityQueue :: heap_decrease_key(int i, int key)
{
    if(i < 0 || i > (h->heapsize - 1))
    {
        cout<<"Invalid Index\n";
        return;
    }
    if(h->heap[i] < key)
    {   
        cout<<"New Key is larger than the Current Key\n";
        return;
    }
    else
    {
        h->heap[i] = key;
        while (i > 0 && (h->heap[h->parent(i)] > h->heap[i]))
        {
            int temp = h->heap[i];
            h->heap[i] = h->heap[h->parent(i)];
            h->heap[h->parent(i)] = temp;
            i = h->parent(i);
        } 
    } 
}

void PriorityQueue :: min_heap_insert(int key)
{
    h->insert(h,key);
    h->buildMinHeap(h);
}

int PriorityQueue :: heap_minimum()
{
    if(h->heapsize > 0)
    {
        return h->heap[0];
    }
    else
    {
        cout<<"Queue Empty\n";
    }
}

int PriorityQueue :: heap_extract_min()
{
    if(h->heapsize < 0)
    {
        cout<<"Heap Underflow\n";
    }
    else
    {
        int min = h->heap[0];
        h->heap[0] = h->heap[--(h->heapsize)];
        h->minHeapify(h,0);
        return min;
    }
    
}

int main()
{
    int queueFlag = 1;
    cout<<"PRIORITY QUEUE\n"
        <<"1. Min Priority Queue\n"
        <<"2. Max Priority Queue\n"
        <<"What Priority Queue You Want? : "; cin>>queueFlag;
    queueFlag--;
    if(!(queueFlag == 0 || queueFlag == 1))
    {
        cout<<"Error\n";
        return -1;
    }
    int flag = 1;
    int op,temp;
    PriorityQueue *p = new PriorityQueue();
    system("CLS");
    cout<<"Indexing Start at Zero\n";
    do
    {
        cout<<"================================================\n"
            <<"Queue - ";p->display();
        cout<<"================================================\n";
        cout<<"Operations :\n";
        if(queueFlag)
        {
            cout<<"1. Insert\n"
                <<"2. Increase Key\n"
                <<"3. Get Maximum\n"
                <<"4. Extract Maximum\n";
        }
        else
        {
            cout<<"1. Insert\n"
                <<"2. Decrease Key\n"
                <<"3. Get Minimum\n"
                <<"4. Extract Minimum\n";
        }
        cout<<"What do you want to perform : "; cin>>op;
        switch(op)
        {
            case 1:
                cout<<"Enter Value : "; cin>>temp;
                if(queueFlag)
                {
                    p->max_heap_insert(temp); 
                }
                else
                {
                    p->min_heap_insert(temp);
                }
                break;
            case 2:
                int i;
                cout<<"Enter Index : "; cin>>i;
                cout<<"Enter Value : "; cin>>temp;
                if(queueFlag)
                {
                    p->heap_increase_key(i,temp);
                }
                else
                {
                    p->heap_decrease_key(i,temp);
                }
                break;
            case 3:
                if(queueFlag)
                {
                    cout<<p->heap_maximum();
                }
                else
                {
                    cout<<p->heap_minimum();
                }
                break;
            case 4:
                if(queueFlag)
                {
                    cout<<p->heap_extract_max();
                }
                else
                {
                    cout<<p->heap_extract_min();
                }
                break;
            default:
                flag = 0;
                break;
        }
        getch();
        system("CLS");
    } 
    while(flag);
    delete p;
    return 0;
}