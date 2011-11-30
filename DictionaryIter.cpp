//**************************************************************************************************************
// CLASS: DictionaryIter
//
// DESCRIPTION
// Instantiates templated DictionaryIter classes.
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
#include "DictionaryIter.hpp"
#include "Label.hpp"
#include "Types.hpp"
#include "Variable.hpp"

//==============================================================================================================
//                                         TEMPLATE INSTANTIATIONS
//==============================================================================================================

template class DictionaryIter<std::string, Label>;
template class DictionaryIter<std::string, Variable>;
