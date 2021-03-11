#include <iostream>
#include "MultiMap.h"
#include "ExtendedTest.h"
#include "ShortTest.h"
#include "MultiMapIterator.h"
#include <crtdbg.h>

using namespace std;


int main() {


	testAll();
	test_jumpForward();
	testAllExtended();
	cout << "End" << endl;
	system("pause");
	_CrtDumpMemoryLeaks();
}
