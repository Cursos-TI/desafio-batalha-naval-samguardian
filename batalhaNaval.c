#include <stdio.h>
#include <string.h>
#include <ctype.h> // Usanda para capitalizar entrada de dados referente às letras

struct stNavio
{
    char nome;
    short int linha;
    short int coluna;
    short int orientacao; // 0 - Vertical, 1 - Horizontal, 2 - Diagonal Positiva, 3 - Diagonal Negativa
};

void inicializaTabuleiro();
void exibeTabuleiro();
void exibeLetrasColunas();
void posicionaNavio(struct stNavio navio);
void entradaEPosicionamentoNavio(struct stNavio navio, char nome);
size_t dicionarioLinhas(char letra);
const short int LIMITE_TABULEIRO = 10;
short int TABULEIRO[10][10];

int main()
{
    struct stNavio navioA = {'a', 0, 0, 0}, navioB = {'b', 0, 0, 1}, navioC = {'c', 0, 0, 2}, navioD = {'d', 0, 0, 3};
    char letraReferenciaColuna;

    inicializaTabuleiro();

    // Entra com as coordenadas do navio A
    entradaEPosicionamentoNavio(navioA, 'a');
    // Entra com as coordenadas do navio B
    entradaEPosicionamentoNavio(navioB, 'b');
    // Entra com as coordenadas do navio C
    entradaEPosicionamentoNavio(navioC, 'c');
    // Entra com as coordenadas do navio D
    entradaEPosicionamentoNavio(navioD, 'd');

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
    exibeTabuleiro();
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
        printf("%hd\t", i + 1);
        for (size_t j = 0; j < 10; j++)
        {
            printf("%hd ", TABULEIRO[i][j]);
        }
        printf("\n");
    }
}

// Retorna o índice correspondente à letra da coluna, se não for uma letra válida (no intervalo), retorna 0
size_t dicionarioLinhas(char letra)
{
    letra = toupper(letra);
    switch (letra)
    {
    case 65:
        return 0;
    case 66:
        return 1;
    case 67:
        return 2;
    case 68:
        return 3;
    case 69:
        return 4;
    case 70:
        return 5;
    case 71:
        return 6;
    case 72:
        return 7;
    case 73:
        return 8;
    case 74:
        return 9;
    default:
        return 0;
    }
}

// Posiciona o navio com base na orientação e nas coordenadas fornecidas. 3 indica navio e 1 indica colisão
void posicionaNavio(struct stNavio navio)
{
    switch (navio.orientacao)
    {
    case 0: // Vertical
        for (size_t i = navio.linha; i <= (navio.linha + 2); i++)
        {
            if (TABULEIRO[i][navio.coluna] == 0)
                TABULEIRO[i][navio.coluna] = 3;
        }
        break;

    case 1: // Horizontal
        for (size_t i = navio.linha, j = navio.coluna; i <= (navio.linha + 2); i++, j++)
        {
            if (TABULEIRO[navio.linha][j] == 0)
                TABULEIRO[navio.linha][j] = 3;
        }
        break;

    case 2: // Diagonal Positiva
        for (size_t i = navio.linha, j = navio.coluna; i >= (navio.linha - 2); i--, j++)
        {
            if (TABULEIRO[i][j] == 0)
                TABULEIRO[i][j] = 3;
        }
        break;

    case 3: // Diagonal Negativa
        for (size_t linha = navio.linha, coluna = navio.coluna; linha <= (navio.linha + 2); linha++, coluna++)
        {
            if (TABULEIRO[linha][coluna] == 0)
                TABULEIRO[linha][coluna] = 3;
        }
        break;
    }
}

void entradaEPosicionamentoNavio(struct stNavio navio, char nome)
{
    char letraReferenciaColuna;
    navio.nome = toupper(nome);
    do
    {
        printf("Insira as coordenadas do navio %c (Linha x Coluna): ", navio.nome);
        scanf("%hd %c", &navio.linha, &letraReferenciaColuna);

        // Decrementar a varíavel para ajustar ao índice do vetor que começa em 0
        --navio.linha;
        // Ajustar a letra para o índice do vetor
        navio.coluna = dicionarioLinhas(letraReferenciaColuna);

    } while (navio.linha >= LIMITE_TABULEIRO || navio.coluna >= LIMITE_TABULEIRO);
    posicionaNavio(navio);
}