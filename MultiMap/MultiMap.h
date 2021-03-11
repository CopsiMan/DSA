#pragma once
#include <vector>
#include <utility>

#include <exception>

//DO NOT INCLUDE MultiMapIterator

using namespace std;

//DO NOT CHANGE THIS PART
typedef int TKey;
typedef int TValue;
typedef std::pair<TKey, TValue> TElem;
#define NULL_TVALUE -11111;
#define NULL_TELEM pair<int,int>(-11111, -11111);
class MultiMapIterator;

class MultiMap
{
	friend class MultiMapIterator;

private:
	//TODO - Representation

	struct SLLNODE_TValue {
		TValue value;
		SLLNODE_TValue* next;
	};

	struct SLL_TValues {
		SLLNODE_TValue* head;
	};

	struct SLLNODE_TKey {
		SLL_TValues* values;
		TKey key;
		SLLNODE_TKey* next;
	};

	struct SLL_TKey {
		SLLNODE_TKey* head;
	};

	SLL_TKey* elems;
	int length;

public:

	//constructor
	/*
	complexity: Θ(1)
	*/
	MultiMap();

	//adds a key value pair to the multimap
	/*
	n = number of keys
	Best case: Θ(1)
	Worst case: Θ(n)
	Average case: Θ(n)
	Total (overall) complexity: O(n)
	*/
	void add(TKey c, TValue v);

	//removes a key value pair from the multimap
	//returns true if the pair was removed (if it was in the multimap) and false otherwise
	/*
	m = number of values associated to a key
	n = number of keys
	Best case: Θ(1)
	Worst case: Θ(n + m)
	Average case: Θ(n + m)
	Total(overall) complexity : O(n + m)
	*/
	bool remove(TKey c, TValue v);

	//returns the vector of values associated to a key. If the key is not in the MultiMap, the vector is empty
	/*
	m = number of values associated to a key
	n = number of keys
	Best case: Θ(1)
	Worst case: Θ(n + m)
	Average case: Θ(n + m)
	Total(overall) complexity : O(n + m)
	*/
	vector<TValue> search(TKey c) const;

	//returns the number of pairs from the multimap
	/*
	complexity: Θ(1)
	*/
	int size() const;

	//checks whether the multimap is empty
	/*
	complexity: Θ(1)
	*/
	bool isEmpty() const;

	//returns an iterator for the multimap
	/*
	complexity: Θ(1)
	*/
	MultiMapIterator iterator() const;

	//descturctor
	/*
	m = number of values associated to all keys
	n = number of keys
	complexity : Θ(n + m)
	*/
	~MultiMap();


};

