//**************************************************************************************************************
// CLASS: Segment
//
// DESCRIPTION
// Superclass for the DataSegment and TextSegment classes. This is a pure virtual class, and objects of this
// class cannot be instantiated.
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
#ifndef __SEGMENT_HPP__
#define __SEGMENT_HPP__

#include "Types.hpp"
#include <string.h>

//==============================================================================================================
// CLASS: Segment
//==============================================================================================================
class Segment {
public:
    Segment
        (
        Address const pAddress = 0
        );

    Segment
        (
        Segment const& pSegment
        );

   virtual ~Segment
        (
        )
        = 0;

    Segment& operator=
        (
        Segment const& pSegment
        );

    Address GetAddress
        (
        )
        const;

    virtual Byte *GetContents
        (
        )
        = 0;

    virtual UInt32 GetSize
        (
        )
        const
        = 0;

    void SetAddress
        (
        Address const pAddress
        );

protected:
    Segment& Copy
        (
        Segment const& pSegment
        );

    Word mAddress;    
};

#endif
