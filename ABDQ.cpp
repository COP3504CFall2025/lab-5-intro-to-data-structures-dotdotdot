#include "ABDQ.hpp"

template <typename T>
ABDQ<T>::ABDQ() : data_(new T[4]), capacity_(4), size_(0), front_(0), back_(0) {}

template <typename T>
ABDQ<T>::ABDQ(std::size_t capacity) : data_(new T[capacity]), capacity_(capacity), size_(0), front_(0), back_(0) {}

template <typename T>
ABDQ<T>::ABDQ(const ABDQ &other) : data_(new T[other.capacity_]), capacity_(other.capacity_), size_(other.size_), front_(0), back_(other.size_)
{
    for (std::size_t i = 0; i < size_; ++i)
    {
        data_[i] = other.data_[(other.front_ + i) % other.capacity_];
    }
}

template <typename T>
ABDQ<T>::ABDQ(ABDQ &&other) noexcept : data_(other.data_), capacity_(other.capacity_), size_(other.size_), front_(other.front_), back_(other.back_)
{
    other.data_ = nullptr;
    other.capacity_ = 0;
    other.size_ = 0;
    other.front_ = 0;
    other.back_ = 0;
}

template <typename T>
ABDQ<T> &ABDQ<T>::operator=(const ABDQ &other)
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

template <typename T>
ABDQ<T> &ABDQ<T>::operator=(ABDQ &&other) noexcept
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

template <typename T>
ABDQ<T>::~ABDQ()
{
    delete[] data_;
}

template <typename T>
void ABDQ<T>::ensureCapacity()
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
}

template <typename T>
void ABDQ<T>::pushFront(const T &item)
{
    ensureCapacity();
    front_ = (front_ - 1 + capacity_) % capacity_;
    data_[front_] = item;
    ++size_;
}

template <typename T>
void ABDQ<T>::pushBack(const T &item)
{
    ensureCapacity();
    data_[back_] = item;
    back_ = (back_ + 1) % capacity_;
    ++size_;
}

template <typename T>
T ABDQ<T>::popFront()
{
    if (size_ == 0)
    {
        throw std::out_of_range("Deque is empty");
    }
    T value = data_[front_];
    front_ = (front_ + 1) % capacity_;
    --size_;
    return value;
}

template <typename T>
T ABDQ<T>::popBack()
{
    if (size_ == 0)
    {
        throw std::out_of_range("Deque is empty");
    }
    back_ = (back_ - 1 + capacity_) % capacity_;
    T value = data_[back_];
    --size_;
    return value;
}

template <typename T>
const T &ABDQ<T>::front() const
{
    if (size_ == 0)
    {
        throw std::out_of_range("Deque is empty");
    }
    return data_[front_];
}

template <typename T>
const T &ABDQ<T>::back() const
{
    if (size_ == 0)
    {
        throw std::out_of_range("Deque is empty");
    }
    std::size_t back_index = (back_ - 1 + capacity_) % capacity_;
    return data_[back_index];
}

template <typename T>
std::size_t ABDQ<T>::getSize() const noexcept
{
    return size_;
}

template <typename T>
void ABDQ<T>::PrintForward()
{
    for (std::size_t i = 0; i < size_; ++i)
    {
        std::cout << data_[(front_ + i) % capacity_] << " ";
    }
    std::cout << std::endl;
}

template <typename T>
void ABDQ<T>::PrintReverse()
{
    for (std::size_t i = size_; i > 0; --i)
    {
        std::cout << data_[(front_ + i - 1) % capacity_] << " ";
    }
    std::cout << std::endl;
}