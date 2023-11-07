#include "instruction_macros.h"
#include <stdio.h>
#define U_IMMEDIATE_EXTEND_SIGN(a)(-(a & 0x80000000) + (a & 0x7fffffff))
#define U_IMMEDIATE(a)(a & 0xfffff000)
void lui(int * registry_bank, int instruction);
void auipc(int * registry_bank, int instruction, int * program_counter);
