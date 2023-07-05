#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>
#include <trie.h>


trie *trieinit()
{
    trie *p = (trie *)malloc(sizeof(trie));
    p->ROOT = (trienode *)malloc(sizeof(trienode));
    p->ROOT->c = '0';
    p->ROOT->first_child = NULL;
    p->ROOT->next_sibling = NULL;
    return p;
}

int triesearch(trienode *T, char *S)
{
    int index = 0;
    trienode *p = T->first_child;
    while (p != NULL)
    {
        if ((p)->c == S[index])
        {
            index++;
            if (S[index] == '\0')
            {

                if (p->is_end_of_word == 1)
                    return 1;
                else
                    return 0;
            }
            p = p->first_child;
        }
        else
        {
            p = p->next_sibling;
        }
    }
    if (S[index] == '\0')
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

trienode *trieinsert(trienode *T, char *S)
{
    trienode *p = T;
    int index = 0;
    int c = 0;
    while (1)
    {
        if (p->first_child == NULL)
        {
            trienode *final = (trienode *)malloc(sizeof(trienode));
            final->c = S[index];final->is_end_of_word=0;
            index++;
            final->next_sibling = NULL;
            final->first_child = NULL;
            if (S[index] == '\0')
            {
                final->is_end_of_word = 1;
                p->first_child = final;
                return T;
            }
            p->first_child = final;
            p = p->first_child;
        }
        if (p->first_child != NULL && (p->first_child)->c == S[index])
        {

            index++;

            if (S[index] == '\0')
            {
                (p->first_child)->is_end_of_word = 1;
                p = p->first_child;
                return T;
            }
            p = p->first_child;
        }
        else if (p->first_child != NULL && (p->first_child)->c > S[index])
        {

            trienode *ptr = p->first_child;
            trienode *new = (trienode *)malloc(sizeof(trienode));
            new->c = S[index];new->is_end_of_word=0;
            new->first_child = NULL;
            new->next_sibling = ptr;
            p->first_child = new;

            index++;
            if (S[index] == '\0')
            {
                new->is_end_of_word = 1;
                p = p->first_child;
                return T;
            }

            p = p->first_child;
        }
        else if (p->first_child != NULL)
        {

            trienode *new = (trienode *)malloc(sizeof(trienode));
            p = p->first_child;
            while (p->next_sibling != NULL)
            {
                // if ((p->next_sibling)->c  S[index])
                // {
                //     index++;
                //     if (S[index] == '\0')
                //     {
                //         (p->next_sibling)->is_end_of_word = 1;
                //         return T;
                //     }
                //     p = p->next_sibling;
                // }
                if (p->next_sibling->c >= S[index])
                {

                    break;
                }

                p = p->next_sibling;
            }
            if (p->next_sibling == NULL)
            {

                trienode *new = (trienode *)malloc(sizeof(trienode));
                p->next_sibling = new;
                new->c = S[index];new->is_end_of_word=0;
                new->first_child = NULL;
                new->next_sibling = NULL;
                index++;

                if (S[index] == '\0')
                {

                    new->is_end_of_word = 1;
                    return T;
                }
                p = new;
                // while (S[index] != '\0')
                // {
                //     printf("8\n");
                //     trienode *new = (trienode *)malloc(sizeof(trienode));
                //     new->c = S[index];
                //     index++;
                //     p->first_child = new;
                //     new->next_sibling = NULL;
                //     new->first_child = NULL;
                //     new->is_end_of_word = 0;
                //     if (S[index] == '\0')
                //     {
                //         printf("9\n");
                //         new->is_end_of_word = 1;
                //         return T;
                //     }
                // }
            }
            else if (p->next_sibling->c == S[index])
            {

                p = p->next_sibling;
                index++;
                if (S[index] == '\0')
                {
                    p->is_end_of_word = 1;
                    return T;
                }
            }
            else
            {

                trienode *newnode = (trienode *)malloc(sizeof(trienode));
                newnode->c = S[index];newnode->is_end_of_word=0;
                index++;
                newnode->first_child = NULL;
                trienode *q = p->next_sibling;
                newnode->next_sibling = q;
                p->next_sibling = newnode;
                if (S[index] == '\0')
                {
                    newnode->is_end_of_word = 1;
                    return T;
                }
                p = newnode;
            }
        }
    }
}

void listALL(trienode* p,char string[],int index){

    while (p != NULL)
    {
        string[index] = p->c;
        if(p->is_end_of_word){
            string[index+1] = '\0';
            printf("%s\n",string);
        }
        listALL(p->first_child,string,index+1);
        p = p->next_sibling;
    }
}
void listall(trienode* T){
    char string[50];string[0]='\0';
    int index = 0;
    if(T->first_child == NULL){
        printf("No strings are present in the trie\n");
    }
    else
    {
        listALL(T->first_child,string,index);
    }
    
}

char* addbefore(trie* D,char* S){
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
    return str;
}
char* addafter(trie* D,char* S){
    char* str = (char*)malloc(27*sizeof(char));
    int count = 0;
    int len = strlen(S);
    char temp[len+2];
    temp[len] = '_';
    temp[len+1] = '\0';
    for (int i = 0; i < len ; i++)
    {
        temp[i] = S[i];
    }
    for (int i = 0; i < 26; i++)
    {
        temp[len] = 'a'+i;
        if(triesearch(D->ROOT,temp)){
            str[count] = 'a'+i;
            count++;
        }
    }
    return str;
}


void permutations(){
    
}
char** anagram(trie* D,char* S){

    char** list = malloc(10000000*sizeof(char*));
    char freq[26];
    for (int i = 0; i < 26; i++)
    {
        freq[i] = 0;
    }
    for (int i = 0; i < strlen(S); i++)
    {
        freq[S[i]-'a']++;
    }
    int count = 0;
}
// int main()
// {
//     trie *T = trieinit();
//     char S[5];
//     S[0] = 't';
//     S[1] = 'e';
//     S[2] = 'j';
//     S[3] = 'a';
//     S[4] = '\0';
//     char s[4] = "air";
//     trieinsert(T->ROOT, S);
//     trieinsert(T->ROOT, s);

//     char aero[100];
//     strcpy(aero, "airplane");
//     trieinsert(T->ROOT, aero);
//     strcpy(aero, "airhostress");
//     trieinsert(T->ROOT, aero);

//     strcpy(aero, "ball");
//     trieinsert(T->ROOT, aero);
//     strcpy(aero, "tejas");
//     trieinsert(T->ROOT, aero);
//     strcpy(aero, "lafoot_karthikeya");
//     trieinsert(T->ROOT, aero);
//     strcpy(aero, "zack");
//     trieinsert(T->ROOT, aero);
//     strcpy(aero,"eja");
//     trieinsert(T->ROOT,aero);
//     strcpy(aero,"tejal");
//     trieinsert(T->ROOT,aero);
//     strcpy(aero,"seja");
//     trieinsert(T->ROOT,aero);
//     strcpy(aero,"singabattu");
//     trieinsert(T->ROOT,aero);
//     strcpy(aero,"sing");
//     trieinsert(T->ROOT,aero);
    
//     trienode *p = T->ROOT->first_child->next_sibling->next_sibling->next_sibling->next_sibling;
//     printf("listall  :\n");
//     listall(T->ROOT);
    
//     //printf("addbefore = %s\n",addbefore(T,"eja"));
//     // printf("\n");
//     // printf("st = %d\n",triesearch(T->ROOT,"st"));
//     // printf("sot = %d\n",triesearch(T->ROOT,"sot"));
//     // printf("tos = %d\n",triesearch(T->ROOT,"tos"));
//     // printf("stop = %d\n",triesearch(T->ROOT,"stop"));
//     // printf("spot = %d\n",triesearch(T->ROOT,"spot"));
    
// }
