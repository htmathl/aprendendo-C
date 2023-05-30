#ifndef _FOGEFOGE_H_

#define _FOGEFOGE_H_
#define CIMA 'w'
#define ESQUERDA 'a'
#define BAIXO 's'
#define DIREITA 'd'
#define BOMBA 'b'

void move(char direcao);
void andaFantasmas();
int escolherPosicaoFantasma(int xAtual, int yAtual, int* xDestino, int* yDestino);
int acabou();
void defineAsPosDoExplodePilula();
void explodePilula(int x, int y, int somax, int somay, int qtd);

#endif
