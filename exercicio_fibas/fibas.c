#include <stdio.h>

int fib(int n) {
    if(n == 0) return 0;
    if(n == 1) return 1;

    return fib(n-1) + fib(n-2);
}

int main() {
    int n;

    printf("Qual fibas vc quer? ");
    scanf("%d", &n);

    int fibas = fib(n);
    printf("O fibas de %d é %d\n", n, fibas);
}