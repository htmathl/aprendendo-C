#include <stdio.h>

#define LINHA 20
#define COLUNA 10

int main() {
    int num[LINHA][COLUNA];

    for(int i = 0; i < LINHA; i++) {
        for(int j = 0; i < COLUNA; i ++) {
            printf("%d", num[i][j]);
        }
        printf("\n");
    } 
}