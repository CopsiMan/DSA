#include "SMIterator.h"
#include "SortedMap.h"
#include <exception>
using namespace std;

SortedMap::SortedMap(Relation r) {
	//TODO - Implementation
	this->relation = r;
	this->length = 0;
}

void SortedMap::replace(TKey k, TValue oldValue, TValue newValue)
{
	Node* current = this->tree.root;
	bool found = false;
	while (current != NULL && found == false) {
		if (current->value.first == k)
			found = true;
		else {
			if (this->relation(current->value.first, k))
				current = current->right;
			else
				current = current->left;
		}
	}
	if (found) {
		if (current->value.second == oldValue)
			current->value.second = newValue;
	}
}

TValue SortedMap::add(TKey k, TValue v) {
	//TODO - Implementation
	if (this->isEmpty()) {
		Node* newNode = new Node;
		newNode->left = NULL;
		newNode->right = NULL;
		newNode->value = TElem(k, v);
		this->tree.root = newNode;
		this->length++;
		return NULL_TVALUE;
	}
	Node* current = this->tree.root;
	Node* prev = this->tree.root;
	bool found = false;
	while (current != NULL && found == false) {
		if (current->value.first == k)
			found = true;
		else {
			prev = current;
			if (this->relation(current->value.first, k))
				current = current->right;
			else
				current = current->left;
		}
	}
	if (found) {
		TValue currentValue = current->value.second;
		current->value.second = v;
		return currentValue;
	}
	
	Node* newNode = new Node;
	newNode->left = NULL;
	newNode->right = NULL;
	newNode->value = TElem(k, v);
	if (this->relation(prev->value.first, k))
		prev->right = newNode;
	else
		prev->left = newNode;
	this->length++;
	return NULL_TVALUE;
}

TValue SortedMap::search(TKey k) const {
	//TODO - Implementation
	Node* current = this->tree.root;
	bool found = false;
	while (current != NULL && found == false) {
		if (current->value.first == k)
			found = true;
		else {
			if (this->relation(current->value.first, k))
				current = current->right;
			else
				current = current->left;
		}
	}
	if (found)
		return current->value.second;
	return NULL_TVALUE;
}

TValue SortedMap::remove(TKey k) {
	//TODO - Implementation

	if (this->isEmpty()) {
		return NULL_TVALUE;
	}

	Node* current = this->tree.root;
	Node* prev = NULL;
	bool found = false;
	while (current != NULL && found == false) {
		if (current->value.first == k)
			found = true;
		else {
			prev = current;
			if (this->relation(current->value.first, k))
				current = current->right;
			else
				current = current->left;
		}
	}

	if (found) {
		this->length--;
		TValue value = current->value.second;
		if (this->isEmpty()) {
			this->tree.root = NULL;
		}
		else if (prev == NULL) // we only have the root
		{
			if (current->left == NULL)
				this->tree.root = current->right;
			else if (current->right == NULL)
				this->tree.root = current->left;
		}
		else if (current->left == NULL && current->right == NULL) {
			if (this->relation(prev->value.first, current->value.first))
				prev->right = NULL;
			else
				prev->left = NULL;
		}
		else if (current->left == NULL) {
			if (this->relation(prev->value.first, current->value.first))
				prev->right = current->right;
			else
				prev->left = current->right;
		}
		else if (current->right == NULL) {
			if (this->relation(prev->value.first, current->value.first))
				prev->right = current->left;
			else
				prev->left = current->left;
		}
		else {
			Node* child = current->right;
			prev = NULL;
			while (child->left != NULL) {
				prev = child;
				child = child->left;
			}

			current->value = child->value;
			if (prev == NULL)
				current->right = child->right;
			else if (child->right != NULL)
				prev->left = child->right;
			else
				prev->left = NULL;
			delete child;
			return value;
		}
		delete current;
		return value;
	}

	return NULL_TVALUE;
}

int SortedMap::size() const {
	//TODO - Implementation
	return this->length;
}

bool SortedMap::isEmpty() const {
	//TODO - Implementation
	return !this->length;
}

SMIterator SortedMap::iterator() const {
	return SMIterator(*this);
}

void SortedMap::dealocateNode(Node* node)
{
	if (node->right != NULL)
		this->dealocateNode(node->right);
	if (node->left != NULL)
		this->dealocateNode(node->left);
	delete node;
}

SortedMap::~SortedMap() {
	//TODO - Implementation
	if(!this->isEmpty())
		this->dealocateNode(this->tree.root);
}
