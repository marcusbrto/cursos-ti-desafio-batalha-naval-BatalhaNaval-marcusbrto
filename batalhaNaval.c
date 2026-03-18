#include <stdio.h>

// Desafio Batalha Naval - MateCheck
// Desafio Nivel Novato - CONCLUIDO
// Desafio Nivel Aventureiro - CONCLUIDO
// Desafio Nivel Mestre - CONCLUIDO
// Adicionei algumas cores com ANSI para melhorar a visilidade, eu tambem ia trocar o 0 por ~ e o 3 por N mas manti assim para ficar o padrao do desafio

#define LINHAS 10
#define COLUNA 10
#define TAM_NAVIO 3
#define TAM_HABILIDADE 5

int main() {
    //declaracao das variaveis
    int matriz[LINHAS][COLUNA];
    char letras[COLUNA] = {'A','B','C','D','E','F','G','H','I','J'};

    //matriz das habilidades, nesse exemplo é 5 por 5 podendo ser alterado mais acima
    int cone[TAM_HABILIDADE][TAM_HABILIDADE];
    int cruz[TAM_HABILIDADE][TAM_HABILIDADE];
    int oct[TAM_HABILIDADE][TAM_HABILIDADE];

    int centro = TAM_HABILIDADE / 2; // com isso o centro da matriz das habilidades sempre vai ser 2

    // inicializando matriz com agua "0"
    for (int i = 0; i < LINHAS; i++) //cinhas
    {
        for (int j = 0; j < COLUNA; j++)//colunas
        {
            matriz[i][j] = 0; //tudo comeca como agua
        }
    }

    // colocando navio na horizontal
    for (int i = 0; i < TAM_NAVIO; i++)
    {
        matriz[1][i] = 3;// altera somente a linbha
    }
    // colocando navio na vertical
    for (int i = 0; i < TAM_NAVIO; i++)
    {
        matriz[i][7] = 3;// altera somente a coluna
    }
    //colocando navio na diagonal
    for (int i = 0; i < TAM_NAVIO; i++)
    {
        matriz[4 + i][2 + i] = 3; //como matriz[linha][coluna] entao somando com o valor de i, cada repeticao eles aumentam juntos, dando o resuldado de diagonal

    }
    //Colocando navio na diagonal INVERTIDO
    for (int i = 0; i < TAM_NAVIO; i++)
    {
        matriz[6 + i][8 - i] = 3;//nesse caso a linha aumenta e a coluna diminui
    }
    //Criando as habilidades
    //aqui ele percorre toda a matriz 5 por 5, cada linha e coluna
    for (int i = 0; i < TAM_HABILIDADE; i++) {
        for (int j = 0; j < TAM_HABILIDADE; j++) {
            // CONE
            if (i <= centro && j >= centro - i && j <= centro + i)
                cone[i][j] = 1;
            else
                cone[i][j] = 0;

            // CRUZ
            if (i == centro || j == centro)
                cruz[i][j] = 1;
            else
                cruz[i][j] = 0;

            // OCTAEDRO
            if (
                (i == centro && j >= centro - 2 && j <= centro + 2) ||
                (i == centro - 1 && j >= centro - 1 && j <= centro + 1) ||
                (i == centro + 1 && j >= centro - 1 && j <= centro + 1) ||
                (i == centro - 2 && j == centro) ||
                (i == centro + 2 && j == centro)
            )
                oct[i][j] = 1;
            else
                oct[i][j] = 0;
        }
    }
    //Adicionando as habilidade
    int origemLinha = 7;
    int origemColuna = 5;

    for (int i = 0; i < TAM_HABILIDADE; i++) {
        for (int j = 0; j < TAM_HABILIDADE; j++) {
            //Aqui eh só trocar o nome da habilidade> cone/cruz/oct
            if (cone[i][j] == 1) {

                int linhaTab = origemLinha + (i - centro);
                int colTab   = origemColuna + (j - centro);

                if (linhaTab >= 0 && linhaTab < LINHAS &&
                    colTab >= 0 && colTab < COLUNA) {

                    matriz[linhaTab][colTab] = 5;
                    }
            }
        }
    }

    //Prints meramentes visuais
    printf("\033[35m=================================\n");
    printf("      DESAFIO BATALHA NAVAL      \n");
    printf("=================================\n\033[m");
    printf("   "); //Espaco só para arrumar visualmente o espacamento nas letras em cima da matriz

    //Imprime as letras em cima da matriz
    for (int i = 0; i < COLUNA; i++)
    {
        printf("\033[32m %2c\033[m", letras[i]);//Esse %2 é somente para manter fixo a largurra
    }
    printf("\n");

    // imprime a matriz
    for (int i = 0; i < LINHAS; i++)//Linhas
    {
        printf("\033[32m%2d \033[m", i + 1);//Printa a numeracao de 1 a 10 mantendo a largura fixa
        for (int j = 0; j < COLUNA; j++)//Colunas
        {
            if (matriz[i][j] == 3) //aqui eu fiz a condicional só para deixar bonitinho
            {
                printf("\033[31m %2d\033[m", matriz[i][j]);//se for um indice que tem o numero 3 pinta de vermelho
            }else if (matriz[i][j] == 5)
            {
                printf("\033[33m %2d\033[m", matriz[i][j]);
            }
            else
            {
                printf("\033[34m %2d\033[m", matriz[i][j]);//se for 0 printa de azul
            }
        }
        printf("\n");
    }

    return 0;
}
