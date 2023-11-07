#include "./instruction_macros.h"
#include <stdio.h>
#define EXTEND_IMMEDIATE_SIGN(a)(((a & 0x800) == 0x800) ? -(-a) : a)
#define EXTEND_BYTE_SIGN(a)(((a & 0x80) == 0x80) ? a + (unsigned) 0xffffff00 : a)
#define EXTEND_HALF_SIGN(a)(((a & 0x8000) == 0x8000) ? -a : a)
#define I_IMMEDIATE(a)(EXTEND_IMMEDIATE_SIGN((a >> 20) & 0xfff))
#define SHIFT_IMMEDIATE(a)(RS2(a))

void jalr(int * registry_bank, int instruction, int * program_counter);

void lb(int * registry_bank, int instruction, unsigned char * memory);

void lh(int * registry_bank, int instruction, unsigned char * memory);

void lw(int * registry_bank, int instruction, unsigned char * memory);

void lbu(int * registry_bank, int instruction, unsigned char * memory);

void lhu(int * registry_bank, int instruction, unsigned char * memory);

void addi(int * registry_bank, int instruction);

void slti(int * registry_bank, int instruction);

void sltiu(int * registry_bank, int instruction);

void xori(int * registry_bank, int instruction);

void ori(int * registry_bank, int instruction);

void andi(int * registry_bank, int instruction);

void slli(int * registry_bank, int instruction);

void srli(int * registry_bank, int instruction);

void srai(int * registry_bank, int instruction);
