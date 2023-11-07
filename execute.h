#include <stdio.h>
#include "./execute/i_instructions.h"
#include "./execute/instruction_macros.h"
#include "./execute/r_instructions.h"
#include "./execute/s_instructions.h"
#include "./execute/sb_instructions.h"
#include "./execute/sys_calls.h"
#include "./execute/u_instructions.h"
#include "./execute/uj_instructions.h"

void execute(int * program_counter, unsigned char * memory, int * registry_bank, int * kill);

void select_b_instruction(int * registry_bank, int instruction, int * program_counter);

void select_load_instruction(int * registry_bank, int instruction, unsigned char * memory);

void select_store_instruction(int * registry_bank, int instruction, unsigned char * memory);

void select_I_instruction(int * registry_bank, int instruction);

void select_R_instruction(int * registry_bank, int instruction);
