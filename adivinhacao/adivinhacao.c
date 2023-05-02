#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUMERO_DE_TENTATIVAS 5

int acerto(int acertou, int maior, double ptns) {
    if(acertou) {
        printf("Parabéns! Você acertou o número <3\n\n");
        printf("      |\\      _,,,---,,_\n");
        printf("ZZZzz /,`.-'`'    -.  ;-;;,_\n");
        printf("     |,4-  ) )-,_. ,\\ (  `'-'\n");
        printf("    '---''(_/--'  `-'\\_)\n\n");
        printf("Total de pontos: %.1f\n", ptns);
        return 1;
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

    int segundos = time(0);
    srand(segundos);

    int numeroGrandao = rand();
    int num = numeroGrandao % 100;
    int chute, lim;
    double pontos = 1000.0;

    while(1) {
        printf("Deseja jogar com número de tentativas limitadas?\n");
        printf("(0) Não | (1) Sim : ");
        scanf("%d", &lim);

        if(lim == 1) {
            for (int i = 1; i <= NUMERO_DE_TENTATIVAS; i++) {
            
                printf("Tentativa %d de %d\n", i, NUMERO_DE_TENTATIVAS);

                printf("Qual o seu chute? ");
                scanf("%d", &chute);
                printf("Seu chute foi %d \n", chute);

                if(chute < 0) {
                    printf("Número negativo não :(\n");
                    i--;
                    continue;
                }

                int acertou = chute == num;
                int maior = chute > num;
                double ptnsPerdidos = abs(chute - num) / (double)2;
                pontos -= ptnsPerdidos;
                if(acerto(acertou, maior, pontos) == 1) return 0;
            }

            printf("Você exauriu todas suas tentativas! Tente jogar novamente...\n");
            printf("Total de pontos: %.1f\n", pontos);

        } else if(lim == 0) {
            int tent = 1;

            while(1) {
            
                printf("Tentativa %d\n", tent);

                printf("Qual o seu chute? ");
                scanf("%d", &chute);
                printf("Seu chute foi %d \n", chute);

                if(chute < 0) {
                    printf("Número negativo não :(\n");
                    continue;
                }

                int acertou = chute == num;
                int maior = chute > num;
                double ptnsPerdidos = abs(chute - num) / 2.0;
                pontos -= ptnsPerdidos;
                if(acerto(acertou, maior, pontos) == 1) break;
                tent ++;
            }
        } else {
            printf("*** Erro 404 ***\n");
            continue;
        }
        break;
    }
}
