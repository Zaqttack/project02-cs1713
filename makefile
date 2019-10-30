output: main.o airlinestats.o
	gcc main.o airlinestats.o -o program

main.o: main.c main.h airlinestats.h
	gcc -c main.c

airlinestats.o: airlinestats.c airlinestats.h
	gcc -c airlinestats.c

clean:
	rm *.o program
