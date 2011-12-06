//**************************************************************************************************************
// CLASS: InstrTypeB
//
// DESCRIPTION
// A type B instruction is a branch instruction. Each branch instruction encodes the branch target address in
// the address field of the instruction. All branch instructions are instances of this class.
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
#ifndef __INSTRTYPEB_HPP__
#define __INSTRTYPEB_HPP__

#include <string>
#include "Instr.hpp"
#include "Label.hpp"

//==============================================================================================================
// CLASS: InstrTypeB
//==============================================================================================================
class InstrTypeB : public Instr {
public:
    InstrTypeB
        (
        std::string const& pMnemonic,
        Label const&       pLabel
        );

    InstrTypeB
        (
        InstrTypeB const& pInstr
        );

    virtual ~InstrTypeB
        (
        );

    InstrTypeB& operator=
        (
        InstrTypeB const& pInstr
        );

    virtual void Encode
        (
        );

    Label const& GetLabel
        (
        )
        const;

protected:
    InstrTypeB& Copy
        (
        InstrTypeB const& pInstr
        );

private:
    Label mLabel;
};

#endif
