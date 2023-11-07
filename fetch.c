#include "fetch.h"

unsigned char * load_mem() {
  static unsigned char memory[MEM_SIZE];
  FILE* instructions;

  instructions = fopen("instructions", "rb");
  fread(memory, MEM_SIZE, 1, instructions);
  fclose(instructions);

  FILE* data;

  data = fopen("data", "rb");
  fread((memory + CHUNK_SIZE), MEM_SIZE, 1, data);
  fclose(data);

  return memory;
}
