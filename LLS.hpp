#pragma once

#include "Interfaces.hpp"
#include "LinkedList.hpp"
#include <stdlib.h>
#include <stdexcept>

template <typename T>
class LLS : public StackInterface<T> {
public:
    LLS() {}
    
    void push(const T& item) override {
        list.addHead(item);
    }
    
    T pop() override {
        if (list.getCount() == 0) {
            throw std::runtime_error("");
        }
        T value = list.getHead()->data;
        list.removeHead();
        return value;
    }
    
    T peek() const override {
        if (list.getCount() == 0) {
            throw std::runtime_error("");
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

private:
    LinkedList<T> list;
};