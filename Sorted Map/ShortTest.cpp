#include <assert.h>

#include "SortedMap.h"
#include "SMIterator.h"
#include "ShortTest.h"
#include <exception>
using namespace std;

bool relatie1(TKey cheie1, TKey cheie2) {
    if (cheie1 <= cheie2) {
        return true;
    }
    else {
        return false;
    }
}

void test_replace() {
    SortedMap sm(relatie1);
    assert(sm.size() == 0);
    assert(sm.isEmpty());
    sm.add(1, 4);
    sm.add(3, 2);
    sm.add(2, 1);
    sm.add(0, 4);
    assert(sm.size() == 4);
    assert(!sm.isEmpty());
    assert(sm.search(1) != NULL_TVALUE);
    assert(sm.search(3) == 2);
    sm.replace(3, 2, 3);
    assert(sm.search(3) == 3);
    sm.replace(1, 2, 3);
    assert(sm.search(1) == 4);
}

void testAll() {

    test_replace();

    SortedMap sm(relatie1);
    assert(sm.size() == 0);
    assert(sm.isEmpty());
    sm.add(1, 2);
    assert(sm.size() == 1);
    assert(!sm.isEmpty());
    assert(sm.search(1) != NULL_TVALUE);
    TValue v = sm.add(1, 3);
    assert(v == 2);
    assert(sm.search(1) == 3);
    SMIterator it = sm.iterator();
    it.first();
    while (it.valid()) {
        TElem e = it.getCurrent();
        assert(e.second != NULL_TVALUE);
        it.next();
    }
    assert(sm.remove(1) == 3);
    assert(sm.isEmpty());
}

