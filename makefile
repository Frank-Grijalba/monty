main:
	gcc -g -Wall -Werror -Wextra -pedantic *.c -o monty
gdb: main
	gdb ./monty
valgrind: main
	valgrind --leak-check=full --track-origins=yes --show-leak-kinds=all ./monty
0: main
	./monty bytecodes/00.m
1: main
	./monty bytecodes/06.m
2: main
	./monty bytecodes/07.m
3: main
	./monty bytecodes/09.m
4: main
	./monty bytecodes/12.m
prueba: main
	./monty bytecodes/prueba.m