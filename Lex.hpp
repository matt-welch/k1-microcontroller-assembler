//**************************************************************************************************************
// CLASS: Lex
//
// DESCRIPTION
// Implements the lexical analyzer which returns successive tokens read from the source code file.
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
#ifndef __LEX_HPP__
#define __LEX_HPP__

#include <fstream>
#include <string>

#include "Types.hpp"

//==============================================================================================================
// CLASS: Lex
//==============================================================================================================
class Lex {
public:
    Lex
        (
        std::string const& pSrcFname = ""
        );

   ~Lex
        (
        );

    std::string NextToken
        (
        );

    void Reset
        (
        );

    void SkipRestOfLine
        (
        );

protected:
    std::ifstream  mFin;
    std::string    mSrcFname;
};

#endif
