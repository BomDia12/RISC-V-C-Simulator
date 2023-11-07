#include "execute.h"
void execute(int * program_counter, unsigned char * memory, int * registry_bank, int * kill) {
  *registry_bank = 0;
  int instruction = (*(memory + *program_counter + 3) << 24) + (*(memory + *program_counter + 2) << 16) + (*(memory + *program_counter + 1) << 8) + *(memory + *program_counter);
  (*program_counter) += 4;
  int opcode = OPCODE(instruction);
  switch (opcode) {
  case 0b0110111:
    lui(registry_bank, instruction);
    break;
  case 0b0010111:
    auipc(registry_bank, instruction, program_counter);
    break;
  case 0b1101111:
    jal(registry_bank, instruction, program_counter);
    break;
  case 0b1100111:
    jalr(registry_bank, instruction, program_counter);
    break;
  case 0b1100011:
    select_b_instruction(registry_bank, instruction, program_counter);
    break;
  case 0b0000011:
    select_load_instruction(registry_bank, instruction, memory);
    break;
  case 0b0100011:
    select_store_instruction(registry_bank, instruction, memory);
    break;
  case 0b0010011:
    select_I_instruction(registry_bank, instruction);
    break;
  case 0b0110011:
    select_R_instruction(registry_bank, instruction);
    break;
  case 0b1110011:
    ecall(registry_bank, kill, memory);
    break;
  default:
    printf("\n%i\n", *program_counter);
    printf("opcode not found\n");
    *kill = 1;
    return;
  }
}

void select_b_instruction(int * registry_bank, int instruction, int * program_counter) {
  int func3 = FUNCT3(instruction);
  switch (func3) {
  case 0b000:
    beq(registry_bank, instruction, program_counter);
    break;
  case 0b001:
    bne(registry_bank, instruction, program_counter);
    break;
  case 0b100:
    blt(registry_bank, instruction, program_counter);
    break;
  case 0b101:
    bge(registry_bank, instruction, program_counter);
    break;
  case 0b110:
    bltu(registry_bank, instruction, program_counter);
    break;
  case 0b111:
    bgeu(registry_bank, instruction, program_counter);
    break;
  default:
    printf("B instruction not found");
    break;
  }
}

void select_load_instruction(int * registry_bank, int instruction, unsigned char * memory) {
  int func3 = FUNCT3(instruction);
  switch (func3) {
  case 0b000:
    lb(registry_bank, instruction, memory);
    break;
  case 0b001:
    lh(registry_bank, instruction, memory);
    break;
  case 0b010:
    lw(registry_bank, instruction, memory);
    break;
  case 0b100:
    lbu(registry_bank, instruction, memory);
    break;
  case 0b101:
    lhu(registry_bank, instruction, memory);
    break;
  default:
    printf("Load instruction not found");
    break;
  }
}

void select_store_instruction(int * registry_bank, int instruction, unsigned char * memory) {
  int func3 = FUNCT3(instruction);
  switch (func3) {
  case 0b000:
    sb(registry_bank, instruction, memory);
    break;
  case 0b001:
    sh(registry_bank, instruction, memory);
    break;
  case 0b010:
    sw(registry_bank, instruction, memory);
    break;
  default:
    printf("store instruction not found");
    break;
  }
}

void select_I_instruction(int * registry_bank, int instruction) {
  int func3 = FUNCT3(instruction);
  int func7 = FUNCT7(instruction);
  switch (func3) {
  case 0b000:
    addi(registry_bank, instruction);
    break;
  case 0b010:
    slti(registry_bank, instruction);
    break;
  case 0b011:
    sltiu(registry_bank, instruction);
    break;
  case 0b100:
    xori(registry_bank, instruction);
    break;
  case 0b110:
    ori(registry_bank, instruction);
    break;
  case 0b111:
    andi(registry_bank, instruction);
    break;
  case 0b001:
    slli(registry_bank, instruction);
    break;
  case 0b101:
    if(func7 == 0b0100000) {
      srai(registry_bank, instruction);
      break;
    }
    srli(registry_bank, instruction);
    break;
  default:
    printf("I instruction not found");
    break;
  }
}

void select_R_instruction(int * registry_bank, int instruction) {
  int func3 = FUNCT3(instruction);
  int func7 = FUNCT7(instruction);
  switch (func3) {
  case 0b000:
    if (func7 == 0b0100000) {
      sub(registry_bank, instruction);
      break;
    }
    add(registry_bank, instruction);
    break;
  case 0b010:
    slt(registry_bank, instruction);
    break;
  case 0b011:
    sltu(registry_bank, instruction);
    break;
  case 0b100:
    r_xor(registry_bank, instruction);
    break;
  case 0b110:
    r_or(registry_bank, instruction);
    break;
  case 0b111:
    r_and(registry_bank, instruction);
    break;
  case 0b001:
    sll(registry_bank, instruction);
    break;
  case 0b101:
    if(func7 == 0b0100000) {
      sra(registry_bank, instruction);
      break;
    }
    srl(registry_bank, instruction);
    break;
  default:
    printf("I instruction not found");
    break;
  }
}
