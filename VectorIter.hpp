//**************************************************************************************************************
// CLASS: VectorIter
//
// DESCRIPTION
// Declares a vector iterator class for iterating over the elements of a Vector.
//
// COURSE
// CSE220 Programming for Computer Engineering, Fall 2011
//
// AUTHOR INFORMATION
// Kevin R. Burger [KRB]
//   
// Mailing Address:
// Computer Science & Engineering
// School of Computing, Informatics, and Decision Systems Engineering
// Arizona State University
// Tempe, AZ 85287-8809
//
// Email: burgerk@asu
// Web:   http://kevin.floorsoup.com
//
// MODIFICATION HISTORY:
// -------------------------------------------------------------------------------------------------------------
// 21 Nov 2011 [KRB] Initial revision.
//**************************************************************************************************************
#ifndef __VECTORITER_HPP__
#define __VECTORITER_HPP__

#include "Vector.hpp"
#include "Types.hpp"

//==============================================================================================================
// CLASS: VectorIter<T>
//==============================================================================================================
template <typename T>
class VectorIter {
public:
    VectorIter
        (
        Vector<T>& pVector
        );

    T& GetNext
        (
        );

    Bool HasNext
        (
        )
        const;

    void Reset
        (
        );

protected:
    Vector<T>& mVector;
    UInt       mIdx;

private:
    //----------------------------------------------------------------------------------------------------------
    // CTOR:  VectorIter(VectorIter<T> const&)
    // DESCR: By making the copy constructor private, we prevent someone from making a copy of a VectorIter
    //        object by doing something like this,
    //
    //        Vector<Int> vector;
    //        ...
    //        VectorIter<Int> it(vector);
    //        ...
    //        VectorIter<Int> it_copy(it);  -- No! Won't compile.
    //----------------------------------------------------------------------------------------------------------
    VectorIter
        (
        VectorIter<T> const& pVectorIter
        )
        : mVector(pVectorIter.mVector)
    {
    }

    //----------------------------------------------------------------------------------------------------------
    // FUNCTION: operator=
    // DESCR:    By making the overloaded operator= function constructor private, we prevent someone from
    //           assigning one VectorIter to another by doing something like this,
    //
    //        Vector<Int> vector;
    //        ...
    //        VectorIter<Int> it(vector);
    //        ...
    //        VectorIter<Int> it_another = it;  -- No! Won't compile.
    //----------------------------------------------------------------------------------------------------------
    VectorIter& operator=
        (
        VectorIter const& pVectorIter
        )
    {
        return *this;
    }
};

//==============================================================================================================
// PUBLIC FUNCTIONS
//==============================================================================================================

template <typename T>
VectorIter<T>::VectorIter
    (
    Vector<T>& pVector
    )
    : mVector(pVector)
{
    Reset();
}

template <typename T>
T& VectorIter<T>::GetNext
    (
    )
{
    return mVector(mIdx++);
}

template <typename T>
Bool VectorIter<T>::HasNext
    (
    )
    const
{
    return mIdx < mVector.GetSize();
}

template <typename T>
void VectorIter<T>::Reset
    (
    )
{
    mIdx = 0;
}

//==============================================================================================================
// PROTECTED FUNCTIONS
//==============================================================================================================

//==============================================================================================================
// PRIVATE FUNCTIONS
//==============================================================================================================

#endif
