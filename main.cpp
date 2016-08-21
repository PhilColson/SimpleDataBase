#include <iostream>
#include <ctime>
#include <cstdlib>
#include <vector>
#include "BinaryTree.h"

using namespace std;

void main(){
	srand(time(0));
	BinaryTree tree;
	std::vector<int> save;
	for (int i = 0; i < 10; i++){
		int v = rand();
		save.push_back(v);
		tree.put(v);
	}

	tree.inorder();

	for (int v : save)
		tree.remove(v);

	tree.inorder();


	system("pause");
}

