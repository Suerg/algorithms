#include <stdio.h>
#include <string.h>

int isPalindrome(char* string);

int main()
{
    printf("%d\n", isPalindrome("heh"));
    printf("%d\n", isPalindrome("hello world!"));
    printf("%d\n", isPalindrome("suppus"));

    return 0;
}

int isPalindrome(char* string)
{
    int i, j;
    int len = strlen(string);
    for (i=0, j=len-1; i < j; i++, j--) {
        if (string[i] != string[j]) {
            return 0;
        }
    }
    return 1;
}
