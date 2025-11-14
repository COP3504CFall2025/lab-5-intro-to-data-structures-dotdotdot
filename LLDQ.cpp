#include "LLDQ.hpp"

template <typename T>
LLDQ<T>::LLDQ() {}

template <typename T>
void LLDQ<T>::pushFront(const T &item)
{
    list.addHead(item);
}

template <typename T>
void LLDQ<T>::pushBack(const T &item)
{
    list.addTail(item);
}

template <typename T>
T LLDQ<T>::popFront()
{
    if (list.getCount() == 0)
    {
        throw std::out_of_range("Deque is empty");
    }
    T value = list.getHead()->data;
    list.removeHead();
    return value;
}

template <typename T>
T LLDQ<T>::popBack()
{
    if (list.getCount() == 0)
    {
        throw std::out_of_range("Deque is empty");
    }
    T value = list.getTail()->data;
    list.removeTail();
    return value;
}

template <typename T>
const T &LLDQ<T>::front() const
{
    if (list.getCount() == 0)
    {
        throw std::out_of_range("Deque is empty");
    }
    return list.getHead()->data;
}

template <typename T>
const T &LLDQ<T>::back() const
{
    if (list.getCount() == 0)
    {
        throw std::out_of_range("Deque is empty");
    }
    return list.getTail()->data;
}

template <typename T>
std::size_t LLDQ<T>::getSize() const noexcept
{
    return list.getCount();
}

template <typename T>
void LLDQ<T>::PrintForward()
{
    list.printForward();
}

template <typename T>
void LLDQ<T>::PrintReverse()
{
    list.printReverse();
}