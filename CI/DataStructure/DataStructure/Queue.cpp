#include "stdafx.h"
#include "Queue.h"
#include <iostream>

template <class T>
Queue<T>::Queue()
{
	_head = _tail = NULL;
}

template <class T>
Queue<T>::~Queue()
{
	Node *curr, *temp;
	curr = _head;
	while (curr)
	{
		temp = curr;
		delete temp;
		curr = curr->next;
	}
}

template <class T>
void Queue<T>::Enqueue(T elem)
{
	Node* newNode = new Node;
	newNode ->next = NULL;
	newNode->item = elem;

	if(!_head)
	{
		_head = newNode;
		_tail = _head;
	}
	else
	{
		
		_tail->next = newNode;
		_tail = newNode;
	}
}

template <class T>
bool Queue<T>::IsEmpty()
{
	if(!_head)
		return true;
	else
		return false;
}



template <class T>
T Queue<T>::Dequeue()
{
	if(IsEmpty())
		return NULL;
	Node * curr = _head;
	T elem = curr->item;
	_head = curr->next;

	delete curr;
	return elem;
}

template <class T>
void Queue<T>::Display()
{
	if(IsEmpty())
	{
		std::cout<<"Queue is empty"<<"\n";
		return;
	}
		

    Node *curr = _head;
	while (curr)
	{
		std::cout<<curr->item<<"  ";
		curr= curr->next;
	}
}

template <class T>
Queue<T>::Queue(const Queue &rhs) : _head(rhs._head),_tail(rhs._tail)
{
	Node *p = rhs._head;
	Node *pre = p;
	while (p)
	{
		Node *newNode = new Node;
		pre->next = newNode;
		newNode->item = p->item;
		newNode->next = NULL;
		pre = newNode;
		p=p->next;
	}

}