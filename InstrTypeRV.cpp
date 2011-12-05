//**************************************************************************************************************
// CLASS: InstrTypeRV
//
// DESCRIPTION
// See comments in InstrTypeRV.hpp.
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

//--------------------------------------------------------------------------------------------------------------
// This class is very similar to the InstrTypeRI class. Look at it for hints about how to implement this class.
//--------------------------------------------------------------------------------------------------------------
#ifdef DEBUG
    #include <iostream>
#endif

#include "InstrTypeRV.hpp"

//==============================================================================================================
// PUBLIC FUNCTIONS
//==============================================================================================================

InstrTypeRV::InstrTypeRV
    (
    std::string const& pMnemonic,
    Register const&    pRegister,
    Variable const&     pVariable
    )
    :
    InstrTypeR(pMnemonic, pRegister),
    mVariable(pVariable)
{
}

InstrTypeRV::InstrTypeRV
    (
    InstrTypeRV const& pInstr
    )
    :
    InstrTypeR(pInstr.mMnemonic, pInstr.mRegister),
    mVariable(pInstr.mVariable)
{
}

InstrTypeRV::~InstrTypeRV
    (
    )
{
}

InstrTypeRV& InstrTypeRV::operator=
    (
    InstrTypeRV const& pInstr
    )
{
    if (this != &pInstr) Copy(pInstr);
    return *this;
}

void InstrTypeRV::Encode
    (
    )
{
    Instr::Encode();
    mEncoding |= (mRegister.GetEncoding() << 26) | mVariable.GetInitValue();// mInteger.GetValue();
}

Variable const& InstrTypeRV::GetVariable
    (
    )
    const
{
    return mVariable;
}

//==============================================================================================================
// PROTECTED FUNCTIONS
//==============================================================================================================

InstrTypeRV& InstrTypeRV::Copy
    (
    InstrTypeRV const& pInstr
    )
{
    // Copy pInstr's superclass data members to 'this'.
    InstrTypeR::Copy(pInstr);
    // Copy pInstr's class data members to 'this'.
    mVariable = pInstr.mVariable;
    return *this;
}

//==============================================================================================================
// PRIVATE FUNCTIONS
//==============================================================================================================
