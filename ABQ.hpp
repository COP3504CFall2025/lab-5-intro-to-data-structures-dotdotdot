#pragma once

#include <cstddef>
#include <stdexcept>
#include <iostream>
#include "Interfaces.hpp"

using std::size_t;

template<typename T>
class ABQ : public QueueInterface<T>{
public:
    ABQ();
    explicit ABQ(const size_t capacity);
    ABQ(const ABQ& other);
    ABQ& operator=(const ABQ& rhs);
    ABQ(ABQ&& other) noexcept;
    ABQ& operator=(ABQ&& rhs) noexcept;
    ~ABQ();

    [[nodiscard]] size_t getSize() const noexcept override;
    void enqueue(const T& data) override;
    T peek() const override;
    T dequeue() override;
    void PrintForward();
    void PrintReverse();

private:
    size_t capacity_;
    size_t curr_size_;
    T *array_;
    static constexpr size_t scale_factor_ = 2;
};

#include "ABQ.cpp"
