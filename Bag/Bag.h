#pragma once
//DO NOT INCLUDE BAGITERATOR

//DO NOT CHANGE THIS PART
#define NULL_TELEM -111111;
typedef int TElem;
class BagIterator;

typedef int (*TFunction)(TElem key);

class Bag {

private:
	//TODO - Representation
	int length, capacity, m;
	float alpha;

	struct Node
	{
		TElem key;
		Node* next;
	};

	struct HashTable
	{
		Node** T;
		int m;
	} table;

	// n is the number of elements
	// complexity: Θ(n)
	void resize();

	// complexity: Θ(1)
	int hashFunction(TElem key) const;

	//DO NOT CHANGE THIS PART
	friend class BagIterator;
public:
	//constructor
	// complexity: Θ(1)
	Bag();

	//adds an element to the bag
	/*
	n is the number of elements already on the same position
	Best case: Θ(1)
	Worst case: Θ(n)
	Average case: Θ(1)
	Total(overall) complexity : O(n)
	*/
	void add(TElem e);

	//removes one occurence of an element from a bag
	//returns true if an element was removed, false otherwise (if e was not part of the bag)
	/*
	n is the number of elements already on the same position
	Best case: Θ(1)
	Worst case: Θ(n)
	Average case: Θ(1)
	Total(overall) complexity : O(n)
	*/
	bool remove(TElem e);

	//removes all occurrences of elem from the Bag
	//returns the number of elements removed
	/*
	n - the number of occurrences
	m - the number of elements on that position
	Best case: Θ(n)
	Worst case: Θ(m)
	Average case: Θ(n)
	Total(overall) complexity : O(n + m)
	*/
	int removeAllOccurrences(TElem elem);

	//checks if an element appearch is the bag
	/*
	n is the number of elements already on the same position
	Best case: Θ(1)
	Worst case: Θ(n)
	Average case: Θ(1)
	Total(overall) complexity : O(n)
	*/
	bool search(TElem e) const;

	//returns the number of occurrences for an element in the bag
	/*
	n is the number of elements already on the same position
	complexity: Θ(n)
	*/
	int nrOccurrences(TElem e) const;

	//returns the number of elements from the bag
	// complexity: Θ(n)
	int size() const;

	//returns an iterator for this bag
	// complexity: Θ(1)
	BagIterator iterator() const;

	//checks if the bag is empty
	// complexity: Θ(1)
	bool isEmpty() const;

	//destructor
	// n is the number of elements already on the same position
	// complexity: Θ(n)
	~Bag();
};