#include "ListIterator.h"
#include "SortedIteratedList.h"
#include <exception>

using namespace std;

ListIterator::ListIterator(const SortedIteratedList& list) : list(list){
	//TODO - Implementation
	this->currentElement = list.head;
}

void ListIterator::first(){
	//TODO - Implementation
	this->currentElement = this->list.head;
}

void ListIterator::next(){
	//TODO - Implementation
	if (this->currentElement == -1)
		throw std::exception("Invalid element!");
	this->currentElement = this->list.nodes[this->currentElement].next;
}

bool ListIterator::valid() const{
	//TODO - Implementation
	if (this->currentElement == -1)
		return false;
	return true;
}

void ListIterator::last()
{
	this->currentElement = -1;
}

TComp ListIterator::getCurrent() const{
	//TODO - Implementation
	if (this->currentElement == -1)
		throw std::exception("Invalid element!");
	return this->list.nodes[this->currentElement].info;
}