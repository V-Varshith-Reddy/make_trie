## Problem Statement
This assignment deals with the development of some utilities on English words, and has three components.    
• A library for storing and working with lists of strings: A trie is a popular and efficient data structure for this purpose. Prepare a shared library libtrie.so that implements some basic trie operations (initialize, search, insert, and list). Here, all strings consist only of lower-case roman letters a–z.    
• A library for some word-based utilities: Another shared library libwordutils.so is to be designed. This library uses a trie as a dictionary (to be interpreted as a word list) of English words (only those with lower-case letters). The dictionary is to be populated by reading the words from a text file words.txt to be supplied to you. The library should implement functions to investigate possibilities of new word generation by adding letters to the beginning and to the end of a string, and also by permuting the letters of a string. The two libraries should be built independently of one another.    
• Two application programs: The first application program maxchain.c is intended to find a longest chain of valid English words such that each word in the chain is obtained by appending a single letter at one of the two ends of the previous word in the chain. For example, the following chain consists of six valid English words. All single letters are considered valid words.     
o → or → ore → core → score → scored Here is a longer chain.    
t → at → ate → rate → irate → pirate → pirates    
The second application program subwords.c reads a string S from the user. Let l be the length of
S. The program finds and prints all (l − 1)-letter words that can be formed from the letters of S. For example, if the user enters osptp, then the valid 4-letter English subwords are
opts, post, pots, spot, stop, tops, pops.
Words like toss cannot be built from osptp (the input supplies only one s, whereas toss uses two).
The files in this assignment should be organized as follows. A brief description is provided here. Detailed explanations appear in the rest of this document. Stick to this organization strictly from the very beginning.
