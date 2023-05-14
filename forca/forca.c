#include <stdio.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>

//assinatura de funções servem para vc poder colocar as funções depois
//em qualquer ordem
// void abertura();
// void desenhaForca();
// void escolhePalavra();
// void chuta();
// int jaChutou(char letra);
// int acertou();
// int enforcou();

//Porém é usual colocar isso em outro arquivo seprarado com a extensão
//.h (header file)

#include "forca.h"

//para declarar variaveis globais é só colocar fora de todas funções
char chutes[26];
char palavraSecreta[20];
int chutesDados = 0;

void abertura() {
    printf("********************************\n");
    printf("*         Jogo de forca        *\n");
    printf("********************************\n\n");
}

void escolhePalavra() {
    FILE* f;

    f = fopen("palavras.txt", "r");
    if(f == 0) {
        printf("Desculpe ERRO TOTAL");
        exit(1);
    }

    int qntPalavras;
    fscanf(f, "%d", &qntPalavras);

    srand(time(0));
    int rando = rand() % qntPalavras;

    for(int i = 0; i <= rando; i++) {
        fscanf(f, "%s", palavraSecreta);
    }

    fclose(f);
}

void chuta() {
    char chute;
    scanf(" %c", &chute);
    chutes[chutesDados] = chute;
    chutesDados++;
}

int jaChutou(char letra) {
    int achou = 0;
    for (int j = 0; j < chutesDados; j++) {
        if(chutes[j] == letra) {
            achou = 1;
            break;
        }
    }
    return achou;
}

void desenhaForca() {
     for(int i = 0; i < strlen(palavraSecreta); i++) {
            
            int achou = jaChutou(palavraSecreta[i]);

            if(!achou) {
                printf("_ ");
            } else {
                printf("%c ", palavraSecreta[i]);
            }
        }
    printf("\n");
}

int acertou() {
    for(int i = 0; i < strlen(palavraSecreta); i++) {
        if(!jaChutou(palavraSecreta[i])) {
            return 0;
        }
    }

    desenhaForca();
    return 1;
}

int enforcou() {
    int erros = 0;

    for(int i = 0; i < chutesDados; i++) {
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

    escolhePalavra(palavraSecreta);
    abertura();

    do {

        desenhaForca();
        chuta();

    } while(!acertou() && !enforcou());
}
