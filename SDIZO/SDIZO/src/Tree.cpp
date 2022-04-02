#include <math.h>
#include <Windows.h>
#include "../include/Tree.hpp"

template<typename T>
SDIZO::Tree<T>::Tree() : root(nullptr) {}

template<typename T>
SDIZO::Tree<T>::~Tree()
{
}

template<typename T>
void SDIZO::Tree<T>::print(std::ostream& out)
{
	if (this->root != nullptr)
	{
		// Calculate tree depth
		int depth = 0;
		calculateDepth(this->root, depth, 0);

		// Calculate maximum number of nodes
		int size = pow(2, depth);

		// Create table to get access to all nodes
		SDIZO::TreeNode<T>** table = new SDIZO::TreeNode<T>*[size];
		for (int i = 0; i < size; i++)
		{
			table[i] = nullptr;
		}

		// Place nodes inside table
		placeNode(this->root, table, 0);

		// Get handler for console manipulation
		HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

		bool outOfBound = false;
		size_t first = 0;
		size_t last = 1;
		size--;

		// Calculate the maximum number of nodes at the current heap level
		size_t space = size;

		while (!outOfBound)
		{
			// Print space before each heap level
			out << std::string(space / 2 * 3, ' ');

			// Print nodes on current heap level
			for (size_t i = first; i < last; i++)
			{
				if (i >= size)
				{
					outOfBound = true;
					break;
				}

				// Check if table on current index is not empty
				if (table[i] != nullptr)
				{
					// Display node
					int color = table[i]->color == SDIZO::Color::Red ? 12 : 8;
					SetConsoleTextAttribute(hConsole, color);
					out << '[' << table[i]->value << ']' << std::string(space * 3, ' ');
					continue;
				}

				// Display emply space instead of node
				out << "   " << std::string(space * 3, ' ');
			}
			out << "\n\n";

			// Change indexes or last and first node on each heap level
			first = last;
			last = 2 * last + 1;

			// Change size of space between nodes
			space = space / 2;
		}

		// Set back default console color
		SetConsoleTextAttribute(hConsole, 15);

		// Delete table for storing nodes
		delete[] table;

		return;
	}
	out << "Data structure is empty" << std::endl;
}

template<typename T>
void SDIZO::Tree<T>::calculateDepth(SDIZO::TreeNode<T>* node, int& maxDepth, int currentDepth)
{
	currentDepth++;

	if (currentDepth > maxDepth)
	{
		maxDepth = currentDepth;
	}

	if (node->left != nullptr)
	{
		calculateDepth(node->left, maxDepth, currentDepth);
	}

	if (node->right != nullptr)
	{
		calculateDepth(node->right, maxDepth, currentDepth);
	}
}

template<typename T>
void SDIZO::Tree<T>::placeNode(SDIZO::TreeNode<T>* node, SDIZO::TreeNode<int>** table, int index)
{
	table[index] = node;

	if (node->left != nullptr)
	{
		placeNode(node->left, table, 2 * index + 1);
	}

	if (node->right != nullptr)
	{
		placeNode(node->right, table, 2 * index + 2);
	}
}

// The only one data type necessary in this project
template class SDIZO::Tree<int>;