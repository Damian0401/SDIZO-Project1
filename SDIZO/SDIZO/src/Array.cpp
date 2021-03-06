#include "../include/Array.hpp"

template <typename T>
SDIZO::Array<T>::Array() : head(nullptr), size(0) {}

template <typename T>
SDIZO::Array<T>::~Array()
{
	if (this->head != nullptr)
	{
		delete[] this->head;
	}
}

template<typename T>
void SDIZO::Array<T>::addFront(const T& data)
{
	T* newHead = new T[this->size + 1];
	newHead[0] = data;

	// Copy data if exists
	if (this->head != nullptr)
	{
		for (size_t i = 0; i < this->size; i++)
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
void SDIZO::Array<T>::addBack(const T& data)
{
	T* newHead = new T[this->size + 1];
	newHead[this->size] = data;

	// Copy data if exists
	if (this->head != nullptr)
	{
		for (size_t i = 0; i < this->size; i++)
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
bool SDIZO::Array<T>::addAt(const size_t& index, const T& data)
{
	// Check if index is correct
	if (index > this->size)
	{
		return false;
	}

	T* newHead = new T[this->size + 1];
	newHead[index] = data;

	// Copy elements before specific index
	for (size_t i = 0; i < index; i++)
	{
		newHead[i] = this->head[i];
	}

	// Copy elements after specific index
	for (size_t i = index + 1; i <= size; i++)
	{
		newHead[i] = this->head[i - 1];
	}

	delete[] this->head;
	this->size++;
	this->head = newHead;
	return true;
}

template<typename T>
bool SDIZO::Array<T>::search(const T& data)
{
	if (this->size == 0)
	{
		return false;
	}

	for (size_t i = 0; i < this->size; i++)
	{
		if (this->head[i] == data)
		{
			return true;
		}
	}

	return false;
}

template<typename T>
bool SDIZO::Array<T>::removeFront()
{
	// Check if any data exists
	if (this->head == nullptr)
	{
		return false;
	}

	T* newHead = nullptr;

	// Copy data if needed
	if (this->size > 1)
	{
		newHead = new T[size - 1];
		for (size_t i = 1; i < this->size; i++)
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
bool SDIZO::Array<T>::removeBack()
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
		for (size_t i = 0; i < this->size; i++)
		{
			newHead[i] = this->head[i];
		}
	}

	delete[] this->head;
	this->head = newHead;
	return true;
}

template<typename T>
bool SDIZO::Array<T>::removeAt(const size_t& index)
{
	// Check if index is correct
	if (index >= this->size)
	{
		return false;
	}

	T* newHead = nullptr;

	// Copy data if needed
	if (this->size > 1)
	{
		newHead = new T[size - 1];

		// Copy data before index
		for (size_t i = 0; i < index; i++)
		{
			newHead[i] = this->head[i];
		}

		// Copy data after index
		for (size_t i = index + 1; i < size; i++)
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
void SDIZO::Array<T>::print(std::ostream& out)
{
	if (this->size > 0 && this->head != nullptr)
	{
		for (size_t i = 0; i < this->size; i++)
		{
			out << i << " -> " << this->head[i] << std::endl;
		}
		return;
	}
	out << "Data structure is empty" << std::endl;
}

template<typename T>
size_t SDIZO::Array<T>::getSize()
{
	return this->size;
}

// The only one data type necessary in this project
template class SDIZO::Array<int>;
