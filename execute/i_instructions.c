#include "./i_instructions.h"

void jalr(int * registry_bank, int instruction, int * program_counter) {
  *(registry_bank + RSD(instruction)) = *program_counter;
  *program_counter = (I_IMMEDIATE(instruction) + *(registry_bank + RS1(instruction)));
}

void lb(int * registry_bank, int instruction, unsigned char * memory) {
  int memory_address = *(registry_bank + RS1(instruction)) + I_IMMEDIATE(instruction);
  *(registry_bank + RSD(instruction)) = EXTEND_BYTE_SIGN(*(memory + memory_address));
}

void lh(int * registry_bank, int instruction, unsigned char * memory) {
  int memory_address = *(registry_bank + RS1(instruction)) + I_IMMEDIATE(instruction);
  int value = (*(memory + memory_address + 1) << 8) + *(memory + memory_address);
  *(registry_bank + RSD(instruction)) = EXTEND_HALF_SIGN(value);
}

void lw(int * registry_bank, int instruction, unsigned char * memory) {
  int memory_address = *(registry_bank + RS1(instruction)) + I_IMMEDIATE(instruction);
  int value = (*(memory + memory_address + 3) << 24) + (*(memory + memory_address + 2) << 16) + (*(memory + memory_address + 1) << 8) + *(memory + memory_address);
  *(registry_bank + RSD(instruction)) = value;
}

void lbu(int * registry_bank, int instruction, unsigned char * memory) {
  int memory_address = *(registry_bank + RS1(instruction)) + I_IMMEDIATE(instruction);
  *(registry_bank + RSD(instruction)) = *(memory + memory_address);
}

void lhu(int * registry_bank, int instruction, unsigned char * memory) {
  int memory_address = *(registry_bank + RS1(instruction)) + I_IMMEDIATE(instruction);
  int value = (*(memory + memory_address + 1) << 8) + *(memory + memory_address);
  *(registry_bank + RSD(instruction)) = value;
}

void addi(int * registry_bank, int instruction) {
  *(registry_bank + RSD(instruction)) = *(registry_bank + RS1(instruction)) + I_IMMEDIATE(instruction);
}

void slti(int * registry_bank, int instruction) {
  if (*(registry_bank + RS1(instruction)) < I_IMMEDIATE(instruction)) {
    *(registry_bank + RSD(instruction)) = 1;
  } else {
    *(registry_bank + RSD(instruction)) = 0;
  }
}

void sltiu(int * registry_bank, int instruction) {
  if (*(registry_bank + RS1(instruction)) < (unsigned) I_IMMEDIATE(instruction)) {
    *(registry_bank + RSD(instruction)) = 1;
  } else {
    *(registry_bank + RSD(instruction)) = 0;
  }
}

void xori(int * registry_bank, int instruction) {
  *(registry_bank + RSD(instruction)) = *(registry_bank + RS1(instruction)) ^ I_IMMEDIATE(instruction);
}

void ori(int * registry_bank, int instruction) {
  *(registry_bank + RSD(instruction)) = *(registry_bank + RS1(instruction)) | I_IMMEDIATE(instruction);
}

void andi(int * registry_bank, int instruction) {
  *(registry_bank + RSD(instruction)) = *(registry_bank + RS1(instruction)) & I_IMMEDIATE(instruction);
}

void slli(int * registry_bank, int instruction) {
  *(registry_bank + RSD(instruction)) = *(registry_bank + RS1(instruction)) << SHIFT_IMMEDIATE(instruction);
}

void srli(int * registry_bank, int instruction) {
  *(registry_bank + RSD(instruction)) = ((unsigned) *(registry_bank + RS1(instruction))) >> SHIFT_IMMEDIATE(instruction);
}

void srai(int * registry_bank, int instruction) {
  *(registry_bank + RSD(instruction)) = *(registry_bank + RS1(instruction)) >> SHIFT_IMMEDIATE(instruction);
}
