#include <stdio.h>
#include <stdlib.h>

int* makeChange(int amount);
void printChange(int* change);

int main()
{

    printChange(makeChange(909));
    return 0;
}

int* makeChange(int amount)
{
    /* F, D, Q, D, N, P */
    int* change = malloc(sizeof(int)*6);
    while (amount >= 500) {
        amount -= 500;
        change[0]++;
    }
    while (amount >= 100) {
        amount -= 100;
        change[1]++;
    }
    while (amount >= 25) {
        amount -= 25;
        change[2]++;
    }
    while (amount >= 10) {
        amount -= 10;
        change[3]++;
    }
    while (amount >= 5) {
        amount -= 5;
        change[4]++;
    }
    while (amount >= 1) {
        amount--;
        change[5]++;
    }
    return change;
}

void printChange(int* change)
{
    printf("F: %d D: %d Q: %d D: %d N: %d P: %d\n",
            change[0], change[1],
            change[2], change[3],
            change[4], change[5]);
}
