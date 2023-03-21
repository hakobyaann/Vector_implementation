#include <iostream>
#include "Vector.h"

template <typename T>
MyVector<T>::MyVector()
{
    _array = new T[1];
    _size = 0;
    _capacity = 1;
}

template <typename T>
MyVector<T>::MyVector(unsigned long size)
{
    _size = size;
    _capacity = size;
    _array = new T[_size];
}

template <typename T>
MyVector<T>::MyVector(unsigned long size, const T& value)
{
    _size = size;
    _capacity = size;
    _array = new T[_size];
    for (int i = 0; i < _size; ++i)
    {
        _array[i] = value;
    }
}

template <typename T>
MyVector<T>::~MyVector()
{
   clear();
}

template <typename T>
unsigned long MyVector<T>::size() const
{
    return _size;
}

template <typename T>
unsigned long MyVector<T>::capacity() const
{
    return _capacity;
}

template <typename T>
inline bool MyVector<T>::empty() const
{
    return _size == 0 ? true : false;
}

template <typename T>
void MyVector<T>::pushBack(const T& value)
{
    if (_size >= _capacity)
    {
        resize(_size + 1);
    }
    _array[_size] = value;
    ++_size;
}

template <typename T>
void MyVector<T>::popBack()
{
    if (this->empty())
    {
        throw std::logic_error("Empty Vector");
    }
    T* tmp = new T[_size - 1];
    for (int i = 0; i < _size - 1; ++i)
    {
        tmp[i] = _array[i];
    }
    --_size;


    delete[] _array;
    _array = tmp;
    tmp = nullptr;
}

template <typename T>
void MyVector<T>::insert(const T& value, unsigned long index)
{
    if (index >= _capacity)
    {
        throw std::out_of_range("Out of range");
    }
    else if (_size == _capacity)
    {
        resize(_size + 1);
    }
        T* tmp = new T[_capacity];
        for (int i = 0, j = 0; i < _capacity; ++i)
        {
            if (i == index)
            {
                tmp[i] = value;
                ++_size;
                continue;
            }
            tmp[i] = _array[j];
            ++j;
        }

        delete[] _array;
        _array = tmp;
        tmp = nullptr;
   
}

template <typename T>
void MyVector<T>::erase(unsigned long index)
{
    if (this->empty())
    {
        throw std::logic_error("Empty Vector");
    }
    if (index > _capacity)
    {
        throw std::out_of_range("Out of range");
    }
    T* tmp = new T[_capacity];
    for (int i = 0, j = 0; i < _size; ++i)
    {
        if (i == index)
        {
            continue;
        }
        tmp[j] = _array[i];
        ++j;
    }
    --_size;

    delete[] _array;
    _array = tmp;
    tmp = nullptr;
}

template <typename T>
void MyVector<T>::resize(unsigned long newSize)
{
    if (newSize > _capacity)
    {
        _capacity *= 2;
        T* tmp = new T[_capacity];
        int i = 0;
        for (; i < _size; ++i)
        {
            tmp[i] = _array[i];
        }
        
        delete[] _array;
        _array = tmp;
        tmp = nullptr;
    }
    else if (newSize < _size)
    {
        _capacity = newSize;
        _size = _capacity;
        T* tmp = new T[_capacity];
        for (int i = 0; i < _size; ++i)
        {
            tmp[i] = _array[i];
        }

        delete[] _array;
        _array = tmp;
        tmp = nullptr;
    }
}

template <typename T>
void MyVector<T>::clear()
{
    delete[] _array;
    _size = 0;
    _array = nullptr;
    _capacity = 0;
}

template <typename T>
void MyVector<T>::swap(MyVector& obj)
{
    T* tmp = new T[_capacity];
    for (int i = 0; i < _size; ++i)
    {
        tmp[i] = _array[i];
    }
    int size = _size;
    delete[] _array;
    _array = new T[obj.capacity()];
    for (int i = 0; i < obj.size(); ++i)
    {
        _array[i] = obj[i];
    }
    obj.clear();
    for (int i = 0; i < size; ++i)
    {
        obj.pushBack(tmp[i]);
    }
}

template <typename T>
T& MyVector<T>::operator[](size_t index)
{
    if (index >= size()) 
    {
        throw std::out_of_range("Index out of range");
    }
    return _array[index];
}

template <typename T>
const T& MyVector<T>::operator[](size_t index) const
{
    if (index >= size()) 
    {
        throw std::out_of_range("Index out of range");
    }
    return _array[index];
}