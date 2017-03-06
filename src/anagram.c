#include <stdio.h>
#include <string.h>

#include "basicSorts.h"
#include "advancedSorts.h"

int isAnagram(char* str1, char* str2);

int main()
{
    char *str1 = malloc(sizeof(char)*6);
    char *str2 = malloc(sizeof(char)*6);
    str1[0] = 'c'; str1[1] = 'i';
    str1[2] = 'n'; str1[3] = 'e';
    str1[4] = 'm'; str1[5] = 'a';
    str1[6] = 0;

    str2[0] = 'i'; str2[1] = 'c';
    str2[2] = 'e'; str2[3] = 'm';
    str2[4] = 'a'; str2[5] = 'n';
    str2[6] = 0;

    printf("isAnagram: %d\n", isAnagram(str1, str2));
    return 0;
}

int isAnagram(char* str1, char* str2)
{
    int i, len1, len2;
    len1 = strlen(str1);
    len2 = strlen(str2);
    ASorts_mergesort(str1, len1, sizeof(char), Sorts_charcmp);
    ASorts_mergesort(str2, len2, sizeof(char), Sorts_charcmp);

    return strcmp(str1, str2) == 0;
}
