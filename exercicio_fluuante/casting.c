#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int a = 3;
    int b = 2;
    double pontos = a / (double)b;
    //printf("%f\n", pontos);

    int c = abs(3);
    int d = abs(-3);
    //printf("%d %d\n", c, d);

    int segundos = time(0);
    srand(segundos);

    int n1 = rand();
    int n2 = rand();
    printf("%d %d\n", n1, n2);
}