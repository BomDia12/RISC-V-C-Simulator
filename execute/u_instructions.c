#include "./u_instructions.h"

void lui(int * registry_bank, int instruction) {
  *(registry_bank + RSD(instruction)) = U_IMMEDIATE(instruction);
}

void auipc(int * registry_bank, int instruction, int * program_counter) {
  *(registry_bank + RSD(instruction)) = (*program_counter - 4) + U_IMMEDIATE(instruction);
}
