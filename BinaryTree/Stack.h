#pragma once
#include <iostream>

using namespace std;

template <class type>
class Stack 
{
private:
	class Node
	{
	public:
		Node* next;//pointer to the next element in the list
		type data;//element value

		Node(type data = type(), Node* next = NULL)//creating element
		{
			this->data = data;
			this->next = next;
		}
	};
	Node* head;//pointer to the head of the list

public:
	Stack()
	{
		head = NULL;//zeroing head element
	}
	~Stack()
	{

	}
	void push(type data)
	{
		head = new Node(data, head);//element creation
	}
	bool isEmpty()
	{
		if (head == NULL) return true;
		else return false;
	}
	type pop()
	{
		Node* current = head;//remember the first element
		head = head->next;//make the second element first
		type cur = current->data;
		delete current;//delete first element
		return cur;
	}
	type top()
	{
		return head->data;
	}
};
