#include "./sb_instructions.h"

void beq(int * registry_bank, int instruction, int * program_counter) {
  if (*(registry_bank + RS1(instruction)) == *(registry_bank + RS2(instruction))) {
    *program_counter += SB_IMMEDIATE(instruction) - 4;
  }
}

void bne(int * registry_bank, int instruction, int * program_counter) {
  if (*(registry_bank + RS1(instruction)) != *(registry_bank + RS2(instruction))) {
    *program_counter += SB_IMMEDIATE(instruction) - 4;
  }
}

void blt(int * registry_bank, int instruction, int * program_counter) {
  if (*(registry_bank + RS1(instruction)) < *(registry_bank + RS2(instruction))) {
    *program_counter += SB_IMMEDIATE(instruction) - 4;
  }
}

void bge(int * registry_bank, int instruction, int * program_counter) {
  if (*(registry_bank + RS1(instruction)) >= *(registry_bank + RS2(instruction))) {
    *program_counter += SB_IMMEDIATE(instruction) - 4;
  }
}

void bltu(int * registry_bank, int instruction, int * program_counter) {
  if (*(registry_bank + RS1(instruction)) < (unsigned) *(registry_bank + RS2(instruction))) {
    *program_counter += SB_IMMEDIATE(instruction) - 4;
  }
}

void bgeu(int * registry_bank, int instruction, int * program_counter) {
  int v1 = *(registry_bank + RS1(instruction));
  unsigned int v2 = *(registry_bank + RS2(instruction));
  if (v1 >= v2) {
    *program_counter += SB_IMMEDIATE(instruction) - 4;
  }
}
