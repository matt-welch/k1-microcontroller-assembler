//**************************************************************************************************************
// CLASS: Instr
//
// DESCRIPTION
// See comments in Instr.hpp.
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
#include "Instr.hpp"

//==============================================================================================================
// PUBLIC FUNCTIONS
//==============================================================================================================

Instr::Instr
    (
    std::string const& pMnemonic
    )
    :
    mMnemonic(pMnemonic)
{
}

Instr::Instr
    (
    Instr const& pInstr
    )
    :
    mEncoding(pInstr.mEncoding),
    mMnemonic(pInstr.mMnemonic)
{
}

/* 
	use M.I.L. 

OR use member fcns

	SetEncoding(pEncoding);
	SetMnemonic(pMnemonic);

OR assign the variables directly

	mEncoding = pEncoding;
	mMnemonic = pMnemonic;
*/

Instr::~Instr
    (
    )
{
}

Instr& Instr::operator=
    (
    Instr const& pInstr
    )
{
    if (this != &pInstr) Copy(pInstr);
    return *this;
}

void Instr::Encode
    (
    )
{
    mEncoding = GetOpcode() << 27;
}

Word Instr::GetEncoding
    (
    )
    const
{
    return mEncoding;
}

std::string const& Instr::GetMnemonic
    (
    )
    const
{
    return mMnemonic;
}

void Instr::SetMnemonic
    (
    std::string const& pMnemonic
    )
{
    mMnemonic = pMnemonic;
}

//==============================================================================================================
// PROTECTED FUNCTIONS
//==============================================================================================================

Instr& Instr::Copy
    (
    Instr const& pInstr
    )
{
    
    SetMnemonic(pInstr.mMnemonic);
    SetEncoding(pInstr.mEncoding);
    return *this;
}

Byte Instr::GetOpcode
    (
    )
    const
{
    if (mMnemonic == "ADD")       return OPCODE_ADD;
    else if (mMnemonic == "BEQ")  return OPCODE_BEQ;
    else if (mMnemonic == "BLT")  return OPCODE_BLT;
    else if (mMnemonic == "BR")   return OPCODE_BR;
    else if (mMnemonic == "BSUB") return OPCODE_BSUB;
    else if (mMnemonic == "HALT") return OPCODE_HALT;
    else if (mMnemonic == "IN")   return OPCODE_IN;
    else if (mMnemonic == "LD")   return OPCODE_LD;
    else if (mMnemonic == "LDA")  return OPCODE_LDA;
    else if (mMnemonic == "LDI")  return OPCODE_LDI;
    else if (mMnemonic == "NEG")  return OPCODE_NEG;
    else if (mMnemonic == "NOR")  return OPCODE_NOR;
    else if (mMnemonic == "OUT")  return OPCODE_OUT;
    else if (mMnemonic == "POP")  return OPCODE_POP;
    else if (mMnemonic == "PUSH") return OPCODE_PUSH;
    else if (mMnemonic == "RET")  return OPCODE_RET;
    else if (mMnemonic == "ROL")  return OPCODE_ROL;
    else if (mMnemonic == "ST")   return OPCODE_ST;
    else return 0xFF;
}

Instr& Instr::SetEncoding
    (
    Word const pEncoding
    )
{
    mEncoding = pEncoding;
    return *this;
}
