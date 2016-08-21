#include "BinaryTree.h"

void BinaryTree::put(const int val){
	if (nullptr == root){
		root = new BinaryTreeNode(val);
	}
	else{
		BinaryTreeNode* curr = root;
		while (true){
			if (val < curr->data){
				if (nullptr == curr->left){
					BinaryTreeNode* p = new BinaryTreeNode(val);
					p->parent = curr;
					curr->left = p;
					break;
				}
				else{
					curr = curr->left;
					continue;
				}
			}
			else if(val > curr->data){
				if (nullptr == curr->right){
					BinaryTreeNode* p = new BinaryTreeNode(val);
					p->parent = curr;
					curr->right = p;
					break;
				}
				else{
					curr = curr->right;
					continue;
				}
			}else if (val == curr->data){
				//duplicated key is not allowed now
				break;
			}
		}//while(true)
	}
}

void BinaryTree::preorder(const function<void(BinaryTreeNode*)>& func){
	//TODO: use loop instead of recursion
	if (nullptr == root)
		return;
	else
		root->preorder(func);
}

void BinaryTree::inorder(const function<void(BinaryTreeNode*)>& func){
	//TODO: use loop instead of recursion
	if (nullptr == root)
		return;
	else
		root->inorder(func);
}

void BinaryTree::postorder(const function<void(BinaryTreeNode*)>& func){
	//TODO: use loop instead of recursion
	if (nullptr == root)
		return;
	else
		root->postorder(func);
}

BinaryTreeNode* BinaryTree::get(const int val){
	if (nullptr == root)
		return nullptr;
	BinaryTreeNode* curr = root;
	while (curr != nullptr){
		if (val < curr->data){
			curr = curr->left;
			continue;
		}
		else if (val > curr->data){
			curr = curr->right;
			continue;
		}
		else
		    return curr;
	}
	return nullptr;
}

void BinaryTree::remove(const int val){
	BinaryTreeNode* p = get(val);
	if (p == root){
		delete p;
		root = nullptr;
		return;
	}

	if (nullptr == p->left && nullptr == p->right){
		if (p == p->parent->left){
			p->parent->left = nullptr;
		}
		else{
			p->parent->right = nullptr;
		}
		delete p;
		return;
	}
	else if (nullptr == p->left){
		if (p == p->parent->left){
			p->parent->left = p->right;
			p->right->parent = p->parent;
		}
		else{
			p->parent->right = p->right;
			p->right->parent = p->parent;
		}
		delete p;
		return;
	} if (nullptr == p->right){
		if (p == p->parent->left){
			p->parent->left = p->left;
			p->left->parent = p->parent;
		}
		else{
			p->parent->right = p->left;
			p->left->parent = p->parent;
		}
		delete p;
		return;
	}
	//both left and right child is not null
	//make the right most child of left child
	else{
		BinaryTreeNode* curr = p->left;
		while (true){
			if (nullptr == curr->right){
				break;
			}
			else{
				curr = curr->right;
			}
		}//while(true)

		if (p == p->parent->left){
			p->parent->left = curr;
		}
		else{
			p->parent->right = curr;
		}

		curr->parent = p->parent;
		curr->right = p->right;
		p->left = curr;
		if (nullptr == curr->left){
			curr->parent->right = nullptr;
			curr->left = p->left;
			p->left->parent = curr;
		}
		else{
			curr->parent->right = curr->left;
			curr->left->parent = curr->parent;
			curr->left = p->left;
		}
		
		delete p;
	}
}