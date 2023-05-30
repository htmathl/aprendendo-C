#ifndef _MAPA_H_

#define _MAPA_H_
#define HEROI '@'
#define FANTASMA 'F'
#define VAZIO '.'
#define PAREDE_VERTICAL '|'
#define PAREDE_HORIZONTAL '-'
#define PILULA 'P'

struct mapa{
    char** matriz;
    int linhas;
    int colunas;
};
typedef struct mapa MAPA;

struct posicao {
    int x, y;
};
typedef struct posicao POSICAO;

int encontraMapa(MAPA* m, POSICAO* p, char c);
void leMapa(MAPA* m);
void alocaMapa(MAPA* m);
void liberaMapa(MAPA* m);

int ehValida(MAPA* m, int x, int y);
int ehVazia(MAPA* m, int x, int y);
int ehParede(MAPA* m, int x, int y);
int ehPersonagem(MAPA* m, char personagem, int x, int y);
int podeAndar(MAPA* m, char personagem, int x, int y);
void andandoMapa(MAPA* m, int destinoX, 
    int destinoY, int origemX, int OrigemY);
void copiaMapa(MAPA* destino, MAPA* origem);

#endif
