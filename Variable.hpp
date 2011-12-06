//**************************************************************************************************************
// CLASS: Variable
//
// DESCRIPTION
// Declares a class that represents Variable operands in assembly language instructions. This class is a
// subclass of Operand.
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
#ifndef __VARIABLE_HPP__
#define __VARIABLE_HPP__

#include "Operand.hpp"

//==============================================================================================================
// CLASS: Variable
//==============================================================================================================
class Variable : public Operand {
public:
    Variable
        (
        std::string const& pName      = "",
        Address const      pAddress   = 0,
        Word const         pInitValue = 0
        );

    Variable
        (
        Variable const& pVariable
        );

    ~Variable
        (
        );

    Variable& operator=
        (
        Variable const& pVariable
        );

    Address GetAddress
        (
        )
        const;

    Int32 GetInitValue
        (
        )
        const;

    std::string const& GetName
        (
        )
        const;

    void SetAddress
        (
        Address const pAddress
        );

    void SetInitValue
        (
        Int32 const pInitValue
        );

    void SetName
        (
        std::string const& pName
        );

protected:
    Variable& Copy
        (
        Variable const& pVariable
        );

    Address mAddress;
    Word    mInitValue;
};

#endif
