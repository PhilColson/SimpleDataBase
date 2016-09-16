#include "../tests/test.h"
#include "../file//FileManager.h"
#include "../tree/BinarySearchTree.h"


bool FileManagerHeaderTest(){
	FileManager<BinarySearchTreeNode> filemanager("FileManagerHeaderTest");
	return true;
}

ADDTEST(FileManagerHeaderTest)