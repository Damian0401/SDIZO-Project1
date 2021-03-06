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
bool SDIZO::Heap<T>::search(const T& data)
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
bool SDIZO::Heap<T>::removeRoot()
{
	// Check if heap is not empty
	if (this->size == 0)
	{
		return false;
	}

	this->size--;
	T* newHead = nullptr;

	if (this->size > 0)
	{
		newHead = new T[this->size];

		// Set the last element of the heap as new root
		newHead[0] = this->head[this->size];

		// Copy existing data
		for (int i = 1; i < this->size; i++)
		{
			newHead[i] = this->head[i];
		}
	}

	delete[] this->head;
	this->head = newHead;
	this->maxHeapify(0);

	return true;
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
			out << "\n\n";

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
	// Check if heap is not empty
	if (this->size == 0)
	{
		return false;
	}

	// Swap index if needed
	if (this->head[childIndex] > this->head[parentIndex])
	{
		T value = this->head[parentIndex];
		this->head[parentIndex] = this->head[childIndex];
		this->head[childIndex] = value;
		return true;
	}
	return false;
}

template<typename T>
void SDIZO::Heap<T>::maxHeapify(size_t index)
{
	size_t left = index * 2 + 1;
	size_t right = (index + 1) * 2;
	size_t largest = index;

	// Check if left child is greater than parent
	if (left < this->size && this->head[left] > this->head[largest])
	{
		largest = left;
	}

	// Check if right child is greater than parent
	if (right < this->size && this->head[right] > this->head[largest])
	{
		largest = right;
	}

	bool swapped = this->swapIfNeeded(index, largest);
	if (swapped)
	{
		this->maxHeapify(largest);
	}
}

// The only one data type necessary in this project
template class SDIZO::Heap<int>;