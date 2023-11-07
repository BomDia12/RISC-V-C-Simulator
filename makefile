all: fetch.o execute.o
	+$(MAKE) -C execute
	gcc -Wall ./*/*.o ./*.o ./main.c -o main.exe

fetch.o: fetch.c fetch.h
	gcc -Wall -c fetch.c -o fetch.o

execute.o: execute.c execute.h
	gcc -Wall -c execute.c -o execute.o

clean:
	rm -rf ./*.o ./*.exe ./**/*.o
