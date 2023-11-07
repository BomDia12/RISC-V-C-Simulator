#include "./instruction_macros.h"

void add(int * registry_bank, int instruction) {
  *(registry_bank + RSD(instruction)) = *(registry_bank + RS1(instruction)) + *(registry_bank + RS2(instruction));
}

void sub(int * registry_bank, int instruction) {
  *(registry_bank + RSD(instruction)) = *(registry_bank + RS1(instruction)) - *(registry_bank + RS2(instruction));
}

void sll(int * registry_bank, int instruction) {
  *(registry_bank + RSD(instruction)) = *(registry_bank + RS1(instruction)) << *(registry_bank + RS2(instruction));
}

void slt(int * registry_bank, int instruction) {
  if (*(registry_bank + RS1(instruction)) < *(registry_bank + RS2(instruction))) {
    *(registry_bank + RSD(instruction)) = 1;
  } else {
    *(registry_bank + RSD(instruction)) = 0;
  }
}

void sltu(int * registry_bank, int instruction) {
  if (*(registry_bank + RS1(instruction)) < (unsigned) *(registry_bank + RS2(instruction))) {
    *(registry_bank + RSD(instruction)) = 1;
  } else {
    *(registry_bank + RSD(instruction)) = 0;
  }
}

void r_xor(int * registry_bank, int instruction) {
  *(registry_bank + RSD(instruction)) = *(registry_bank + RS1(instruction)) ^ *(registry_bank + RS2(instruction));
}

void srl(int * registry_bank, int instruction) {
  *(registry_bank + RSD(instruction)) = *(registry_bank + RS1(instruction)) >> (unsigned) *(registry_bank + RS2(instruction));
}

void sra(int * registry_bank, int instruction)  {
  *(registry_bank + RSD(instruction)) = *(registry_bank + RS1(instruction)) >> *(registry_bank + RS2(instruction));
}

void r_or(int * registry_bank, int instruction) {
  *(registry_bank + RSD(instruction)) = *(registry_bank + RS1(instruction)) | *(registry_bank + RS2(instruction));
}

void r_and(int * registry_bank, int instruction) {
  *(registry_bank + RSD(instruction)) = *(registry_bank + RS1(instruction)) & *(registry_bank + RS2(instruction));
}
