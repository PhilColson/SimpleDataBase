#include "../tests/test.h"
#include "../tree/BinarySearchTree.h"

#include <algorithm>

bool BinarySearchTreeTest(){
	BinarySearchTree tree;
	std::vector<int> keys;
	std::vector<int> values;
	for (int i = 0; i < 100; i++){
		int k = i;
		int v = i;
		keys.push_back(k);
		values.push_back(v);
		tree.put(k, v);
	}
	LOG << "finished insertion" << endl;

	int keysize = keys.size();
	for (int i = 0; i < keysize; i++){
		int ret = tree.get(keys[i]);
		if (ret != values[i]){
			LOG << "expected: " << values[i] << " got " << ret << endl;
			LOG << "verification failure!" << endl;
			return false;
		}

	}

	LOG << "finished verification" << endl;
	for (int v : keys)
		tree.remove(v);
	return true;
}

bool BinarySearchTree_writeAllNodeToDisk(){
	bool ret = true;
	BinarySearchTree tree;
	tree.initFileManager("temp/BinarySearchTree_writeAllNodeToDisk");
	std::vector<int> keys;
	std::vector<int> values;
	for (int i = 0; i < 100; i++){
		int k = i;
		int v = i;
		keys.push_back(k);
		values.push_back(v);
		tree.put(k, v);
	}
	try{
		tree.writeAllNodeToDisk();
	}
	catch (...){
		ret = false;
	}
	

	for (int v : keys)
		tree.remove(v);

	return ret;
}

bool BinarySearchTree_readAllNodeFromDisk(){
	bool ret = true;
	BinarySearchTree tree;
	tree.initFileManager("temp/BinarySearchTree_writeAllNodeToDisk");
	std::vector<int> keys;
	std::vector<int> values;
	for (int i = 0; i < 100; i++){
		int k = i;
		int v = i;
		keys.push_back(k);
		values.push_back(v);
		
	}
	random_shuffle(keys.begin(), keys.end());
	for (int i = 0; i < 100; i++)
	    tree.put(keys[i], values[i]);
	try{
		tree.writeAllNodeToDisk();
	}
	catch (...){
		ret = false;
	}


	for (int v : keys)
		tree.remove(v);

	LOG << "Going to read from file" << endl;

	BinarySearchTree readtree;
	readtree.initFileManager("temp/BinarySearchTree_writeAllNodeToDisk");
	readtree.readAllNodeFromDisk();

	LOG << "finished reading going to verified tree" << endl;

	int keysize = keys.size();
	for (int i = 0; i < keysize; i++){
		int ret = readtree.get(keys[i]);
		if (ret != values[i]){
			LOG << "expected: " << values[i] << " got " << ret << endl;
			LOG << "verification failure!" << endl;
			return false;
		}

	}

	LOG << "finished verification" << endl;
	for (int v : keys)
		readtree.remove(v);

	return ret;
}

ADDTEST(BinarySearchTreeTest)
ADDTEST(BinarySearchTree_writeAllNodeToDisk)
ADDTEST(BinarySearchTree_readAllNodeFromDisk)