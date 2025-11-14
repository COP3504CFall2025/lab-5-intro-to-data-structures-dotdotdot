#pragma once

#include "Interfaces.hpp"
#include "LinkedList.hpp"
#include <stdlib.h>
#include <stdexcept>

template <typename T>
class LLQ : public QueueInterface<T> {
public:
    LLQ() {}
    
    void enqueue(const T& item) override
    {
        list.addTail(item);
    }
    
    T dequeue() override
    {
        if (list.getCount() == 0)
        {
            throw std::runtime_error("");
        }
        T value = list.getHead()->data;
        list.removeHead();
        return value;
    }
    
    T peek() const override
    {
        if (list.getCount() == 0)
        {
            throw std::runtime_error("");
        }
        return list.getHead()->data;
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

private:
    LinkedList<T> list;
};
