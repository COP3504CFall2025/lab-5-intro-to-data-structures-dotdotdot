#pragma once

#include <cstddef>
#include <stdexcept>
#include "Interfaces.hpp"
#include "LinkedList.hpp"
#include <utility>

template <typename T>
class LLDQ : public DequeInterface<T> {
public:
    LLDQ();
    void pushFront(const T& item) override;
    void pushBack(const T& item) override;
    T popFront() override;
    T popBack() override;
    const T& front() const override;
    const T& back() const override;
    std::size_t getSize() const noexcept override;
    void PrintForward();
    void PrintReverse();

private:
    LinkedList<T> list;
};





