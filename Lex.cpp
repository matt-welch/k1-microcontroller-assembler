//**************************************************************************************************************
// CLASS: Lex
//
// DESCRIPTION
// See comments in Lex.hpp.
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
#include <iostream>
#include "Lex.hpp"

//==============================================================================================================
// PUBLIC FUNCTIONS
//==============================================================================================================

Lex::Lex
    (
    std::string const& pSrcFname
    )
    :
    mSrcFname(pSrcFname)
{
    mFin.open(mSrcFname.c_str());
}

Lex::~Lex
    (
    )
{
    mFin.close();
}

//--------------------------------------------------------------------------------------------------------------
// NextToken(). Returns the next token (i.e., string) from the source file.
// Pseudocode:
// Define comment as a Bool.
// Define token as a string.
// Do
//     Read from mFin into token. If the read fails (mFin will be false) then return the empty string. This
//     Set comment to false.
//     If the first character of token is ';' Then Call SkipRestOfLine(); Set comment to true
// While comment is true
// Return token
//--------------------------------------------------------------------------------------------------------------

std::string Lex::NextToken(){
	Bool comment;
	std::string token;
	do{
		mFin >> token; // reads next token from the file
		if(!mFin)
		{// true if stream has not failed, false if fail
			return "";
		}
		comment = false;
		if(token[0] == ';'){
			// Lex just read a comment, throw it away
			SkipRestOfLine();
			comment = true;
		}
	}while(comment); // if comment found, keep parsing

	return token;
}

//--------------------------------------------------------------------------------------------------------------
// Reset(). Closes the source code file and then reopens it.
// Pseudocode:
// Close the file.
// Open the file again.
//
// alternatively, can seek back to beginning of the file
//--------------------------------------------------------------------------------------------------------------
void Lex::Reset(){// this may not work on cygwin
	mFin.close();
	mFin.open(mSrcFname.c_str());
}

//--------------------------------------------------------------------------------------------------------------
// SkipRestOfLine(). Reads and discards all characters until '\n' is read.
// Pseudocode:
// Define ignore as a string.
// Call getline(mFine, ignore, '\n').
//--------------------------------------------------------------------------------------------------------------

void Lex::SkipRestOfLine(){
	std::string ignore;
	getline(mFin, ignore); // reads until newline char
}

//==============================================================================================================
// PROTECTED FUNCTIONS
//==============================================================================================================

//==============================================================================================================
// PRIVATE FUNCTIONS
//==============================================================================================================
