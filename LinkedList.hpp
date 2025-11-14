#pragma once
#include <iostream>
using namespace std;

template <typename T>
struct Node
{
	T data;
	Node *prev;
	Node *next;
};

template <typename T>
class LinkedList
{
public:
	void printForward() const
	{
		Node<T> *current = head;
		while (current)
		{
			cout << current->data << " ";
			current = current->next;
		}
		cout << endl;
	}
	
	void printReverse() const
	{
		Node<T> *current = tail;
		while (current)
		{
			cout << current->data << " ";
			current = current->prev;
		}
		cout << endl;
	}

	[[nodiscard]] unsigned int getCount() const { return count; };
	Node<T> *getHead() { return head; };
	const Node<T> *getHead() const { return head; };
	Node<T> *getTail() { return tail; };
	const Node<T> *getTail() const { return tail; };

	void addHead(const T &data)
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
	
	void addTail(const T &data)
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

	bool removeHead()
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
	
	bool removeTail()
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
	
	void clear()
	{
		while (removeHead())
		{
		}
	}

	LinkedList<T> &operator=(LinkedList<T> &&other) noexcept
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
	
	LinkedList<T> &operator=(const LinkedList<T> &rhs)
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

	LinkedList() : head(nullptr), tail(nullptr), count(0) {}
	
	LinkedList(const LinkedList<T> &list)
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
	
	LinkedList(LinkedList<T> &&other) noexcept : head(other.head), tail(other.tail), count(other.count)
	{
		other.head = nullptr;
		other.tail = nullptr;
		other.count = 0;
	}
	
	~LinkedList()
	{
		clear();
	}

private:
	Node<T> *head;
	Node<T> *tail;
	unsigned int count;
};
