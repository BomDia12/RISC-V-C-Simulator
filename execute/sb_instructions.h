#include "./instruction_macros.h"
#include <stdio.h>
#define SB_IMMEDIATE(a)(((a >> 7) & 0x1e) + ((a >> 20) & 0x7e0) + ((a << 4) & 0x800) + ((a >> 19) & 0x1000))

void beq(int * registry_bank, int instruction, int * program_counter);

void bne(int * registry_bank, int instruction, int * program_counter);

void blt(int * registry_bank, int instruction, int * program_counter);

void bge(int * registry_bank, int instruction, int * program_counter);

void bltu(int * registry_bank, int instruction, int * program_counter);

void bgeu(int * registry_bank, int instruction, int * program_counter);
