#include<iostream>
#include<conio.h>
using namespace std;

class Treenode
{
    public:
        Treenode *l,*r;
        int data,bF;
        Treenode(int data = 0,Treenode *l =0, Treenode *r = 0)
        {
            this->data = data;
            this->l = l;
            this->r = r;
            bF = 0;
        }
        ~Treenode()
        {
            cout<<"\n Deleting Treenode with Data : "<<this->data;
        }
};

class AVLTrees
{
public:
    Treenode *root;
    AVLTrees()
    {
        root = 0;
    }
    ~AVLTrees()
    {
        clear(this->root);
    }
    Treenode *returnroot()
    {
        return root;
    }

    void clear(Treenode *root)
    {
        Treenode *temp = 0;
        if (root != 0)
        {
            clear(root->l);
            clear(root->r);
            temp = root;
            delete temp;
        }
        return;
    }

    int height(Treenode *root)
    {
        if (root == 0)
        {
            return -1;
        }
        int lheight = height(root->l);
        int rheight = height(root->r);
        int height = (lheight > rheight) ? lheight:rheight;
        return height+1;
    }

    void setbF( Treenode *root)
    {
        if (root != 0)
        {
            root->bF = height(root->l) - height(root->r);
            setbF(root->l);
            setbF(root->r);
        }
    }

    int getbF(Treenode *root)
    {
        if (root == 0)
        {
            return 0;
        }
        return(height(root->l) - height(root->r));
    }

    Treenode* right(Treenode *u)
    {
        Treenode *x = u->l;
        Treenode *y = u;
        y->l = x->r;
        x->r = y;
        return x;
    }

    Treenode* left(Treenode *u)
    {
        Treenode *x = u->r;
        Treenode *y = u;
        y->r = x->l;
        x->l = y;
        return x;
    }

    void Display(Treenode *root)
    {
        if (root != 0)
        {
            cout<<"\n("<<root->bF<<" "<<root->data<<")";
            Display(root->l);
            Display(root->r);
        }
        return;
    }

    Treenode* insert(Treenode *root,int data)
    {
        if (root == 0)
        {
            return new Treenode(data,0,0);
        }
        else
        {
            if (root->data < data)
            {
                root->r = insert(root->r,data);
            }
            else if (root->data > data)
            {
                root->l = insert(root->l,data);
            }
        }
        if (root != 0)
        {
            int bF = getbF(root);
            if (bF > 1 && data < root->l->data)
            {
                root = right(root);
            }
            else if (bF < -1 && data > root->r->data)
            {
                root = left(root);
            }
            else if (bF < -1 && data < root->r->data)
            {
                root->r = right(root->r);
                root = left(root);
            }
            else if (bF > 1 && data > root->l->data)
            {
                root->l = left(root->l);
                root = right(root);
            }
        }
        return root;
    }

    Treenode* Deletenode(Treenode *root,int data)
    {
        if (root != 0)
        {
            if (root->data == data)
            {
                Treenode *temp = 0;
                if (root->l != 0 && root->r == 0)
                {
                    temp = root;
                    root = root->l;
                    delete temp;
                }
                else if (root->l == 0 && root->r != 0)
                {
                    Treenode *temp = root;
                    root = root->r;
                    delete temp;
                }
                else if (root->l != 0 && root->r != 0)
                {
                    Treenode *leftTree = root->l;
                    Treenode *rightmostleft = leftTree;
                    while (rightmostleft->r != 0)
                    {
                        rightmostleft = rightmostleft->r;
                    }
                    int d = rightmostleft->data;
                    root = Deletenode(root,rightmostleft->data);
                    root->data = d;
                }
                else if (root->l == 0 && root->r == 0)
                {
                   delete root;
                   root = 0;
                }
                return root;
            }
            else if (root->data < data)
            {
                root->r = Deletenode(root->r,data);
            }
            else if (root->data > data)
            {
                root->l = Deletenode(root->l,data); 
            }
            
            if (root != 0)
            {
                int bF = getbF(root);
                int bfright = getbF(root->r);
                int bfleft = getbF(root->l);
                if (bF > 1 && bfleft >= 0)
                {
                    root = right(root);
                }
                else if (bF < -1 && bfright <= 0)
                {
                    root = left(root);
                }
                else if (bF < -1 && bfright > 0)
                {
                    root->r = right(root->r);
                    root = left(root);
                }
                else if(bF > 1 && bfleft < 0)
                {
                    root->l = left(root->l);
                    root = right(root);
                }
            }
        }
        return root;
    }

};

int main()
{
    AVLTrees *tree = new AVLTrees();
    int ch = 0;
    int flag = true;
    int data = 0;
    cout<<"\n Node ->(Balance Factor, Data";
    do
    {
        cout<<"\n AVL TREES";
        tree->Display(tree->returnroot());
        cout<<"\n Enter your choice "
            <<"\n 1. Insert "
            <<"\n 2. Delete \n";
        cin>>ch;
        switch (ch)
        {
        case 1: cout<<"\n Enter Data "; cin>>data;
                tree->root = tree->insert(tree->returnroot(),data);
            break;
        case 2: cout<<"\n Enter Data "; cin>>data;
                tree->root = tree->Deletenode(tree->returnroot(),data);
            break;
        
        default: flag = 0;
            break;
        }
        tree->setbF(tree->returnroot());
    } while (flag);
    delete tree;
    return 0;
}
