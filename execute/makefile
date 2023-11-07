all: i_instructions.o instruction_macros.o r_instructions.o uj_instructions.o u_instructions.o s_instructions.o sb_instructions.o sys_calls.o

i_instructions.o: i_instructions.c i_instructions.h
	gcc -Wall -c i_instructions.c -o i_instructions.o

instruction_macros.o: instruction_macros.c instruction_macros.h
	gcc -Wall -c instruction_macros.c -o instruction_macros.o

r_instructions.o: r_instructions.c r_instructions.h
	gcc -Wall -c r_instructions.c -o r_instructions.o

s_instructions.o: s_instructions.c s_instructions.h
	gcc -Wall -c s_instructions.c -o s_instructions.o

sb_instructions.o: sb_instructions.c sb_instructions.h
	gcc -Wall -c sb_instructions.c -o sb_instructions.o

sys_calls.o: sys_calls.c sys_calls.h
	gcc -Wall -c sys_calls.c -o sys_calls.o

u_instructions.o: u_instructions.c u_instructions.h
	gcc -Wall -c u_instructions.c -o u_instructions.o

uj_instructions.o: uj_instructions.c uj_instructions.h
	gcc -Wall -c uj_instructions.c -o uj_instructions.o
