#include "SMIterator.h"
#include "SortedMap.h"
#include <exception>

using namespace std;

SMIterator::SMIterator(const SortedMap& m) : map(m){
	//TODO - Implementation
	this->index = -1;
	this->capacity = 4;
	this->stack = new SortedMap::Node * [this->capacity];
	this->first();
}

void SMIterator::first(){
	//TODO - Implementation
	this->index = -1;
	SortedMap::Node* node = this->map.tree.root;
	while (node != NULL) {
		this->push(node);
		node = node->left;
	}
	if (!this->isEmpty())
		this->current = top();
	else
		this->current = NULL;
}

void SMIterator::next(){
	//TODO - Implementation
	SortedMap::Node* node = this->pop();

	if (node->right != NULL) {
		node = node->right;
		while (node != NULL) {
			this->push(node);
			node = node->left;
		}
	}
	if (!this->isEmpty())
		this->current = this->top();
	else
		this->current = NULL;

}

bool SMIterator::valid() const{
	//TODO - Implementation
	return this->current != NULL;
}

TElem SMIterator::getCurrent() const{
	//TODO - Implementation
	if (this->valid() == false)
		throw exception("Invalid element!");
	return this->current->value;
}

bool SMIterator::isEmpty()
{
	return this->index == -1;
}

SortedMap::Node* SMIterator::pop()
{
	if (this->index == -1)
		throw exception("Invalid operation");
	return this->stack[this->index--];
}

void SMIterator::push(SortedMap::Node* node)
{
	if (this->index == this->capacity - 1)
		this->resize();
	this->stack[++this->index] = node;
}

SortedMap::Node* SMIterator::top()
{
	return this->stack[this->index];
}

void SMIterator::resize()
{
	this->capacity *= 2;
	SortedMap::Node** newStack = new SortedMap::Node * [this->capacity];
	for (int i = 0; i <= this->index; i++)
		newStack[i] = this->stack[i];
	delete this->stack;
	this->stack = newStack;
}


