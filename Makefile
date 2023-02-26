queue: main.c Queue.o
	gcc main.c Queue.o -o Queue.out
Queue.o:
	gcc -c Queue.c
clean:
	rm -f *.o
