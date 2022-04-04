#include "../include/List.hpp"

template<typename T>
SDIZO::List<T>::List()
	: firstNode(nullptr), lastNode(nullptr), size(0) {}

template<typename T>
SDIZO::List<T>::~List()
{
	ListNode<T>* currentNode = this->firstNode;

	// Free all occupied memory
	while (this->firstNode != nullptr)
	{
		this->firstNode = currentNode->next;
		delete currentNode;
		currentNode = this->firstNode;
	}
}

template<typename T>
void SDIZO::List<T>::addFront(const T& data)
{
	// Create new node, if list is empty
	if (this->size == 0)
	{
		this->createFirstNode(data);
		return;
	}

	// Create new node and set it as previous element of old first node
	this->firstNode->previous = new ListNode<T>(data, nullptr, this->firstNode);
	// Set created node as new first node
	this->firstNode = this->firstNode->previous;
	this->size++;
}

template<typename T>
void SDIZO::List<T>::addBack(const T& data)
{
	// Create new node, if list is empty
	if (this->size == 0)
	{
		this->createFirstNode(data);
		return;
	}

	// Create new node and set it as next element for old last node
	this->lastNode->next = new ListNode<T>(data, this->lastNode, nullptr);
	// Set created node as new last node
	this->lastNode = this->lastNode->next;
	this->size++;
}

template<typename T>
bool SDIZO::List<T>::addAt(const size_t& index, const T& data)
{
	// Check if index is correct
	if (index > this->size)
	{
		return false;
	}

	// Add first node
	if (index == 0)
	{
		this->addFront(data);
		return true;
	}

	// Add last node
	if (index == this->size)
	{
		this->addBack(data);
		return true;
	}

	size_t middleIndex = this->size / 2;

	// Add a node in first half of list
	if (index < middleIndex)
	{
		this->addFromFront(index, data);
		return true;
	}

	// Add a node in second half of list
	this->addFromBack(index, data);
	return true;
}

template<typename T>
bool SDIZO::List<T>::removeFront()
{
	// Check if any data exists
	if (this->size == 0)
	{
		return false;
	}

	// Check if exists only one node
	if (this->size == 1)
	{
		delete this->firstNode;
		this->firstNode = this->lastNode = nullptr;
		this->size--;
		return true;
	}

	// Replace reference to first node 
	this->firstNode = this->firstNode->next;

	// Delete old first node
	delete this->firstNode->previous;
	this->firstNode->previous = nullptr;
	this->size--;
	return true;
}

template<typename T>
bool SDIZO::List<T>::removeBack()
{
	// Check if any data exists
	if (this->size == 0)
	{
		return false;
	}

	// Check if exists only one node
	if (this->size == 1)
	{
		delete this->firstNode;
		this->firstNode = this->lastNode = nullptr;
		this->size--;
		return true;
	}

	// Replace reference to last node
	this->lastNode = this->lastNode->previous;

	// Delete old last node
	delete this->lastNode->next;
	this->lastNode->next = nullptr;
	this->size--;
	return true;
}

template<typename T>
bool SDIZO::List<T>::removeAt(const size_t& index)
{
	// Check if index is correct
	if (index >= this->size)
	{
		return false;
	}

	// Remove first node
	if (index == 0)
	{
		this->removeFront();
		return true;
	}

	// Remove last node
	if (index == this->size - 1)
	{
		this->removeBack();
		return true;
	}

	size_t middleIndex = this->size / 2;

	if (index < middleIndex)
	{
		this->removeFromFront(index);
		this->size--;
		return true;
	}

	this->removeFromBack(index);
	this->size--;
	return true;
}

template<typename T>
void SDIZO::List<T>::print(std::ostream& out)
{
	if (this->size > 0)
	{
		ListNode<T>* iterator = this->firstNode;
		size_t index = 0;
		while (iterator != nullptr)
		{
			out << index << " -> " << iterator->value << std::endl;
			iterator = iterator->next;
			index++;
		}
		return;
	}
	out << "Data structure is empty" << std::endl;
}

template<typename T>
size_t SDIZO::List<T>::getSize()
{
	return this->size;
}

template<typename T>
void SDIZO::List<T>::createFirstNode(const T& data)
{
	this->firstNode = this->lastNode = new ListNode<T>(data, nullptr, nullptr);
	this->size++;
}

template<typename T>
void SDIZO::List<T>::addFromFront(const size_t& index, const T& data)
{
	size_t currentIndex = 0;
	ListNode<T>* currentNode = this->firstNode;

	// Find correct index for new node
	while (currentIndex < index)
	{
		currentNode = currentNode->next;
		currentIndex++;
	}

	ListNode<T>* newNode = new ListNode<T>(data, currentNode->previous, currentNode);
	currentNode->previous->next = newNode;
	currentNode->previous = newNode;
	this->size++;
}

template<typename T>
void SDIZO::List<T>::addFromBack(const size_t& index, const T& data)
{
	size_t currentIndex = this->size - 1;
	ListNode<T>* currentNode = this->lastNode;

	// Find correct index for new node
	while (currentIndex > index)
	{
		currentNode = currentNode->previous;
		currentIndex--;
	}

	ListNode<T>* newNode = new ListNode<T>(data, currentNode->previous, currentNode);
	currentNode->previous->next = newNode;
	currentNode->previous = newNode;
	this->size++;
}

template<typename T>
void SDIZO::List<T>::removeFromFront(const size_t& index)
{
	size_t currentIndex = 0;
	ListNode<T>* currentNode = this->firstNode;

	// Find node to remove
	while (currentIndex < index)
	{
		currentNode = currentNode->next;
		currentIndex++;
	}

	// Replace references
	currentNode->next->previous = currentNode->previous;
	currentNode->previous->next = currentNode->next;

	// Delete selected node
	delete currentNode;
}

template<typename T>
void SDIZO::List<T>::removeFromBack(const size_t& index)
{
	size_t currentIndex = this->size - 1;
	ListNode<T>* currentNode = this->lastNode;

	// Find node to remove
	while (currentIndex > index)
	{
		currentNode = currentNode->previous;
		currentIndex--;
	}

	// Replace references
	currentNode->next->previous = currentNode->previous;
	currentNode->previous->next = currentNode->next;

	// Delete selected node
	delete currentNode;
}

// The only one data type necessary in this project
template class SDIZO::List<int>;