#pragma once
#include "ABQ.hpp"

template <typename T>
ABQ<T>::ABQ() : capacity_(1), curr_size_(0), array_(new T[1]) {}

template <typename T>
ABQ<T>::ABQ(const size_t capacity) : capacity_(capacity), curr_size_(0)
{
    array_ = new T[capacity_];
}

template <typename T>
ABQ<T>::ABQ(const ABQ &other) : capacity_(other.capacity_), curr_size_(other.curr_size_)
{
    array_ = new T[capacity_];
    for (size_t i = 0; i < curr_size_; ++i)
    {
        array_[i] = other.array_[i];
    }
}

template <typename T>
ABQ<T> &ABQ<T>::operator=(const ABQ &rhs)
{
    if (this != &rhs)
    {
        delete[] array_;
        capacity_ = rhs.capacity_;
        curr_size_ = rhs.curr_size_;
        array_ = new T[capacity_];
        for (size_t i = 0; i < curr_size_; ++i)
        {
            array_[i] = rhs.array_[i];
        }
    }
    return *this;
}

template <typename T>
ABQ<T>::ABQ(ABQ &&other) noexcept : capacity_(other.capacity_), curr_size_(other.curr_size_), array_(other.array_)
{
    other.capacity_ = 0;
    other.curr_size_ = 0;
    other.array_ = nullptr;
}

template <typename T>
ABQ<T> &ABQ<T>::operator=(ABQ &&rhs) noexcept
{
    if (this != &rhs)
    {
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

template <typename T>
ABQ<T>::~ABQ()
{
    delete[] array_;
}

template <typename T>
size_t ABQ<T>::getSize() const noexcept
{
    return curr_size_;
}

template <typename T>
void ABQ<T>::enqueue(const T &data)
{
    if (curr_size_ >= capacity_)
    {
        size_t new_capacity = capacity_ * scale_factor_;
        T *new_array = new T[new_capacity];
        for (size_t i = 0; i < curr_size_; ++i)
        {
            new_array[i] = array_[i];
        }
        delete[] array_;
        array_ = new_array;
        capacity_ = new_capacity;
    }
    array_[curr_size_] = data;
    ++curr_size_;
}

template <typename T>
T ABQ<T>::peek() const
{
    if (curr_size_ == 0)
    {
        throw std::out_of_range("Queue is empty");
    }
    return array_[0];
}

template <typename T>
T ABQ<T>::dequeue()
{
    if (curr_size_ == 0)
    {
        throw std::out_of_range("Queue is empty");
    }
    T value = array_[0];
    for (size_t i = 1; i < curr_size_; ++i)
    {
        array_[i - 1] = array_[i];
    }
    --curr_size_;
    return value;
}

template <typename T>
void ABQ<T>::PrintForward()
{
    for (size_t i = 0; i < curr_size_; ++i)
    {
        std::cout << array_[i] << " ";
    }
    std::cout << std::endl;
}

template <typename T>
void ABQ<T>::PrintReverse()
{
    for (size_t i = curr_size_; i > 0; --i)
    {
        std::cout << array_[i - 1] << " ";
    }
    std::cout << std::endl;
}