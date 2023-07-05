libraries :
	cd trie ; make library 
	cd util ; make library

maxchain :
	cd apps ; make maxchain

subwords :
	cd apps ; make subwords

clean :
	cd trie ; make clean
	cd util ; make clean
	cd apps ; make clean
	