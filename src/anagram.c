#include <stdio.h>
#include <string.h>

#include "advancedSorts.h"

int isAnagram(char* str1, char* str2);

int main()
{
    isAnagram("cinema", "iceman");
    return 0;
}

int isAnagram(char* str1, char* str2)
{
    int i, len1, len2;
    len1 = strlen(str1);
    len2 = strlen(str2);
    ASorts_mergesort(str1, len1);
    ASorts_mergesort(str2, len2);
    printf("str1: %s\n", str1);
    printf("str2: %s\n", str2);

    return 0;
}
