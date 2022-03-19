#include "../include/Heap.hpp"
#include <math.h>

template<typename T>
SDIZO::Heap<T>::Heap() : head(nullptr), size(0) {}

template<typename T>
SDIZO::Heap<T>::~Heap()
{
	if (this->head != nullptr)
	{
		delete[] this->head;
	}
}

template<typename T>
void SDIZO::Heap<T>::add(const T& data)
{
	T* newHead = new T[this->size + 1];
	newHead[this->size] = data;

	// Check if any data exists
	if (this->head != nullptr)
	{
		// Copy all data
		for (size_t i = 0; i < this->size; i++)
		{
			newHead[i] = this->head[i];
		}

		// Delete old dynamic array
		delete[] this->head;
	}

	this->size++;
	this->head = newHead;
	this->correctHeap();
}

template<typename T>
void SDIZO::Heap<T>::print(std::ostream& out)
{
	if (this->size > 0 && this->head != nullptr)
	{
		bool outOfBound = false;
		size_t first = 0;
		size_t last = 1;

		// Calculate the maximum number of nodes at the current heap level
		size_t space = pow(2, floor(log2(this->size)) + 1) - 1;

		while (!outOfBound)
		{
			// Print space before each heap level
			out << std::string(space / 2 * 3, ' ');

			// Print nodes on current heap level
			for (size_t i = first; i < last; i++)
			{
				if (i >= this->size)
				{
					outOfBound = true;
					break;
				}
				out << '[' << this->head[i] << ']' << std::string(space * 3, ' ');
			}
			out << std::endl;

			// Change indexes or last and first node on each heap level
			first = last;
			last = 2 * last + 1;

			// Change size of space between nodes
			space = space / 2;
		}
		return;
	}
	out << "Data structure is empty" << std::endl;
}

template<typename T>
void SDIZO::Heap<T>::correctHeap()
{
	size_t childIndex = this->size - 1;
	size_t parentIndex = (childIndex - 1) / 2;
	bool swapped = true;
	while (childIndex != 0 && swapped)
	{
		swapped = this->swapIfNeeded(parentIndex, childIndex);
		childIndex = parentIndex;
		parentIndex = (childIndex - 1) / 2;
	}
}

template<typename T>
bool SDIZO::Heap<T>::swapIfNeeded(size_t parentIndex, size_t childIndex)
{
	if (this->head[childIndex] > this->head[parentIndex])
	{
		T value = this->head[parentIndex];
		this->head[parentIndex] = this->head[childIndex];
		this->head[childIndex] = value;
		return true;
	}
	return false;
}

// The only one data type necessary in this project
template class SDIZO::Heap<int>;