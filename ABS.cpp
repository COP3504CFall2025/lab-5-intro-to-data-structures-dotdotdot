#include "ABS.hpp"
#include <stdexcept>

template <typename T>
ABS<T>::ABS() : capacity_(1), curr_size_(0), array_(new T[1]) {}

template <typename T>
ABS<T>::ABS(const size_t capacity) : capacity_(capacity), curr_size_(0)
{
    array_ = new T[capacity_];
}

template <typename T>
ABS<T>::ABS(const ABS &other) : capacity_(other.capacity_), curr_size_(other.curr_size_)
{
    array_ = new T[capacity_];
    for (size_t i = 0; i < curr_size_; ++i)
    {
        array_[i] = other.array_[i];
    }
}

template <typename T>
ABS<T> &ABS<T>::operator=(const ABS &rhs)
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
ABS<T>::ABS(ABS &&other) noexcept : capacity_(other.capacity_), curr_size_(other.curr_size_), array_(other.array_)
{
    other.capacity_ = 0;
    other.curr_size_ = 0;
    other.array_ = nullptr;
}

template <typename T>
ABS<T> &ABS<T>::operator=(ABS &&rhs) noexcept
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
ABS<T>::~ABS()
{
    delete[] array_;
}

template <typename T>
size_t ABS<T>::getSize() const noexcept
{
    return curr_size_;
}

template <typename T>
void ABS<T>::push(const T &data)
{
    if (curr_size_ >= capacity_)
    {
        size_t new_capacity = (capacity_ == 0) ? 1 : capacity_ * scale_factor_;
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
T ABS<T>::peek() const
{
    if (curr_size_ == 0)
    {
        throw std::runtime_error("Stack is empty");
    }
    return array_[curr_size_ - 1];
}

template <typename T>
T ABS<T>::pop()
{
    if (curr_size_ == 0)
    {
        throw std::runtime_error("Stack is empty");
    }
    T value = array_[curr_size_ - 1];
    --curr_size_;
    return value;
}

template <typename T>
void ABS<T>::PrintForward()
{
    for (size_t i = 0; i < curr_size_; ++i)
    {
        std::cout << array_[i] << " ";
    }
    std::cout << std::endl;
}

template <typename T>
void ABS<T>::PrintReverse()
{
    for (size_t i = curr_size_; i > 0; --i)
    {
        std::cout << array_[i - 1] << " ";
    }
    std::cout << std::endl;
}