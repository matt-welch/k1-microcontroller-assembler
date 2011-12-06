//**************************************************************************************************************
// CLASS: InstrTypeR
//
// DESCRIPTION
// Declares a class that represents a type R instruction, i.e., one that has just one operand: a register. This
// class is a subclass of Instr.
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
#ifndef __INSTRTYPER_HPP__
#define __INSTRTYPER_HPP__

#include <string>
#include "Instr.hpp"
#include "Register.hpp"

//==============================================================================================================
// CLASS: InstrTypeR
//==============================================================================================================
class InstrTypeR : public Instr {
public:
    InstrTypeR
        (
        std::string const& pMnemonic,
        Register const&    pReg
        );

    InstrTypeR
        (
        InstrTypeR const& pInstr
        );

    virtual ~InstrTypeR
        (
        );

    InstrTypeR& operator=
        (
        InstrTypeR const& pInstr
        );

    virtual void Encode
        (
        );

    Register const& GetRegister
        (
        )
        const;

protected:
    InstrTypeR& Copy
        (
        InstrTypeR const& pInstr
        );

    Register mRegister;
};

#endif
