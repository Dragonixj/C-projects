CC=gcc 
FLAGS=-g -Wall -Werror -Wextra -pedantic -std=c11
FILE= 

.PHONY: simpleshell.o simple_shell

all: simpleshell.o
	${CC} simple_shell.o -o simple_shell

simpleshell.o: ${FILE}
	${CC} -c ${FILE} ${FLAGS} -o simpleshell.o 

clean:
	@touch a.o simple_shell 
	rm *.o simple_shell 
