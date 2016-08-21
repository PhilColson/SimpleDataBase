#ifndef __BINARYTREE_H__
#define __BINARYTREE_H__
#include <functional>
#include <iostream>
#include "BinaryTreeNode.h"
using namespace std;

class BinaryTree
{
public:
	BinaryTree()
	{
		root = nullptr;
	}

	void preorder(const function<void(BinaryTreeNode*)>& func = [](BinaryTreeNode* node){cout << node->data << "\n"; });

	void inorder(const function<void(BinaryTreeNode*)>& func = [](BinaryTreeNode* node){cout << node->data << endl; });

	void postorder(const function<void(BinaryTreeNode*)>& func = [](BinaryTreeNode* node){cout << node->data << "\n"; });

	void put(const int val);

	BinaryTreeNode* get(const int val);

	void remove(const int val);
private:
	BinaryTreeNode* root;
};

#endif//__BINARYTREENODE_H__