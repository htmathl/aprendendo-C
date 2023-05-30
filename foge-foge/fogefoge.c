#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "fogefoge.h"
#include "mapa.h"
#include "ui.h"

MAPA m;
POSICAO heroi;
int temPilula = 0;

int escolherPosicaoFantasma(int xAtual, int yAtual, int* xDestino, int* yDestino) {
    int opcoes[4][2] = {
        { xAtual, yAtual+1 },
        { xAtual+1, yAtual },
        { xAtual, yAtual-1 },
        { xAtual-1, yAtual }
    };

    srand(time(0));
    for(int i = 0; i < 10; i++) {
        int posicao = rand() % 4;

        if(podeAndar(&m, FANTASMA, opcoes[posicao][0], opcoes[posicao][1])) {
            *xDestino = opcoes[posicao][0];
            *yDestino = opcoes[posicao][1];
            
            return 1;
        }
    }
    
    return 0;
}

void andaFantasmas() {
    MAPA copia;

    copiaMapa(&copia, &m);

    for(int i = 0; i < m.linhas; i++) {
        for(int j = 0; j < m.colunas; j++) {
            if(copia.matriz[i][j] == FANTASMA) {

                int xDestino, yDestino;
                int encontrou = escolherPosicaoFantasma(i, j,
                &xDestino, &yDestino);

                if(encontrou)
                    andandoMapa(&m, xDestino, yDestino, i, j);
            }
        }
    }

    liberaMapa(&copia);
}

int acabou() {
    POSICAO pos;
    return !encontraMapa(&m, &pos, HEROI);
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
    case BOMBA:
        defineAsPosDoExplodePilula();
        break;
    default:
        printf("** Você só pode usar w,a,s ou d para se mover **\n");
    }

    if(!podeAndar(&m, HEROI, proxX, proxY)) return;

    if(ehPersonagem(&m, PILULA, proxX, proxY)) temPilula = 1 ;

    andandoMapa(&m, proxX, proxY, heroi.x, heroi.y);
    heroi.x = proxX;
    heroi.y = proxY;
}

void defineAsPosDoExplodePilula() {
    if(!temPilula) return;

    explodePilula(heroi.x, heroi.y, 0, 1, 3);
    explodePilula(heroi.x, heroi.y, 0, -1, 3);
    explodePilula(heroi.x, heroi.y, 1, 0, 3);
    explodePilula(heroi.x, heroi.y, -1, 0, 3);

    temPilula = 0;
}

void explodePilula(int x, int y, int somax, int somay, int qtd) {
    if(qtd == 0) return;

    int novox = x + somax;
    int novoy = y + somay;

    if(!ehValida(&m, novox, novoy)) return;
    if(ehParede(&m, novox, novoy)) return;

    m.matriz[novox][novoy] = VAZIO;
    explodePilula(novox, novoy, somax, somay, qtd-1);
}

int main() {

    leMapa(&m);
    encontraMapa(&m, &heroi, HEROI);

    do {
        printf("Tem pilula: %s\n", (temPilula ? "SIM" : "NÃO"));
        imprimeMapa(&m);
        
        char comando;
        scanf(" %c", &comando);
        move(comando);
        andaFantasmas();

    } while(!acabou());

    liberaMapa(&m);

}