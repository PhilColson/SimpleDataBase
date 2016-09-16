#include "../tests/test.h"
#include "../tree/BinarySearchTree.h"

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

	for (int i = 0; i < keys.size(); i++){
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

ADDTEST(BinarySearchTreeTest)