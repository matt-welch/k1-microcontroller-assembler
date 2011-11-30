//**************************************************************************************************************
// CLASS: ArgException
//
// DESCRIPTIONstd::
// Demonstrates how to declare and use a subclass of the std::exception class.
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
#ifndef __ARGEXCEPTION_HPP__
#define __ARGEXCEPTION_HPP__

#include <exception>
#include <string>
#include "Types.hpp"

//==============================================================================================================
// CLASS: ArgException
//==============================================================================================================
class ArgException : public std::exception {
public:
    ArgException
        (
        std::string const& pMsg
        );

    virtual ~ArgException
        (
        )
        throw();

    virtual const Char *what
        (
        )
        const
        throw();

protected:
    std::string mMsg;
};

#endif
