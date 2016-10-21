tunez: linked_list.o library.o main.o
	gcc -g linked_list.o library.o main.o -o tunez

linked_list.o: linked_list.c linked_list.h
	gcc -g -c linked_list.c

library.o: library.c library.h
	gcc -g -c library.c

main.o: main.c library.h
	gcc -g -c main.c

run: tunez
	./tunez

debug: tunez
	gdb tunez

clean:
	rm *~; rm *.o