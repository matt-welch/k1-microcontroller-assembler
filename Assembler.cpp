//**************************************************************************************************************
// CLASS: Assembler
//
// DESCRIPTION
// See comments in Assembler.hpp.
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

#include <cstdlib>
#include <string>
#include "Assembler.hpp"
#include "Binary.hpp"
#include "Dictionary.hpp"
#include "Integer.hpp"
#include "Label.hpp"
#include "Register.hpp"
#include "Types.hpp"
#include "Variable.hpp"
#include "Vector.hpp"

//==============================================================================================================
// PUBLIC FUNCTIONS
//==============================================================================================================

Assembler::Assembler
    (
    std::string pSrcFname,
    std::string pBinFname
    )
    :
    mBinFname(pBinFname),
    mLex(pSrcFname),
    mSrcFname(pSrcFname)
{
}

Assembler::~Assembler
    (
    )
{
}

Int Assembler::Run
    (
    )
{
    Assemble(1);
    mLex.Reset();
    Assemble(2);
    WriteBinary();
    return 0;
}

//==============================================================================================================
// PROTECTED FUNCTIONS
//==============================================================================================================

//--------------------------------------------------------------------------------------------------------------
// FUNCTION: Assembler::Assemble()
//
// DESCR:
// Assembles the source code file in two passes. During the first pass, directives, variables, and labels are
// parsed and handled; instructions are skipped. During the second pass, directives, variables, and labels are
// skipped and instructions are parsed and encoded.
//
// PSEUDOCODE:
// #If preprocessor macro DEBUG is defined then
//     Display "Pass: " pPass
// #Endif
// mCurrAddr <- 0
// token <- mLex.NextToken()
// While token != "" Do
//     If first char of token is '.' Then  -- Directive
//         if pPass is 1 Then AssembleDirective(token)
//         Else mLex.SkipRestOfLine()
//     Elseif first char of token is '$' Then  -- Variable
//         If pPass is 1 then AssemblerVariable(token); mCurrAddr++
//         Else mLex.SkipRestOfLine()
//     Elseif first char of token is '@' Then  -- Label
//         If pPass is 1 then AssembleLabel(token); mLex.SkipRestOfLine()
//         Else instr <- AssembleInstruction(mLex.NextToken(), token); mTextSeg.AddInstr(instr)
//         mCurrAddr++
//     Else  -- Instruction
//         If pPass is 1 Then mLex.SkipRestOfLine()
//         Else instr <- AssembleInstruction(mLex.NextToken(), token); mTextSeg.AddInstr(instr)
//         mCurrAddr++;
//     End If
//     token <- mLex.NextToken()
// End While
// #If preprocessor macro DEBUG is defined Then
//     If pPass is 1 then mDataSeg.Dump()
//     Else mTextSeg.Dump()
// #Endif
//--------------------------------------------------------------------------------------------------------------
void Assembler::Assemble
    (
    UInt const pPass
    )
{
    ???
}

//--------------------------------------------------------------------------------------------------------------
// FUNCTION: Assembler::AssembleDirective()
//
// DESCR:
// Parses and handles a .DATA or .TEXT directive.
//
// PSEUDOCODE:
// address <- atoi(mLext.NextToken.c_str())
// If pDirective is ".DATA" Then mDataSeg.SetAddress(address)
// Else mTextSeg.SetAddress(address)
// mCurrAddr <- address
//--------------------------------------------------------------------------------------------------------------
void Assembler::AssembleDirective
    (
    std::string const& pDirective
    )
{
    ???
}

//--------------------------------------------------------------------------------------------------------------
// FUNCTION: Assembler::AssembleInstr()
//
// DESCR:
// Parses and assembles an instruction. On input, pMnemonic is the mnemonic that was parsed, and pLabel is
// a the instruction label, which may be the empty string.
//
// PSEUDOCODE:
// If pMnemonic is in [ADD, NEG, NOR, POP, PUSH, ROL] Then
//     return AssembleInstrTypeR(pMnemonic, pLabel)
// Elseif pMnemonic is in [BEQ, BLT, BR, BSUB] Then
//     return AssembleInstrTypeB(pMnemonic, pLabel)
// Elseif pMnemonic is in [HALT, RET] Then
//     return AssembleInstrTypeN(pMnemonic, pLabel)
// Elseif pMnemonic is in [IN, OUT, LDI] Then- 
//     return AssembleInstrTypeRI(pMnemonic, pLabel)
// Else
//     return AssembleInstrTypeRV(pMnemonic, pLabel)
// End If
//--------------------------------------------------------------------------------------------------------------
Instr *Assembler::AssembleInstr
    (
    std::string const& pMnemonic,
    std::string const& pLabel
    )
{
    ???
}

//--------------------------------------------------------------------------------------------------------------
// FUNCTION: Assembler::AssembleInstrTypeB
//
// DESCR:
// Parses and assembles a type B instruction (BEQ, BLT, BR, or BSUB).
//
// PSEUDOCODE:
// Label targetLabel <- mTextSeg.GetLabel(mLex.NextToken())
// return new InstrTypeB(pMnemonic, mTargetLabel)
//--------------------------------------------------------------------------------------------------------------
Instr *Assembler::AssembleInstrTypeB
    (
    std::string const& pMnemonic,
    std::string const& pLabel
    )
{
    ???
}

//--------------------------------------------------------------------------------------------------------------
// FUNCTION: Assembler::AssembleInstrTypeN
//
// DESCR:
// Parses and assembles a type N instruction (N = no operands; these are HALT and RET).
//
// PSEUDOCODE:
// return new Instr(pMnemonic)
//--------------------------------------------------------------------------------------------------------------
Instr *Assembler::AssembleInstrTypeN
    (
    std::string const& pMnemonic,
    std::string const& pLabel
    )
{
    ???
}

//--------------------------------------------------------------------------------------------------------------
// FUNCTION: Assembler::AssembleInstrTypeR
//
// DESCR:
// Parses and assembles a type R instruction (R = register).
//
// PSEUDOCODE:
// Register reg(mLex.NextToken())
// return new InstrTypeR(pMnemonic, reg)
//--------------------------------------------------------------------------------------------------------------
Instr *Assembler::AssembleInstrTypeR
    (
    std::string const& pMnemonic,
    std::string const& pLabel
    )
{
    ???
}

//--------------------------------------------------------------------------------------------------------------
// FUNCTION: Assembler::AssembleInstrTypeRI
//
// DESCR:
// Parses and assembles a type RI instruction (R = register, I = integer).
//
// PSEUDOCODE:
// Register reg(mLex.NextToken())
// Integer i(mLex.NextToken())
// return new InstrTypeRI(pMnemonic, reg, i)
//--------------------------------------------------------------------------------------------------------------
Instr *Assembler::AssembleInstrTypeRI
    (
    std::string const& pMnemonic,
    std::string const& pLabel
    )
{
    ???
}

//--------------------------------------------------------------------------------------------------------------
// FUNCTION: Assembler::AssembleInstrTypeRV
//
// DESCR:
// Parses and assembles a type RI instruction (R = register, V = variable).
//
// PSEUDOCODE:
// If pMnemonic is in [LD, LDA] Then
//     reg_string <- mLex.NextToken()
//     var_string <- mLex.NextToken()
// Else
//     var_string <- mLex.NextToken()
//     reg_string <- mLex.NextToken()
// End If
// Variable var <- mDataSeg.GetVariable(var_string)
// return new InstrTypeRV(pMnemonic, Register(reg_string), var)
//--------------------------------------------------------------------------------------------------------------
Instr *Assembler::AssembleInstrTypeRV
    (
    std::string const& pMnemonic,
    std::string const& pLabel
    )
{
    ???
}

//--------------------------------------------------------------------------------------------------------------
// FUNCTION: Assembler::AssembleLabel
//
// DESCR:
// Parses a label during the first pass. Gets the string, creates a new Label object, and then adds the Label
// to the dictionary of labels stored in the mTextSeg object.
//
// PSEUDOCODE:
// Label newLabel(pName, mCurrAddr)
// mTextSeg.AddLabel(newLabel)
//--------------------------------------------------------------------------------------------------------------
void Assembler::AssembleLabel
    (
    std::string const& pName
    )
{
    mTextSeg.AddLabel(Label(pName, mCurrAddr));
}

//--------------------------------------------------------------------------------------------------------------
// FUNCTION: Assembler::AssembleVariable
//
// DESCR:
// Parses a variable during the first pass. Gets the string, createa a new Variable object, and then adds the
// Variable to the dictionary of Variables stored in the mDataSeg object.
//
// PSEUDOCODE:
// initValue <- atoi(mLex.NextToken.c_str())
// Variable newVariable(pName, mCurrAddr, initValue)
// mDataSeg.AddVariable(newVariable)
//--------------------------------------------------------------------------------------------------------------
void Assembler::AssembleVariable
    (
    std::string const& pName
    )
{
    ???
}

//--------------------------------------------------------------------------------------------------------------
// FUNCTION: Assembler::WriteBinary
//
// DESCR:
// Creates a Binary object and then calls Write on the object to write the binary.
//
// PSEUDOCODE:
// Binary bin;
// bin.Write(mBinFname, mDataSeg, mTextSeg)
//--------------------------------------------------------------------------------------------------------------
void Assembler::WriteBinary
    (
    )
{
    ???
}

//==============================================================================================================
// PRIVATE FUNCTIONS
//==============================================================================================================

