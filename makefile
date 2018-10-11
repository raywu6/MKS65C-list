all: llist.o
	gcc driver.c llist.o

run: all
	./a.out

llist.o: llist.c llist.h
	gcc -c llist.c

test.o: driver.c llist.h
	gcc -c driver.c

clean:
	rm *~ *.gch* a.out *.o
