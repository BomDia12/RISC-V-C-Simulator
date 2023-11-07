#include "./s_instructions.h"

void sb(int * registry_bank, int instruction, unsigned char * memory) {
  int memory_address = S_IMMEDIATE(instruction) + *(registry_bank + RS1(instruction));
  int value_to_be_stored = *(registry_bank + RS2(instruction)) & 0xff;
  *(memory + memory_address) = value_to_be_stored;
}

void sh(int * registry_bank, int instruction, unsigned char * memory) {
  int memory_address = S_IMMEDIATE(instruction) + *(registry_bank + RS1(instruction));
  int byte1 = *(registry_bank + RS2(instruction)) & 0xff;
  int byte2 = (*(registry_bank + RS2(instruction)) & 0xff00) >> 8;
  *(memory + memory_address + 1) = byte2;
  *(memory + memory_address) = byte1;
}

void sw(int * registry_bank, int instruction, unsigned char * memory) {
  int memory_address = S_IMMEDIATE(instruction) + *(registry_bank + RS1(instruction));
  int word_to_store = *(registry_bank + RS2(instruction));
  int byte1 = word_to_store & 0xff;
  int byte2 = (word_to_store & 0xff00) >> 8;
  int byte3 = (word_to_store & 0xff0000) >> 16;
  int byte4 = (word_to_store & 0xff000000) >> 24;
  *(memory + memory_address + 3) = byte4;
  *(memory + memory_address + 2) = byte3;
  *(memory + memory_address + 1) = byte2;
  *(memory + memory_address) = byte1;
}
