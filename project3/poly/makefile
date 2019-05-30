CC	= gcc
CFLAGS	= -std=c11 -pedantic -Wall -Werror -g -fno-inline
OUT	= a.out
FILE	= poly

execute: compile
	$(OUT) < input > output
	diff output correct

compile: clean $(FILE).o main.o
	$(CC) $(CFLAGS) -o $(OUT) $(FILE).o main.o

clean:
	rm -f *.s *.o $(OUT)
