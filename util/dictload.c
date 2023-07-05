#include <stdio.h>
#include<stdlib.h>
#include <dictutils.h>

dict *loaddfltdict()
{
    FILE *fp = fopen("../dict/words.txt", "r");
    char *string = (char*)malloc(100);
    dict *dictionary = trieinit();
    while(!feof(fp))
    {
        fscanf(fp, "%s", string);
        trieinsert(dictionary->ROOT, string);
    }
    // printf("list completed\n");
    free(string);
    fclose(fp);
    // listall(dictionary->ROOT);
    return dictionary;
}

dict *loaddict(char * path)
{
    FILE *fp = fopen(path, "r");
    char *string = (char*)malloc(100);
    dict *dictionary = trieinit();
    while(!feof(fp))
    {
        fscanf(fp, "%s", string);
        trieinsert(dictionary->ROOT, string);
    }
    free(string);
    fclose(fp);
    return dictionary;
}	


