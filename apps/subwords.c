#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<string.h>
#include <wordutils.h>

void subwords(dict* D,char *S)
{
    int k = strlen(S);
    char s[k];
    int freq[26];
    for (int i = 0; i < 26; i++)
    {
        freq[i] = 0;
    }
    for (int i = 0; i < k; i++)
    {
        freq[S[i] - 'a']++;
    }
    char A[26];
    int index = 0;
    for (int i = 0; i < 26; i++)
    {
        if (freq[i] > 0)
        {
            A[index] = 'a' + i;
            index++;
        }
    }
    int count = 0;
    for (int i = 0; i < index; i++)
    {
        int x = 0;
        int x0 = 0;
        freq[A[i]-'a']--;
        for(int j = 0;j < index;j++){
            if(freq[A[j]-'a']>0){ 
                x0 = freq[A[j]-'a'];
                while(x0--)
                s[x++]= A[j];
            }
            // x += x0;
        }
        s[x] = '\0';
        char** anagram = anagrams(D,s);
        int cnt = 0;
        while (1)
        {
            if(anagram[cnt] == NULL){break;}
            printf("%s\n",anagram[cnt]);
            cnt++;
        }
        count += cnt;
        freq[A[i]-'a']++;
    }
    printf("\n%d subwords found\n",count);
}

int main(){
    dict* D = loaddfltdict();
    char S[100];
    printf("Enter a lowercase word:");
    scanf("%s",S);
    printf("Subwords of %s : \n",S);
    subwords(D,S);
}