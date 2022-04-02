#pragma once

#include <iostream>
#include "TreeNode.hpp"

namespace SDIZO
{
	template<typename T>
	class Tree
	{
	public:
		Tree();
		~Tree();
		virtual void print(std::ostream& out);
	private:
		TreeNode<T>* root;
		void calculateDepth(SDIZO::TreeNode<T>* node, int& maxDepth, int currentDepth);
		void placeNode(SDIZO::TreeNode<T>* node, SDIZO::TreeNode<int>** table, int index);
	};
}