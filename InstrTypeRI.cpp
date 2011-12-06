//**************************************************************************************************************
// CLASS: InstrTypeRI
//
// DESCRIPTION
// See comments in InstrTypeRI.hpp.
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
#ifdef DEBUG
    #include <iostream>
#endif

#include "InstrTypeRI.hpp"

//==============================================================================================================
// PUBLIC FUNCTIONS
//==============================================================================================================

InstrTypeRI::InstrTypeRI
    (
    std::string const& pMnemonic,
    Register const&    pRegister,
    Integer const&     pInteger
    )
    :
    InstrTypeR(pMnemonic, pRegister),
    mInteger(pInteger)
{
}

InstrTypeRI::InstrTypeRI
    (
    InstrTypeRI const& pInstr
    )
    :
    InstrTypeR(pInstr.mMnemonic, pInstr.mRegister),
    mInteger(pInstr.mInteger)
{
}

InstrTypeRI::~InstrTypeRI
    (
    )
{
}

InstrTypeRI& InstrTypeRI::operator=
    (
    InstrTypeRI const& pInstr
    )
{
    if (this != &pInstr) Copy(pInstr);
    return *this;
}

void InstrTypeRI::Encode
    (
    )
{
    Instr::Encode();
    mEncoding |= (mRegister.GetEncoding() << 26) | mInteger.GetValue();
}

Integer const& InstrTypeRI::GetInteger
    (
    )
    const
{
    return mInteger;
}

//==============================================================================================================
// PROTECTED FUNCTIONS
//==============================================================================================================

InstrTypeRI& InstrTypeRI::Copy
    (
    InstrTypeRI const& pInstr
    )
{
    // Copy pInstr's superclass data members to 'this'.
    InstrTypeR::Copy(pInstr);                               
    // Copy pInstr's class data members to 'this'.
    mInteger = pInstr.mInteger;
    return *this;
}

//==============================================================================================================
// PRIVATE FUNCTIONS
//==============================================================================================================
