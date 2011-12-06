//**************************************************************************************************************
// CLASS: InstrTypeRV
//
// DESCRIPTION
// An instruction with two operands: a register and a variable.
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
#ifndef __INSTRTYPERV_HPP__
#define __INSTRTYPERV_HPP__

#include <string>
#include "InstrTypeR.hpp"
#include "Variable.hpp"

//--------------------------------------------------------------------------------------------------------------
// This class is very similar to the InstrTypeRI class. Look at it for hints about how to implement this class.
//--------------------------------------------------------------------------------------------------------------
//==============================================================================================================
// CLASS: InstrTypeRV
//==============================================================================================================
class InstrTypeRV : public InstrTypeR {
public:
    InstrTypeRV
        (
        std::string const& pMnemonic,
        Register const&    pRegister,
        Variable const&     pVariable
        );

    InstrTypeRV
        (
        InstrTypeRV const& pInstr
        );

    virtual ~InstrTypeRV
        (
        );

    InstrTypeRV& operator=
        (
        InstrTypeRV const& pInstr
        );

    virtual void Encode
        (
        );

    Variable const& GetVariable
        (
        )
        const;

protected:
    InstrTypeRV& Copy
        (
        InstrTypeRV const& pInstr
        );

    Variable mVariable;
};
#endif
