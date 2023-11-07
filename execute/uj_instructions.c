#include "./uj_instructions.h"

void jal(int * registry_bank, int instruction, int * program_counter) {
  int imm = UJ_IMMEDIATE(instruction);
  imm = -(imm & 0x100000) + (imm & 0xfffff);
  *(registry_bank + RSD(instruction)) = *program_counter;
  *program_counter += imm - 4;
}
