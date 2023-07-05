#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <dictutils.h>

char *addafter(dict *D, char *S)
{
    char *str = (char *)malloc(27 * sizeof(char));
    int count = 0;
    int len = strlen(S);
    char temp[len + 2];
    temp[len] = '_';
    temp[len + 1] = '\0';
    for (int i = 0; i < len; i++)
    {
        temp[i] = S[i];
    }
    for (int i = 0; i < 26; i++)
    {
        temp[len] = 'a' + i;
        // printf("%s\n",temp);
        if (triesearch(D->ROOT, temp))
        {
            str[count] = 'a' + i;
            count++;
        }
    }
    str[count]='\0';
    return str;
}


char* addbefore(dict *D,char* S){
    char* str = (char*)malloc(27*sizeof(char));
    int count = 0;
    int len = strlen(S);
    char temp[len+2];
    temp[len+1] = '\0';
    temp[0] = '_';
    for (int i = 0; i < len; i++)
    {
        temp[i+1] = S[i];
    }
    for (int i = 0; i < 26; i++)
    {
        temp[0] = 'a' + i;
        if (triesearch(D->ROOT,temp))
        {
            str[count] = 'a' + i;
            count++;
        }
    }
    str[count]='\0';
    return str;
}

void swap(char* x,char* y){
    char temp;
    temp = *x;
    *x = *y;
    *y = temp;
}

void permute(dict* D,char** LIST,dict* T,char* A,int l,int r,int index[]){

    if(l == r){
        if (triesearch(D->ROOT,A) == 1)
        {
            // trieinsert(D,A);
            // LIST[*index] = A;
            // *(index)++;
            if (triesearch(T->ROOT,A) == 0)
            {
                // printf("%s ","Accepted");
                trieinsert(T->ROOT,A);
                LIST[index[0]] = (char*)malloc(50);
                strcpy(LIST[index[0]],A);
                (index[0])++;
            }   
        }
        // printf("%s\n",A);
    }
    else
    {
        for(int i=l;i <= r;i++){
            swap(A+l,A+i);
            permute(D,LIST,T,A,l+1,r,index);
            swap(A+l,A+i);
        }
    }
    
}

char** anagrams(dict* D,char* S){
    char** LIST = (char**)malloc(sizeof(char*)*1000000);
    dict* T = trieinit();
    int k = strlen(S);
    int index[1]; index[0]=0;
    permute(D,LIST,T,S,0,k-1,index);
    LIST[index[0]] = NULL;
    return LIST;
}