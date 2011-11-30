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
        = 0;

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