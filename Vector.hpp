//**************************************************************************************************************
// CLASS: Vector
//
// DESCRIPTION
// Implements a simple, but not complete, templated Vector class.
//
// COURSE
// CSE220 Programming for Computer Engineering, Fall 2011
//
// AUTHOR INFORMATION
// Kevin R. Burger [KRB]
// James Matthew Welch [JMW]
//   
// Mailing Address:
// Computer Science & Engineering
// School of Computing, Informatics, and Decision Systems Engineering
// Arizona State University
// Tempe, AZ 85287-8809
//
// Email: burgerk@asu
// Web:   http://kevin.floorsoup.com
// Email: matt.welch@asu.edu
// Web:   https://bitbucket.org/mwelch/k1-microcontroller-assembler
//
// MODIFICATION HISTORY:
// -------------------------------------------------------------------------------------------------------------
// 21 Nov 2011 [KRB] Initial revision.
// 06 Dec 2011 [JMW] Submission for grading
//**************************************************************************************************************
#ifndef __VECTOR_HPP__
#define __VECTOR_HPP__

#include "Types.hpp"

//==============================================================================================================
// CLASS: Vector<T>
//==============================================================================================================
template <typename T>
class Vector {
public:
    Vector
        (
        UInt const pCapacity = 2
        );

    Vector
        (
        Vector const& pVector
        );

    ~Vector
        (
        );

    T& operator()
        (
        UInt const pIndex
        );

    T const& operator()
        (
        UInt const pIndex
        )
        const;

    Vector& operator=
        (
        Vector const& pVector
        );

    Vector& Append
        (
        T const& pElement
        );

    Vector& Append
        (
        T *Element
        );

    UInt const GetCapacity
        (
        )
        const;

    UInt const GetSize
        (
        )
        const;

protected:
    T * const Alloc
        (
        UInt const pCapacity
        )
        const;

    Vector& Copy
        (
        Vector const& pVector
        );

    void CopyArray
        (
        T *          pDstArray,
        T * const    pSrcArray,
        UInt32 const pSize
        )
        const;

    void Dealloc
        (
        T * const pArray
        )
        const;

    void Enlarge
        (
        );

    T    *mArray;
    UInt  mCapacity;
    Int   mLastIndex;
};

//==============================================================================================================
// PUBLIC FUNCTIONS
//==============================================================================================================

template <typename T>
Vector<T>::Vector
    (
    UInt const pCapacity
    )
    :
    mArray(0),
    mCapacity(pCapacity),
    mLastIndex(-1)
{
    mArray = Alloc(mCapacity);
}

template <typename T>
Vector<T>::Vector
    (
    Vector<T> const& pVector
    )
{
    *this = pVector;
}

template <typename T>
Vector<T>::~Vector
    (
    )
{
    Dealloc(mArray);
}

template <typename T>
T& Vector<T>::operator()
    (
    UInt pIndex
    )
{
    return mArray[pIndex];
}

template <typename T>
T const& Vector<T>::operator()
    (
    UInt pIndex
    )
    const
{
    return mArray[pIndex];
}

template <typename T>
Vector<T>& Vector<T>::operator=
    (
    Vector<T> const& pVector
    )
{
    if (this != &pVector) Copy(pVector);
    return *this;
}

template <typename T>
Vector<T>& Vector<T>::Append
    (
    T const& pElement
    )
{
    if (GetSize() == GetCapacity()) Enlarge();
    mArray[++mLastIndex] = pElement;
    return *this;
}

template <typename T>
Vector<T>& Vector<T>::Append
    (
    T *pElement
    )
{
    return Append(*pElement);
}

template <typename T>
UInt const Vector<T>::GetCapacity
    (
    )
    const
{
    return mCapacity;
}

template <typename T>
UInt const Vector<T>::GetSize
    (
    )
    const
{
    return mLastIndex + 1;
}

//==============================================================================================================
// PROTECTED FUNCTIONS
//==============================================================================================================

template <typename T>
T * const Vector<T>::Alloc
    (
    UInt const pCapacity
    )
    const
{
    return new T[pCapacity];
}

template <typename T>
Vector<T>& Vector<T>::Copy
    (
    Vector<T> const& pVector
    )
{
    Dealloc(mArray);
    mArray = Alloc(pVector.GetCapacity());
    CopyArray(mArray, pVector.mArray, pVector.GetSize());
    mCapacity = pVector.mCapacity;
    mLastIndex = pVector.mLastIndex;
    return *this;
}

template <typename T>
void Vector<T>::CopyArray
    (
    T *        pDstArray,
    T * const  pSrcArray,
    UInt const pSize
    )
    const
{
    for (UInt i = 0; i < pSize; i++) pDstArray[i] = pSrcArray[i];
}

template <typename T>
void Vector<T>::Dealloc
    (
    T * const pArray
    )
    const
{
    delete[] pArray;
}

template <typename T>
void Vector<T>::Enlarge
    (
    )
{
    T *newArray = Alloc(2 * GetCapacity());
    CopyArray(newArray, mArray, GetSize());
    Dealloc(mArray);
    mArray = newArray;
    mCapacity *= 2;
}

//==============================================================================================================
// PRIVATE FUNCTIONS
//==============================================================================================================

#endif
