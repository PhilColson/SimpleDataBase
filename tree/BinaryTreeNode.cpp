#include "BinaryTreeNode.h"

void BinarySearchTreeNode::preorder(const function<void(BinarySearchTreeNode*)>& func){
	func(this);
	if (left != nullptr)
		left->preorder(func);
	if (right != nullptr)
		right->preorder(func);
}

void BinarySearchTreeNode::inorder(const function<void(BinarySearchTreeNode*)>& func){
	if (left != nullptr)
		left->inorder(func);
	func(this);
	if (right != nullptr)
		right->inorder(func);
}

void BinarySearchTreeNode::postorder(const function<void(BinarySearchTreeNode*)>& func){
	if (left != nullptr)
		left->postorder(func);
	if (right != nullptr)
		right->postorder(func);
}