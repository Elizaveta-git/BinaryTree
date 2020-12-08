#pragma once
#include <iostream>
#include "../BinaryTree/Iterator.h"
#include "../BinaryTree/Stack.h"
#include "../BinaryTree/Queue.h"
class BinaryTree
{
	private:
		class NodeTree
		{
		public:
			int value;//element value
			NodeTree* left;//pointer to the left element in the list
			NodeTree* right;//pointer to the right element in the list
			NodeTree(int val)//creating element
			{
				left = NULL;
				right = NULL;
				value = val;
			}
		};
		NodeTree* root;//pointer to the root of the list
		void PrintTree(NodeTree*);
		void DeleteTree(NodeTree*);

	public:
		BinaryTree(int);
		~BinaryTree();
		bool contains(int);//search for an element in the tree by key
		void print();//print a tree
		void insert(int);//adding an element to the tree by key.
		void remove(int);// deleting a tree element by key

		Iterator* create_dft_iterator();// create an iterator that implements direct depth-first traversal
		Iterator* create_bft_iterator();// create an iterator that implements breadth-first traversal method

		class bft_iterator: public Iterator
		{
		public:
			bft_iterator(NodeTree* start)
			{
				current = start;
				queue.push(current);
			}
			~bft_iterator()
			{
				delete current;
			};
			bool has_next() override;
			int next() override;

		private:
			NodeTree* current;
			Queue <NodeTree*> queue;
		};

		class dft_iterator : public Iterator
		{
		public:
			dft_iterator(NodeTree* start)
			{
				current = start;
				stack.push(current);
			}
			~dft_iterator()
			{
				delete current;
			};
			bool has_next() override;
			int next() override;

		private:
			Stack <NodeTree*> stack;
			NodeTree* current;
		};

	
};





