//**************************************************************************************************************
// CLASS: DataSegment
//
// DESCRIPTION
// See comments in DataSegment.hpp.
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
#ifdef DEBUG
    #include <iostream>
#endif

#include "DataSegment.hpp"
#include "DictionaryIter.hpp"

//==============================================================================================================
// PUBLIC FUNCTIONS
//==============================================================================================================

DataSegment::DataSegment
    (
    Address const pAddress
    )
    :
    Segment(pAddress)
{
}

DataSegment::~DataSegment
    (
    )
{
}

void DataSegment::AddVariable
    (
    Variable const& pVariable
    )
{
    mVars.Add(pVariable.GetName(), pVariable);
}

#ifdef DEBUG
void DataSegment::Dump
    (
    )
{
    std::cout << "Found Variables:" << std::endl;
    DictionaryIter<std::string, Variable> it(mVars);
    while (it.HasNext()) {
        Tuple<std::string, Variable> entry = it.GetNext();
        std::cout << "Var: " << entry.GetKey() << " at " << entry.GetValue().GetAddress() << std::endl;
    }
}
#endif

Variable DataSegment::GetVariable
    (
    std::string const& pName
    )
{
    return mVars.GetValue(pName);
}

Byte *DataSegment::GetContents
    (
    )
{
    UInt offset = 0;
    Byte *contents = new Byte[mVars.GetSize() * 4];
    DictionaryIter<std::string, Variable> it(mVars);
    while (it.HasNext()) {
        Tuple<std::string, Variable> tuple = it.GetNext();
        Int32 initValue = tuple.GetValue().GetInitValue();
        memcpy(&contents[offset], reinterpret_cast<Byte *>(&initValue), 4);
        offset += 4;
    }
    return contents;
}

UInt32 DataSegment::GetSize
    (
    )
    const
{
    return 9 + 4 * mVars.GetSize();
}

//==============================================================================================================
// PROTECTED FUNCTIONS
//==============================================================================================================

DataSegment& DataSegment::Copy
    (
    DataSegment const& pDataSegment
    )
{
    mVars = pDataSegment.mVars;
    return *this;
}
