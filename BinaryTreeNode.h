#ifndef __BINARYTREENODE_H__
#define __BINARYTREENODE_H__
#include <functional>
#include <iostream>
using namespace std;

class BinaryTreeNode
{
public:
	BinaryTreeNode(int val) :data(val),left(nullptr),right(nullptr),parent(nullptr){}
	int data;
	BinaryTreeNode *left, *right;
	BinaryTreeNode *parent;

	void preorder(const function<void(BinaryTreeNode*)>& func);

	void inorder(const function<void(BinaryTreeNode*)>& func);

	void postorder(const function<void(BinaryTreeNode*)>& func);
};

#endif//__BINARYTREENODE_H__
