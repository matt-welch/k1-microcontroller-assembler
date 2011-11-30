//**************************************************************************************************************
// CLASS: Vector
//
// DESCRIPTION
// Instantiates Vector<T> classes.
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
#include "Instr.hpp"
#include "Variable.hpp"
#include "Vector.hpp"

//==============================================================================================================
//                                         TEMPLATE INSTANTIATIONS
//==============================================================================================================

template class Vector<Instr>;
template class Vector<Variable>;
