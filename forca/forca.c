#include <stdio.h>
#include <string.h>

//para declarar variaveis globais é só colocar fora de todas funções

void abertura() {
    printf("********************************\n");
    printf("*         Jogo de forca        *\n");
    printf("********************************\n\n");
}

void escolhePalavra(char palavraSecreta[20]) {
    sprintf(palavraSecreta, "MELANCIA");
}

void chuta(char chutes[26], int* tentativas) {
    char chute;
    scanf(" %c", &chute);
    chutes[*tentativas] = chute;
    (*tentativas)++;
}

int jaChutou(char letra, char chts[26], int tent) {
    int achou = 0;
    for (int j = 0; j < tent; j++) {
        if(chts[j] == letra) {
            achou = 1;
            break;
        }
    }
    return achou;
}

void desenhaForca(char palavraSecreta[20], char chutes[26], int tentativas) {
     for(int i = 0; i < strlen(palavraSecreta); i++) {
            
            int achou = jaChutou(palavraSecreta[i], chutes, tentativas);

            if(!achou) {
                printf("_ ");
            } else {
                printf("%c ", palavraSecreta[i]);
            }
        }
        printf("\n");
}

int enforcou(int tentativas, char palavraSecreta[20], char chutes[26]) {
    int erros = 0;

    for(int i = 0; i < tentativas; i++) {
        int existe = 0;

        for(int j = 0; j < strlen(palavraSecreta); j++) {
            if(chutes[i] == palavraSecreta[j]) {
                existe = 1;
                break;
            }
        }
        if(!existe) erros++;
    }
    
    return erros >= 5;
}

int main() {
    char palavraSecreta[20];

    int acertou = 0;
    
    char chutes[26];
    int tentativas = 0;

    int enfrc = enforcou(tentativas, palavraSecreta, chutes);

    escolhePalavra(palavraSecreta);
    abertura();

    do {
        desenhaForca(palavraSecreta, chutes, tentativas);
        chuta(chutes, &tentativas);

    } while(!acertou && !enfrc);
}