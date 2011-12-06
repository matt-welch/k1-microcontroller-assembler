//**************************************************************************************************************
// CLASS: Register
//
// DESCRIPTION
// Stores information for a register opernad. This class is a subclass of Operand.
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
#include "Register.hpp"

//==============================================================================================================
// PUBLIC FUNCTIONS
//==============================================================================================================

Register::Register
    (
    std::string const& pName
    )
    :
    Operand(pName)
{
}

Register::Register
    (
    Register const& pRegister
    )
    :
    Operand(pRegister.mString)
{
}

Register::~Register
    (
    )
{
}

Register& Register::operator=
    (
    Register const& pRegister
    )
{
    if (this != &pRegister) Copy(pRegister);
    return *this;
}

Byte Register::GetEncoding
    (
    )
    const
{
    return (GetName() == "%A") ? 0 : 1;
}

std::string const& Register::GetName
    (
    )
    const
{
    return GetString();
}

void Register::SetName
    (
    std::string const& pName
    )
{
    SetString(pName);
}

//==============================================================================================================
// PROTECTED FUNCTIONS
//==============================================================================================================

Register& Register::Copy
    (
    Register const& pRegister
    )
{
    // Copy pRegister's superclass data members to 'this'.
    Operand::Copy(pRegister);
    return *this;
}

//==============================================================================================================
// PRIVATE FUNCTIONS
//==============================================================================================================
