#ifndef __BINARYTREENODE_H__
#define __BINARYTREENODE_H__
#include <functional>
#include <iostream>
#include "NodeBase.h"
using namespace std;

class BinarySearchTreeNodeBase
{
public:
	BinarySearchTreeNodeBase():ptrInDisk(-1),
		leftptrInDisk(-1), rightptrInDisk(-1),
		parentptrInDisk(-1){}
	BinarySearchTreeNodeBase(int key, int value)
		:key(key), value(value), ptrInDisk(-1),
		leftptrInDisk(-1), rightptrInDisk(-1),
		parentptrInDisk(-1){}
	int ptrInDisk;
	int key;
	int value;
	int leftptrInDisk, rightptrInDisk;
	int parentptrInDisk;
};

class BinarySearchTreeNode :public BinarySearchTreeNodeBase
{
public:
	BinarySearchTreeNode():left(nullptr),
		right(nullptr), parent(nullptr){}
	BinarySearchTreeNode(int key,int value):
		BinarySearchTreeNodeBase(key,value),
		left(nullptr),right(nullptr),parent(nullptr){}
	
	BinarySearchTreeNode *left, *right;
	
	BinarySearchTreeNode *parent;
	

	void preorder(const function<void(BinarySearchTreeNode*)>& func);

	void inorder(const function<void(BinarySearchTreeNode*)>& func);

	void postorder(const function<void(BinarySearchTreeNode*)>& func);
};

#endif//__BINARYTREENODE_H__
