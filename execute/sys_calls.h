#include <stdio.h>
#include <string.h>
#include "./instruction_macros.h"

void ecall(int * registry_bank, int * kill, unsigned char * memory);

void print_string(int * registry_bank, unsigned char * memory);

void print_integer(int * registry_bank);
