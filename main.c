#include "main.h"

int main() {
  printf("\n --- Simulating Risc-V processor ---\n\n");
  unsigned char * memory;
  memory = load_mem();

  static int registry_bank[32];
  int program_counter = 0;

  run(&program_counter, memory, registry_bank);

  return 0;
}

void run(int * program_counter, unsigned char * memory, int * registry_bank) {
  int kill = 0;
  while (*program_counter < DATA_SEGMENT_START && kill == 0) {
    execute(program_counter, memory, registry_bank, &kill);
  }
  printf("\n%s\n", (memory + 0x20012));
}