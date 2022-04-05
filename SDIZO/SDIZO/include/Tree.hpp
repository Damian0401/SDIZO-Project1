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
		virtual void add(const T& data);
		virtual bool remove(const T& data);
		virtual void print(std::ostream& out);
	private:
		TreeNode<T>* root;
		TreeNode<T>* guard;
		TreeNode<T>* successor(TreeNode<T>* node);
		TreeNode<T>* minumum(TreeNode<T>* node);
		TreeNode<T>* findNode(const T& data, TreeNode<T>* node);
		void leftRotation(TreeNode<T>* node);
		void rightRotation(TreeNode<T>* node);
		void deleteFixUp(TreeNode<T>* node);
		void deleteNodes(TreeNode<T>* node);
		void calculateDepth(SDIZO::TreeNode<T>* node, size_t& maxDepth, size_t currentDepth);
		void placeNodes(SDIZO::TreeNode<T>* node, SDIZO::TreeNode<T>** table, size_t index);
	};
}