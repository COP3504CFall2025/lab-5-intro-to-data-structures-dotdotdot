#pragma once

#include "Interfaces.hpp"
#include "LinkedList.hpp"
#include <stdlib.h>
#include <stdexcept>

template <typename T>
class LLQ : public QueueInterface<T> {
public:
    LLQ();
    void enqueue(const T& item) override;
    T dequeue() override;
    T peek() const override;
    std::size_t getSize() const noexcept override;
    void PrintForward();
    void PrintReverse();

private:
    LinkedList<T> list;
};

#include "LLQ.cpp"