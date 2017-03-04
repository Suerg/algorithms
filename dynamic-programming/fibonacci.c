#include <stdio.h>
#include <time.h>

int fib(int n);
int fibMemo(int n);

int main()
{
    int i;
    clock_t start, end;
    double cputime1, cputime2;

    start = clock();
    for (i=0; i<40; i++) {
        fib(i);
    }
    end = clock();
    cputime1 = ((double) (end-start)) / CLOCKS_PER_SEC;
    printf("time: %f seconds \n", cputime1);

    start = clock();
    for (i=0; i<40; i++) {
        fib(i);
    }
    end = clock();
    cputime2 = ((double) (end-start)) / CLOCKS_PER_SEC;
    printf("time memo: %f seconds ]n", cputime2);

    return 0;
}

int fib(int n)
{
    if (n<0) {
        return 0;
    } else if (n==1) {
        return 1;
    } else {
        return fib(n-1)+fib(n-2);
    }
}

int fibMemo(int n)
{
    int f[n+1];
    int i;

    f[0] = 0;
    f[1] = 1;

    for (i=2; i<=n; i++) {
        f[i] = f[i-1]+f[i-2];
    }

    return f[n];
}
