//**************************************************************************************************************
// CLASS: Args
//
// DESCRIPTION
// See comments in Args.hpp.
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

#include "ArgException.hpp"
#include "Args.hpp"

//==============================================================================================================
// PUBLIC FUNCTIONS
//==============================================================================================================

Args::Args
    (
    UInt const   pArgc, 
    Char const **pArgv
    )
{
    Init(pArgc, pArgv);
}

Args::Args
    (
    Args const& pArgs
    )
{
    *this = pArgs;
}

Args::~Args
    (
    ) 
{
}

Args& Args::operator=
    (
    Args const& pArgs
    ) 
{
    if (this != &pArgs) Copy(pArgs);
    return *this;    
}

std::string Args::GetBinFilename
    (
    )
    const
{
    return mBinFilename;
}

std::string Args::GetSrcFilename
    (
    )
    const
{
    return mSrcFilename;
}

//==============================================================================================================
// PROTECTED FUNCTIONS
//==============================================================================================================

Args& Args::Copy
    (
    Args const& pArgs
    ) 
{
    return *this;
}

void Args::SetBinFilename
    (
    std::string pBinFilename
    )
{
    mBinFilename = pBinFilename;
}

void Args::SetSrcFilename
    (
    std::string pSrcFilename
    )
{
    mSrcFilename = pSrcFilename;
}

Args& Args::Init
    (
    UInt const   pArgc, 
    Char const **pArgv
    )
    throw (ArgException)
{
    if (pArgc < 2) throw ArgException("k1as: Missing source file.");
    SetBinFilename("");
    SetSrcFilename(""); 
    for (UInt i = 1; i < pArgc; i++) {
        std::string arg(pArgv[i]);
        if (arg == "-o") {
            SetBinFilename(pArgv[++i]);
        } else if (arg[0] == '-') {
            throw ArgException("k1as: something weird on command line: " + arg);
        } else {
            SetSrcFilename(arg);
            size_t dot = arg.find('.');
            arg.erase(dot);
            SetBinFilename(arg);
        }
    }
    #ifdef DEBUG
        std::cout << "Source filename: " << GetSrcFilename() << std::endl;
        std::cout << "Binary filename: " << GetBinFilename() << std::endl;
    #endif
    return *this;
}

//==============================================================================================================
// PRIVATE FUNCTIONS
//==============================================================================================================
