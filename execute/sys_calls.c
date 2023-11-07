#include "./sys_calls.h"

void ecall(int * registry_bank, int * kill, unsigned char * memory) {
  switch (*(registry_bank + A7))
  {
  case 1:
    print_integer(registry_bank);
    break;
  case 4:
    print_string(registry_bank, memory);
    break;
  case 10:
    printf("\nexited successfully\n");
    *kill = 1;
    return;
  default:
    printf("syscall not found");
    break;
  }
}

void print_string(int * registry_bank, unsigned char * memory) {
  int string_pointer = *(registry_bank + A0);
  printf("%s", (memory + string_pointer));
}

void print_integer(int * registry_bank) {
  printf("%i", *(registry_bank + A0));
}
