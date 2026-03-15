#include <stdio.h>

// Desafio Batalha Naval - MateCheck
// Desafio Nivel Novato - CONCLUIDO
// Desafio Nivel Aventureiro - CONCLUIDO
// Adicionei algumas cores com ANSI para melhorar a visilidade, eu tambem ia trocar o 0 por ~ e o 3 por N mas manti assim para ficar o padrao do desafio

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
    for (int i = 0; i < 3; i++)
    {
        matriz[1][i] = 3;// altera somente a linbha
    }
    // Colocando navio na vertical
    for (int i = 0; i < 3; i++)
    {
        matriz[i][7] = 3;// altera somente a coluna
    }
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
    printf("\033[35m=================================\n");
    printf("      DESAFIO BATALHA NAVAL      \n");
    printf("=================================\n\033[m");
    printf("   "); //Espaco só para arrumar visualmente as letras em cima da matriz

    //Imprime as letras em cima da matriz
    for (int i = 0; i < 10; i++)
    {
        printf("\033[32m %2c\033[m", letras[i]);//Esse %2 é somente para manter fixo a largurra
    }
    printf("\n");

    // imprime a matriz
    for (int i = 0; i < 10; i++)//Linhas
    {
        printf("\033[32m%2d \033[m", i + 1);//Printa a numeracao de 1 a 10 mantendo a largura fixa
        for (int j = 0; j < 10; j++)//Colunas
        {
            if (matriz[i][j] == 3) //aqui eu fiz a condicional só para deixar bonitinho
            {
                printf("\033[31m %2d\033[m", matriz[i][j]);
            }else
            {
                printf("\033[34m %2d\033[m", matriz[i][j]);
            }
        }
        printf("\n");
    }

    return 0;
}
