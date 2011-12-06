//**************************************************************************************************************
// CLASS: Assembler
//
// DESCRIPTION
// Main class for the K1 assembler.
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
#ifndef __ASSEMBLER_HPP__
#define __ASSEMBLER_HPP__

#include "DataSegment.hpp"
#include "Instr.hpp"
#include "InstrTypeB.hpp"
#include "InstrTypeR.hpp"
#include "InstrTypeRI.hpp"
#include "InstrTypeRV.hpp"
#include "Lex.hpp"
#include "TextSegment.hpp"
#include "Types.hpp"

//==============================================================================================================
// CLASS: Assembler
//==============================================================================================================
class Assembler {
public:
    Assembler
        (
        std::string pSrcFname,
        std::string pBinFname
        );

   ~Assembler
        (
        );

    Int Run
        (
        );

protected:
    void Assemble
        (
        UInt const pPass
        );

    void AssembleDirective
        (
        std::string const& pDirective
        );

    Instr *AssembleInstr
        (
        std::string const& pMnemonic,
        std::string const& pLabel = ""
        );

    Instr *AssembleInstrTypeB
        (
        std::string const& pMnemonic,
        std::string const& pLabel = ""
        );

    Instr *AssembleInstrTypeN
        (
        std::string const& pMnemonic,
        std::string const& pLabel = ""
        );

    Instr *AssembleInstrTypeR
        (
        std::string const& pMnemonic,
        std::string const& pLabel = ""
        );

    Instr *AssembleInstrTypeRI
        (
        std::string const& pMnemonic,
        std::string const& pLabel = ""
        );

    Instr *AssembleInstrTypeRV
        (
        std::string const& pMnemonic,
        std::string const& pLabel = ""
        );

    void AssembleLabel
        (
        std::string const& pName
        );

    void AssembleVariable
        (
        std::string const& pName
        );

    void WriteBinary
        (
        );

private:
    Bool IsTypeR(std::string pMnemonic);
    Bool IsTypeB(std::string pMnemonic);
    Bool IsTypeN(std::string pMnemonic);
    Bool IsTypeRI(std::string pMnemonic);
    Bool IsTypeRV(std::string pMnemonic);
    Bool IsLoad(std::string pMnemonic);

    std::string mBinFname;
    UInt32      mCurrAddr;
    DataSegment mDataSeg;
    Lex         mLex;
    std::string mSrcFname;
    TextSegment mTextSeg;
};

#endif
