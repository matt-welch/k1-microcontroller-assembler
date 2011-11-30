//**************************************************************************************************************
// CLASS: Variable
//
// DESCRIPTION
// See comments in Variable.hpp.
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
#include "Variable.hpp"

//==============================================================================================================
// PUBLIC FUNCTIONS
//==============================================================================================================

//--------------------------------------------------------------------------------------------------------------
// Default constructor. Write a member initialization list to call the Operand class constructor and pass pName
// as the parameter, to initialize mAddress to pAddress, and to initialize mInitValue to pInitValue. The body
// of the constructor is empty.
//--------------------------------------------------------------------------------------------------------------
???

//--------------------------------------------------------------------------------------------------------------
// Copy constructor. Write a member initialization list to call the Operand class constructor and pass
// pVariable.mString as the parameter, to initialize mAddress to pVariable.mAddress, and to initialize
// mInitValue to pVariable.mInitValue. The body of the constructor is empty.
//--------------------------------------------------------------------------------------------------------------
???

//--------------------------------------------------------------------------------------------------------------
// Destructor. In this class, it is simply an empy function.
//--------------------------------------------------------------------------------------------------------------
???

//--------------------------------------------------------------------------------------------------------------
// operator=. Hint: look at the other source code files to see how this is done.
//--------------------------------------------------------------------------------------------------------------
???

//--------------------------------------------------------------------------------------------------------------
// GetAddress(). Accessor function for the mAddress data member.
//--------------------------------------------------------------------------------------------------------------
???

//--------------------------------------------------------------------------------------------------------------
// GetInitValue(). Accessor function for the mInitValue data member.
//--------------------------------------------------------------------------------------------------------------
???

//--------------------------------------------------------------------------------------------------------------
// GetName(). Returns the name of the variable. The name is the mString data member that is inherited from the
// Operand class. Call the GetString() function to get mString and return it.
//--------------------------------------------------------------------------------------------------------------
???

//--------------------------------------------------------------------------------------------------------------
// SetAddress(). Mutator function for the mAddress data member.
//--------------------------------------------------------------------------------------------------------------
???

//--------------------------------------------------------------------------------------------------------------
// SetInitValue(). Mutator function for the mInitValue data member.
//--------------------------------------------------------------------------------------------------------------
???

//--------------------------------------------------------------------------------------------------------------
// Setname(). Mutator function for the mString data member that is inherited from the Operand class.
//--------------------------------------------------------------------------------------------------------------
???

//==============================================================================================================
// PROTECTED FUNCTIONS
//==============================================================================================================

//--------------------------------------------------------------------------------------------------------------
// Copy(). Makes 'this' Variable a copy of pVariable.
// Pseudocode:
// Call Operand::Copy(pVariable). This copies the mString data member of pVariable to this object's mString.
// Call SetAddress() with pVariable.GetAddress() as the parameter.
// Call SetInitValue() with pVariable.GetInitValue() as the parameter.
// Return a reference to this object.
//--------------------------------------------------------------------------------------------------------------
???

//==============================================================================================================
// PRIVATE FUNCTIONS
//==============================================================================================================
