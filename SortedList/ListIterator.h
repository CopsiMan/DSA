#pragma once
#include "SortedIteratedList.h"


//DO NOT CHANGE THIS PART
class ListIterator{
	friend class SortedIteratedList;
private:
	const SortedIteratedList& list;
	ListIterator(const SortedIteratedList& list);

	//TODO - Representation
	int currentElement;

public:
	// complexity: Θ(1)
	void first();
	// complexity: Θ(1)
	void next();
	// complexity: Θ(1)
	bool valid() const;
	// complexity: Θ(1)
	void last();
	// complexity: Θ(1)
    TComp getCurrent() const;
};


