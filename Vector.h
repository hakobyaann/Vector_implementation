#ifndef VECTOR_H
#define VECTOR_H

#include <exception>

template <typename T>
class MyVector
{
public:
    MyVector();
    MyVector(unsigned long);
    MyVector(unsigned long, const T&);
    ~MyVector();
public:
    unsigned long size() const;
    unsigned long capacity() const;
    bool empty() const;
    void pushBack(const T&);
    void popBack();
    void insert(const T&, unsigned long);
    void erase(unsigned long);
    void resize(unsigned long);
    void clear();
    void swap(MyVector&);
    
public:
    T& operator[](size_t);
    const T& operator[](size_t) const;

private:
    T* _array;
    unsigned long _size;
    unsigned long _capacity;
};


#endif //VECTOR_H