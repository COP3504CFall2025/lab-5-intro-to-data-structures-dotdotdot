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
    ABDQ() : data_(new T[4]), capacity_(4), size_(0), front_(0), back_(0) {}
    explicit ABDQ(const size_t capacity) : capacity_(capacity), size_(0), front_(0), back_(0)
    {
        data_ = new T[capacity_];
    }
    ABDQ(const ABDQ &other) : data_(new T[other.capacity_]), capacity_(other.capacity_), size_(other.size_), front_(0), back_(other.size_)
    {
        for (std::size_t i = 0; i < size_; ++i)
        {
            data_[i] = other.data_[(other.front_ + i) % other.capacity_];
        }
    }
    ABDQ(ABDQ &&other) noexcept : data_(other.data_), capacity_(other.capacity_), size_(other.size_), front_(other.front_), back_(other.back_)
    {
        other.data_ = nullptr;
        other.capacity_ = 0;
        other.size_ = 0;
        other.front_ = 0;
        other.back_ = 0;
    }
    ABDQ &operator=(const ABDQ &other)
    {
        if (this != &other)
        {
            delete[] data_;
            data_ = new T[other.capacity_];
            capacity_ = other.capacity_;
            size_ = other.size_;
            front_ = 0;
            back_ = other.size_;
            for (std::size_t i = 0; i < size_; ++i)
            {
                data_[i] = other.data_[(other.front_ + i) % other.capacity_];
            }
        }
        return *this;
    }
    ABDQ &operator=(ABDQ &&other) noexcept
    {
        if (this != &other)
        {
            delete[] data_;
            data_ = other.data_;
            capacity_ = other.capacity_;
            size_ = other.size_;
            front_ = other.front_;
            back_ = other.back_;
            other.data_ = nullptr;
            other.capacity_ = 0;
            other.size_ = 0;
            other.front_ = 0;
            other.back_ = 0;
        }
        return *this;
    }
    ~ABDQ()
    {
        delete[] data_;
    }

    void pushFront(const T &item) override
    {
        if (size_ >= capacity_)
        {
            std::size_t new_capacity = capacity_ * SCALE_FACTOR;
            T *new_data = new T[new_capacity];
            for (std::size_t i = 0; i < size_; ++i)
            {
                new_data[i] = data_[(front_ + i) % capacity_];
            }
            delete[] data_;
            data_ = new_data;
            capacity_ = new_capacity;
            front_ = 0;
            back_ = size_;
        }
        front_ = (front_ - 1 + capacity_) % capacity_;
        data_[front_] = item;
        ++size_;
    }
    void pushBack(const T &item) override
    {
        if (size_ >= capacity_)
        {
            std::size_t new_capacity = capacity_ * SCALE_FACTOR;
            T *new_data = new T[new_capacity];
            for (std::size_t i = 0; i < size_; ++i)
            {
                new_data[i] = data_[(front_ + i) % capacity_];
            }
            delete[] data_;
            data_ = new_data;
            capacity_ = new_capacity;
            front_ = 0;
            back_ = size_;
        }
        data_[back_] = item;
        back_ = (back_ + 1) % capacity_;
        ++size_;
    }
    T popFront() override
    {
        if (size_ == 0)
        {
            throw std::runtime_error("");
        }
        T value = data_[front_];
        front_ = (front_ + 1) % capacity_;
        --size_;
        return value;
    }
    T popBack() override
    {
        if (size_ == 0)
        {
            throw std::runtime_error("");
        }
        back_ = (back_ - 1 + capacity_) % capacity_;
        T value = data_[back_];
        --size_;
        return value;
    }
    const T &front() const override
    {
        if (size_ == 0)
        {
            throw std::runtime_error("");
        }
        return data_[front_];
    }
    const T &back() const override
    {
        if (size_ == 0)
        {
            throw std::runtime_error("");
        }
        std::size_t back_index = (back_ - 1 + capacity_) % capacity_;
        return data_[back_index];
    }
    std::size_t getSize() const noexcept override
    {
        return size_;
    }
    
    std::size_t getMaxCapacity() const noexcept
    {
        return capacity_;
    }
    
    void PrintForward()
    {
        for (std::size_t i = 0; i < size_; ++i)
        {
            std::cout << data_[(front_ + i) % capacity_] << " ";
        }
        std::cout << std::endl;
    }
    void PrintReverse()
    {
        for (std::size_t i = size_; i > 0; --i)
        {
            std::cout << data_[(front_ + i - 1) % capacity_] << " ";
        }
        std::cout << std::endl;
    }

private:
    T *data_;
    std::size_t capacity_;
    std::size_t size_;
    std::size_t front_;
    std::size_t back_;

    static constexpr std::size_t SCALE_FACTOR = 2;
};
