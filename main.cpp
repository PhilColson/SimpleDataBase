#include <iostream>
#include <ctime>
#include <cstdlib>
#include <vector>
#include "tree/BinarySearchTree.h"
#include "log/log.h"
#include "file/FileManager.h"
#include "tests/test.h"

using namespace std;

int main(){
	srand(time(0));
	//Logger::getInstance().redirectStream("log.txt");
	
	RUNALLTEST;

	SUMMARY;

	return 0;
}

