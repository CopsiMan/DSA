#include <assert.h>

#include "SortedIteratedList.h"
#include "ListIterator.h"

#include <exception>
#include <iostream>
using namespace std;

bool relation1(TComp e1, TComp e2) {
	if (e1 <= e2) {
		return true;
	}
	else {
		return false;
	}
}

void testRemoveBetween() {
    SortedIteratedList list = SortedIteratedList(relation1);
    for (int i = 9; i >= 0; i--)
        list.add(i);
    assert(list.size() == 10);
    ListIterator start = list.search(3);
    ListIterator end = list.search(7);
    list.removeBetween(start, end);
    assert(list.size() == 5);
    list.removeBetween(end, start);
    assert(list.size() == 5);
    try {
        list.removeBetween(list.search(-1), list.search(3));
        assert(false);
    }
    catch (const exception& ex) {
        assert(true);
    }
    try {
        list.removeBetween(list.search(1), list.search(11));
        assert(false);
    }
    catch (const exception& ex) {
        assert(true);
    }
    //cout << "yes"<<endl;
}

void testAll(){
	SortedIteratedList list = SortedIteratedList(relation1);
	assert(list.size() == 0);
	assert(list.isEmpty());
    list.add(1);
    assert(list.size() == 1);
    assert(!list.isEmpty());
    ListIterator it = list.search(1);
    assert(it.valid());
    assert(it.getCurrent() == 1);
    it.next();
    assert(!it.valid());
    it.first();
    assert(it.valid());
    ListIterator itFirst = list.first();
    assert(itFirst.valid());
    assert(itFirst.getCurrent() == 1);
    assert(list.remove(it) == 1);
    assert(list.size() == 0);
    assert(list.isEmpty());
    testRemoveBetween();
}

