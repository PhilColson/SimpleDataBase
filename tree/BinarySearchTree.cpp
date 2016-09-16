#include <exception>
#include "BinarySearchTree.h"

void BinarySearchTree::put(const int key,const int value){
	if (nullptr == root){
		root = new BinarySearchTreeNode(key,value);
	}
	else{
		BinarySearchTreeNode* curr = root;
		while (true){
			if (key < curr->key){
				if (nullptr == curr->left){
					BinarySearchTreeNode* p = new BinarySearchTreeNode(key,value);
					p->parent = curr;
					curr->left = p;
					break;
				}
				else{
					curr = curr->left;
					continue;
				}
			}
			else if(key > curr->key){
				if (nullptr == curr->right){
					BinarySearchTreeNode* p = new BinarySearchTreeNode(key,value);
					p->parent = curr;
					curr->right = p;
					break;
				}
				else{
					curr = curr->right;
					continue;
				}
			}else if (key == curr->key){
				//duplicated key is not allowed now
				break;
			}
		}//while(true)
	}
}

void BinarySearchTree::preorder(const function<void(BinarySearchTreeNode*)>& func){
	//TODO: use loop instead of recursion
	if (nullptr == root)
		return;
	else
		root->preorder(func);
}

void BinarySearchTree::inorder(const function<void(BinarySearchTreeNode*)>& func){
	//TODO: use loop instead of recursion
	if (nullptr == root)
		return;
	else
		root->inorder(func);
}

void BinarySearchTree::postorder(const function<void(BinarySearchTreeNode*)>& func){
	//TODO: use loop instead of recursion
	if (nullptr == root)
		return;
	else
		root->postorder(func);
}

BinarySearchTreeNode* BinarySearchTree::getRawPtr(const int key){
	if (nullptr == root)
		return nullptr;
	BinarySearchTreeNode* curr = root;
	while (curr != nullptr){
		if (key < curr->key){
			curr = curr->left;
			continue;
		}
		else if (key > curr->key){
			curr = curr->right;
			continue;
		}
		else
		    return curr;
	}
	return nullptr;
}

int BinarySearchTree::get(const int key){
	BinarySearchTreeNode* node = getRawPtr(key);
	if (nullptr == node)
	{
		throw exception("node does not exist");
	}
	return node->value;
}

void BinarySearchTree::remove(const int val){
	BinarySearchTreeNode* p = getRawPtr(val);
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
		BinarySearchTreeNode* curr = p->left;
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