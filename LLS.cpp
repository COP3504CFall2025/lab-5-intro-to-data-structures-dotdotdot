#include "LLS.hpp"

template <typename T>
LLS<T>::LLS() {}

template <typename T>
void LLS<T>::push(const T &item)
{
    list.addHead(item);
}

template <typename T>
T LLS<T>::pop()
{
    if (list.getCount() == 0)
    {
        throw std::out_of_range("Stack is empty");
    }
    T value = list.getHead()->data;
    list.removeHead();
    return value;
}

template <typename T>
T LLS<T>::peek() const
{
    if (list.getCount() == 0)
    {
        throw std::out_of_range("Stack is empty");
    }
    return list.getHead()->data;
}

template <typename T>
std::size_t LLS<T>::getSize() const noexcept
{
    return list.getCount();
}

template <typename T>
void LLS<T>::PrintForward()
{
    list.printForward();
}

template <typename T>
void LLS<T>::PrintReverse()
{
    list.printReverse();
}