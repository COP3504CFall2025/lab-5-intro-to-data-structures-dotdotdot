#pragma once

#include <cstddef>
#include <stdexcept>
#include <iostream>
#include "Interfaces.hpp"

using std::size_t;

template <typename T>
class ABQ : public QueueInterface<T>
{
public:
    ABQ() : capacity_(1), curr_size_(0), array_(new T[1]) {}
    
    explicit ABQ(const size_t capacity) : capacity_(capacity), curr_size_(0) {
        array_ = new T[capacity_];
    }
    
    ABQ(const ABQ& other) : capacity_(other.capacity_), curr_size_(other.curr_size_) {
        array_ = new T[capacity_];
        for (size_t i = 0; i < curr_size_; ++i) {
            array_[i] = other.array_[i];
        }
    }
    
    ABQ& operator=(const ABQ& rhs) {
        if (this != &rhs) {
            delete[] array_;
            capacity_ = rhs.capacity_;
            curr_size_ = rhs.curr_size_;
            array_ = new T[capacity_];
            for (size_t i = 0; i < curr_size_; ++i) {
                array_[i] = rhs.array_[i];
            }
        }
        return *this;
    }
    
    ABQ(ABQ&& other) noexcept : capacity_(other.capacity_), curr_size_(other.curr_size_), array_(other.array_) {
        other.capacity_ = 0;
        other.curr_size_ = 0;
        other.array_ = nullptr;
    }
    
    ABQ& operator=(ABQ&& rhs) noexcept {
        if (this != &rhs) {
            delete[] array_;
            capacity_ = rhs.capacity_;
            curr_size_ = rhs.curr_size_;
            array_ = rhs.array_;
            rhs.capacity_ = 0;
            rhs.curr_size_ = 0;
            rhs.array_ = nullptr;
        }
        return *this;
    }
    
    ~ABQ() {
        delete[] array_;
    }

    [[nodiscard]] size_t getSize() const noexcept override {
        return curr_size_;
    }
    
    void enqueue(const T& data) override {
        if (curr_size_ >= capacity_) {
            size_t new_capacity = capacity_ * scale_factor_;
            T* new_array = new T[new_capacity];
            for (size_t i = 0; i < curr_size_; ++i) {
                new_array[i] = array_[i];
            }
            delete[] array_;
            array_ = new_array;
            capacity_ = new_capacity;
        }
        array_[curr_size_] = data;
        ++curr_size_;
    }
    
    T peek() const override {
        if (curr_size_ == 0) {
            throw std::runtime_error("");
        }
        return array_[0];
    }
    
    T dequeue() override {
        if (curr_size_ == 0) {
            throw std::runtime_error("");
        }
        T value = array_[0];
        for (size_t i = 1; i < curr_size_; ++i) {
            array_[i - 1] = array_[i];
        }
        --curr_size_;
        return value;
    }
    
    void PrintForward() {
        for (size_t i = 0; i < curr_size_; ++i) {
            std::cout << array_[i] << " ";
        }
        std::cout << std::endl;
    }
    
    void PrintReverse() {
        for (size_t i = curr_size_; i > 0; --i) {
            std::cout << array_[i - 1] << " ";
        }
        std::cout << std::endl;
    }

private:
    size_t capacity_;
    size_t curr_size_;
    T *array_;
    static constexpr size_t scale_factor_ = 2;
};
