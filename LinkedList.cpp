#include "LinkedList.hpp"
#include <iostream>

template <typename T>
void LinkedList<T>::printForward() const
{
	Node<T> *current = head;
	while (current)
	{
		cout << current->data << " ";
		current = current->next;
	}
	cout << endl;
}

template <typename T>
void LinkedList<T>::printReverse() const
{
	Node<T> *current = tail;
	while (current)
	{
		cout << current->data << " ";
		current = current->prev;
	}
	cout << endl;
}

template <typename T>
void LinkedList<T>::addHead(const T &data)
{
	Node<T> *newNode = new Node<T>{data, nullptr, head};
	if (head)
	{
		head->prev = newNode;
	}
	head = newNode;
	if (!tail)
	{
		tail = newNode;
	}
	count++;
}

template <typename T>
void LinkedList<T>::addTail(const T &data)
{
	Node<T> *newNode = new Node<T>{data, tail, nullptr};
	if (tail)
	{
		tail->next = newNode;
	}
	tail = newNode;
	if (!head)
	{
		head = newNode;
	}
	count++;
}

template <typename T>
bool LinkedList<T>::removeHead()
{
	if (!head)
		return false;
	Node<T> *temp = head;
	head = head->next;
	if (head)
	{
		head->prev = nullptr;
	}
	else
	{
		tail = nullptr;
	}
	delete temp;
	count--;
	return true;
}

template <typename T>
bool LinkedList<T>::removeTail()
{
	if (!tail)
		return false;
	Node<T> *temp = tail;
	tail = tail->prev;
	if (tail)
	{
		tail->next = nullptr;
	}
	else
	{
		head = nullptr;
	}
	delete temp;
	count--;
	return true;
}

template <typename T>
void LinkedList<T>::clear()
{
	while (removeHead())
	{
	}
}

template <typename T>
LinkedList<T> &LinkedList<T>::operator=(LinkedList<T> &&other) noexcept
{
	if (this != &other)
	{
		clear();
		head = other.head;
		tail = other.tail;
		count = other.count;
		other.head = nullptr;
		other.tail = nullptr;
		other.count = 0;
	}
	return *this;
}

template <typename T>
LinkedList<T> &LinkedList<T>::operator=(const LinkedList<T> &rhs)
{
	if (this != &rhs)
	{
		clear();
		Node<T> *current = rhs.head;
		while (current)
		{
			addTail(current->data);
			current = current->next;
		}
	}
	return *this;
}

template <typename T>
LinkedList<T>::LinkedList() : head(nullptr), tail(nullptr), count(0) {}

template <typename T>
LinkedList<T>::LinkedList(const LinkedList<T> &list)
{
	head = nullptr;
	tail = nullptr;
	count = 0;
	Node<T> *current = list.head;
	while (current)
	{
		addTail(current->data);
		current = current->next;
	}
}

template <typename T>
LinkedList<T>::LinkedList(LinkedList<T> &&other) noexcept : head(other.head), tail(other.tail), count(other.count)
{
	other.head = nullptr;
	other.tail = nullptr;
	other.count = 0;
}

template <typename T>
LinkedList<T>::~LinkedList()
{
	clear();
}