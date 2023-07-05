library : trie.o
	gcc -shared -o libtrie.so trie.o

trie.o  : trie.c
	gcc -c -I. -o trie.o trie.c

clean   :
	rm  trie.o libtrie.so
