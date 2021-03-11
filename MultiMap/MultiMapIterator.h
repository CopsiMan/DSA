#pragma once
#include "MultiMap.h"

class MultiMap;

class MultiMapIterator
{
	friend class MultiMap;

private:
	const MultiMap& col;
	//TODO - Representation

	/*
	complexity: Θ(1)
	*/
	MultiMapIterator(const MultiMap& c);
	struct SLLTValue_Iterator {
		MultiMap::SLL_TValues* list;
		MultiMap::SLLNODE_TValue* currentElement;
	};

	struct SLLTKey_Iterator {
		MultiMap::SLL_TKey* list;
		MultiMap::SLLNODE_TKey* currentElement;
		SLLTValue_Iterator* values;
		//MultiMap::SLLNODE_TValue* currentValue;
	};

	SLLTKey_Iterator* it;

public:

	//moves the current element from the iterator k steps forward, or makes the iterator invalid if there are less than k elements left in the MultiMap.
	//throws an exception if the iterator is invalid or if k is 0 zero negative
	/*
	Best case: Θ(1)
	Worst case: Θ(k)
	Average case: Θ(k)
	Total(overall) complexity : O(k)
	*/
	void jumpForward(int k);

	// complexity: Θ(1)
	TElem getCurrent()const;
	// complexity: Θ(1)
	bool valid() const;
	// complexity: Θ(1)
	void next();
	// complexity: Θ(1)
	void first();
	// complexity: Θ(1)
	~MultiMapIterator();
};

