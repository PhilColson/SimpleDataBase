#include "../tests/test.h"
#include "../file//FileManager.h"
#include "../tree/BinarySearchTree.h"


bool FileManagerHeaderTest(){
	FileManager<BinarySearchTreeNodeBase> filemanager("temp/FileManagerHeaderTest");
	return true;
}

ADDTEST(FileManagerHeaderTest)