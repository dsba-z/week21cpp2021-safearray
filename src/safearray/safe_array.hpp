#ifndef SAFE_ARRAY_H_
#define SAFE_ARRAY_H_

#include <cstddef>
#include <algorithm>        // std::min
#include <stdexcept>        // std::out_of_range

template<typename T>
class SafeArray {
public:

    /// The default constructor.
    SafeArray()
        :_size(0), _arr(nullptr)
    {
    }

    /// Constructor creates an array with \a sz elements of value \a def
    SafeArray(size_t sz, T def = T())
        :SafeArray()
    {
        _arr = new T[sz];

        // for
            // _arr[i] = def;
    }

    /// The copy constructor.
    SafeArray(const SafeArray& origin)
        :SafeArray(origin._size)
    {

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

    }


//    /// The Copy Assignment operator overloading.
//    <output type> operator = (<input type> rhv)
//    {

//        SafeArray<T> temp = rhv;
//        swap(*this, temp);

////        old_arr = _arr;
////        _arr = new[rhv._size];
////        // for loop that copies data
////        _size = rhv._size;


////        delete old_arr;

//    }

public:
    /// Resizes the array.
    void resize(size_t newSz, T def /* = ???*/)
    {
        SafeArray<T> temp(newSz, def);
        // edge cases


        // create a new array, copy elements of the old array, and remove the old

        // if new array is bigger, need to fill the difference

    }


//    /// Getting the ref to i-th element with no checking out of range.
//    /* <output type> */ operator [] (/* input type */) noexcept { /* ??? */ }
//    /// Const version
//    /* <output type (const)> */ operator [] (/* input type */) /*???*/ noexcept { /* ??? */ }

//    /// Getting the ref to i-th element with checking out of range.
//    /// Regular version and const version
//    /* <output type> */ at(/* input type */)
//    {
//    }


    /// getters
    // getSize()
    // getPtr()

private:

    /// Auxialiary method swapping two array objects with a managed resource
    /// correctly. Method guarantees that it doesn't throw under any conditions.
    static void swap(/*input arguments*/) noexcept
    {
        T* temp_arr = left._arr;
        // use std::swap
    }

private:
    T* _arr;                ///< Actual resource handler.
    size_t _size;           ///< Stores size of an array.
};// SafeArray


//template<typename T>
//std::ostream& operator << (std::ostream& s, /*input type*/)
//{
//    // write the array as [10, 20, 30]
//    // using square brackets and commas
//}



#endif // SAFE_ARRAY_H_
