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
	MultiMap();

	//adds a key value pair to the multimap
	void add(TKey c, TValue v);

	//removes a key value pair from the multimap
	//returns true if the pair was removed (if it was in the multimap) and false otherwise
	bool remove(TKey c, TValue v);

	//returns the vector of values associated to a key. If the key is not in the MultiMap, the vector is empty
	vector<TValue> search(TKey c) const;

	//returns the number of pairs from the multimap
	int size() const;

	//checks whether the multimap is empty
	bool isEmpty() const;

	//returns an iterator for the multimap
	MultiMapIterator iterator() const;

	//descturctor
	~MultiMap();


};

