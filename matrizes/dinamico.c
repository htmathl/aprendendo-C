#include <stdio.h>
#include <stdlib.h>

#define LINHAS 5
#define COLUNAS 10

char** mapa;

int main() {
    mapa = malloc(sizeof(int*) * LINHAS);
    for (int i = 0; i < LINHAS; i++) {
        mapa[i] = malloc(sizeof(int) * (COLUNAS+1));
    }

    mapa[4][14] = 'm';
    char miau = mapa[4][14];

    printf("%d x %d\n%c\n", LINHAS, COLUNAS, miau);

    for (int i = 0; i < LINHAS; i++) {
        free(mapa[i]);
    }
    free(mapa);
}