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
char palavraSecreta[TAMANHO_PALAVRA];
int chutesDados = 0;

void abertura() {
    printf("********************************\n");
    printf("*         Jogo de forca        *\n");
    printf("********************************\n\n");
}

void adicionaPalavra() {
    char quer;

    printf("Você deseja adicionar uma nova palavra? (S/N) ");
    scanf(" %c", &quer);

    if(quer == 'S' || quer == 's') {
        char novaPalavra[TAMANHO_PALAVRA];

        printf("Qual a nova palavra? ");
        scanf("%s", novaPalavra);

        FILE* f;

        f = fopen("palavras.txt", "r+");
        if(f == 0) {
            printf("Desculpe ERRO TOTAL\n");
            exit(1);
        }

        int qtd;
        fscanf(f, "%d", &qtd);
        qtd++;

        fseek(f, 0, SEEK_SET);
        fprintf(f, "%d", qtd);

        fseek(f, 0, SEEK_END);
        fprintf(f, "\n%s", novaPalavra);

    }
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
    int erros = chutesErrados();

    printf("  _______      \n");
    printf(" |/      |     \n");
    printf(" |      %c%c%c \n", (erros >= 1 ? '(' : ' '), (erros >= 1 ? '_' : ' '), (erros >= 1 ? ')': ' '));
    printf(" |      %c%c%c \n", (erros >= 3 ? '\\' : ' '), (erros >= 2 ? '|' : ' '), (erros >= 3 ? '/' : ' '));
    printf(" |       %c    \n", (erros >= 2 ? '|' : ' '));
    printf(" |      %c %c  \n", (erros >= 4 ? '/': ' '), (erros >=5 ? '\\' : ' '));
    printf(" |             \n");
    printf("_|___          \n");
    printf("\n\n");

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

int chutesErrados() {
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
    
    return erros;
}

int enforcou() {
    int cht = chutesErrados();
    if(cht >= 5) {
        desenhaForca();
        return 1;
    }
    return 0;
}

int main() {

    escolhePalavra(palavraSecreta);
    abertura();

    do {
        //colocar dica depois :)
        desenhaForca();
        chuta();

    } while(!acertou() && !enforcou());

    if(acertou()) {
        printf("\nParabéns!! Você ganhou <3\n");
        printf("      |\\      _,,,---,,_\n");
        printf("ZZZzz /,`.-'`'    -.  ;-;;,_\n");
        printf("     |,4-  ) )-,_. ,\\ (  `'-'\n");
        printf("    '---''(_/--'  `-'\\_)\n\n");
    } else {
        printf("\nPoxa :(\nInfelizmente você virou o Olavo de Carvalho\n");
        printf("    _______________         \n");
        printf("   /               \\       \n"); 
        printf("  /                 \\      \n");
        printf("//                   \\/\\  \n");
        printf("\\|   XXXX     XXXX   | /   \n");
        printf(" |   XXXX     XXXX   |/     \n");
        printf(" |   XXX       XXX   |      \n");
        printf(" |                   |      \n");
        printf(" \\__      XXX      __/     \n");
        printf("   |\\     XXX     /|       \n");
        printf("   | |           | |        \n");
        printf("   | I I I I I I I |        \n");
        printf("   |  I I I I I I  |        \n");
        printf("   \\_             _/       \n");
        printf("     \\_         _/         \n");
        printf("       \\_______/           \n\n");
        printf("A palavra secreta era ** %s ** \n\n", palavraSecreta);
    }
    adicionaPalavra();
}
