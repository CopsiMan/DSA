#include "Bag.h"
#include "BagIterator.h"
#include <exception>
#include <iostream>
#include <stdlib.h>
using namespace std;


void Bag::resize()
{
	Node** newTable = new Node * [this->capacity * 2];
	this->m = this->capacity * 2;
	for (int i = 0; i < this->capacity * 2; i++) {
		newTable[i] = NULL;
	}
	BagIterator it = this->iterator();
	it.first();
	while (it.valid()) {
		TElem e = it.getCurrent();

		int position = this->hashFunction(e);
		Node* currentNode = newTable[position];
		Node* newNode = new Node;
		newNode->key = e;
		if (currentNode == NULL) { // no item on this position
			newNode->next = NULL;
			newTable[position] = newNode;
		}
		else { // insert first
			newNode->next = currentNode;
			newTable[position] = newNode;
		}

		it.next();
	}

	for (int i = 0; i < this->capacity; i++) {
		Node* currentElement = this->table.T[i];
		Node* prevElem = currentElement;
		while (currentElement != NULL) {
			prevElem = currentElement;
			currentElement = currentElement->next;
			delete prevElem;
		}
	}
	delete this->table.T;

	this->capacity *= 2;
	this->table.m = this->capacity;
	this->table.T = newTable;

	this->alpha = (float)this->length / this->capacity;
}

int Bag::hashFunction(TElem key) const
{
	return abs(key) % this->m;
}

Bag::Bag() {
	//TODO - Implementation
	this->length = 0;
	this->capacity = 2;
	this->table.T = new Node * [this->capacity];
	for (int i = 0; i < this->capacity; i++) {
		this->table.T[i] = NULL;
	}
	this->table.m = this->m = this->capacity;
	this->alpha = 0;
}


void Bag::add(TElem elem) {
	//TODO - Implementation

	if (this->alpha > 0.75)
		this->resize();

	int position = this->hashFunction(elem);
	Node* currentNode = this->table.T[position];
	Node* newNode = new Node;
	newNode->key = elem;
	if (currentNode == NULL) { // no item on this position
		newNode->next = NULL;
		this->table.T[position] = newNode;
	}
	else { // insert first
		newNode->next = currentNode;
		this->table.T[position] = newNode;
	}

	this->length++;
	this->alpha = (float)this->length / this->capacity;
}


bool Bag::remove(TElem elem) {
	//TODO - Implementation
	int position = this->hashFunction(elem);
	Node* currentNode = this->table.T[position];
	Node* prevNode = currentNode;
	while (currentNode != NULL && currentNode->key != elem) {
		prevNode = currentNode;
		currentNode = currentNode->next;
	}
	if (currentNode == NULL) // no item on this position
		return false;

	if (prevNode == currentNode) { // this is the first element
		this->table.T[position] = currentNode->next;
	}

	prevNode->next = currentNode->next;
	delete currentNode;


	this->length--;
	this->alpha = float(this->length / this->capacity);
	return true;
}


bool Bag::search(TElem elem) const {
	//TODO - Implementation
	int position = this->hashFunction(elem);
	Node* currentNode = this->table.T[position];
	while (currentNode != NULL && currentNode->key != elem)
		currentNode = currentNode->next;
	if (currentNode == NULL) // no item on this position
		return false;
	return true;
}

int Bag::nrOccurrences(TElem elem) const {
	//TODO - Implementation
	int occ = 0;
	int position = this->hashFunction(elem);
	Node* currentNode = this->table.T[position];
	while (currentNode != NULL) {
		if (currentNode->key == elem) occ++;
		currentNode = currentNode->next;
	}
	return occ; 
}


int Bag::size() const {
	//TODO - Implementation
	return this->length;
}


bool Bag::isEmpty() const {
	//TODO - Implementation
	return !this->length;
}

BagIterator Bag::iterator() const {
	return BagIterator(*this);
}


Bag::~Bag() {
	//TODO - Implementation
	for (int i = 0; i < this->capacity; i++) {
		Node* currentElement = this->table.T[i];
		Node* prevElem = currentElement;
		while (currentElement != NULL) {
			prevElem = currentElement;
			currentElement = currentElement->next;
			delete prevElem;
		}
	}
	delete this->table.T;
}

