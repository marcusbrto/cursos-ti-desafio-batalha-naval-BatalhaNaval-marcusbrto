#include <stdio.h>

// Desafio Batalha Naval - MateCheck

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
    //Colocando navio na diagonal
    for (int i = 0; i < 3; i++)
    {
        matriz[4 + i][2 + i] = 3; //como matriz[linha][coluna] entao somando com o valor de i, cada repeticao eles aumentam juntos, dando o resuldado de diagonal

    }
    //Colocando navio na diagonal INVERTIDO
    for (int i = 0; i < 3; i++)
    {
        matriz[1 + i][8 - i] = 3;//nesse caso a linha aumenta e a coluna diminui
    }

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
