//**************************************************************************************************************
// CLASS: Label
//
// DESCRIPTION
// Declares a class that represents a Label on an assembly language instruction. This class is a subclass
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
#ifndef __LABEL_HPP__
#define __LABEL_HPP__

#include "Operand.hpp"

//==============================================================================================================
// CLASS: Label
//==============================================================================================================
class Label : public Operand {
public:
    Label
        (
        std::string const& pName    = "",
        Address const      pAddress = 0
        );

    Label
        (
        Label const& pLabel
        );

   ~Label
        (
        );

    Label& operator=
        (
        Label const& pLabel
        );

    UInt32 const GetAddress
        (
        )
        const;

    std::string const& GetName
        (
        )
        const;

    void SetAddress
        (
        UInt32 const pAddress
        );

    void SetName
        (
        std::string const& pName
        );

protected:
    Label& Copy
        (
        Label const& pLabel
        );

    Address mAddress;
};

#endif
