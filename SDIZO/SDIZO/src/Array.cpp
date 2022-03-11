#include "../include/Array.hpp"

template <typename T>
DS::Array<T>::Array() : head(nullptr), size(0) {}

template <typename T>
DS::Array<T>::~Array()
{
	if (this->head != nullptr)
	{
		delete[] this->head;
	}
}

template<typename T>
size_t DS::Array<T>::getSize()
{
	return this->size;
}

template<typename T>
void DS::Array<T>::addFront(const T data)
{
	T* newHead = new T[this->size + 1];
	newHead[0] = data;

	// Copy data if exists
	if (this->head != nullptr)
	{
		for (int i = 0; i < this->size; i++)
		{
			newHead[i + 1] = this->head[i];
		}

		// Delete old dynamic array
		delete[] this->head;
	}

	this->size++;
	this->head = newHead;
}

template<typename T>
void DS::Array<T>::addBack(const T data)
{
	T* newHead = new T[this->size + 1];
	newHead[this->size] = data;

	// Copy data if exists
	if (this->head != nullptr)
	{
		for (int i = 0; i < this->size; i++)
		{
			newHead[i] = this->head[i];
		}

		// Delete old dynamic array
		delete[] this->head;
	}

	this->size++;
	this->head = newHead;
}

template<typename T>
bool DS::Array<T>::addAt(const size_t index, T data)
{
	// Check if index if correct
	if (index > this->size)
	{
		return false;
	}

	T* newHead = new T[this->size + 1];
	newHead[index] = data;

	// Copy elements before specific index
	for (int i = 0; i < index; i++)
	{
		newHead[i] = this->head[i];
	}

	// Copy elements after specific index
	for (int i = index + 1; i <= size; i++)
	{
		newHead[i] = this->head[i - 1];
	}

	delete[] this->head;
	this->size++;
	this->head = newHead;
	return true;
}

template<typename T>
bool DS::Array<T>::removeFront()
{
	// Check if data exists
	if (this->head == nullptr)
	{
		return false;
	}

	T* newHead = nullptr;

	// Copy data if needed
	if (this->size > 1)
	{
		newHead = new T[size - 1];
		for (int i = 1; i < this->size; i++)
		{
			newHead[i - 1] = this->head[i];
		}
	}

	delete[] this->head;
	this->size--;
	this->head = newHead;
	return true;
}

template<typename T>
bool DS::Array<T>::removeBack()
{
	// Check if any data exists
	if (this->head == nullptr)
	{
		return false;
	}

	T* newHead = nullptr;
	this->size--;

	// Copy data if needed
	if (this->size >= 1)
	{
		newHead = new T[size];
		for (int i = 0; i < this->size; i++)
		{
			newHead[i] = this->head[i];
		}
	}

	delete[] this->head;
	this->head = newHead;
	return true;
}

template<typename T>
bool DS::Array<T>::removeAt(const size_t index)
{
	// Check if data exists and index is correct
	if (this->head == nullptr || index >= this->size)
	{
		return false;
	}

	T* newHead = nullptr;

	// Copy data if needed
	if (this->size > 1)
	{
		newHead = new T[size - 1];
		for (int i = 0; i < index; i++)
		{
			newHead[i] = this->head[i];
		}

		for (int i = index + 1; i < size; i++)
		{
			newHead[i - 1] = this->head[i];
		}
	}

	delete[] this->head;
	this->size--;
	this->head = newHead;
	return true;
}

template<typename T>
void DS::Array<T>::print(std::ostream& out)
{
	if (this->size > 0 && this->head != nullptr)
	{
		for (int i = 0; i < this->size; i++)
		{
			out << i << " -> " << this->head[i] << std::endl;
		}
	}
}

// The only one data type necessary in this project
template class DS::Array<int>;
