#pragma once
#include <iostream>
#include <exception>
#define st size_t

template<class T>
class HeterogeneousContainer {
public:
	HeterogeneousContainer();
	HeterogeneousContainer(int cap);
	HeterogeneousContainer(const HeterogeneousContainer<T>& other);
	HeterogeneousContainer(HeterogeneousContainer&& other) noexcept;

	HeterogeneousContainer<T>& operator=(const HeterogeneousContainer<T>& other);
	HeterogeneousContainer<T>& operator=(HeterogeneousContainer<T>&& other) noexcept;

	void add(T* obj);
	st getSize() const;

	const T* operator[](int ind) const;

	~HeterogeneousContainer() noexcept;

private:
	T** data = nullptr;
	st size = 0;
	st capacity = 8;

	void resize(int newCap);

	void copyFrom(const HeterogeneousContainer<T>& other);
	void moveFrom(HeterogeneousContainer<T>&& other);
	void free();
};

template<class T>
inline void HeterogeneousContainer<T>::resize(int newCap)
{
	T** temp = new T * [newCap];

	for (size_t i = 0; i < size; i++)
	{
		temp[i] = data[i];
	}

	delete[] data;
	data = temp;
	capacity = newCap;
}

template<class T>
inline void HeterogeneousContainer<T>::copyFrom(const HeterogeneousContainer<T>& other)
{
	data = new T * [other.capacity];

	for (size_t i = 0; i < other.size; i++)
	{
		data[i] = other.data[i]->clone();
	}

	size = other.size;
	capacity = other.capacity;
}

template<class T>
inline void HeterogeneousContainer<T>::moveFrom(HeterogeneousContainer<T>&& other)
{
	data = other.data;
	other.data = nullptr;

	size = other.size;
	capacity = other.capacity;

	other.size = other.capacity = 0;
}

template<class T>
inline void HeterogeneousContainer<T>::free()
{
	for (size_t i = 0; i < size; i++)
	{
		delete data[i];
	}

	delete[] data;
}

template<class T>
inline HeterogeneousContainer<T>::HeterogeneousContainer()
{
	data = new T * [capacity] {nullptr};
}

template<class T>
inline HeterogeneousContainer<T>::HeterogeneousContainer(int cap)
{
	capacity = cap;
	data = new T * [capacity] {nullptr};
}

template<class T>
inline HeterogeneousContainer<T>::HeterogeneousContainer(const HeterogeneousContainer<T>& other)
{
	copyFrom(other);
}

template<class T>
inline HeterogeneousContainer<T>::HeterogeneousContainer(HeterogeneousContainer<T>&& other) noexcept
{
	moveFrom(std::move(other));
}

template<class T>
inline HeterogeneousContainer<T>& HeterogeneousContainer<T>::operator=(const HeterogeneousContainer<T>& other)
{
	if (this != &other) {
		free();
		copyFrom(other);
	}

	return *this;
}

template<class T>
inline HeterogeneousContainer<T>& HeterogeneousContainer<T>::operator=(HeterogeneousContainer<T>&& other) noexcept
{
	if (this != &other) {
		free();
		moveFrom(std::move(other));
	}

	return *this;
}

template<class T>
inline void HeterogeneousContainer<T>::add(T* obj)
{
	if (size >= capacity) {
		resize(capacity * 2);
	}

	data[size++] = obj;
}

template<class T>
inline st HeterogeneousContainer<T>::getSize() const
{
	return size;
}

template<class T>
inline const T* HeterogeneousContainer<T>::operator[](int ind) const
{
	if (ind < 0 || ind >= size) {
		throw std::out_of_range("Index out of range!");
	}

	return data[ind];
}

template<class T>
inline HeterogeneousContainer<T>::~HeterogeneousContainer() noexcept
{
	free();
}
