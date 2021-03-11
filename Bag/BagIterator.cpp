#include <exception>
#include "BagIterator.h"
#include "Bag.h"

using namespace std;


BagIterator::BagIterator(const Bag& c): bag(c) {
	//TODO - Implementation
	this->currentPos = 0;
	while (this->currentPos < bag.table.m && bag.table.T[this->currentPos] == NULL)
		this->currentPos++;
	if (this->currentPos < bag.table.m)
		this->currentNode = bag.table.T[this->currentPos];
	else
		this->currentNode = NULL;
}

void BagIterator::first() {
	//TODO - Implementation
	this->currentPos = 0;
	while (this->currentPos < bag.table.m && bag.table.T[this->currentPos] == NULL)
		this->currentPos++;
	if (this->currentPos < bag.table.m)
		this->currentNode = bag.table.T[this->currentPos];
	else
		this->currentNode = NULL;
}


void BagIterator::next() {
	//TODO - Implementation
	if (this->currentNode == NULL)
		throw exception("Invalid iterator");
	if (this->currentNode->next != NULL) {
		this->currentNode = this->currentNode->next;
		return;
	}
	this->currentPos++;
	while (this->currentPos < bag.table.m && bag.table.T[this->currentPos] == NULL)
		this->currentPos++;
	if (this->currentPos < bag.table.m)
		this->currentNode = bag.table.T[this->currentPos];
	else
		this->currentNode = NULL;
}


bool BagIterator::valid() const {
	//TODO - Implementation
	return this->currentPos < this->bag.table.m;
}



TElem BagIterator::getCurrent() const {
	//TODO - Implementation
	if (this->currentNode == NULL)
		throw exception("Invalid iterator");
	return this->currentNode->key;
}
