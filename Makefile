build: main.o
	gcc -o add-nbo main.o

main.o: main.c
	gcc -c main.c

clean:
	rm -f *.o add-nbo