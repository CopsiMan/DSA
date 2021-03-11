#include "Bag.h"

class BagIterator
{
	//DO NOT CHANGE THIS PART
	friend class Bag;
	
private:
	const Bag& bag;
	//TODO  - Representation

	int currentPos;
	Bag::Node* currentNode;

	/*
	n is the number of elements
	Best case: Θ(1)
	Worst case: Θ(n)
	Average case: Θ(n)
	Total(overall) complexity : O(n)
	*/
	BagIterator(const Bag& c);
public:
	/*
	n is the number of elements
	Best case: Θ(1)
	Worst case: Θ(n)
	Average case: Θ(n)
	Total(overall) complexity : O(n)
	*/
	void first();

	/*
	n is the number of elements
	Best case: Θ(1)
	Worst case: Θ(n)
	Average case: Θ(1)
	Total(overall) complexity : O(n)
	*/
	void next();

	// complexity: Θ(n)
	TElem getCurrent() const;

	// complexity: Θ(n)
	bool valid() const;
};
