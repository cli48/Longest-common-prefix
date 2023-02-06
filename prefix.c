#include<stdio.h>
#include<string.h>
#include<stdlib.h>
char* longestCommonPrefix(char** strs, int strsSize);
int main()
    {
    int size = 3;
    char* words[3] = {"wad","Do","Dog"};
    char* result;
    /*
    for(int i=0;i<size;i++)
        {
        printf("%s\n",words[i]);
        }
    */
    result = longestCommonPrefix(words,size);
    printf("%s\n",result);
    return 0;
    }

    char* longestCommonPrefix(char** strs, int strsSize)
    {
    int i, j;
    char c;
    int len = 0;
    int end = 0;

    if (strsSize == 0) return "";

    for (i = 0; i < strlen(strs[0]); i++)
    {
        c = strs[0][i];
        for (j = 1; j < strsSize; j++)
        {
            if (i == strlen(strs[j]) || strs[j][i] != c)
            {
                end = 1;
                break;
            }
        }
        if (end) break;
        len++;
    }

    char* result = (char*)malloc(len + 1);
    strncpy(result, strs[0], len);
    result[len] = '\0';
    return result;
}