#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "mapa.h"

void copiaMapa(MAPA* destino, MAPA* origem) {
    destino->linhas = origem->linhas;
    destino->colunas = origem->colunas;

    alocaMapa(destino);
    for(int i = 0; i < origem->linhas; i++) {
        strcpy(destino->matriz[i], origem->matriz[i]);
    }
}

void andandoMapa(MAPA* m, int destinoX, 
    int destinoY, int origemX, int OrigemY) {
    
    char personagem = m -> matriz[origemX][OrigemY];
    m -> matriz[destinoX][destinoY] = personagem;
    m -> matriz[origemX][OrigemY] = VAZIO;
}

int ehVazia(MAPA* m, int x, int y) {
    return m->matriz[x][y] == VAZIO;
}

int ehValida(MAPA* m, int x, int y) {
    if(x >= m->linhas || y >= m->colunas) return 0;

    return 1;
}

int encontraMapa(MAPA* m, POSICAO* p, char c) {
    //acha o foge-foge
    for (int i = 0; i < m->linhas; i++) {
        for (int j = 0; j < m->colunas; j++) {
            if(m->matriz[i][j] == c) {
                p->x = i;
                p->y = j;
                break;
            }
        }
    }
}

void liberaMapa(MAPA* m) {
    for (int i = 0; i < m->linhas; i++) {
        free(m->matriz[i]);
    }
    free(m->matriz);
}

void leMapa(MAPA* m) {
    FILE* f;
    f = fopen("mapa.txt", "r");
    if(f == 0) {
        printf("Mapa não pode ser carregado!\n");
    }

    fscanf(f, "%d %d", &(m->linhas), &(m->colunas));

    alocaMapa(m);

    for(int i = 0; i < 5; i++) {
        fscanf(f, "%s", m->matriz[i]);
    }

    fclose(f);
}

void alocaMapa(MAPA* m) {
    m->matriz = malloc(sizeof(char*) * m->linhas);
    for(int i = 0; i < m->linhas; i++) {
        m->matriz[i] = malloc(sizeof(char) * (m->colunas+1));
    }
}

void imprimeMapa(MAPA* m) {
    for(int i = 0; i < 5; i++) {
        printf("%s\n", m->matriz[i]);
    }
}