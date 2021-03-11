#include "ListIterator.h"
#include "SortedIteratedList.h"
#include <iostream>
using namespace std;
#include <exception>



int SortedIteratedList::allocate()
{
	int newElem = this->firstEmpty;
	if (newElem != -1) {
		this->firstEmpty = this->nodes[this->firstEmpty].next;
		if (this->firstEmpty != -1) {
			this->nodes[this->firstEmpty].prev = -1;
		}
		this->nodes[newElem].next = -1;
		this->nodes[newElem].prev = -1;
	}

	return newElem;
}

void SortedIteratedList::free(int pos)
{
	this->nodes[pos].next = this->firstEmpty;
	this->nodes[pos].prev = -1;
	if (this->firstEmpty != -1) {
		this->nodes[this->firstEmpty].prev = pos;
	}
	this->firstEmpty = pos;
}

void SortedIteratedList::resize()
{
	DLLANode* newList = new DLLANode[this->capacity * 2];
	for (int i = 0; i < this->capacity; i++) {
		newList[i].next = this->nodes[i].next;
		newList[i].prev = this->nodes[i].prev;
		newList[i].info = this->nodes[i].info;
	}
	for (int i = this->capacity; i < this->capacity * 2; i++) {
		newList[i].next = i + 1;
		newList[i].prev = i - 1;
	}
	newList[this->capacity * 2 - 1].next = -1;
	this->firstEmpty = this->capacity;
	this->capacity *= 2;
	delete this->nodes;
	this->nodes = newList;
}

SortedIteratedList::SortedIteratedList(Relation r) {
	//TODO - Implementation
	this->r = r;
	this->capacity = 2;
	this->length = 0;
	this->nodes = new DLLANode[this->capacity];
	this->head = this->tail = -1;
	for (int i = 0; i < this->capacity; i++) {
		this->nodes[i].next = i + 1;
		this->nodes[i].prev = i - 1;
	}
	this->nodes[this->capacity - 1].next = -1;
	this->firstEmpty = 0;
}

void SortedIteratedList::removeBetween(ListIterator start, ListIterator end)
{
	if (!start.valid() || !end.valid())
		throw (exception("Invalid Range!"));

	while (this->r(start.getCurrent(), end.getCurrent())) {
		this->remove(start);
	}
}

int SortedIteratedList::size() const {
	//TODO - Implementation
	return this->length;
}

bool SortedIteratedList::isEmpty() const {
	//TODO - Implementation
	return !this->length;
}

ListIterator SortedIteratedList::first() const {
	//TODO - Implementation
	return ListIterator(*this);
}

TComp SortedIteratedList::getElement(ListIterator poz) const {
	//TODO - Implementation
	if (poz.currentElement == -1)
		throw std::exception("Invalid element!");
	return this->nodes[poz.currentElement].info;
}

TComp SortedIteratedList::remove(ListIterator& poz) {
	//TODO - Implementation
	if (poz.currentElement == -1 || poz.currentElement >= this->capacity)
		throw std::exception("Invalid element!");

	int currentNode = poz.currentElement;
	poz.currentElement = this->nodes[currentNode].next;  //poz.next();
	if (currentNode != -1) {
		if (currentNode == this->head) {
			if (currentNode == this->tail) {
				this->head = this->tail = -1;
			}
			else {
				this->head = this->nodes[this->head].next;
				this->nodes[this->head].prev = -1;
			}
		}
		else if (currentNode == this->tail){
			this->tail = this->nodes[this->tail].prev;
			this->nodes[this->tail].next = -1;
		}
		else {
			this->nodes[this->nodes[currentNode].next].prev = this->nodes[currentNode].prev;
			this->nodes[this->nodes[currentNode].prev].next = this->nodes[currentNode].next;
		}
	}

	this->free(currentNode);
	this->length--;
	return this->nodes[currentNode].info;
}

ListIterator SortedIteratedList::search(TComp e) const {
	//TODO - Implementation
	ListIterator it{ *this };
	try {
		while (!this->r(e, it.getCurrent())) {
			it.next();
		}
		if (it.getCurrent() != e) {
			it.last();
		}
	}
	catch (std::exception&) {}
	return it;
}

void SortedIteratedList::add(TComp e) {
	//TODO - Implementation
	int newElem = this->allocate();
	if (newElem == -1) {
		this->resize();
		newElem = this->allocate();
	}

	this->nodes[newElem].info = e;
	this->nodes[newElem].next = this->nodes[newElem].prev = -1;
	if (this->head == -1) { // the list is empty
		this->head = newElem;
		this->tail = newElem;
	}
	else if (this->r(e, this->nodes[this->head].info)) { // the element is "less than" the info from the head
		this->nodes[newElem].next = this->head;
		this->nodes[this->head].prev = newElem;
		this->head = newElem;
	}
	else { // we find the right position to insert the new element
		int currentElement = this->head;
		while (this->nodes[currentElement].next != -1 && this->r(e, this->nodes[this->nodes[currentElement].next].info) == false) {
			currentElement = this->nodes[currentElement].next;
		}
		if (currentElement == this->tail) { // insert on last position
			this->nodes[newElem].prev = this->tail;
			this->nodes[this->tail].next = newElem;
			this->tail = newElem;
		}
		else { // insert between two nodes
			this->nodes[newElem].next = this->nodes[currentElement].next;
			this->nodes[newElem].prev = currentElement;
			this->nodes[this->nodes[currentElement].next].prev = newElem;
			this->nodes[currentElement].next = newElem;
		}
	}

	this->length++;
}

SortedIteratedList::~SortedIteratedList() {
	//TODO - Implementation
	delete this->nodes;
}
