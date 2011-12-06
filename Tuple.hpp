//**************************************************************************************************************
// CLASS: Tuple
//
// DESCRIPTION
// This is a templated class. A tuple is a pair (key, value) where the key is of type T_Key and the value of
// type T_Value. It is implemented so the Dictionary class can implement a Vector of Tuple objects. This class
// along with the Dictionary class is used to store the variables and labels and provide a lookup feature.
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
#ifndef __TUPLE_HPP__
#define __TUPLE_HPP__

#include "Types.hpp"

//==============================================================================================================
// CLASS: Tuple<T_Key, T_Value>
//==============================================================================================================
template <typename T_Key, typename T_Value>
class Tuple {
public:
    Tuple
        (
        );

    Tuple
        (
        T_Key const&   pKey,
        T_Value const& pValue
        );

    Tuple
        (
        Tuple const& pTuple
        );

    ~Tuple
        (
        );

    Tuple& operator=
        (
        Tuple const& pTuple
        );

    T_Key const& GetKey
        (
        )
        const;

    T_Value const& GetValue
        (
        )
        const;

protected:
    Tuple& Copy
        (
        Tuple const& pTuple
        );

    T_Key   mKey;
    T_Value mValue;
};

//==============================================================================================================
// PUBLIC FUNCTIONS
//==============================================================================================================

template <typename T_Key, typename T_Value>
Tuple<T_Key, T_Value>::Tuple
    (
    )
{
}

template <typename T_Key, typename T_Value>
Tuple<T_Key, T_Value>::Tuple
    (
    T_Key const&   pKey,
    T_Value const& pValue
    )
    :
    mKey(pKey),
    mValue(pValue)
{
}

template <typename T_Key, typename T_Value>
Tuple<T_Key, T_Value>::Tuple
    (
    Tuple const& pTuple
    )
    :
    mKey(pTuple.mKey),
    mValue(pTuple.mValue)    
{
}

template <typename T_Key, typename T_Value>
Tuple<T_Key, T_Value>::~Tuple
    (
    )
{
}

template <typename T_Key, typename T_Value>
Tuple<T_Key, T_Value>& Tuple<T_Key, T_Value>::operator=
    (
    Tuple const& pTuple
    )
{
    if (this != &pTuple) Copy(pTuple);
    return *this;
}

template <typename T_Key, typename T_Value>
T_Key const& Tuple<T_Key, T_Value>::GetKey
    (
    )
    const
{
    return mKey;
}

template <typename T_Key, typename T_Value>
T_Value const& Tuple<T_Key, T_Value>::GetValue
    (
    )
    const
{
    return mValue;
}

//==============================================================================================================
// PROTECTED FUNCTIONS
//==============================================================================================================

template <typename T_Key, typename T_Value>
Tuple<T_Key, T_Value>& Tuple<T_Key, T_Value>::Copy
    (
    Tuple const& pTuple
    )
{
    mKey = pTuple.mKey;
    mValue = pTuple.mValue;
    return *this;
}

#endif
