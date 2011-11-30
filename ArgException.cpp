//**************************************************************************************************************
// CLASS: ArgException
//
// DESCRIPTION
// See comments in ArgException.hpp.
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
#include "ArgException.hpp"

//==============================================================================================================
// PUBLIC FUNCTIONS
//==============================================================================================================

ArgException::ArgException
    (
    std::string const& pMsg
    )
    : mMsg(pMsg)
{
}

ArgException::~ArgException
    (
    )
    throw()
{
}

const Char *ArgException::what
    (
    )
    const
    throw()
{
    return mMsg.c_str();
}

//==============================================================================================================
// PROTECTED FUNCTIONS
//==============================================================================================================

//==============================================================================================================
// PRIVATE FUNCTIONS
//==============================================================================================================

