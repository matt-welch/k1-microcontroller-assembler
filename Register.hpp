//**************************************************************************************************************
// CLASS: Register
//
// DESCRIPTION
// Decalres a class that represents a register operand in an instruction. This class is a subclass of Operand.
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

// What goes at the top of a header file?
#ifndef __REGISTER_HPP__
#define __REGISTER_HPP__

#include "Operand.hpp"

//==============================================================================================================
// CLASS: Register
//==============================================================================================================

// Look a the Register.cpp file and implement the class declaration here. Register is a subclass of Operand.
// The default constructor is the first one, and the pName parameter is a default parameter set to the empty
// string.
class Register : public Operand{
public:
	Register();
	Register(std::string const& pName);
	Register(Register const& pRegister);
	~Register();
	Register& 			operator= (Register const& pRegister);
	Byte 				GetEncoding() const;
	std::string const& 	GetName() const;
	void 				SetName(std::string const& pName);

protected:
	Register& 			Copy(Register const& pRegister);
private:

};

// What goes at the end of a header file?
#endif /* end of include guard __REGISTER_HPP__ */
