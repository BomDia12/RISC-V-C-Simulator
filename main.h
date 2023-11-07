#include <stdio.h>
#include "fetch.h"
#include "execute.h"
#define DATA_SEGMENT_START 0x2000
int main();

void run(int * program_counter, unsigned char * memory, int * registry_bank);
