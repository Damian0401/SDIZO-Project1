#pragma once

#include "interface/Enums.hpp"

namespace SDIZO
{
	template<typename T>
	struct TreeNode
	{
		T value;
		TreeNode* parent;
		TreeNode* left;
		TreeNode* right;
		Color color;
		TreeNode(T value, TreeNode* parent, TreeNode* left, 
			TreeNode* right, Color color)
			: value(value), parent(parent),	left(left), 
			right(right), color(color) {};
		TreeNode() {};
	};
}