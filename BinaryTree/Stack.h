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
	size_t Size;

public:
	Stack()
	{
		Size = 0;
		head = NULL;//zeroing head element
	}
	~Stack()
	{
		while (Size)
		{
			pop_front();
		}
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
	size_t get_size()//getting list size
	{
		if (isEmpty() == 1)
		{
			throw out_of_range("The list is empty");
		}
		else return Size;
	}
	void pop_front()//remove an element from the beginning of the list
	{
		if (isEmpty() == 1)
		{
			throw out_of_range("The list is empty");
		}
		else
		{
			Node* current = head;//remember the first element
			head = head->Next;//make the second element first
			delete current;//delete first element
			Size--;//reduce list size
		}
	}
};
