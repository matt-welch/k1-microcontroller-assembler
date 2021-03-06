//**************************************************************************************************************
// CLASS: TextSegment
//
// DESCRIPTION
// Maintains the text segment. The text segment has two data members: a Dictionary of the labels, and a Vector
// of the instructions.
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
#ifndef __TEXTSEGMENT_HPP__
#define __TEXTSEGMENT_HPP__

#include <string>
#include "Dictionary.hpp"
#include "Instr.hpp"
#include "Label.hpp"
#include "Segment.hpp"
#include "Types.hpp"
#include "Vector.hpp"

//==============================================================================================================
// CLASS: TextSegment
//==============================================================================================================
class TextSegment : public Segment {
public:
    TextSegment
        (
        Address const pAddress = 0
        );

   ~TextSegment
        (
        );

    void AddInstr
        (
        Instr *pInstr
        );

    void AddLabel
        (
        Label const& pLabel
        );

    #ifdef DEBUG
    void Dump
        (
        );
    #endif 
   
    Byte *GetContents
        (
        );

    Label GetLabel
        (
        std::string const& pName
        );

    UInt32 GetSize
        (
        )
        const;

protected:
    TextSegment& Copy
        (
        TextSegment const& pTextSegment
        );

    TextSegment& Init
        (
        );

private:
    // Declare a data member named mInstrs which is an object of the templated class Vector<Instr>.
    //----------------------------------------------------------------------------------------------------------
    Vector<Instr> mInstrs;

    //----------------------------------------------------------------------------------------------------------
    // Declare a data member named mLabels which is an object of the templated class Dictionary<std::string,
    // Label>.
    //----------------------------------------------------------------------------------------------------------
    Dictionary<std::string,Label> mLabels;
};

#endif
