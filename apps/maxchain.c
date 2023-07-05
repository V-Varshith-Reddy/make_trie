//NAME  : VONTERI VARSHITH REDDY
//ROLLNO: 21CS10081


#include<stdio.h>
#include<string.h>
#include<stdbool.h>
#include<stdlib.h>
#include<wordutils.h>

int backtrack(dict* D,char* str){
    if (strlen(str) == 1)
    {
        return 1;
    }
    char newstr[100] = "";
    strcpy(newstr,&str[1]);
    if (triesearch(D->ROOT,newstr))
    {
        if(backtrack(D,newstr))
        {
            printf("%s\n",newstr);
            return 1;
        }
    }
    strcpy(newstr,str); newstr[strlen(str)-1]='\0';
    if (triesearch(D->ROOT,newstr))
    {
        if(backtrack(D,newstr))
        {
            printf("%s\n",newstr);
            return 1;
        }
    }
    return 0;
    
}





void maxchain(dict *D,char* str,char* max_str)
{
    int k = strlen(str);
    // printf("%s\n",str);
    char* b = addbefore(D,str);
    char* a = addafter(D,str);
    if (b[0]== '\0'&& a[0] == '\0')
    {
        if (k > strlen(max_str))
        {
            strcpy(max_str,str);
        }
        return;
    }
    
    char newstr[30];

    strcpy(&newstr[1],str);
    for(int i= 0;i < strlen(b);i++){
        newstr[0] = b[i];
        maxchain(D,newstr,max_str);
    }
    strcpy(newstr,str);
    newstr[k+1] = '\0';
    for (int i = 0; i < strlen(a); i++)
    {
        newstr[k] = a[i];
        maxchain(D,newstr,max_str);
    }
    newstr[k+1] = '\0';

}

int main(){
    dict* D = loaddfltdict();
    // trieinsert(D->ROOT,"test");
    // trieinsert(D->ROOT,"tent");
    // printf("%d\n",triesearch(D->ROOT,"tent"));
    // printf("%d\n",D->ROOT->first_child->is_end_of_word);
    char max_str[100],str[10];
    max_str[0] = '\0';str[0]='\0';
    printf("Maxchain sequence:\n");
    maxchain(D,str,max_str);
    backtrack(D,max_str);
    printf("%s\n",max_str);

    // char after[10];
    // after[0]='a';after[1]='\0';
    // char * new = addafter(D,after);
    // printf("%s\n",new);

    // listall(D->ROOT);

}
