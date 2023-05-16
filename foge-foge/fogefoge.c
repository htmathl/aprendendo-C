#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "fogefoge.h"
#include "mapa.h"

MAPA m;
POSICAO heroi;

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

    andandoMapa(&m, proxX, proxY, &heroi.x, &heroi.y);
}

int main() {

    leMapa(&m);
    encontraMapa(&m, &heroi, HEROI);

    do {
        imprimeMapa(&m);
        
        char comando;
        scanf(" %c", &comando);
        move(comando);

    } while(!acabou());

    liberaMapa(&m);

}