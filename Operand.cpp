//**************************************************************************************************************
// CLASS: Operand
//
// DESCRIPTION
// See comments in Operand.hpp.
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
#include "Operand.hpp"

//==============================================================================================================
// PUBLIC FUNCTIONS
//==============================================================================================================

Operand::Operand
    (
    std::string const& pString
    )
    :
    mString(pString)
{
}

Operand::Operand
    (
    Operand const& pOperand
    )
    :
    mString(pOperand.mString)
{
}

Operand::~Operand
    (
    )
{
}

Operand& Operand::operator=
    (
    Operand const& pOperand
    )
{
    if (this != &pOperand) Copy(pOperand);
    return *this;
}

std::string const& Operand::GetString
    (
    )
    const
{
    return mString;
}

void Operand::SetString
    (
    std::string const& pString
    )
{
    mString = pString;
}

//==============================================================================================================
// PROTECTED FUNCTIONS
//==============================================================================================================

Operand& Operand::Copy
    (
    Operand const& pOperand
    )
{
    mString = pOperand.mString;
    return *this;
}

//==============================================================================================================
// PRIVATE FUNCTIONS
//==============================================================================================================

