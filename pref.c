    #include<stdlib.h>
    #include<string.h>
    char* longestCommonPrefix(char** strs, int strsSize) //function to find the most common prefix amongst three other words
    {
    int i, j;
    char c;
    int len = 0;
    int end = 0;

    if (strsSize == 0) return ""; //if no words then return empty string

    for (i = 0; i < strlen(strs[0]); i++)  //iterates through individual letters
    {
        c = strs[0][i];
        for (j = 1; j < strsSize; j++)  //compares letter to each string
        {
            if (i == strlen(strs[j]) || strs[j][i] != c) //if the strings are equal lengths OR string letter do not match then break loop and stop analyzing
            {
                end = 1;
                break;
            }
        }
        if (end) break; //break out of for loop logic if end = 1 (something doesnt match anymore)
        len++; //adds length of prefix (Also accounts for null character)
    }

    char* result = (char*)malloc(len + 1); //allocates memory to return string
    strncpy(result, strs[0], len); //copies string zero for how ever many letters passed the if condition on **line 35**
    result[len] = '\0'; //adds null character so trash doesnt get printed when attempting to print prefix (result)
    return result; //returns prefix
    }