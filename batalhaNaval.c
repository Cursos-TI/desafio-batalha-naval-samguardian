#include <stdio.h>
#include <string.h>

void inicializaTabuleiro();
void exibeTabuleiro();
void exibeLetrasColunas();

short int TABULEIRO[10][10];

int main()
{
    short int navioA[3] = {3, 3, 3}, navioB[3] = {3, 3, 3};

    inicializaTabuleiro();

adicionaNavioA:
    for (size_t i = 3; i <= 5; i++)
    {
        if (TABULEIRO[i][2] == 0)
        {
            TABULEIRO[i][2] = navioA[0];
        }
        
    }

adicionaNavioB:
    for (size_t i = 5; i <= 7; i++)
    {
        if (TABULEIRO[7][i] == 0)
        {
            TABULEIRO[7][i] = navioB[0];
        }
        
    }

    exibeTabuleiro();

    return 0;
}

// Inicializa o tabuleiro com todas as posições com o número 0
void inicializaTabuleiro()
{
    for (size_t i = 0; i < 10; i++)
    {
        for (size_t j = 0; j < 10; j++)
        {
            TABULEIRO[i][j] = 0;
        }
    }
}

// Exibe letras de A a J na primeira linha da tabuleiro
void exibeLetrasColunas()
{
    char linha[10];
    printf("\t");
    for (size_t i = 0, j = 65; i < 10; i++, j++)
    {
        linha[i] = j;
        printf("%c ", linha[i]);
    }
    printf("\n");
}

// Exibe o tabuleiro por completo e com os rótulos de linha e coluna
void exibeTabuleiro()
{
    char letra[10] = "A";
    printf("TABULEIRO BATALHA NAVAL\n");
    exibeLetrasColunas();
    for (size_t i = 0; i < 10; i++)
    {
        printf("%zd\t", i + 1);
        for (size_t j = 0; j < 10; j++)
        {
            printf("%zd ", TABULEIRO[i][j]);
        }
        printf("\n");
    }
}
