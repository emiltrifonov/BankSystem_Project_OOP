#pragma once
#include <iostream>
#include <exception>
#define st size_t

// Dynamic array of pointers (because a normal vector  requires
// default constructor which makes no sense for many of the classes)
template<class T>
class Collection {
public:
	Collection();
	Collection(st cap);
	Collection(const Collection<T>& other);
	Collection(Collection<T>&& other) noexcept;

	Collection<T>& operator=(const Collection<T>& other);
	Collection<T>& operator=(Collection<T>&& other) noexcept;

	st getSize() const;

	void add(const T& obj);
	void add(T&& obj);

	void removeAt(int index);

	T& operator[](int index);
	const T& operator[](int index) const;

	~Collection() noexcept;

private:
	T** data = nullptr;
	st size = 0;
	st capacity = 8;

	void shiftDownTo(int index);
	void validateIndex(int index) const;

	void resize(st newCap);
	void copyFrom(const Collection<T>& other);
	void moveFrom(Collection<T>&& other);
	void free();
};

template<class T>
Collection<T>::Collection()
{
	data = new T * [capacity] {nullptr};
}

template<class T>
Collection<T>::Collection(st cap)
{
	capacity = cap;
	data = new T * [capacity] {nullptr};
}

template<class T>
Collection<T>::Collection(const Collection<T>& other) {
	copyFrom(other);
}

template<class T>
Collection<T>::Collection(Collection<T>&& other) noexcept {
	moveFrom(std::move(other));
}

template<class T>
Collection<T>& Collection<T>::operator=(const Collection<T>& other) {
	if (this != &other) {
		free();
		copyFrom(other);
	}
	return *this;
}

template<class T>
Collection<T>& Collection<T>::operator=(Collection<T>&& other) noexcept {
	if (this != &other) {
		free();
		moveFrom(std::move(other));
	}
	return *this;
}

template<class T>
st Collection<T>::getSize() const {
	return size;
}

template<class T>
void Collection<T>::add(const T& obj) {
	if (size >= capacity) {
		resize(capacity * 2);
	}
	data[size++] = new T(obj);
}

template<class T>
void Collection<T>::add(T&& obj) {
	if (size >= capacity) {
		resize(capacity * 2);
	}
	data[size++] = new T(std::move(obj));
}

template<class T>
void Collection<T>::removeAt(int index) {
	validateIndex(index);

	delete data[index];
	data[index] = nullptr;
	shiftDownTo(index);
	size--;
}

template<class T>
T& Collection<T>::operator[](int index) {
	validateIndex(index);
	return *data[index];
}

template<class T>
const T& Collection<T>::operator[](int index) const {
	validateIndex(index);
	return *data[index];
}

template<class T>
Collection<T>::~Collection() noexcept {
	free();
}

template<class T>
void Collection<T>::shiftDownTo(int index) {
	for (size_t i = index; i < size - 1; i++) {
		data[i] = data[i + 1];
	}
	data[size - 1] = nullptr;
}

template<class T>
void Collection<T>::validateIndex(int index) const {
	if (index < 0 || index >= size) {
		throw std::out_of_range("Index out of range");
	}
}

template<class T>
void Collection<T>::resize(st newCap) {
	T** temp = new (std::nothrow) T * [newCap] {nullptr};
	for (size_t i = 0; i < size; i++) {
		temp[i] = data[i];
	}
	delete[] data;
	data = temp;
	capacity = newCap;
}

template<class T>
void Collection<T>::copyFrom(const Collection<T>& other) {
	size = other.size;
	capacity = other.capacity;
	data = new T * [capacity]();
	for (size_t i = 0; i < size; i++) {
		data[i] = new T(*other.data[i]);
	}
}

template<class T>
void Collection<T>::moveFrom(Collection<T>&& other) {
	data = other.data;
	other.data = nullptr;

	size = other.size;
	capacity = other.capacity;

	other.size = 0;
	other.capacity = 0;
}

template<class T>
void Collection<T>::free() {
	for (size_t i = 0; i < size; i++) {
		delete data[i];
	}
	delete[] data;
	data = nullptr;
}
