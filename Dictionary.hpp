//**************************************************************************************************************
// CLASS: Dictionary
//
// DESCRIPTION
// A Dictionary is a data structure that stores tuples: a (key, value) pair. It provides for lookup of values
// given keys. My Dictionary class is not implemented in a very efficient manner, using a Vector as the under-
// lying data structure. It would be more efficient to implement a Dictionary data structure as a binary search
// tree or a hash table. But, I'm not terribly concerned about efficiency in this project.
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
#ifndef __DICTIONARY_HPP__
#define __DICTIONARY_HPP__

#include "Tuple.hpp"
#include "Types.hpp"
#include "Vector.hpp"
#include "VectorIter.hpp"

//==============================================================================================================
// CLASS: Dictionary<T_Key, T_value>
//==============================================================================================================
template <typename T_Key, typename T_Value>
class Dictionary {
public:
    Dictionary
        (
        );

    Dictionary
        (
        Dictionary const& pDictionary
        );

   ~Dictionary
        (
        );

    Tuple<T_Key, T_Value>& operator()
        (
        UInt const pIndex
        );

    Tuple<T_Key, T_Value> const& operator()
        (
        UInt const pIndex
        )
        const;

    Dictionary& operator=
        (
        Dictionary const& pDictionary
        );

    Dictionary& Add
        (
        T_Key   pKey,
        T_Value pValue
        );

    UInt GetSize
        (
        )
        const;

    T_Value GetValue
        (
        T_Key pKey
        )
        throw (Int);

    static Int const NOT_FOUND = 1;

protected:
    Dictionary& Copy
        (
        Dictionary const& pDictionary
        );

    Vector< Tuple<T_Key, T_Value> > mVector;
};

//==============================================================================================================
// PUBLIC FUNCTIONS
//==============================================================================================================

template <typename T_Key, typename T_Value>
Dictionary<T_Key, T_Value>::Dictionary
    (
    )
{
}

template <typename T_Key, typename T_Value>
Dictionary<T_Key, T_Value>::Dictionary
    (
    Dictionary const& pDictionary
    )
    :
    mVector(pDictionary.mVector)
{
}

template <typename T_Key, typename T_Value>
Dictionary<T_Key, T_Value>::~Dictionary
    (
    )
{
}

template <typename T_Key, typename T_Value>
Tuple<T_Key, T_Value>& Dictionary<T_Key, T_Value>::operator()
    (
    UInt const pIndex
    )
{
   return mVector(pIndex); 
}

template <typename T_Key, typename T_Value>
Tuple<T_Key, T_Value> const& Dictionary<T_Key, T_Value>::operator()
    (
    UInt const pIndex
    )
    const
{
   return mVector(pIndex); 
}

template <typename T_Key, typename T_Value>
Dictionary<T_Key, T_Value>& Dictionary<T_Key, T_Value>::operator=
    (
    Dictionary const& pDictionary
    )
{
    if (this != &pDictionary) Copy(pDictionary);
    return *this;
}

template <typename T_Key, typename T_Value>
Dictionary<T_Key, T_Value>& Dictionary<T_Key, T_Value>::Add
    (
    T_Key   pKey,
    T_Value pValue
    )
{
    mVector.Append(Tuple<T_Key, T_Value>(pKey, pValue));
    return *this;
}

template <typename T_Key, typename T_Value>
T_Value Dictionary<T_Key, T_Value>::GetValue
    (
    T_Key pKey
    )
    throw (Int)
{
    VectorIter< Tuple<T_Key, T_Value> > it(mVector);
    while (it.HasNext()) {
        Tuple<T_Key, T_Value> tuple = it.GetNext();
        if (tuple.GetKey() == pKey) {
            T_Value value = tuple.GetValue();
            return value;
        }
    }
    throw NOT_FOUND;
}

template <typename T_Key, typename T_Value>
UInt Dictionary<T_Key, T_Value>::GetSize
    (
    )
    const
{
    return mVector.GetSize();
}

//==============================================================================================================
// PROTECTED FUNCTIONS
//==============================================================================================================

template <typename T_Key, typename T_Value>
Dictionary<T_Key, T_Value>& Dictionary<T_Key, T_Value>::Copy
    (
    Dictionary const& pDictionary
    )
{
    mVector = pDictionary.mVector;
    return *this;
}

//==============================================================================================================
// PRIVATE FUNCTIONS
//==============================================================================================================

#endif
