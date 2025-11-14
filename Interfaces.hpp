#pragma once

#include <cstddef>
#include <stdexcept>

template <typename T>
class StackInterface
{
    virtual void push(const T &item) = 0;
    virtual T pop() = 0;
    virtual T peek() const = 0;
    virtual std::size_t getSize() const noexcept = 0;

    virtual StackInterface<T>(const StackInterface<T> &other) = 0;
    virtual StackInterface<T>(StackInterface<T> &&other) noexcept = 0;
    virtual StackInterface<T> &operator=(const StackInterface<T> &other) = 0;
    virtual StackInterface<T> &operator=(StackInterface<T> &&other) noexcept = 0;
    virtual ~StackInterface() = 0;
};

template <typename T>
class QueueInterface
{
    virtual void enqueue(const T &item) = 0;
    virtual T dequeue() = 0;
    virtual T peek() const = 0;
    virtual std::size_t getSize() const noexcept = 0;
};

template <typename T>
class DequeInterface
{
    virtual void pushFront(const T &item) = 0;
    virtual void pushBack(const T &item) = 0;
    virtual T popFront() = 0;
    virtual T popBack() = 0;
    virtual const T &front() const = 0;
    virtual const T &back() const = 0;
    virtual std::size_t getSize() const noexcept = 0;
};
