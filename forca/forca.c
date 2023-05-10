#include <stdio.h>
#include <string.h>

int chuta(char chutes[26], int tentativas) {
    char chute;
    scanf(" %c", &chute);
    chutes[tentativas] = chute;
    return tentativas++;
}

int main() {
    char palavraSecreta[20];

    sprintf(palavraSecreta, "MELANCIA");

    int acertou = 0;
    int enforcou = 0;

    char chutes[26];
    int tentativas = 0;

    printf("********************************\n");
    printf("*         Jogo de forca        *\n");
    printf("********************************\n\n");

    do {
        for(int i = 0; i < strlen(palavraSecreta); i++) {
            int achou = 0;
            for (int j = 0; j < tentativas; j++) {
                if(chutes[j] == palavraSecreta[i]) {
                    achou = 1;
                    break;
                }
            }
            if(!achou) {
                printf("_ ");
            } else {
                printf("%c ", palavraSecreta[i]);
            }
        }
        printf("\n");
        tentativas += chuta(chutes, tentativas);
    } while(!acertou && !enforcou);
}