library : dictload.o dictutils.o
	gcc -shared -o libwordutils.so dictload.o dictutils.o
dictload.o : dictload.c
	gcc -c -I. -I../trie -o dictload.o dictload.c
dictutils.o : dictutils.c
	gcc -c -I. -I../trie -o dictutils.o dictutils.c

clean :
	rm libwordutils.so dictload.o dictutils.o