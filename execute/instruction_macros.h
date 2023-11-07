#ifndef INSTRUCTIONS_MACRO
#define INSTRUCTIONS_MACRO

// Removing information from instruction
#define OPCODE(a)(a & 0x7f)
#define FUNCT3(a)((a >> 12) & 0x7 )
#define FUNCT7(a)((a >> 25) & 0x7f)
#define RS1(a)   ((a >> 15) & 0x1f)
#define RS2(a)   ((a >> 20) & 0x1f)
#define RSD(a)   ((a >>  7) & 0x1f)

// Registry bank Addresses
#define A0 10
#define A7 17

#endif
