#define HEROI '@'
#define VAZIO '.'
#define PAREDE_VERTICAL '|'
#define PAREDE_HORIZONTAL '-'

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

void encontraMapa(MAPA* m, POSICAO* p, char c);
void leMapa(MAPA* m);
void alocaMapa(MAPA* m);
void imprimeMapa(MAPA* m);
void liberaMapa(MAPA* m);

int ehValida(MAPA* m, int x, int y);
int ehVazia(MAPA* m, int x, int y);
void andandoMapa(MAPA* m, int destinoX, 
    int destinoY, int* origemX, int* OrigemY);