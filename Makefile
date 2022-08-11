money: menu.o main.o
	gcc -Wall -std=c99 menu.o main.o -o money

menu.o: menu.c header.h
	gcc -Wall -std=c99 -c menu.c

main.o: main.c header.h
	gcc -Wall -std=c99 -c main.c

clean:
	rm *.o money
