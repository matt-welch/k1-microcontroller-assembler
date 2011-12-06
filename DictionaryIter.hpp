//**************************************************************************************************************
// CLASS: DictionaryIter
//
// DESCRIPTION
// Defines an iterator class for iterating over the elements of a Vector.
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
#ifndef __DICTIONARYITER_HPP__
#define __DICTIONARYITER_HPP__

#include "Dictionary.hpp"
#include "Tuple.hpp"
#include "Types.hpp"

//==============================================================================================================
// CLASS: DictionaryIter<T_Key, T_Value>
//==============================================================================================================
template <typename T_Key, typename T_Value>
class DictionaryIter {
public:
    DictionaryIter
        (
        Dictionary<T_Key, T_Value>& pDictionary
        );

    Tuple<T_Key, T_Value>& GetNext
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

private:
    //----------------------------------------------------------------------------------------------------------
    // CTOR:  DictionaryIter(DictionaryIter<T> const&)
    // DESCR: By making the copy constructor private, we prevent someone from making a copy of a DictionaryIter
    //        object by doing something like this,
    //
    //        Dictionary<Int> Dictionary;
    //        ...
    //        DictionaryIter<Int> it(Dictionary);
    //        ...
    //        DictionaryIter<Int> it_copy(it);  -- No! Won't compile.
    //----------------------------------------------------------------------------------------------------------
    DictionaryIter
        (
        DictionaryIter<T_Key, T_Value> const& pDictionaryIter
        )
        : mDictionary(pDictionaryIter.mDictionary)
    {
    }

    //----------------------------------------------------------------------------------------------------------
    // FUNCTION: operator=
    // DESCR:    By making the overloaded operator= function constructor private, we prevent someone from
    //           assigning one DictionaryIter to another by doing something like this,
    //
    //        Dictionary<Int> Dictionary;
    //        ...
    //        DictionaryIter<Int> it(Dictionary);
    //        ...
    //        DictionaryIter<Int> it_another = it;  -- No! Won't compile.
    //----------------------------------------------------------------------------------------------------------
    DictionaryIter& operator=
        (
        DictionaryIter const& pDictionaryIter
        )
    {
        return *this;
    }

    Dictionary<T_Key, T_Value>& mDictionary;
    UInt                        mIdx;
};

//==============================================================================================================
// PUBLIC FUNCTIONS
//==============================================================================================================

template <typename T_Key, typename T_Value>
DictionaryIter<T_Key, T_Value>::DictionaryIter
    (
    Dictionary<T_Key, T_Value>& pDictionary
    )
    :
    mDictionary(pDictionary)
{
    Reset();
}

template <typename T_Key, typename T_Value>
Tuple<T_Key, T_Value>& DictionaryIter<T_Key, T_Value>::GetNext
    (
    )
{
    return mDictionary(mIdx++);
}

template <typename T_Key, typename T_Value>
Bool DictionaryIter<T_Key, T_Value>::HasNext
    (
    )
    const
{
    return mIdx < mDictionary.GetSize();
}

template <typename T_Key, typename T_Value>
void DictionaryIter<T_Key, T_Value>::Reset
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
