#ifndef BSTREE_H_INCLUDED
#define BSTREE_H_INCLUDED
#include<iostream>
#include<fstream>
#include<string>
#include<functional>
#include<assert.h>

namespace BSTreeNS
{
  using namespace std;
//class BSTree;

class BSTreeNode
  {


    public:
        //初始化
        BSTreeNode(int _key,int _data) : data(_data),key(_key),left(nullptr),right(nullptr),parent(nullptr){}

        void preorder(const function<void(BSTreeNode*)>& func);
        void inorder(const function<void(BSTreeNode*)>& func);
        void postorder(const function<void(BSTreeNode*)>& func);

    private:
      friend class BSTree;
      friend class File;
        int key;
        int data;

        BSTreeNode  *left,*right;
        BSTreeNode *parent;

    };


class BSTree
    {
    public:
        //初始化
        BSTree():root(nullptr){}
        //函数
        void Insert( int key,int value);

        void remove(const int key,int data );

        void preorder(const function<void(BSTreeNode *)>& func=[](BSTreeNode *p){cout<<p->key<<" "<<p->data<<"\n";});
        void inorder(const function<void(BSTreeNode*)>& func=[](BSTreeNode*p){cout<<p->key<<" "<<p->data<<"\n";});
        void postorder(const function<void(BSTreeNode*)>& func=[](BSTreeNode*p){cout<<p->key<<" "<<p->data<<"\n";});


        void WriteInFile();
        void pre(BSTreeNode*);
    protected:
       BSTreeNode * root ;
       ifstream Infile;
       ofstream Outfile;
    private:


        BSTreeNode *get(const int key,const int data);
    };



}

#endif // BTREEHEAD_H_INCLUDED
