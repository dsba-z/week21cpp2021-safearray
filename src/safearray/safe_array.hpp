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
    {}

    /// Constructor creates an array with \a sz elements of value \a def
    SafeArray(size_t sz, T def /* = ???*/)
//      constructor delegate
    {
        
    }

    /// The copy constructor.
    SafeArray(const SafeArray& origin)
    // ????
    {

    }

    /// Constructor with initializer list
    SafeArray(std::initializer_list<T> vals)
//    ????
    {

    }


    /// The Destructor. Implements RAII closing part.
    ~SafeArray()
    {

    }


    /// The Copy Assignment operator overloading.
//    <output type> operator = (<input type> rhv)
//    {

//    }

public:
    /// Resizes the array.
    void resize(size_t newSz, T def /* = ???*/)
    {
        // edge cases


        // create a new array, copy elements of the old array, and remove the old

        // if new array is bigger, need to fill the difference

    }


    /// Getting the ref to i-th element with no checking out of range.
    /* <output type> */ operator [] (/* input type */) noexcept { /* ??? */ }
    /// Const version
    /* <output type (const)> */ operator [] (/* input type */) /*???*/ noexcept { /* ??? */ }

    /// Getting the ref to i-th element with checking out of range.
    /// Regular version and const version
    /* <output type> */ at(/* input type */)
    {
    }


    /// getters
    // getSize()
    // getPtr()

private:

    /// Auxialiary method swapping two array objects with a managed resource
    /// correctly. Method guarantees that it doesn't throw under any conditions.
    static void swap(/*input arguments*/) noexcept
    {
        // use std::swap
    }

private:
    T* _arr;                ///< Actual resource handler.
    size_t _size;           ///< Stores size of an array.
};// SafeArray


template<typename T>
std::ostream& operator << (std::ostream& s, /*input type*/)
{
    // write the array as [10, 20, 30]
    // using square brackets and commas
}



#endif // SAFE_ARRAY_H_
