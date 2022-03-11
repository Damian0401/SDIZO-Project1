#pragma once

#include <iostream>

namespace DS
{
	template<typename T>
	class Array
	{
	public:
		Array();
		~Array();
		size_t getSize();
		virtual void addFront(const T data);
		virtual void addBack(const  T data);
		virtual bool addAt(const size_t index, T data);
		virtual bool removeFront();
		virtual bool removeBack();
		virtual bool removeAt(const size_t index);
		virtual void print(std::ostream& out);
	private:
		T* head;
		size_t size;
	};
}
