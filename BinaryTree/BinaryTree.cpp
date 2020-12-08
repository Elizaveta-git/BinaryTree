#include "BinaryTree.h"
#include "Iterator.h"
#include <iostream>

using namespace std;

BinaryTree::BinaryTree(int key)//constructor
{
	root = new NodeTree(key);
}

BinaryTree::~BinaryTree()//destructor
{
	DeleteTree(root);
}

void BinaryTree::DeleteTree(NodeTree* current)
{
	if (current)
	{
		DeleteTree(current->left);
		DeleteTree(current->right);
		delete current;
	}
}

bool BinaryTree::contains(int key)
{
		NodeTree* current = root;
		while (current && current->value != key)//until the desired element is found
		{
			if (current->value > key)//if the root element is larger than the required one, then move to the left
			{
				current = current->left;
			}
			else//if the root element is less than necessary, then move to the right
			{
				current = current->right;
			}
		}
		return current != NULL;
}

void BinaryTree::insert(int key)
{
	if (root == NULL)
	{
		root = new NodeTree(key);
	}
	else
	{
		NodeTree* curr = root;
		while (curr && curr->value != key)//until the desired element is found
		{
			if (curr->value > key && curr->left == NULL)//if the root element is larger than the desired one and there is no left subtree, then add the element to the left
			{
				curr->left = new NodeTree(key);
				return;
			}
			if (curr->value < key && curr->right == NULL)//if the root element is less than the required oneand there is no right subtree, then add the element to the right
			{
				curr->right = new NodeTree(key);
				return;
			}
			if (curr->value > key)//if the root element is larger than the required one, then move to the left
			{
				curr = curr->left;
			}
			else//if the root element is less than the required one, then move to the right
			{
				curr = curr->right;
			}
		}
	}
}

void BinaryTree::remove(int key)
{
	NodeTree* curr = root;
	NodeTree* parent = NULL;
	while (curr && curr->value != key)//until the desired element is found
	{
		parent = curr;
		if (curr->value > key)//if the root element is larger than the required one, then move to the left
		{
			curr = curr->left;
		}
		else//if the root element is less than the required one, then move to the right
		{
			curr = curr->right;
		}
	}
	if (!curr)
		return;
	if (curr->left == NULL)//if there is no left subtree then instead of curr, its right subtree is suspended
	{
		if (parent && parent->left == curr)
			parent->left = curr->right;
		if (parent && parent->right == curr)
			parent->right = curr->right;
		delete curr;
		return;
	}
	if (curr->right == NULL)//if there is no left subtree then instead of curr, its left subtree is suspended
	{
		if (parent && parent->left == curr)
			parent->left = curr->left;
		if (parent && parent->right == curr)
			parent->right = curr->left;
		delete curr;
		return;
	}
	if (curr->left == NULL && curr->right == NULL)
	{
		delete curr;
	}
	//if an element has two children, then replace the element with the smallest element from its right subtree
	NodeTree* replace = curr->right;
	while (replace->left)
		replace = replace->left;
	int replace_value = replace->value;
	remove(replace_value);
	curr->value = replace_value;
}

void BinaryTree::print()
{
	PrintTree(root);
	cout << endl;
}

void BinaryTree::PrintTree(NodeTree* curr)
{
	if (curr) // Checking for a non-null pointer
	{
		PrintTree(curr->left);
		cout << curr->value << " ";
		PrintTree(curr->right);
	}
}

Iterator* BinaryTree::create_dft_iterator()
{
	return new dft_iterator(root);
}
bool BinaryTree::dft_iterator::has_next()
{
	return (!stack.isEmpty());
}
int BinaryTree::dft_iterator::next()
{
	if (!has_next()) throw std::out_of_range("has next is false");
	current = stack.pop();
	if (current->right != NULL)
	{
		stack.push(current->right);

	}
	if (current->left != NULL)
	{
		stack.push(current->left);
	}
	return current->value;
}

Iterator* BinaryTree::create_bft_iterator()
{
	return new bft_iterator(root);
}
bool BinaryTree::bft_iterator::has_next()
{
	return (!queue.isEmpty());
}
int BinaryTree::bft_iterator::next()
{
	if (!has_next()) throw std::out_of_range("has next is false");
	current = queue.pop();
	if (current->left != NULL)
	{
		queue.push(current->left);

	}
	if (current->right != NULL)
	{
		queue.push(current->right);
	}
	return current->value;
}

