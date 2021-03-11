#include "MultiMapIterator.h"
#include "MultiMap.h"


MultiMapIterator::MultiMapIterator(const MultiMap& c) : col(c) {
	//TODO - Implementation
	this->it = new SLLTKey_Iterator;
	this->it->list = col.elems;
	this->it->currentElement = col.elems->head;
	this->it->values = new SLLTValue_Iterator;
	if (col.elems->head != NULL) {
		this->it->values->list = col.elems->head->values;
		this->it->values->currentElement = col.elems->head->values->head;
	}
}

void MultiMapIterator::jumpForward(int k)
{
	if (k <= 0)
		throw exception("Invalid number of steps");
	if (!this->valid())
		throw exception("Invalid iterator");

	while (k && this->valid()) {
		this->next();
		k--;
	}
}

TElem MultiMapIterator::getCurrent() const{
	//TODO - Implementation
	if (this->it->currentElement == NULL) {
		throw exception("Invalid element");
	}
	if (this->it->values->currentElement == NULL) {
		throw exception("Invalid element");
	}
	TElem elem(this->it->currentElement->key, this->it->values->currentElement->value);
	return elem;
}

bool MultiMapIterator::valid() const {
	//TODO - Implementation
	if (this->it->currentElement == NULL)
		return false;
	return true;
}

void MultiMapIterator::next() {
	//TODO - Implementation
	if (this->it->currentElement == NULL)
		throw exception("Invalid element");

	if (this->it->values->currentElement != NULL) {
		this->it->values->currentElement = this->it->values->currentElement->next;
		if (this->it->values->currentElement == NULL) {
			this->it->currentElement = this->it->currentElement->next;
			if (this->it->currentElement != NULL) {
				this->it->values->list = this->it->currentElement->values;
				this->it->values->currentElement = this->it->values->list->head;
			}
		}
	}
	else {
		this->it->currentElement = this->it->currentElement->next;
	}
}

void MultiMapIterator::first() {
	//TODO - Implementation
	this->it->list = col.elems;
	this->it->currentElement = col.elems->head;
	if (col.elems->head != NULL) {
		this->it->values->list = col.elems->head->values;
		this->it->values->currentElement = col.elems->head->values->head;
	}
}

MultiMapIterator::~MultiMapIterator()
{
	delete this->it->values;
	delete this->it;
}

