//**************************************************************************************************************
// CLASS: Segment
//
// DESCRIPTION
// See comments in Segment.hpp.
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
#include "Segment.hpp"

//==============================================================================================================
// PUBLIC FUNCTIONS
//==============================================================================================================

Segment::Segment
    (
    Address const pAddress
    )
    : 
    mAddress(pAddress)
{
}

Segment::Segment
    (
    Segment const& pSegment
    )
    :
    mAddress(pSegment.mAddress)
{
}

Segment::~Segment
    (
    )
{
}

Segment& Segment::operator=
    (
    Segment const& pSegment
    )
{
    if (this != &pSegment) Copy(pSegment);
    return *this;
}

UInt32 Segment::GetAddress
    (
    )
    const
{
    return mAddress;
}

void Segment::SetAddress
    (
    Address const pAddress
    )
{
    mAddress = pAddress;
}

//==============================================================================================================
// PROTECTED FUNCTIONS
//==============================================================================================================

Segment& Segment::Copy
    (
    Segment const& pSegment
    )
{
    SetAddress(pSegment.GetAddress());
    return *this;
}

//==============================================================================================================
// PRIVATE FUNCTIONS
//==============================================================================================================
