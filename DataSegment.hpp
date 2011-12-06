//**************************************************************************************************************
// CLASS: DataSegment.hpp.
//
// DESCRIPTION
// Declares a class that maintains the information in the .DATA segment. In particular, stores a Dictionary
// with T_Key = std::string and T_Value = Variable.
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
#ifndef __DATASEGMENT_HPP__
#define __DATASEGMENT_HPP__

#include <string>
#include "Dictionary.hpp"
#include "Segment.hpp"
#include "Types.hpp"
#include "Variable.hpp"

//==============================================================================================================
// CLASS: DataSegment
//==============================================================================================================
class DataSegment : public Segment {
public:
    DataSegment
        (
        Address const pAddress = 0
        );

   ~DataSegment
        (
        );

    void AddVariable
        (
        Variable const& pVariable
        );

    #ifdef DEBUG
    void Dump
        (
        );
    #endif 
   
    Variable GetVariable
        (
        std::string const& pName
        );

    Byte *GetContents
        (
        );

    UInt32 GetSize
        (
        )
        const;

protected:
    DataSegment& Copy
        (
        DataSegment const& pDataSegment
        );

    Dictionary<std::string, Variable> mVars;
};

#endif
