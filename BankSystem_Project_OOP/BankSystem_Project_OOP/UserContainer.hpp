#pragma once
#include <iostream>
#include <exception>
#include <utility> // for std::exchange
#include "User.h"
#define st size_t

class UserContainer {
public:
    UserContainer();
    explicit UserContainer(int cap);
    UserContainer(const UserContainer& other);
    UserContainer(UserContainer&& other) noexcept;

    UserContainer& operator=(const UserContainer& other);
    UserContainer& operator=(UserContainer&& other) noexcept;

    void add(User* user);
    st getSize() const;

    const User* operator[](int ind) const;
    User* operator[](int ind);

    ~UserContainer() noexcept;

private:
    User** data = nullptr;
    st size = 0;
    st capacity = 8;

    void resize(st newCap);

    void copyFrom(const UserContainer& other);
    void moveFrom(UserContainer&& other);
    void free();
};

inline void UserContainer::resize(st newCap)
{
    User** temp = new User * [newCap] {nullptr};

    for (st i = 0; i < size; i++)
    {
        temp[i] = data[i];
    }

    delete[] data;
    data = temp;
    capacity = newCap;
}

inline void UserContainer::copyFrom(const UserContainer& other)
{
    data = new User * [other.capacity] {nullptr};

    for (st i = 0; i < other.size; i++)
    {
        data[i] = other.data[i]->clone();
    }

    size = other.size;
    capacity = other.capacity;
}

inline void UserContainer::moveFrom(UserContainer&& other)
{
    data = std::exchange(other.data, nullptr);
    size = std::exchange(other.size, 0);
    capacity = std::exchange(other.capacity, 0);
}

inline void UserContainer::free()
{
    for (st i = 0; i < size; i++)
    {
        delete data[i];
    }

    delete[] data;
}

inline UserContainer::UserContainer()
{
    data = new User * [capacity] {nullptr};
}

inline UserContainer::UserContainer(int cap)
    : capacity(cap)
{
    data = new User * [capacity] {nullptr};
}

inline UserContainer::UserContainer(const UserContainer& other)
{
    copyFrom(other);
}

inline UserContainer::UserContainer(UserContainer&& other) noexcept
{
    moveFrom(std::move(other));
}

inline UserContainer& UserContainer::operator=(const UserContainer& other)
{
    if (this != &other) {
        free();
        copyFrom(other);
    }

    return *this;
}

inline UserContainer& UserContainer::operator=(UserContainer&& other) noexcept
{
    if (this != &other) {
        free();
        moveFrom(std::move(other));
    }

    return *this;
}

inline void UserContainer::add(User* user)
{
    if (size >= capacity) {
        resize(capacity * 2);
    }

    data[size++] = user;
}

inline st UserContainer::getSize() const
{
    return size;
}

inline const User* UserContainer::operator[](int ind) const
{
    if (ind < 0 || ind >= size) {
        throw std::out_of_range("Index out of range!");
    }

    return data[ind];
}

inline User* UserContainer::operator[](int ind)
{
    if (ind < 0 || ind >= size) {
        throw std::out_of_range("Index out of range!");
    }

    return data[ind];
}

inline UserContainer::~UserContainer() noexcept
{
    free();
}
