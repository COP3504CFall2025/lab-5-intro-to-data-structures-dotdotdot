#pragma once
#include <iostream>
using namespace std;

template <typename T>
class LinkedList
{
public:
	// Behaviors
	void printForward() const;
	void printReverse() const;

	// Accessors
	[[nodiscard]] unsigned int getCount() const { return count; };
	Node<T> *getHead() { return head; };
	const Node<T> *getHead() const { return head; };
	Node<T> *getTail() { return tail; };
	const Node<T> *getTail() const { return tail; };

	// Insertion
	void addHead(const T &data);
	void addTail(const T &data);

	// Removal
	bool removeHead();
	bool removeTail();
	void Clear();

	// Operators
	LinkedList<T> &operator=(LinkedList<T> &&other) noexcept;
	LinkedList<T> &operator=(const LinkedList<T> &rhs);

	// Construction/Destruction
	LinkedList();
	LinkedList(const LinkedList<T> &list);
	LinkedList(LinkedList<T> &&other) noexcept;
	~LinkedList();

private:
	// Stores pointers to first and last nodes and count
	Node *head;
	Node *tail;
	unsigned int count;
};
