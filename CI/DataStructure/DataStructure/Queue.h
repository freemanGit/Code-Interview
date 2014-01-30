#pragma once

template <class T>
class Queue
{
public:
	Queue();
	Queue(const Queue &rhs);
	~Queue();

	T Dequeue();
	void Enqueue(T item);
	bool IsEmpty();
	void Display();

private:
	struct Node
	{
		T item;
		Node* next;
	};

	Node* _head;
	Node* _tail;

};