//**************************************************************************************************************
// CLASS: Binary
//
// DESCRIPTION
// Provides a class that represents the binary output file. Writes the binary.
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
#ifndef __BINARY_HPP__
#define __BINARY_HPP__

#include <string>
#include "DataSegment.hpp"
#include "TextSegment.hpp"
#include "Types.hpp"

//==============================================================================================================
// CLASS: Binary
//==============================================================================================================
class Binary {
public:
    Binary
        (
        );

    ~Binary
        (
        );

    void Write
        (
        std::string const& pBinFname,
        DataSegment&       pDataSeg,
        TextSegment&       pTextSeg
        );

protected:

private:
    Binary
        (
        Binary const& pBinary
        )
    {
    }

    Binary& operator=
        (
        Binary const& pBinary
        );

};

#endif
