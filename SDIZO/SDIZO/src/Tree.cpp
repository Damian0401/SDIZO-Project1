#include <math.h>
#include <Windows.h>
#include "../include/Tree.hpp"

template<typename T>
SDIZO::Tree<T>::Tree()
{
	// Initialize guardian
	this->guard = new TreeNode<T>();
	this->guard->color = Color::Black;
	this->guard->parent = this->guard;
	this->guard->left = this->guard;
	this->guard->right = this->guard;

	// Set root pointer to the guardian
	this->root = this->guard;
}

template<typename T>
SDIZO::Tree<T>::~Tree()
{
	// Delete all nodes
	this->deleteNodes(this->root);

	// Delete guardian
	if (this->guard != nullptr)
	{
		delete this->guard;
	}
}

template<typename T>
void SDIZO::Tree<T>::add(const T& data)
{
	// Create new node, and temporary helper
	TreeNode<T>* newNode;
	TreeNode<T>* helper;

	// Initialize new node
	newNode = new TreeNode<T>(data, this->root,
		this->guard, this->guard, Color::Red);

	// Check if tree contains any nodes
	if (newNode->parent == this->guard)
	{
		this->root = newNode;
	}
	else
	{
		// Place new node in tree, like in regular BST
		while (true)
		{
			if (data < newNode->parent->value)
			{
				if (newNode->parent->left == this->guard)
				{
					newNode->parent->left = newNode;
					break;
				}
				newNode->parent = newNode->parent->left;
			}
			else
			{
				if (newNode->parent->right == this->guard)
				{
					newNode->parent->right = newNode;
					break;
				}
				newNode->parent = newNode->parent->right;
			}
		}
	}

	// Fix tree structure
	while (newNode != this->root && newNode->parent->color == Color::Red)
	{
		if (newNode->parent == newNode->parent->parent->left)
		{
			helper = newNode->parent->parent->right;

			if (helper->color == Color::Red)
			{
				newNode->parent->color = Color::Black;
				helper->color = Color::Black;
				newNode->parent->parent->color = Color::Red;
				newNode = newNode->parent->parent;
				continue;
			}
			
			if (newNode == newNode->parent->right)
			{
				newNode = newNode->parent;
				this->leftRotation(newNode);
			}

			newNode->parent->color = Color::Black;
			newNode->parent->parent->color = Color::Red;
			this->rightRotation(newNode->parent->parent);
			break;
		}
		else
		{
			helper = newNode->parent->parent->left;

			if (helper->color == Color::Red)
			{
				newNode->parent->color = Color::Black;
				helper->color = Color::Black;
				newNode->parent->parent->color = Color::Red;
				newNode = newNode->parent->parent;
				continue;
			}

			if (newNode == newNode->parent->left)
			{
				newNode = newNode->parent;
				this->rightRotation(newNode);
			}

			newNode->parent->color = Color::Black;
			newNode->parent->parent->color = Color::Red;
			this->leftRotation(newNode->parent->parent);
			break;
		}
	}

	// Change root color to black
	this->root->color = Color::Black;
}

template<typename T>
bool SDIZO::Tree<T>::remove(const T& data)
{
	TreeNode<T>* nodeToRemove = this->findNode(data, this->root);

	// Check if node with wanted key exists
	if (nodeToRemove == nullptr)
	{
		return false;
	}

	TreeNode<T>* helperOne;
	TreeNode<T>* helperTwo;

	if (nodeToRemove->left == this->guard
		|| nodeToRemove->right == this->guard)
	{
		helperOne = nodeToRemove;
	}
	else
	{
		helperOne = this->successor(nodeToRemove);
	}

	if (helperOne->left != this->guard)
	{
		helperTwo = helperOne->left;
	}
	else
	{
		helperTwo = helperOne->right;
	}

	helperTwo->parent = helperOne->parent;

	if (helperOne->parent == this->guard)
	{
		this->root = helperTwo;
	}
	else
	{
		if (helperOne == helperOne->parent->left)
		{
			helperOne->parent->left = helperTwo;
		}
		else
		{
			helperOne->parent->right = helperTwo;
		}
	}

	if (helperOne != nodeToRemove)
	{
		nodeToRemove->value = helperOne->value;
	}

	if (helperOne->color == Color::Black)
	{
		this->deleteFixUp(helperTwo);
	}

	return true;
}

template<typename T>
void SDIZO::Tree<T>::print(std::ostream& out)
{
	if (this->root != this->guard)
	{
		// Calculate tree depth
		size_t depth = 0;
		calculateDepth(this->root, depth, 0);

		// Calculate maximum number of nodes
		size_t size = pow(2, depth);

		// Create table to get access to all nodes
		SDIZO::TreeNode<T>** table = new SDIZO::TreeNode<T>*[size];
		for (size_t i = 0; i < size; i++)
		{
			table[i] = nullptr;
		}

		// Place nodes inside table
		placeNodes(this->root, table, 0);

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
SDIZO::TreeNode<T>* SDIZO::Tree<T>::successor(TreeNode<T>* node)
{
	// Check if right child exists
	if (node->right != this->guard)
	{
		return this->minumum(node->right);
	}

	TreeNode<T>* helper = node->parent;
	while (helper != this->guard && node == helper->right)
	{
		node = helper;
		helper = helper->parent;
	}
	return helper;
}

template<typename T>
SDIZO::TreeNode<T>* SDIZO::Tree<T>::minumum(TreeNode<T>* node)
{
	// Loop while left child exists
	while (node->left != this->guard)
	{
		node = node->right;
	}
	return node;
}

template<typename T>
SDIZO::TreeNode<T>* SDIZO::Tree<T>::findNode(const T& data, TreeNode<T>* node)
{
	// Check if node exists
	if (node == this->guard)
	{
		return nullptr;
	}

	// Check if node store wanted value
	if (data == node->value)
	{
		return node;
	}

	// Look for node in the right branch of tree
	if (data > node->value)
	{
		return findNode(data, node->right);
	}

	// Look for node in the left branch of tree
	return findNode(data, node->left);
}

template<typename T>
void SDIZO::Tree<T>::leftRotation(TreeNode<T>* node)
{
	// Create two temporary pointers
	TreeNode<T>* child;
	TreeNode<T>* parent;

	child = node->right;

	// Check if right child exits
	if (child != this->guard)
	{
		parent = node->parent;
		node->right = child->left;

		// Check if exists left child of right child
		if (node->right != this->guard)
		{
			node->right->parent = node;
		}

		// Swap nodes
		child->left = node;
		child->parent = parent;
		node->parent = child;

		// Check if parent exists
		if (parent != this->guard)
		{
			if (parent->left == node)
			{
				parent->left = child;
				return;
			}
			parent->right = child;
			return;
		}
		this->root = child;
	}
}

template<typename T>
void SDIZO::Tree<T>::rightRotation(TreeNode<T>* node)
{
	// Create two temporary pointers
	TreeNode<T>* child;
	TreeNode<T>* parent;

	child = node->left;

	// Check if left child exits
	if (child != this->guard)
	{
		parent = node->parent;
		node->left = child->right;

		// Check if exists right child of left child
		if (node->left != this->guard)
		{
			node->left->parent = node;
		}

		// Swap nodes
		child->right = node;
		child->parent = parent;
		node->parent = child;

		// Check if parent exists
		if (parent != this->guard)
		{
			if (parent->left == node)
			{
				parent->left = child;
				return;
			}
			parent->right = child;
			return;
		}
		this->root = child;
	}
}

template<typename T>
void SDIZO::Tree<T>::deleteFixUp(TreeNode<T>* node)
{
	TreeNode<T>* helper;

	// Fix tree structure and node colors
	while (node != this->root && node->color == Color::Black)
	{
		if (node == node->parent->left)
		{
			helper = node->parent->right;

			if (helper->color == Color::Red)
			{
				helper->color = Color::Black;
				node->parent->color = Color::Red;
				this->leftRotation(node->parent);
				helper = node->parent->right;
			}

			if (helper->left->color == Color::Black
				&& helper->right->color == Color::Black)
			{
				helper->color = Color::Red;
				node = node->parent;
			}
			else if (helper->right->color == Color::Black)
			{
				helper->left->color = Color::Black;
				helper->color = Color::Red;
				this->rightRotation(helper);
				helper = node->parent->right;
			}
			helper->color = helper->parent->color;
			node->parent->color = Color::Black;
			helper->right->color = Color::Black;
			this->leftRotation(node->parent);
			node = this->root;
		}
		else
		{
			helper = node->parent->left;

			if (helper->color == Color::Red)
			{
				helper->color = Color::Black;
				node->parent->color = Color::Red;
				this->rightRotation(node->parent);
				helper = node->parent->left;
			}

			if (helper->right->color == Color::Black
				&& helper->left->color == Color::Black)
			{
				helper->color = Color::Red;
				node = node->parent;
			}
			else if (helper->left->color == Color::Black)
			{
				helper->right->color = Color::Black;
				helper->color = Color::Red;
				this->leftRotation(helper);
				helper = node->parent->left;
			}
			helper->color = helper->parent->color;
			node->parent->color = Color::Black;
			helper->left->color = Color::Black;
			this->rightRotation(node->parent);
			node = this->root;
		}
	}
	node->color = Color::Black;
}

template<typename T>
void SDIZO::Tree<T>::deleteNodes(TreeNode<T>* node)
{
	// Check if current node is not the guardian
	if (node != this->guard)
	{
		deleteNodes(node->left);
		deleteNodes(node->right);
		delete node;
	}
}

template<typename T>
void SDIZO::Tree<T>::calculateDepth(SDIZO::TreeNode<T>* node, size_t& maxDepth, size_t currentDepth)
{
	// Increase depth
	currentDepth++;

	// Chech if calculated depth is grater than max depth
	if (currentDepth > maxDepth)
	{
		maxDepth = currentDepth;
	}

	// Check if left child is not guardian
	if (node->left != this->guard)
	{
		calculateDepth(node->left, maxDepth, currentDepth);
	}

	// Check if right child is not guardian
	if (node->right != this->guard)
	{
		calculateDepth(node->right, maxDepth, currentDepth);
	}
}

template<typename T>
void SDIZO::Tree<T>::placeNodes(SDIZO::TreeNode<T>* node, SDIZO::TreeNode<T>** table, size_t index)
{
	// Place node in table
	table[index] = node;

	// Check if exists left child
	if (node->left != this->guard)
	{
		placeNodes(node->left, table, 2 * index + 1);
	}

	// Check if exists right child
	if (node->right != this->guard)
	{
		placeNodes(node->right, table, 2 * index + 2);
	}
}

// The only one data type necessary in this project
template class SDIZO::Tree<int>;