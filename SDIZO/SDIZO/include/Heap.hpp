#pragma once

#include <iostream>

namespace SDIZO
{
	template<typename T>
	class Heap
	{
	public:
		Heap();
		~Heap();
		virtual void add(const T& data);
		virtual bool removeRoot();
		virtual void print(std::ostream& out);
	private:
		T* head;
		size_t size;
		void correctHeap();
		bool swapIfNeeded(size_t firstIndex, size_t secondIndex);
		void maxHeapify(size_t index);
	};
}