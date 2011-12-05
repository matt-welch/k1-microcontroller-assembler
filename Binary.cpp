//**************************************************************************************************************
// CLASS: Binary
//
// DESCRIPTION
// See comments in Binary.hpp.
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
#include <fstream>
#include "Binary.hpp"

//==============================================================================================================
// PUBLIC FUNCTIONS
//==============================================================================================================

Binary::Binary
    (
    )
{
}

Binary::~Binary
    (
    )
{
}

//--------------------------------------------------------------------------------------------------------------
// FUNCTION: Binary::Write
//
// DESCR:
// Writes the binary to the file with name pBinFname.
//
// PSEUDOCODE:
// Define bout to be an object of the class std::ofstream.
// Open bout passing parameters (pbinFname.c_str(), std::ios_base::binary)
// Write "K1BIN" to bout.
// initPC <- pTextSeg.GetAddress()
// Write initPC to bout.
// Write seven 0 bytes to bout.
// Write 0 byte (.DATA segment) to bout.
// size <- pDataSeg.GetSize()
// Write size as four bytes to bout.
// addr <- pDataSeg.GetAddress()
// Write addr as four bytes to bout.
// contents <- pDataSeg.GetContents()
// Write contents to bout.
// Delete contents (this dynamically allocated array was allocated in GetContents()).
// Write 1 byte (.TEXT segment) to bout.
// size <- pTextSeg.GetSize()
// Write size as four bytes to bout.
// addr <- pTextSeg.GetAddress()
// Write addr as four bytes to bout.
// contents <- pTextSeg.GetContents()
// Write contents to bout.
// Delete contents (this dynamically allocated array was allocated in GetContents()).
// Close bout.
//
// Note: ofstream::write() expects the first parameter to be a pointer to a char, i.e., to be of the data type
// char *. To typecast a pointer of one type to another type in C++ you can use the reinterpet_cast<> operator,
// e.g.,
//
// Byte *contents = mDataSeg.GetContents();
// bout.write(reinterpret_cast<char *>(contents), ...);  -- Typecast 'contents' to be of type char *.
//--------------------------------------------------------------------------------------------------------------
void Binary::Write
    (
    std::string const& pBinFname,
    DataSegment&       pDataSeg,
    TextSegment&       pTextSeg
    )
{
    // todo Binary::Write()
}

//==============================================================================================================
// PROTECTED FUNCTIONS
//==============================================================================================================

//==============================================================================================================
// PRIVATE FUNCTIONS
//==============================================================================================================
