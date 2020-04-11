#include "MultiMap.h"
#include "MultiMapIterator.h"
#include <exception>
#include <iostream>

using namespace std;


MultiMap::MultiMap() {
	//TODO - Implementation
	//this->elems = new SLLNODE_TKey;
	this->elems = new SLL_TKey;
	this->elems->head = NULL;
	this->length = 0;
}


void MultiMap::add(TKey c, TValue v) {
	//TODO - Implementation

	SLLNODE_TKey* current = this->elems->head;
	while (current != NULL && current->key != c)
	{
		current = current->next;
	}
	if (current == NULL) {
		// the key wasn't found so we cand add at the beginning
		SLLNODE_TValue* newValue = new SLLNODE_TValue;
		newValue->value = v;
		newValue->next = NULL;

		SLLNODE_TKey* newNode = new SLLNODE_TKey;
		newNode->values = new SLL_TValues;
		newNode->key = c;
		newNode->next = this->elems->head;
		this->elems->head = newNode;
		newNode->values->head = newValue;

		this->length++;
	}
	else {
		// we need to add at the beginnig of the sll of the current node
		SLLNODE_TValue* newValue = new SLLNODE_TValue;
		newValue->value = v;
		newValue->next = current->values->head;
		current->values->head = newValue;

		this->length++;
	}
}


bool MultiMap::remove(TKey c, TValue v) {
	//TODO - Implementation
	SLLNODE_TKey* current = this->elems->head;
	SLLNODE_TKey* prev = current;
	while (current != NULL && current->key != c) {
		prev = current;
		current = current->next;
	}
	if (current == NULL)
		return  false;

	// now we search for the value
	SLLNODE_TValue* currentValue = current->values->head;
	SLLNODE_TValue* prevValue = currentValue;
	while (currentValue != NULL && currentValue->value != v) {
		prevValue = currentValue;
		currentValue = currentValue->next;
	}
	if (currentValue == NULL)
		return  false;

	if (prevValue->value == currentValue->value) {
		current->values->head = currentValue->next;
		delete currentValue;
	}
	else {
		prevValue->next = currentValue->next;
		delete currentValue;
	}

	if (current->values->head == NULL) {
		 if (prev->key == current->key) {
			 this->elems->head = current->next;
			 delete current->values;
			 delete current;
		 }
		 else {
			 prev->next = current->next;
			 delete current->values;
			 delete current;
		 }
	}

	// prev->next = current->next;
	// delete current;
	this->length--;

	return true;
}


vector<TValue> MultiMap::search(TKey c) const {
	//TODO - Implementation
	vector<TValue> values;
	SLLNODE_TKey* current = this->elems->head;
	//SLLNODE_TKey* prev = current;
	while (current != NULL && current->key != c) {
		//prev = current;
		current = current->next;
	}
	if (current == NULL)
		return values;

	SLLNODE_TValue* currentValue = current->values->head;
	while (currentValue != NULL) {
		values.push_back(currentValue->value);
		currentValue = currentValue->next;
	}

	return values;
}


int MultiMap::size() const {
	//TODO - Implementation
	return this->length;
}


bool MultiMap::isEmpty() const {
	//TODO - Implementation
	return this->length == 0;
}

MultiMapIterator MultiMap::iterator() const {
	return MultiMapIterator(*this);
}


MultiMap::~MultiMap() {
	//TODO - Implementation

	SLLNODE_TKey* current = this->elems->head;
	SLLNODE_TKey* prev = current;
	while (current != NULL) {
		prev = current;

		SLLNODE_TValue* currentValue = current->values->head;
		SLLNODE_TValue* prevValue = currentValue;
		while (currentValue != NULL) {
			prevValue = currentValue;
			currentValue = currentValue->next;
			delete prevValue;
		} 

		current = current->next;
		delete prev->values;
		delete prev;
	}
	delete this->elems;
}

