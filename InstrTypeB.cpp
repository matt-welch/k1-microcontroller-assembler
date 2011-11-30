//**************************************************************************************************************
// CLASS: InstrTypeB
//
// DESCRIPTION
// See comments in InstrTypeB.hpp.
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

#include "InstrTypeB.hpp"

//==============================================================================================================
// PUBLIC FUNCTIONS
//==============================================================================================================

InstrTypeB::InstrTypeB
    (
    std::string const& pMnemonic,
    Label const&       pLabel
    )
    :
    Instr(pMnemonic),
    mLabel(pLabel)
{
    Encode();
}

InstrTypeB::InstrTypeB
    (
    InstrTypeB const& pInstr
    )
    :
    Instr(pInstr.mMnemonic),
    mLabel(pInstr.mLabel)
{
    Encode();
}

InstrTypeB::~InstrTypeB
    (
    )
{
}

InstrTypeB& InstrTypeB::operator=
    (
    InstrTypeB const& pInstr
    )
{
    if (this != &pInstr) Copy(pInstr);
    return *this;
}

void InstrTypeB::Encode
    (
    )
{
    Instr::Encode();
    mEncoding |= mLabel.GetAddress();
}

Label const& InstrTypeB::GetLabel
    (
    )
    const
{
    return mLabel;
}

//==============================================================================================================
// PROTECTED FUNCTIONS
//==============================================================================================================

InstrTypeB& InstrTypeB::Copy
    (
    InstrTypeB const& pInstr
    )
{
    // Copy pInstr's superclass data members to 'this'.
    Instr::Copy(pInstr);
    mLabel = pInstr.mLabel;
    Encode();
    return *this;
}

//==============================================================================================================
// PRIVATE FUNCTIONS
//==============================================================================================================

