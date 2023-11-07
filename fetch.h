#include <fcntl.h>
#include <inttypes.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <unistd.h>
#define MEM_SIZE 32768
#define CHUNK_SIZE 0x2000
unsigned char * load_mem();
