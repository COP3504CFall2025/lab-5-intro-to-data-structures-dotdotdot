#pragma once

#include <cstddef>
#include <stdexcept>
#include "Interfaces.hpp"
#include "LinkedList.hpp"
#include <utility>

template <typename T>
class LLDQ : public DequeInterface<T>
{
private:
    LinkedList<T> list;

public:
    LLDQ() {}

    void pushFront(const T &item) override
    {
        list.addHead(item);
    }

    void pushBack(const T &item) override
    {
        list.addTail(item);
    }

    T popFront() override
    {
        if (list.getCount() == 0)
        {
            throw std::out_of_range("Deque is empty");
        }
        T value = list.getHead()->data;
        list.removeHead();
        return value;
    }

    T popBack() override
    {
        if (list.getCount() == 0)
        {
            throw std::out_of_range("Deque is empty");
        }
        T value = list.getTail()->data;
        list.removeTail();
        return value;
    }

    const T &front() const override
    {
        if (list.getCount() == 0)
        {
            throw std::out_of_range("Deque is empty");
        }
        return list.getHead()->data;
    }

    const T &back() const override
    {
        if (list.getCount() == 0)
        {
            throw std::out_of_range("Deque is empty");
        }
        return list.getTail()->data;
    }

    std::size_t getSize() const noexcept override
    {
        return list.getCount();
    }

    void PrintForward()
    {
        list.printForward();
    }

    void PrintReverse()
    {
        list.printReverse();
    }
};
