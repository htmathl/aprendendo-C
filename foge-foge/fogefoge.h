#define CIMA 'w'
#define ESQUERDA 'a'
#define BAIXO 's'
#define DIREITA 'd'

void move(char direcao);
void andaFantasmas();
int escolherPosicaoFantasma(int xAtual, int yAtual, int* xDestino, int* yDestino);
int acabou();