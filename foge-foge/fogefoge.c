#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "fogefoge.h"
#include "mapa.h"

MAPA m;
POSICAO heroi;

void andaFantasmas() {
    MAPA copia;

    copiaMapa(&copia, &m);

    for(int i = 0; i < m.linhas; i++) {
        for(int j = 0; j < m.colunas; j++) {
            if(copia.matriz[i][j] == FANTASMA)
                if(ehValida(&m, i, j+1) && ehVazia(&m, i, j+1))
                    andandoMapa(&m, i, j+1, i, j);
        }
    }

    liberaMapa(&copia);
}

int acabou() {
    return 0;
}

void move(char direcao) {

    int proxX = heroi.x;
    int proxY = heroi.y;

    //quando insere mais de um char ele anda + de uma casa
    
    switch (direcao) {
    case CIMA:
        proxX--;
        break;
    case ESQUERDA:
        proxY--;
        break;
    case BAIXO:
        proxX++;
        break;
    case DIREITA:
        proxY++;
        break;
    default:
        printf("** Você só pode usar w,a,s ou d para se mover **\n");
    }

    if(!ehValida(&m, proxX, proxY)) return;
    if(!ehVazia(&m, proxX, proxY)) return;

    andandoMapa(&m, proxX, proxY, heroi.x, heroi.y);
    heroi.x = proxX;
    heroi.y = proxY;
}

int main() {

    leMapa(&m);
    encontraMapa(&m, &heroi, HEROI);

    do {
        imprimeMapa(&m);
        
        char comando;
        scanf(" %c", &comando);
        move(comando);
        andaFantasmas();

    } while(!acabou());

    liberaMapa(&m);

}