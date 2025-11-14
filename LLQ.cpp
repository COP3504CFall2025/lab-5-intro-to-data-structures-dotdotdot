#include "LLQ.hpp"
#include <stdexcept>

template <typename T>
LLQ<T>::LLQ() {}

template <typename T>
void LLQ<T>::enqueue(const T &item)
{
    list.addTail(item);
}

template <typename T>
T LLQ<T>::dequeue()
{
    if (list.getCount() == 0)
    {
        throw std::runtime_error("Queue is empty");
    }
    T value = list.getHead()->data;
    list.removeHead();
    return value;
}

template <typename T>
T LLQ<T>::peek() const
{
    if (list.getCount() == 0)
    {
        throw std::runtime_error("Queue is empty");
    }
    return list.getHead()->data;
}

template <typename T>
std::size_t LLQ<T>::getSize() const noexcept
{
    return list.getCount();
}

template <typename T>
void LLQ<T>::PrintForward()
{
    list.printForward();
}

template <typename T>
void LLQ<T>::PrintReverse()
{
    list.printReverse();
}