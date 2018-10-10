all: llist.o
	gcc llist.o

run:
	./a.out

llist.o: llist.c llist.h
	gcc -c llist.c llist.h

clean:
	rm *~ *.gch* a.out *.o
