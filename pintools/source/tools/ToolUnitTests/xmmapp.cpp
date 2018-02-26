/*BEGIN_LEGAL 
Intel Open Source License 

Copyright (c) 2002-2017 Intel Corporation. All rights reserved.
 
Redistribution and use in source and binary forms, with or without
modification, are permitted provided that the following conditions are
met:

Redistributions of source code must retain the above copyright notice,
this list of conditions and the following disclaimer.  Redistributions
in binary form must reproduce the above copyright notice, this list of
conditions and the following disclaimer in the documentation and/or
other materials provided with the distribution.  Neither the name of
the Intel Corporation nor the names of its contributors may be used to
endorse or promote products derived from this software without
specific prior written permission.
 
THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
``AS IS'' AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE INTEL OR
ITS CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
(INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
END_LEGAL */
#include <iostream>
#include <iomanip>
#include <cstdlib> // for atoi w/gcc4.3.x
using namespace std;
#define N 1024
int main(int argc, char** argv);
#if defined(_MSC_VER)
typedef unsigned __int8 UINT8 ;
typedef unsigned __int16 UINT16;
typedef unsigned __int32 UINT32;
typedef unsigned __int64 UINT64;
typedef __int8 INT8;
typedef __int16 INT16;
typedef __int32 INT32;
typedef __int64 INT64;
#define ALIGN16 __declspec(align(16))
#define ALIGN8  __declspec(align(8))

#else

#include <stdint.h>
typedef uint8_t  UINT8;
typedef uint16_t UINT16;
typedef uint32_t UINT32;
typedef uint32_t UINT;
typedef uint64_t UINT64;

typedef int8_t  INT8;
typedef int16_t INT16;
typedef int32_t INT32;
typedef int64_t INT64;
#define ALIGN16 __attribute__ ((aligned(16)))
#define ALIGN8  __attribute__ ((aligned(8)))


#endif

#ifdef TARGET_IA32E
typedef UINT64 ADDRINT;
#else
typedef UINT32 ADDRINT;
#endif

#define MAX_XMM_REGS 16
#define MAX_BYTES_PER_XMM_REG 16
#define MAX_WORDS_PER_XMM_REG (MAX_BYTES_PER_XMM_REG/2)
#define MAX_DWORDS_PER_XMM_REG (MAX_WORDS_PER_XMM_REG/2)
#define MAX_QWORDS_PER_XMM_REG (MAX_DWORDS_PER_XMM_REG/2)
#define MAX_FLOATS_PER_XMM_REG (MAX_BYTES_PER_XMM_REG/sizeof(float))
#define MAX_DOUBLES_PER_XMM_REG (MAX_BYTES_PER_XMM_REG/sizeof(double))


union ALIGN16 xmm_reg_t
{
    UINT8  byte[MAX_BYTES_PER_XMM_REG];
    UINT16 word[MAX_WORDS_PER_XMM_REG];
    UINT32 dword[MAX_DWORDS_PER_XMM_REG];
    UINT64 qword[MAX_QWORDS_PER_XMM_REG];

    INT8   s_byte[MAX_BYTES_PER_XMM_REG];
    INT16  s_word[MAX_WORDS_PER_XMM_REG];
    INT32  s_dword[MAX_DWORDS_PER_XMM_REG];
    INT64  s_qword[MAX_QWORDS_PER_XMM_REG];

    float  flt[MAX_FLOATS_PER_XMM_REG];
    double dbl[MAX_DOUBLES_PER_XMM_REG];

} /*__attribute__ ((aligned(16)))*/;

#if defined(_MSC_VER)
extern "C" void set_xmm_reg0(xmm_reg_t& xmm_reg);
extern "C" void get_xmm_reg0(xmm_reg_t& xmm_reg);
extern "C" void set_xmm_reg1(xmm_reg_t& xmm_reg);
extern "C" void get_xmm_reg1(xmm_reg_t& xmm_reg);
extern "C" void set_xmm_reg2(xmm_reg_t& xmm_reg);
extern "C" void get_xmm_reg2(xmm_reg_t& xmm_reg);
extern "C" void set_xmm_reg3(xmm_reg_t& xmm_reg);
extern "C" void get_xmm_reg3(xmm_reg_t& xmm_reg);
extern "C" void set_xmm_reg4(xmm_reg_t& xmm_reg);
extern "C" void get_xmm_reg4(xmm_reg_t& xmm_reg);
extern "C" void set_xmm_reg5(xmm_reg_t& xmm_reg);
extern "C" void get_xmm_reg5(xmm_reg_t& xmm_reg);
extern "C" void set_xmm_reg6(xmm_reg_t& xmm_reg);
extern "C" void get_xmm_reg6(xmm_reg_t& xmm_reg);
extern "C" void set_xmm_reg7(xmm_reg_t& xmm_reg);
extern "C" void get_xmm_reg7(xmm_reg_t& xmm_reg);
#ifdef TARGET_IA32E
extern "C" void set_xmm_reg8(xmm_reg_t& xmm_reg);
extern "C" void get_xmm_reg8(xmm_reg_t& xmm_reg);
extern "C" void set_xmm_reg9(xmm_reg_t& xmm_reg);
extern "C" void get_xmm_reg9(xmm_reg_t& xmm_reg);
extern "C" void set_xmm_reg10(xmm_reg_t& xmm_reg);
extern "C" void get_xmm_reg10(xmm_reg_t& xmm_reg);
extern "C" void set_xmm_reg11(xmm_reg_t& xmm_reg);
extern "C" void get_xmm_reg11(xmm_reg_t& xmm_reg);
extern "C" void set_xmm_reg12(xmm_reg_t& xmm_reg);
extern "C" void get_xmm_reg12(xmm_reg_t& xmm_reg);
extern "C" void set_xmm_reg13(xmm_reg_t& xmm_reg);
extern "C" void get_xmm_reg13(xmm_reg_t& xmm_reg);
extern "C" void set_xmm_reg14(xmm_reg_t& xmm_reg);
extern "C" void get_xmm_reg14(xmm_reg_t& xmm_reg);
extern "C" void set_xmm_reg15(xmm_reg_t& xmm_reg);
extern "C" void get_xmm_reg15(xmm_reg_t& xmm_reg);
#endif
extern "C" void mmx_save(char* buf);
extern "C" void mmx_restore(char* buf);
#else

static void set_xmm_reg0(xmm_reg_t& xmm_reg)
{
    asm volatile("movdqu %0, %%xmm0" :  : "m" (xmm_reg) : "%xmm0"  );
} 
static void get_xmm_reg0(xmm_reg_t& xmm_reg)
{
    asm volatile("movdqu %%xmm0,%0" : "=m" (xmm_reg)  );
}
static void set_xmm_reg1(xmm_reg_t& xmm_reg)
{
    asm volatile("movdqu %0, %%xmm1" :  : "m" (xmm_reg) : "%xmm1"  );
} 
static void get_xmm_reg1(xmm_reg_t& xmm_reg)
{
    asm volatile("movdqu %%xmm1,%0" : "=m" (xmm_reg)  );
}
static void set_xmm_reg2(xmm_reg_t& xmm_reg)
{
    asm volatile("movdqu %0, %%xmm2" :  : "m" (xmm_reg) : "%xmm2"  );
} 
static void get_xmm_reg2(xmm_reg_t& xmm_reg)
{
    asm volatile("movdqu %%xmm2,%0" : "=m" (xmm_reg)  );
}
static void set_xmm_reg3(xmm_reg_t& xmm_reg)
{
    asm volatile("movdqu %0, %%xmm3" :  : "m" (xmm_reg) : "%xmm3"  );
} 
static void get_xmm_reg3(xmm_reg_t& xmm_reg)
{
    asm volatile("movdqu %%xmm3,%0" : "=m" (xmm_reg)  );
}
static void set_xmm_reg4(xmm_reg_t& xmm_reg)
{
    asm volatile("movdqu %0, %%xmm4" :  : "m" (xmm_reg) : "%xmm4"  );
} 
static void get_xmm_reg4(xmm_reg_t& xmm_reg)
{
    asm volatile("movdqu %%xmm4,%0" : "=m" (xmm_reg)  );
}
static void set_xmm_reg5(xmm_reg_t& xmm_reg)
{
    asm volatile("movdqu %0, %%xmm5" :  : "m" (xmm_reg) : "%xmm5"  );
} 
static void get_xmm_reg5(xmm_reg_t& xmm_reg)
{
    asm volatile("movdqu %%xmm5,%0" : "=m" (xmm_reg)  );
}
static void set_xmm_reg6(xmm_reg_t& xmm_reg)
{
    asm volatile("movdqu %0, %%xmm6" :  : "m" (xmm_reg) : "%xmm6"  );
} 
static void get_xmm_reg6(xmm_reg_t& xmm_reg)
{
    asm volatile("movdqu %%xmm6,%0" : "=m" (xmm_reg)  );
}
static void set_xmm_reg7(xmm_reg_t& xmm_reg)
{
    asm volatile("movdqu %0, %%xmm7" :  : "m" (xmm_reg) : "%xmm7"  );
} 
static void get_xmm_reg7(xmm_reg_t& xmm_reg)
{
    asm volatile("movdqu %%xmm7,%0" : "=m" (xmm_reg)  );
}
#ifdef TARGET_IA32E
static void set_xmm_reg8(xmm_reg_t& xmm_reg)
{
    asm volatile("movdqu %0, %%xmm8" :  : "m" (xmm_reg) : "%xmm8"  );
} 
static void get_xmm_reg8(xmm_reg_t& xmm_reg)
{
    asm volatile("movdqu %%xmm8,%0" : "=m" (xmm_reg)  );
}
static void set_xmm_reg9(xmm_reg_t& xmm_reg)
{
    asm volatile("movdqu %0, %%xmm9" :  : "m" (xmm_reg) : "%xmm9"  );
} 
static void get_xmm_reg9(xmm_reg_t& xmm_reg)
{
    asm volatile("movdqu %%xmm9,%0" : "=m" (xmm_reg)  );
}
static void set_xmm_reg10(xmm_reg_t& xmm_reg)
{
    asm volatile("movdqu %0, %%xmm10" :  : "m" (xmm_reg) : "%xmm10"  );
} 
static void get_xmm_reg10(xmm_reg_t& xmm_reg)
{
    asm volatile("movdqu %%xmm10,%0" : "=m" (xmm_reg)  );
}
static void set_xmm_reg11(xmm_reg_t& xmm_reg)
{
    asm volatile("movdqu %0, %%xmm11" :  : "m" (xmm_reg) : "%xmm11"  );
} 
static void get_xmm_reg11(xmm_reg_t& xmm_reg)
{
    asm volatile("movdqu %%xmm11,%0" : "=m" (xmm_reg)  );
}
static void set_xmm_reg12(xmm_reg_t& xmm_reg)
{
    asm volatile("movdqu %0, %%xmm12" :  : "m" (xmm_reg) : "%xmm12"  );
} 
static void get_xmm_reg12(xmm_reg_t& xmm_reg)
{
    asm volatile("movdqu %%xmm12,%0" : "=m" (xmm_reg)  );
}
static void set_xmm_reg13(xmm_reg_t& xmm_reg)
{
    asm volatile("movdqu %0, %%xmm13" :  : "m" (xmm_reg) : "%xmm13"  );
} 
static void get_xmm_reg13(xmm_reg_t& xmm_reg)
{
    asm volatile("movdqu %%xmm13,%0" : "=m" (xmm_reg)  );
}
static void set_xmm_reg14(xmm_reg_t& xmm_reg)
{
    asm volatile("movdqu %0, %%xmm14" :  : "m" (xmm_reg) : "%xmm14"  );
} 
static void get_xmm_reg14(xmm_reg_t& xmm_reg)
{
    asm volatile("movdqu %%xmm14,%0" : "=m" (xmm_reg)  );
}
static void set_xmm_reg15(xmm_reg_t& xmm_reg)
{
    asm volatile("movdqu %0, %%xmm15" :  : "m" (xmm_reg) : "%xmm15"  );
} 
static void get_xmm_reg15(xmm_reg_t& xmm_reg)
{
    asm volatile("movdqu %%xmm15,%0" : "=m" (xmm_reg)  );
}
#endif
#endif

static void
set_xmm_reg(xmm_reg_t& xmm_reg, UINT32 reg_no)
{

    switch (reg_no)
    {
    case 0:
        set_xmm_reg0(xmm_reg);
        break;
    case 1:
        set_xmm_reg1(xmm_reg);
        break;
    case 2:
        set_xmm_reg2(xmm_reg);
        break;
    case 3:
        set_xmm_reg3(xmm_reg);
        break;
    case 4:
        set_xmm_reg4(xmm_reg);
        break;
    case 5:
        set_xmm_reg5(xmm_reg);
        break;
    case 6:
        set_xmm_reg6(xmm_reg);
        break;
    case 7:
        set_xmm_reg7(xmm_reg);
        break;
#ifdef TARGET_IA32E
    case 8:
        set_xmm_reg8(xmm_reg);
        break;
    case 9:
        set_xmm_reg9(xmm_reg);
        break;
    case 10:
        set_xmm_reg10(xmm_reg);
        break;
    case 11:
        set_xmm_reg11(xmm_reg);
        break;
    case 12:
        set_xmm_reg12(xmm_reg);
        break;
    case 13:
        set_xmm_reg13(xmm_reg);
        break;
    case 14:
        set_xmm_reg14(xmm_reg);
        break;
    case 15:
        set_xmm_reg15(xmm_reg);
        break;
#endif
    }

} 
static void
get_xmm_reg(xmm_reg_t& xmm_reg, UINT32 reg_no)
{
    switch (reg_no)
    {
    case 0:
       get_xmm_reg0(xmm_reg);
       break;
    case 1:
        get_xmm_reg1(xmm_reg);
        break;
    case 2:
        get_xmm_reg2(xmm_reg);
        break;
    case 3:
        get_xmm_reg3(xmm_reg);
        break;
    case 4:
        get_xmm_reg4(xmm_reg);
        break;
    case 5:
        get_xmm_reg5(xmm_reg);
        break;
    case 6:
        get_xmm_reg6(xmm_reg);
        break;
    case 7:
        get_xmm_reg7(xmm_reg);
        break;
#ifdef TARGET_IA32E
    case 8:
        get_xmm_reg8(xmm_reg);
        break;
    case 9:
        get_xmm_reg9(xmm_reg);
        break;
    case 10:
        get_xmm_reg10(xmm_reg);
        break;
    case 11:
        get_xmm_reg11(xmm_reg);
        break;
    case 12:
        get_xmm_reg12(xmm_reg);
        break;
    case 13:
        get_xmm_reg13(xmm_reg);
        break;
    case 14:
        get_xmm_reg14(xmm_reg);
        break;
    case 15:
        get_xmm_reg15(xmm_reg);
        break;
#endif
    }

}


UINT32 init_sse(UINT32 z, UINT32 reg_no)
{

    xmm_reg_t xmm;
    xmm.dword[0] = z;
    xmm.dword[1] = 0;
    xmm.dword[2] = 0;
    xmm.dword[3] = 0;
    set_xmm_reg(xmm, reg_no); // from memory to register -- we modify the output using the tool
    get_xmm_reg(xmm, reg_no); // from register to memory
    return xmm.dword[0];
}

UINT32 read_sse(UINT32 reg_no)
{

    xmm_reg_t xmm;
    xmm.dword[0] = 0;
    xmm.dword[1] = 0;
    xmm.dword[2] = 0;
    xmm.dword[3] = 0;
    get_xmm_reg(xmm, reg_no); // from register to memory
    return xmm.dword[0];
}

#ifdef TARGET_IA32E
#define NUM_XMM_REGS 16
#else
#define NUM_XMM_REGS 8
#endif

int main(int argc, char** argv)
{
    //printf ("1 %d\n", atoi(argv[1]));
    //fflush (stdout);
    char buffer[512+16];
    char* aligned_bufp =reinterpret_cast<char*>(((reinterpret_cast<ADDRINT>(buffer) + 16) >> 4) << 4);
    
    UINT32 valsToSet[NUM_XMM_REGS];
    for (UINT32 i=0; i<NUM_XMM_REGS; i++)
    {
        valsToSet[i] = atoi(argv[1])+i; // atoi may set xmm regs
    } 

    for (UINT32 i=0; i<NUM_XMM_REGS; i++)
    {
        // set xmm reg#i to have the value of atoi(argv[1])+i
        init_sse(valsToSet[i], i);
    }
    
    // save current values of xmm regs using the fxsave instruction
#if defined(_MSC_VER)
    mmx_save(aligned_bufp);
#else
    asm("fxsave %0" : "=m"(*aligned_bufp));
#endif
 
    // make sure what was set is actually in the xmm regs, do this comaprison only after the fp state save above, to avoid any
    // xmm register sets that may be generated by the compiler.
    for (UINT32 i=0; i<NUM_XMM_REGS; i++)
    {
        UINT32 x = read_sse(i);
        //printf ("i: %d    x is %x  atoi(argv[1])+i is %x\n", i, x,  atoi(argv[1])+i);
        //fflush (stdout);
        if ( valsToSet[i]!=x)
        {
            cout << "ERROR during first init_sse\n";
            exit (-1);
        }
    }

    // now set to different values
    for (UINT32 i=0; i<NUM_XMM_REGS; i++)
    {
        // set xmm reg#i to have the value of atoi(argv[1])+(i*2)
        UINT32 x = init_sse(atoi(argv[1])+i*2, i);
        UINT32 y = read_sse(i);
        if (y!=x || atoi(argv[1])+i*2!=y)
        {
            cout << "ERROR during second init_sse\n";
            exit (-1);
        }
    }
    cout << endl;
    
    // restore the xmm regs to have the values they had when the above fxsave was done
#if defined(_MSC_VER)
    mmx_restore(aligned_bufp);
#else
    asm("fxrstor %0" : "=m"(*aligned_bufp));
#endif

    // check they indeed have the same values
    UINT32 readVals[NUM_XMM_REGS];
    // first do the all the reads
    for (UINT32 i=0; i<NUM_XMM_REGS; i++)
    {
        readVals[i] = read_sse(i);
    }
    // now do all the compares - so all the reads are done before any compare in order to avoid any xmm reg overwrite the 
    // compiler may generate for the compare code
    for (UINT32 i=0; i<NUM_XMM_REGS; i++)
    {
        if (valsToSet[i]!=readVals[i])
        {
            cout << "ERROR during sse restore\n";
            exit (-1);
        }
    }
    cout << "xmm registers saved and restored successfully\n";
    return 0;
}
