#include<iostream>
#include<stdlib.h>
#include<fstream>
#include<cstdlib>
#include"BSTree.h"
//#include"WriteInFile.h"
using namespace BSTreeNS;


//����ڵ�
void BSTree::Insert(int key,int value)//
{
    BSTreeNode*current=nullptr;
    if(nullptr==root)
    {
       root=new BSTreeNode(key,value);//

    }
    else
    {
        current=root;
        while(true)
        {

          if(key<current->key)
          {
              if(nullptr==current->left)
              {
                 BSTreeNode  *p;
                  p=new BSTreeNode(key,value);
                  p->parent=current;
                  current->left=p;
                  break;
              }
              else
                current=current->left;

          }

          else if(key>current->key)
          {
              if(nullptr==current->right)
              {
                  BSTreeNode *p=new BSTreeNode(key,value);
                  p->parent=current;
                  current->right=p;
                  break;
              }
              else
                current=current->right;
          }
          else
            break;
        }
    }

}

/*
  ����������
  */

//�������
void BSTree::preorder(const function<void(BSTreeNode*)>& func)
{
    if(nullptr==root)
    {
        // cout<<"it's a empty tree!"<<endl;
        return;
    }
    else
    {
      root->preorder(func);
    }
}

//�������
void BSTree::inorder(const function<void(BSTreeNode*)>& func)
{
   if(nullptr==root)
   {
       //cout<<"it's a empty tree"<<endl;
       return;
   }
   else
    root->inorder(func);

}

//�������
void BSTree::postorder(const function<void(BSTreeNode*)>& func)
{
    if(nullptr==root)
    {
        //cout<<"it's a empty tree"<<endl;
        return;
    }
    else
        root->postorder(func);
}

/*
 ɾ���ڵ�
 */

//�õ��ڵ�ĵ�ַ
BSTreeNode * BSTree::get(const int key,const int data)
{
    BSTreeNode*current=root;
    if(nullptr==root)
    {
        return nullptr;
    }

    else
    {
        while(true)
        {
            if(key<current->key)
               {
                current=current->left;
                continue;
               }
            else if(key>current->key)
               {
                current=current->right;

                continue;
               }

            else
               break;
        }

            return current;
    }
}
//ִ��ɾ��
void BSTree::remove(const int key,const int data)
{
    BSTreeNode* curr=get(key,data);
    if(nullptr==curr)
    {
        //cout<<"it's a empty tree"<<endl;
       return;
    }
    else
    {

        if(curr==root)
        {
          delete curr;
           root=nullptr;
           return;
        }
        else
        {
            if(nullptr==curr->left && nullptr==curr->right)
            {
                if(key<curr->parent->key)
                {

                 curr->parent->left=nullptr;
                }
                else
                {
                   curr->parent->right=nullptr;
                }
                delete curr;
                return;

            }
            else if(nullptr!=curr->left && nullptr==curr->right)
            {
                if(key<curr->parent->key)
                    {
                      curr->parent->left=curr->left;
                    curr->left->parent=curr->parent;
                    }

                else
                    {
                        curr->parent->right=curr->left;
                        curr->left->parent=curr->parent;
                    }
                delete curr;
                return;
            }
            else if(nullptr==curr->left && nullptr!=curr->right)
            {
                if(key<curr->parent->key)
                {
                    curr->parent->left=curr->right;
                    curr->right->parent=curr->parent;
                }

                else
                {
                    curr->parent->right=curr->right;
                    curr->right->parent=curr->right;
                }

                delete curr;
                return;
            }
            else
            {
                BSTreeNode *p=curr->right;
                if(key<curr->parent->key)
                {
                    curr->parent->left=curr->right;
                    curr->right->parent=curr->parent;


                }
                else
                {
                    curr->parent->right=curr->right;
                    curr->right->parent=curr->parent;

                }
                while(p->left!=nullptr && p->right!=nullptr)
                    {
                        p=p->left;
                    }
                    p->left=curr->left;
                    curr->left->parent=p;
                    delete curr;
                    return;

            }
        }
    }
}
void BSTree::pre(BSTreeNode*curr)
{
    Infile.open("data.dat",ios::app);

    Outfile.setf(ios::left);
    Outfile.width(sizeof(curr->data));

  if(curr!=nullptr)
   {
       Outfile<<curr->data;
       cout<<curr->data;         //�ص����cout���԰�dataȫ���������Outfile������ȴֻ��0124.
       pre(curr->left);
       pre(curr->right);
   }
  Outfile.close();
}

void BSTree::WriteInFile()
{
    BSTreeNode*p=nullptr;

    Outfile.open("data",ios::app);

    if(Outfile.fail())
      {
         cout<<"failing to open file"<<endl;
        exit(1);
      }
    p=root;
   // cout<<p->data<<"\n"<<sizeof(p->data)<<endl;
    if(p!=nullptr)
    {

        pre(root);
    }
}
