//**************************************************************************************************************
// FILE: Types.hpp
//
// DESCRIPTION
// Useful type definitions.
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
#ifndef __TYPES_HPP__
#define __TYPES_HPP__

typedef bool                Bool;
typedef char                Char;
typedef unsigned char       UChar;
typedef int                 Int;
typedef unsigned int        UInt;
typedef long                Long;
typedef unsigned long       ULong;
typedef short               Short;
typedef unsigned short      UShort;
typedef float               Float;
typedef double              Double;
typedef long double         LDouble;

#ifdef _32_BIT_
    typedef Char            Int8;
    typedef Short           Int16;
    typedef Int             Int32;
    typedef UChar           UInt8;
    typedef UShort          UInt16;
    typedef UInt            UInt32;
#elif _64_BIT_
    // If you have a 64-bit cpu, then you will have to figure out what these should be equivalent to.
    typedef ???             Int8;
    typedef ???             Int16;
    typedef ???             Int32;
    typedef ???             UInt8;
    typedef ???             UInt16;
    typedef ???             UInt32;
#endif

typedef UInt32 Address;
typedef UInt8  Byte;
typedef UInt32 Word;

#endif
