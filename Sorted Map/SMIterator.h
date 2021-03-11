#pragma once
#include "SortedMap.h"

//DO NOT CHANGE THIS PART
class SMIterator{
	friend class SortedMap;
private:
	const SortedMap& map;
	/*
	Best case: Θ(1)
	Worst case: Θ(n)
	Average case: Θ(log2(n))
	Total(overall) complexity : O(n)
	*/
	SMIterator(const SortedMap& mapionar);

	//TODO - Representation
	SortedMap::Node* current;
	SortedMap::Node** stack;
	int index, capacity;

public:

	/*
	Best case: Θ(1)
	Worst case: Θ(n)
	Average case: Θ(log2(n))
	Total(overall) complexity : O(n)
	*/
	void first();

	/*
	Best case: Θ(1)
	Worst case: Θ(n)
	Average case: Θ(log2(n))
	Total(overall) complexity : O(n)
	*/
	void next();

	// complexity: Θ(1)
	bool valid() const;

	// complexity: Θ(1)
    TElem getCurrent() const;

	// complexity: Θ(1)
	bool isEmpty();

	// complexity: Θ(1)
	SortedMap::Node* pop();

	// complexity: Θ(1) amortized 
	void push(SortedMap::Node* node);

	// complexity: Θ(1)
	SortedMap::Node* top();

	// complexity: Θ(n)
	void resize();
};

