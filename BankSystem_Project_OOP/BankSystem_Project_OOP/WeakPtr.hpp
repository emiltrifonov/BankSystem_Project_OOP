#pragma once
#include <iostream>

template<class T>
class WeakPtr {
public:
	WeakPtr(const T* data);

	const T& operator*() const;

private:
	const T* const data;
};

template<class T>
inline WeakPtr<T>::WeakPtr(const T* data) : data(data) {}

template<class T>
inline const T& WeakPtr<T>::operator*() const
{
	return *data;
}
