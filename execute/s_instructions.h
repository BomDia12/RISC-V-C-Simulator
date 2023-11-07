#include "./instruction_macros.h"
#include <stdio.h>
#define EXTEND_S_IMMEDIATE_SIGN(a)(((a & 0x800) == 0x800) ? -a : a)
#define S_IMMEDIATE(a)(EXTEND_S_IMMEDIATE_SIGN(((a >> 7) & 0x1f) + ((a >> 20) & 0xfe0)))

void sb(int * registry_bank, int instruction, unsigned char * memory);

void sh(int * registry_bank, int instruction, unsigned char * memory);

void sw(int * registry_bank, int instruction, unsigned char * memory);
