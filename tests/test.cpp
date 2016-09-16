#include "test.h"

vector<string> _test_details;
int test_count = 0;
int success_count = 0;

TestManager& TestManager::getInstance(){
	static TestManager* instance = new TestManager();
	return *instance;
}