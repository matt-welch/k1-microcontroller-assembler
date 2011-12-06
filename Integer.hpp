//**************************************************************************************************************
// CLASS: Integer
//
// DESCRIPTION
// Declares a class that represents Integer operands in assembly language instructions. This class is a subclass
// of Operand.
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
#ifndef __INTEGER_HPP__
#define __INTEGER_HPP__

#include "Operand.hpp"

//==============================================================================================================
// CLASS: Ineger
//==============================================================================================================
class Integer : public Operand {
public:
    Integer
        (
        std::string const& pValue = ""
        );

    Integer
        (
        Integer const& pInteger
        );

    ~Integer
        (
        );

    Integer& operator=
        (
        Integer const& pInteger
        );

    Int32 GetValue
        (
        )
        const;

    void SetValue
        (
        Int32 const pValue
        );

protected:
    Integer& Copy
        (
        Integer const& pInteger
        );

private:
};

#endif
