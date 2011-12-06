//**************************************************************************************************************
// CLASS: Label
//
// DESCRIPTION
// See comments in Label.hpp.
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
#include "Label.hpp"

//==============================================================================================================
// PUBLIC FUNCTIONS
//==============================================================================================================

Label::Label
    (
    std::string const& pName,
    Address const      pAddress
    )
    :
    Operand(pName),
    mAddress(pAddress)
{
}

Label::Label
    (
    Label const& pLabel
    )
    :
    Operand(pLabel.mString),
    mAddress(pLabel.mAddress)
{
}

Label::~Label
    (
    )
{
}

Label& Label::operator=
    (
    Label const& pLabel
    )
{
    if (this != &pLabel) Copy(pLabel);
    return *this;
}

Address const Label::GetAddress
    (
    )
    const
{
    return mAddress;
}

std::string const& Label::GetName
    (
    )
    const
{
    return GetString();
}

void Label::SetAddress
    (
    UInt32 const pAddress
    )
{
    mAddress = pAddress;
}

void Label::SetName
    (
    std::string const& pName
    )
{
    SetString(pName);
}

//==============================================================================================================
// PROTECTED FUNCTIONS
//==============================================================================================================

Label& Label::Copy
    (
    Label const& pLabel
    )
{
    // Copy pLabel's superclass data members to 'this'.
    Operand::Copy(pLabel);                               
    // Copy pLabel's class data members to 'this;.
    SetAddress(pLabel.GetAddress());
    return *this;
}

//==============================================================================================================
// PRIVATE FUNCTIONS
//==============================================================================================================
