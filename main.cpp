#include <iostream>
//#include"Btree.h"

using namespace std;
struct Tree
{
   int data;
   Tree *left,*right;
   Tree **parent;
};

class  Btree
{
    static int sum_of_leaf;
    static int sum_of_node;
    public:

        Tree *root;
        Btree()
        {
            root=NULL;
        }

        void create_tree(int number);

        void preorder(Tree*);

        void inorder(Tree*);

        void finalorder(Tree*);

        void deletenode(Tree*);
        void cancel(Tree*);

       void display1()
        {
            preorder(root);
            cout<<endl;

        }
        /* void display2()
        {
            inorder(root);
            cout<<endl;

        }
        void display3()
        {
           finalorder(root);
            cout<<endl;

        }*/
        int NO_count(Tree*);
        int findleaf(Tree*);
        int findnode(Tree*);


};



int Btree::n=0;
int Btree::m=0;

void Btree::create_tree(int number)
{
    Tree* newnode=new Tree;
    newnode->data=number;
    newnode->left=NULL;
    newnode->right=NULL;

    if(root==NULL)
    {
        root=newnode;

    }
    else
    {
        Tree* goback;
        Tree* current=root;
        while(current!=NULL)
        {
            goback=current;
            if(current->data > number)
                {
                    current=current->left;

                }

            else
                {
                    current=current->right;

                }


        }

        if(goback->data > number)
               {
                   goback->left=newnode;

                }

        else
            {
                goback->right=newnode;

            }



    }
}

int Btree::NO_count(Tree*p)
{
    if(p==NULL)
        return 0;
    else

         return NO_count(p->left)+NO_count(p->right)+1;
}

void Btree::preorder(Tree* p)
{
    if(p!=NULL)
    {
        cout<<p->data<<" ";
        preorder(p->left);
        preorder(p->right);
    }
}

void Btree::inorder(Tree* p)
{
    if(p!=NULL)
    {

        preorder(p->left);
        cout<<p->data<<" ";
        preorder(p->right);
    }
}
void Btree::finalorder(Tree* p)
{
    if(p!=NULL)
    {

        preorder(p->left);
        preorder(p->right);
        cout<<p->data<<" ";
    }
}

int Btree::findleaf(Tree*p)
{   if(p==NULL)
        return 0;
    else
    {
        if(p->left==NULL && p->right==NULL)
           return n+=1;
       else
        {
          findleaf(p->left);
          findleaf(p->right);
         }
        return n;
     }
}
int Btree::findnode(Tree*p)
{
    if(p==NULL)
        return 0;
    else
    {
        if(p->left!=NULL && p->right!=NULL)
         {

            findnode(p->left);
            findnode(p->right);
         }

        if(p->left!=NULL && p->right==NULL)
         {
            m+=1;
            findnode(p->left);

         }

        if(p->left==NULL && p->right!=NULL)
         {
            m+=1;

            findnode(p->right);
         }
    }
    return m;
}

void Btree::deletenode(Tree *p)
{
    Tree *current;
   if(p==NULL)
    {
       cout<<"it's a empty tree!"<<endl;
        exit(1);
    }
    else
    { while(p!=NULL)
       {
           current=p;

           if(current->left==NULL && current->right==NULL)
         {

              free(current);
               cout<<"success1"<<endl;

         }
        else
         {
             cout<<"dd"<<endl;
                   if(current->right!=NULL)
                   {
                      cancel(current->right);
                       cout<<"kkk"<<endl;

                   }

                   else
                      {
                          cancel(current->left);
                          cout<<"right";

                      }

          }
       }




    }


}

void Btree::cancel(Tree* current)
{
    if(current->left==NULL && current->right==NULL)
         {
            cout<<current->data;
            free(current);
            cout<<" success"<<endl;
                //goto L;
         }
    else
         {
            if(current->right!=NULL)
                {
                     cancel(current->right);
                     //cout<<"kkk"<<endl;
                }

             else
                     cancel(current->left);

          }

}

int main()
{
    Btree A;
    int n;
    //int n[10]={1,2,3,4,5,6,7,8,9,10};
    srand((unsigned )time(NULL));
  while(true)

{
    for(int i=0; i<10; i++)
    {
        n=1+rand()%10;
        cout<<n<<" ";
        A.create_tree(n);
    }
    //A.create_tree(2);
    //cout<<"sum_no"<<A.NO_count(A.root)<<endl;
    //cout<<"leaf"<<A.findleaf(A.root)<<endl;
   // cout<<"pre"<<endl;
  //  A.display1();

    A.deletenode(A.root);
    //cout<<"sum_no"<<A.NO_count(A.root)<<endl;
    //cout<<"pre"<<endl;
    //A.display1();
}
}
