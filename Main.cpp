//**************************************************************************************************************
// FILE: Main.cpp
//
// DESCRIPTION
// The K1 assembler.
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
#include <iostream>
#include "Args.hpp"
#include "Assembler.hpp"
#include "Types.hpp"

//==============================================================================================================
// Starting point.
//==============================================================================================================
int main
    (
    Int   argc,
    Char *argv[]
    )
{
    try {
        Args args(static_cast<UInt>(argc), const_cast<Char const **>(argv));
        Assembler assembler(args.GetSrcFilename(), args.GetBinFilename());
        return assembler.Run();
    } catch (ArgException& e) {
        std::cerr << e.what() << std::endl;
        return -1;
    }
}
