//**************************************************************************************************************
// CLASS: Instr
//
// DESCRIPTION
// Maintains an instruction with no operands. This is the superclass of all instruction classes with operands:
// InstrTypeB, InstrTypeR, InstrTypeRI, and InstrTypeRV.
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
#ifndef __INSTR_HPP__
#define __INSTR_HPP__

#include <string>
#include "Types.hpp"

//==============================================================================================================
// CLASS: Instr
//==============================================================================================================
class Instr {
public:
    Instr
        (
        std::string const& pMnemonic = ""
        );

    Instr
        (
        Instr const& pInstr
        );

    virtual ~Instr
        (
        );

    Instr& operator=
        (
        Instr const& pInstr
        );

    virtual void Encode
        (
        );

    Word GetEncoding
        (
        )
        const;

    std::string const& GetMnemonic
        (
        )
        const;

    void SetMnemonic
        (
        std::string const& pMnemonic
        );

    static Byte const OPCODE_LD   = 0x00;
    static Byte const OPCODE_LDI  = 0x01;
    static Byte const OPCODE_LDA  = 0x02;
    static Byte const OPCODE_ST   = 0x03;
    static Byte const OPCODE_ADD  = 0x04;
    static Byte const OPCODE_NEG  = 0x05;
    static Byte const OPCODE_ROL  = 0x06;
    static Byte const OPCODE_NOR  = 0x07;
    static Byte const OPCODE_PUSH = 0x08;
    static Byte const OPCODE_POP  = 0x09;
    static Byte const OPCODE_BR   = 0x0A;
    static Byte const OPCODE_BEQ  = 0x0B;
    static Byte const OPCODE_BLT  = 0x0C;
    static Byte const OPCODE_BSUB = 0x0D;
    static Byte const OPCODE_RET  = 0x0E;
    static Byte const OPCODE_IN   = 0x0F;
    static Byte const OPCODE_OUT  = 0x10;
    static Byte const OPCODE_HALT = 0x11;

protected:
    Instr& Copy
        (
        Instr const& pInstr
        );

    Byte GetOpcode
        (
        )
        const;

    Instr& SetEncoding
        (
        Word const pEncoding
        );

    Word        mEncoding;
    std::string mMnemonic;
};

#endif
