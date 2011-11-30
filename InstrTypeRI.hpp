//**************************************************************************************************************
// CLASS: InstrTypeRI
//
// DESCRIPTION
// A type RI instruction is one that encodes a register and an integer. All such instructions are instances of
// this class.
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
#ifndef __INSTRTYPERI_HPP__
#define __INSTRTYPERI_HPP__

#include <string>
#include "Integer.hpp"
#include "InstrTypeR.hpp"

//==============================================================================================================
// CLASS: InstrTypeRI
//==============================================================================================================
class InstrTypeRI : public InstrTypeR {
public:
    InstrTypeRI
        (
        std::string const& pMnemonic,
        Register const&    pRegister,
        Integer const&     pInteger
        );

    InstrTypeRI
        (
        InstrTypeRI const& pInstr
        );

    virtual ~InstrTypeRI
        (
        );

    InstrTypeRI& operator=
        (
        InstrTypeRI const& pInstr
        );

    virtual void Encode
        (
        );

    Integer const& GetInteger
        (
        )
        const;

protected:
    InstrTypeRI& Copy
        (
        InstrTypeRI const& pInstr
        );

    Integer mInteger;
};

#endif
