#include "./instruction_macros.h"
#include <stdio.h>
#define UJ_IMMEDIATE(a)(((a >> 20) & 0x7fe) + ((a >> 9) & 0x800) + (a & 0xff000) + ((a >> 11) & 0x100000))

void jal(int * registry_bank, int instruction, int * program_counter);