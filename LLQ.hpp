#pragma once

#include "Interfaces.hpp"
#include "LinkedList.hpp"
#include <stdlib.h>
#include <stdexcept>

template <typename T>
class LLQ : public QueueInterface<T> {
private:
    LinkedList<T> list;
public:
    LLQ() {}

    void enqueue(const T& item) override {
        list.addTail(item);
    }

    T dequeue() override {
        if (list.getCount() == 0) {
            throw std::out_of_range("Queue is empty");
        }
        T value = list.getHead()->data;
        list.removeHead();
        return value;
    }

    T peek() const override {
        if (list.getCount() == 0) {
            throw std::out_of_range("Queue is empty");
        }
        return list.getHead()->data;
    }

    std::size_t getSize() const noexcept override {
        return list.getCount();
    }

    void PrintForward() {
        list.printForward();
    }

    void PrintReverse() {
        list.printReverse();
    }
};