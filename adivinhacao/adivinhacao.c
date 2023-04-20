#include <stdio.h>

int main() {
    printf("*******************************************\n");
    printf("* Bem vindo ao nosso jogo de adivinhação! *\n");
    printf("*******************************************\n");
    
    int num = 17;
    int chute;

    printf("Qual o seu chute? ");
    scanf("%d", &chute);

    printf("Seu chute foi %d \n", chute);

    if(chute == num) {
        printf("Parabrns! Voce acertou o numero");
    } else if(chute > num) {
        printf("Voce errou :(\n");
        printf("O número é menor");
    } else {
        printf("Voce errou :(\n");
        printf("O número é maior");
    }

    return 0;
}