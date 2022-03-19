#pragma once

#include <iostream>
#include "ListNode.hpp"

namespace SDIZO
{
	template<typename T>
	class List
	{
	public:
		List();
		~List();
		virtual void addFront(const T& data);
		virtual void addBack(const  T& data);
		virtual bool addAt(const size_t& index, const T& data);
		virtual bool removeFront();
		virtual bool removeBack();
		virtual bool removeAt(const size_t& index);
		virtual void print(std::ostream& out);
	private:
		ListNode<T>* firstNode;
		ListNode<T>* lastNode;
		size_t size;
		void createFirstNode(const T& data);
		void addFromFront(const size_t& index, const T& data);
		void addFromBack(const size_t& index, const T& data);
		void removeFromFront(const size_t& index);
		void removeFromBack(const size_t& index);
	};
}