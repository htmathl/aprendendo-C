#include <stdio.h>

int main() {
    int num;
    printf("Qual tabuada se quer saber? ");
    scanf("%d", &num);

    for(int i = 1; i <= 10; i++) {
        int result = num * i;
        printf("%d x %d = %d\n", num, i, result);
    }
}