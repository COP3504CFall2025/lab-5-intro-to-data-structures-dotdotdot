#pragma once

#include <cstddef>
#include <stdexcept>
#include <iostream>
#include "Interfaces.hpp"
#include <utility>

template <typename T>
class ABDQ : public DequeInterface<T>
{
public:
    ABDQ();
    explicit ABDQ(std::size_t capacity);
    ABDQ(const ABDQ &other);
    ABDQ(ABDQ &&other) noexcept;
    ABDQ &operator=(const ABDQ &other);
    ABDQ &operator=(ABDQ &&other) noexcept;
    ~ABDQ();

    void pushFront(const T &item) override;
    void pushBack(const T &item) override;
    T popFront() override;
    T popBack() override;
    const T &front() const override;
    const T &back() const override;
    std::size_t getSize() const noexcept override;
    void PrintForward();
    void PrintReverse();

private:
    T *data_;
    std::size_t capacity_;
    std::size_t size_;
    std::size_t front_;
    std::size_t back_;

    static constexpr std::size_t SCALE_FACTOR = 2;
    void ensureCapacity();
};

#include "ABDQ.cpp"
