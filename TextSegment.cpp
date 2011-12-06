//**************************************************************************************************************
// CLASS: TextSegment
//
// DESCRIPTION
// See comments in TextSegment.hpp.
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
    #include "DictionaryIter.hpp"
#endif

#include "TextSegment.hpp"
#include "VectorIter.hpp"

//==============================================================================================================
// PUBLIC FUNCTIONS
//==============================================================================================================

TextSegment::TextSegment
    (
    Address const pAddress
    )
    :
    Segment(pAddress)
{
}

TextSegment::~TextSegment
    (
    )
{
}

//--------------------------------------------------------------------------------------------------------------
// AddInstr(). Encodes the Instr parameter 'pInstr' and then appends the encoded Instr to the mInstrs vector.
// Pseudocode:
// pInstr->Encode()         -- Note: this is a polymorphic function call.
// mInstrs.Append(*pInstr)  -- Dereferences pInstr and passes it to Append() by reference. 
//--------------------------------------------------------------------------------------------------------------
void TextSegment::AddInstr
    (
    Instr *pInstr
    )
{
	pInstr->Encode();
	mInstrs.Append(*pInstr);
}

//--------------------------------------------------------------------------------------------------------------
// AddLabel(). Adds a new label pLabel to the mLabels dictionary. The key is pLabel.GetName() and the value
// is pLabel. Hint: look at DataSegment::AddVariable().
//--------------------------------------------------------------------------------------------------------------
void TextSegment::AddLabel(Label const& pLabel)
{
    mLabels.Add(pLabel.GetName(), pLabel);
}

#ifdef DEBUG
void TextSegment::Dump
    (
    )
{
    std::cout << "Found Labels:" << std::endl;
    DictionaryIter<std::string, Label> itLabels(mLabels);
    while (itLabels.HasNext()) {
        Tuple<std::string, Label> entry = itLabels.GetNext();
        std::cout << "Lab: " << entry.GetKey() << " at " << entry.GetValue().GetAddress() << std::endl;
    }
    std::cout << "Instructions:" << std::endl;
    VectorIter<Instr> itInstrs(mInstrs);
    while (itInstrs.HasNext()) {
        Instr instr = itInstrs.GetNext();
        std::cout << "Instr: " << instr.GetMnemonic() << ", Encoding = " << instr.GetEncoding() << std::endl;
    }
}
#endif

//--------------------------------------------------------------------------------------------------------------
// GetContents(). Dynamically allocates a Byte array large enough to store all of the instructions.
// mInstrs.GetSize() is the number of instructions in the mInstrs vector, and since each instruction is encoded
// using four bytes, the size of the array is mInstrs.GetSize() * 4. Hint: see the GetContents() function in
// the DataSegment class.
//
// Pseudocode:
// UInt offset <- 0
// Dynamically allocate 'contents' as Byte *.  -- Will be deallocated in Binary::Write().
// Define a VectorIter<Instr> object named 'it' to iterate over the mInstrs Vector.
// While it.HasNext() Do
//	   Instr instr <- it.GetNext()
//     Word encoding <- instr.GetEncoding()
//     memcpy(&contents[offset], reinterpret_cast<Byte *>(&encoding), 4)  -- memcpy() is sleazy.
//     offset <- offset + 4
// End While
// Return contents
//--------------------------------------------------------------------------------------------------------------
Byte *TextSegment::GetContents(){
	// UInt offset <- 0
	UInt offset = 0;

	// Dynamically allocate 'contents' as Byte *.  -- Will be deallocated in Binary::Write().
	Byte *contents = new Byte[this-> mInstrs.GetSize() * 4];

	// Define a VectorIter<Instr> object named 'it' to iterate over the mInstrs Vector.
	VectorIter<Instr> it(mInstrs);

	while(it.HasNext()){
		//Instr instr <- it.GetNext()
		Instr instr = it.GetNext();
		//Word encoding <- instr.GetEncoding()
		Word encoding = instr.GetEncoding();
		//memcpy(&contents[offset], reinterpret_cast<Byte *>(&encoding), 4)  -- memcpy() is sleazy.
		memcpy(&contents[offset], reinterpret_cast<Byte *>(&encoding), 4);
		//offset <- offset + 4
		offset = offset + 4;
	}
	return contents;
}


// GetLabel
Label TextSegment::GetLabel
    (
    std::string const& pName
    )
{
    return mLabels.GetValue(pName);
}

//--------------------------------------------------------------------------------------------------------------
// GetSize(). Returns the size of the TextSegment. The size is calculated as:
//
//   1 byte                         Type
// + 4 bytes                        Text segment size
// + 4 bytes                        Address
// + mInstrs.GetSize() * 4 bytes    Encodings of each instruction
//
// Hint: See DataSegment::GetSize().
//--------------------------------------------------------------------------------------------------------------
UInt32 TextSegment::GetSize() const
{
	return (1 + 4 + 4 + (4 * mInstrs.GetSize() ) );
}

//==============================================================================================================
// PROTECTED FUNCTIONS
//==============================================================================================================

TextSegment& TextSegment::Copy
    (
    TextSegment const& pTextSegment
    )
{
    mInstrs = pTextSegment.mInstrs;
    mLabels = pTextSegment.mLabels;
    return *this;
}

//==============================================================================================================
// PRIVATE FUNCTIONS
//==============================================================================================================
