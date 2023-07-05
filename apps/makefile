maxchain : maxchain.c
	gcc  -I../util -I../trie -L../trie -L../util maxchain.c -lwordutils -ltrie
	export LD_LIBRARY_PATH="../util;../trie" ; ./a.out

subwords : subwords.c
	gcc  -I../util -I../trie -L../trie -L../util subwords.c -lwordutils -ltrie
	export LD_LIBRARY_PATH="../util;../trie" ; ./a.out
clean : 
	rm a.out