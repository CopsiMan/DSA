#pragma once
//DO NOT INCLUDE SORTEDMAPITERATOR

//DO NOT CHANGE THIS PART
typedef int TKey;
typedef int TValue;
#include <utility>
typedef std::pair<TKey, TValue> TElem;
#define NULL_TVALUE -111111
#define NULL_TPAIR pair<TKey, TValue>(-111111, -111111);
class SMIterator;
typedef bool(*Relation)(TKey, TKey);

class SortedMap {
	friend class SMIterator;
    private:
		//TODO - Representation

		struct Node {
			TElem value;
			Node* left;
			Node* right;
		};

		struct BST {
			Node* root;
		}tree;

		Relation relation;
		int length;
    public:

    // implicit constructor
	//complexity: Θ(1)
    SortedMap(Relation r);

	// replaces the value currently mapped to a key k, with value newValue, only if the current value is equal to oldValue.
	// if the current value is not oldValue, or if k is not in the sortedmap, nothing is changes.
	void replace(TKey k, TValue oldValue, TValue newValue);

	// adds a pair (key,value) to the map
	//if the key already exists in the map, then the value associated to the key is replaced by the new value and the old value is returned
	//if the key SMes not exist, a new pair is added and the value null is returned
	/*
	Best case: Θ(1)
	Worst case: Θ(n)
	Average case: Θ(log2(n))
	Total(overall) complexity : O(n)
	*/
	TValue add(TKey c, TValue v);

	//searches for the key and returns the value associated with the key if the map contains the key or null: NULL_TVALUE otherwise
	/*
	Best case: Θ(1)
	Worst case: Θ(n)
	Average case: Θ(log2(n))
	Total(overall) complexity : O(n)
	*/
	TValue search(TKey c) const;


	//removes a key from the map and returns the value associated with the key if the key existed ot null: NULL_TVALUE otherwise
	/*
	Best case: Θ(1)
	Worst case: Θ(n)
	Average case: Θ(log2(n))
	Total(overall) complexity : O(n)
	*/
	TValue remove(TKey c);

	//returns the number of pairs (key,value) from the map
	//complexity: Θ(1)
	int size() const;

	//checks whether the map is empty or not
	//complexity: Θ(1)
	bool isEmpty() const;

    // return the iterator for the map
    // the iterator will return the keys following the order given by the relation
	/*
	Best case: Θ(1)
	Worst case: Θ(n)
	Average case: Θ(log2(n))
	Total(overall) complexity : O(n)
	*/
    SMIterator iterator() const;

	//complexity: Θ(1)
	void dealocateNode(Node* node);

    // destructor
	//complexity: Θ(n)
    ~SortedMap();
};
