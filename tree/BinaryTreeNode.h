#ifndef __BINARYTREENODE_H__
#define __BINARYTREENODE_H__
#include <functional>
#include <iostream>
#include "NodeBase.h"
using namespace std;

class BinarySearchTreeNode:public NodeBase 
{
public:
	BinarySearchTreeNode(int key,int value):
		key(key),value(value),left(nullptr),
		right(nullptr),parent(nullptr),
		leftptrInDisk(-1),rightptrInDisk(-1),
		parentptrInDisk(-1){}
	int key;
	int value;
	BinarySearchTreeNode *left, *right;
	int leftptrInDisk, rightptrInDisk;
	BinarySearchTreeNode *parent;
	int parentptrInDisk;

	void preorder(const function<void(BinarySearchTreeNode*)>& func);

	void inorder(const function<void(BinarySearchTreeNode*)>& func);

	void postorder(const function<void(BinarySearchTreeNode*)>& func);
};

#endif//__BINARYTREENODE_H__
