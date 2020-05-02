#pragma once
//DO NOt INCLUDE LISTITERATOR

//DO NOT CHANGE THIS PART
class ListIterator;
typedef int TComp;
typedef bool (*Relation)(TComp, TComp);
#define NULL_TCOMP -11111


class SortedIteratedList {
private:
	friend class ListIterator;
private:
	//TODO - Representation

	struct DLLANode{
		TComp info;
		int next, prev;
	};

	DLLANode* nodes;
	int capacity, head, tail, firstEmpty, length;
	Relation r;

	// complexity: Θ(1)
	int allocate();
	// complexity: Θ(1)
	void free(int pos);
	// complexity: Θ(capacity)
	void resize();

public:
	// constructor
	// complexity: Θ(capacity)
	SortedIteratedList(Relation r);

	// returns the number of elements from the list
	// complexity: Θ(1)
	int size() const;

	// verifies if the list is empty
	// complexity: Θ(1)
	bool isEmpty() const;

	// returns the first position from the list
	// complexity: Θ(1)
	ListIterator first() const;

	// returns the element from the given position
	//throws an exception if the position is not valid
	// complexity: Θ(1)
	TComp getElement(ListIterator pos) const;

	// adds a new element to the list
	/*
	n - number of elements already in the list
	Best case: Θ(1)
	Worst case: Θ(n)
	Average case: Θ(n)
	Total(overall) complexity : O(n)
	*/
	void add(TComp e);

	// removes the element from position pos
	//returns the removed element
	//after removal pos is positioned on the next element (the one after the removed one) or it is invalid if the last element was removed
	//throws an exception if the position is not valid
	/*
	n - number of elements already in the list
	Best case: Θ(1)
	Worst case: Θ(n)
	Average case: Θ(n)
	Total(overall) complexity : O(n)
	*/
	TComp remove(ListIterator& poz);

	// searches for the first occurrence of an element 
	//returns an iterator that points to the element, if it appear in the list, or an invalid iterator if the element is not in the list
	/*
	n - number of elements already in the list
	Best case: Θ(1)
	Worst case: Θ(n)
	Average case: Θ(n)
	Total(overall) complexity : O(n)
	*/
	ListIterator search(TComp e) const;

	//TODO elimina
	//void print();

	//destructor
	/*
	n - number of elements already in the list
	complexity: Θ(n)
	*/
	~SortedIteratedList();

};
