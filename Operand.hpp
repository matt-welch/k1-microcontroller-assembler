//**************************************************************************************************************
// CLASS: Operand
//
// DESCRIPTION
// Operand represents an operand in an assembly language instruction. It is the superclass of Integer, Label,
// Register, and Variable classes.
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
#ifndef __OPERAND_HPP__
#define __OPERAND_HPP__

#include <string>
#include "Types.hpp"

//==============================================================================================================
// CLASS: Operand
//==============================================================================================================
class Operand {
public:
    Operand
        (
        std::string const& pString = ""
        );

    Operand
        (
        Operand const& pOperand
        );

    virtual ~Operand
        (
        )
        = 0; // abstract class so Operand may not be instantiated, subclasses MUST implement this function

    Operand& operator=
        (
        Operand const& pOperand
        );

    std::string const& GetString
        (
        )
        const;

    void SetString
        (
        std::string const& pString
        );

protected:
    virtual Operand& Copy
        (
        Operand const& pOperand
        );

    std::string mString;
};

#endif
