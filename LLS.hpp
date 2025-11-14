#pragma once

#include "Interfaces.hpp"
#include "LinkedList.hpp"
#include <stdlib.h>
#include <stdexcept>

template <typename T>
class LLS : public StackInterface<T> {
public:
    LLS();
    void push(const T& item) override;
    T pop() override;
    T peek() const override;
    std::size_t getSize() const noexcept override;
    void PrintForward();
    void PrintReverse();

private:
    LinkedList<T> list;
};

#include "LLS.cpp"