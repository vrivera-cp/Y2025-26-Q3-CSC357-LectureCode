# Variable for gcc flags
CFLAGS = -g -Wall --pedantic

# Default (First) Target
program: program.c add.c
	gcc ${CFLAGS} program.c add.c -o program

# Often used to remove target(s)
clean:
	rm program
