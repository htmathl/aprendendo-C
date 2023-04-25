#include <stdio.h>

int acerto(int acertou, int maior) {
    if(acertou) {
        printf("Parabéns! Voce acertou o número\n");
        return 0;
    }
    printf("Voce errou :(\n");
    printf("O número secreto é ");
    if(maior) {
        printf("menor\n");
    } else {
        printf("maior\n");
    }
}

int main() {
    printf("*******************************************\n");
    printf("* Bem vindo ao nosso jogo de adivinhação! *\n");
    printf("*******************************************\n");
    
    int num = 17;
    int chute;

    printf("Qual o seu chute? ");
    scanf("%d", &chute);

    printf("Seu chute foi %d \n", chute);

    int acertou = chute == num;
    int maior = chute > num;

    acerto(acertou, maior);

    return 0;
}