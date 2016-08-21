#include "BinaryTreeNode.h"

void BinaryTreeNode::preorder(const function<void(BinaryTreeNode*)>& func){
	func(this);
	if (left != nullptr)
		left->preorder(func);
	if (right != nullptr)
		right->preorder(func);
}

void BinaryTreeNode::inorder(const function<void(BinaryTreeNode*)>& func){
	if (left != nullptr)
		left->inorder(func);
	func(this);
	if (right != nullptr)
		right->inorder(func);
}

void BinaryTreeNode::postorder(const function<void(BinaryTreeNode*)>& func){
	if (left != nullptr)
		left->postorder(func);
	if (right != nullptr)
		right->postorder(func);
}