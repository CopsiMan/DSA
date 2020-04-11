#pragma once
#include "MultiMap.h"

class MultiMap;

class MultiMapIterator
{
	friend class MultiMap;

private:
	const MultiMap& col;
	//TODO - Representation

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
	TElem getCurrent()const;
	bool valid() const;
	void next();
	void first();
	~MultiMapIterator();
};

