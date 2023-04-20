#include <stdio.h>

int main() {
    printf("*******************************************\n");
    printf("* Bem vindo ao nosso jogo de adivinhação! *\n");
    printf("*******************************************\n");
    
    int num = 17;
    int chute;

    printf("Qual o seu chute? ");
    scanf("%d", &chute);

    printf("Seu chute foi %d", chute);

    return 0;
}