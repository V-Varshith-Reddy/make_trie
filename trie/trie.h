typedef struct trienode
{
    char c;
    int is_end_of_word;
    struct trienode *next_sibling;
    struct trienode *first_child;
} trienode;

typedef struct trie
{
    trienode *ROOT;
} trie;

trie *trieinit();
int triesearch(trienode *T, char *S);
trienode *trieinsert(trienode *T, char *S);
void listall(trienode* p);
