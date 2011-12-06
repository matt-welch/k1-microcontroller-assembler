//**************************************************************************************************************
// CLASS: Integer
//
// DESCRIPTION
// See comments in Integer.hpp.
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
#include <cstdlib>      // For atoi() function.
#include <sstream>      // For stringstream class.
#include "Integer.hpp"

//==============================================================================================================
// PUBLIC FUNCTIONS
//==============================================================================================================

Integer::Integer
    (
    std::string const& pValue
    )
    :
    Operand(pValue)
{
}

Integer::Integer
    (
    Integer const& pInteger
    )
    :
    Operand(pInteger.mString)
{
}

Integer::~Integer
    (
    )
{
}

Integer& Integer::operator=
    (
    Integer const& pInteger
    )
{
    if (this != &pInteger) Copy(pInteger);
    return *this;
}

Int32 Integer::GetValue
    (
    )
    const
{
    return atoi(mString.c_str());
}

void Integer::SetValue
    (
    Int32 const pValue
    )
{
    std::stringstream ss;
    ss << pValue;
    mString = ss.str();
}

//==============================================================================================================
// PROTECTED FUNCTIONS
//==============================================================================================================

Integer& Integer::Copy
    (
    Integer const& pInteger
    )
{
    // Copy pInteger's superclass data members to 'this'.
    Operand::Copy(pInteger);                               
    return *this;
}

//==============================================================================================================
// PRIVATE FUNCTIONS
//==============================================================================================================
