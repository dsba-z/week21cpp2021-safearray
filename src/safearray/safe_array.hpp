#ifndef SAFE_ARRAY_H_
#define SAFE_ARRAY_H_

#include <cstddef>
#include <iostream>
#include <algorithm>        // std::min
#include <stdexcept>        // std::out_of_range

template<typename T>
class SafeArray {
public:

    /// The default constructor.
    SafeArray()
        :_size(0), _arr(nullptr)
    {}

    /// Constructor creates an array with \a sz elements of value \a def
    SafeArray(size_t sz, T def = T())
        :SafeArray()
    {
        if (sz == 0) {
            return;
        }
        _size = sz;
        _arr = new T[sz];
        for (int i = 0; i < sz; ++i) {
            _arr[i] = def;
        }
    }

    /// The copy constructor.
    SafeArray(const SafeArray& origin)
        :SafeArray(origin._size)
    {
        for(int i = 0; i < _size; ++i) {
            _arr[i] = origin._arr[i];
        }
    }

    /// Constructor with initializer list
    SafeArray(std::initializer_list<T> vals)
        :SafeArray(vals.size())
    {
        int i = 0;
        for (const T& v: vals) {
            _arr[i++] = v;
        }
     }


    /// The Destructor. Implements RAII closing part.
    ~SafeArray()
    {
        delete[] _arr;
    }


    /// The Copy Assignment operator overloading.
    SafeArray<T>& operator= (const SafeArray<T>& rhv)
    {
        SafeArray<T> temp(rhv);
        SafeArray::swap(*this, temp);
        return *this;
    }

public:
    /// Resizes the array.
    void resize(size_t newSz, T def = T())
    {
        // edge cases
        if (newSz == _size) {
            return;
        }
        if (newSz == 0) {
            delete[] _arr;
            _arr = nullptr;
            _size = 0;
            return;
        }

        // create a new array, copy elements of the old array, and remove the old
        T* newArr = new T[newSz];
        for (int i = 0; i < std::min(newSz, _size); ++i) {
            newArr[i] = _arr[i];
        }
        delete[] _arr;

        // if new array is bigger, need to fill the difference
        if (newSz > _size) {
            for (int i = _size; i < newSz; ++i) {
                newArr[i] = def;
            }
        }
        _arr = newArr;
        _size = newSz;

    }


    /// Getting the ref to i-th element with no checking out of range.
    T& operator [] (size_t i) noexcept { return _arr[i]; }
    /// Const version
    const T& operator [] (size_t i) const noexcept { return _arr[i]; }

    /// Getting the ref to i-th element with checking out of range.
    /// Regular version and const version
    T& at(size_t i)
    {
        if (i >= _size) {
            throw std::out_of_range("Safe array index out of range");
        }
        return _arr[i];
    }

    const T& at(size_t i) const
    {
        if (i >= _size) {
            throw std::out_of_range("Safe array index out of range");
        }
        return _arr[i];
    }


    /// getters
    size_t getSize() const { return _size; }
    T* getPtr() const {return _arr; }

private:

    /// Auxialiary method swapping two array objects with a managed resource
    /// correctly. Method guarantees that it doesn't throw under any conditions.
    static void swap(SafeArray<T>& a, SafeArray<T>& b) noexcept
    {
        std::swap(a._arr, b._arr);
        std::swap(a._size, b._size);
    }

private:
    T* _arr;                ///< Actual resource handler.
    size_t _size;           ///< Stores size of an array.
};// SafeArray


template<typename T>
std::ostream& operator << (std::ostream& s, const SafeArray<T> sa)
{
    s << "[";
    for (int i = 0; i < sa.getSize(); ++i) {
        s << sa[i];
        if (i < sa.getSize() - 1) {
            s << ", ";
        }
    }
    s << "]";
    return s;
    // write the array as [10, 20, 30]
    // using square brackets and commas
}



#endif // SAFE_ARRAY_H_
