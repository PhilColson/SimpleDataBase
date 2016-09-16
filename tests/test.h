#ifndef __TEST_H__
#define __TEST_H__
#include <map>
#include <functional>
#include <string>
#include <vector>
#include "../log/log.h"
using namespace std;

extern vector<string> _test_details;
extern int test_count;
extern int success_count;

class TestManager
{
public:
	static TestManager& getInstance();
	map<string, function<bool(void)>> _test_functions;
private:

	TestManager() = default;
	~TestManager() = default;
};

#define __TEST_REGISTER_FUNC(testfunc)\
	int testfunc##TEST_REGISTER_FUNC(){\
	TestManager::getInstance()._test_functions[#testfunc] = function<bool(void)>(testfunc); \
	return 0;\
	}

#define ADDTEST(testfunc) \
	__TEST_REGISTER_FUNC(testfunc)\
	static int testfunc##TEST_REGISTER_FUNC_HELPER = testfunc##TEST_REGISTER_FUNC();


#define RUNALLTEST \
do \
{\
	test_count = 0; \
	success_count = 0; \
for (pair<string, function<bool(void)>> p : TestManager::getInstance()._test_functions)\
{\
	test_count++; \
	string detail = p.first; \
if (p.second())\
{\
	detail += " success "; \
	success_count++; \
}\
	else\
{\
	detail += " fail "; \
}\
	_test_details.push_back(detail); \
}\
}while (0)

#define SUMMARY \
do \
{\
for (string line : _test_details)\
{\
	LOG << line << endl; \
}\
	LOG << success_count << " of " << test_count << " ( " \
	<< (float)success_count / test_count << " ) passed" << endl; \
} while (0)

#endif//__TEST_H__