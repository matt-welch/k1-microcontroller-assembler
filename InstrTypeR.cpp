//**************************************************************************************************************
// CLASS: InstrTypeR
//
// DESCRIPTION
// See comments in InstrTyprR.hpp.
//
// COURSE
// CSE220 Programming for Computer Engineering, Fall 2011
//
// AUTHOR INFORMATION
// Kevin R. Burger [KRB]
//   
// Mailing Address:
// Computer Science & Engineering
// School of Computing, Informatics, and Decision Systems Engineering
// Arizona State University
// Tempe, AZ 85287-8809
//
// Email: burgerk@asu
// Web:   http://kevin.floorsoup.com
//
// MODIFICATION HISTORY:
// -------------------------------------------------------------------------------------------------------------
// 21 Nov 2011 [KRB] Initial revision.
//**************************************************************************************************************
#ifdef DEBUG
    #include <iostream>
#endif

#include "InstrTypeR.hpp"

//==============================================================================================================
// PUBLIC FUNCTIONS
//==============================================================================================================

InstrTypeR::InstrTypeR
    (
    std::string const& pMnemonic,
    Register const&    pRegister
    )
    :
    Instr(pMnemonic),
    mRegister(pRegister)
{
}

InstrTypeR::InstrTypeR
    (
    InstrTypeR const& pInstr
    )
    :
    Instr(pInstr.mMnemonic),
    mRegister(pInstr.mRegister)
{
}

InstrTypeR::~InstrTypeR
    (
    )
{
}

InstrTypeR& InstrTypeR::operator=
    (
    InstrTypeR const& pInstr
    )
{
    if (this != &pInstr) Copy(pInstr);
    return *this;
}

void InstrTypeR::Encode
    (
    )
{
    Instr::Encode();
    mEncoding |= mRegister.GetEncoding() << 26;
}

Register const& InstrTypeR::GetRegister
    (
    )
    const
{
    return mRegister;
}

//==============================================================================================================
// PROTECTED FUNCTIONS
//==============================================================================================================

InstrTypeR& InstrTypeR::Copy
    (
    InstrTypeR const& pInstr
    )
{
    // Copy pInstr's superclass data members to 'this'.
    Instr::Copy(pInstr);                               
    // Copy pInstr's class data members to 'this'.
    mRegister = pInstr.mRegister;
    return *this;
}

//==============================================================================================================
// PRIVATE FUNCTIONS
//==============================================================================================================

