turing : run.o  tape.o command.o tur.o
	gcc -o turing tur.o  tape.o command.o run.o

run.o : run.c
	gcc -std=c11 -pedantic -Wall -Wextra -c -o run.o run.c

tape.o : tape.c
	gcc -std=c11 -pedantic -Wall -Wextra -c -o tape.o tape.c

tur.o : tur.c
	gcc -std=c11 -pedantic -Wall -Wextra -c -o tur.o tur.c

command.o : command.c
	gcc -std=c11 -pedantic -Wall -Wextra -c -o command.o command.c
