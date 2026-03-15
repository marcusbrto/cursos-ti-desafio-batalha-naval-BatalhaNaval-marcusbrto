#include <stdio.h>

// Desafio Batalha Naval - MateCheck
// Este código inicial serve como base para o desenvolvimento do sistema de Batalha Naval.
// Siga os comentários para implementar cada parte do desafio.

int main() {
    //Declaracao das variaveis
    int matriz[10][10];
    char letras[10] = {'A','B','C','D','E','F','G','H','I','J'};

    // Inicializando matriz com agua "0"
    for (int i = 0; i < 10; i++) //Linhas
    {
        for (int j = 0; j < 10; j++)//Colunas
        {
            matriz[i][j] = 0;
        }
    }

    // Colocando navio na horizontal
    matriz[1][1] = 3;
    matriz[1][2] = 3;
    matriz[1][3] = 3;
    // Colocando navio na vertical
    matriz[6][7] = 3;
    matriz[7][7] = 3;
    matriz[8][7] = 3;

    //Prints meramentes visuais
    printf("=================================\n");
    printf("      DESAFIO BATALHA NAVAL      \n");
    printf("=================================\n");
    printf("   "); //Espaco só para arrumar visualmente as letras em cima da matriz

    //Imprime as letras em cima da matriz
    for (int i = 0; i < 10; i++)
    {
        printf(" %2c", letras[i]);//Esse %2 é somente para manter fixo a largurra
    }
    printf("\n");

    // imprime a matriz
    for (int i = 0; i < 10; i++)//Linhas
    {
        printf("%2d ", i + 1);//Printa a numeracao de 1 a 10 mantendo a largura fixa
        for (int j = 0; j < 10; j++)//Colunas
        {
            printf(" %2d", matriz[i][j]);
        }
        printf("\n");
    }

    return 0;
}
