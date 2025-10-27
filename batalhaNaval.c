#include <stdio.h>

int main() {
    char colunas[11] = {'A','B','C','D','E','F','G','H','I','J'};
    int tabuleiro[10][10];
    int tamanhoNavio = 3;
    
    for(int linha = 0; linha < 10; linha++) {
        for(int coluna = 0; coluna < 10; coluna++) {
            tabuleiro[linha][coluna] = 0;
        }
    }
    
    tabuleiro[5][1] = 3; 
    tabuleiro[5][2] = 3;
    tabuleiro[5][3] = 3;
    
    tabuleiro[6][4] = 3;
    tabuleiro[7][4] = 3;
    tabuleiro[8][4] = 3;

    for (int diagonal = 0; diagonal < tamanhoNavio; diagonal++) {
        tabuleiro[2 + diagonal][2 + diagonal] = 3;
    }
    for (int diagonal = 0; diagonal < tamanhoNavio; diagonal++) {
        tabuleiro[2 + diagonal][8 - diagonal] = 3;
    }

    int alcanceCone = 3;
    int origemLinhaCone = 3;
    int origemColunaCone = 7;

    for (int distancia = 1; distancia <= alcanceCone; distancia++) {
        int largura = distancia - 1;
        for (int deslocamento = -largura; deslocamento <= largura; deslocamento++) {
            int linha = origemLinhaCone - distancia;
            int coluna = origemColunaCone + deslocamento;
            if (linha >= 0 && linha < 10 && coluna >= 0 && coluna < 10) {
                tabuleiro[linha][coluna] = 5;
            } 
        }
    }

    int alcanceCruz = 2;
    int origemLinhaCruz = 3;
    int origemColunaCruz = 3;

    for (int distancia = 0; distancia <= alcanceCruz; distancia++){
        int linhaCima = origemLinhaCruz - distancia;
        int linhaBaixo = origemLinhaCruz + distancia;
        if (linhaCima >= 0) {
            tabuleiro[linhaCima][origemColunaCruz] = 1;
        }
        if (linhaBaixo < 10) {
            tabuleiro[linhaBaixo][origemColunaCruz] = 1;
        }

        int colunaEsquerda = origemColunaCruz - distancia;
        int colunaDireita = origemColunaCruz + distancia;
        if (colunaEsquerda >= 0) {
            tabuleiro[origemLinhaCruz][colunaEsquerda] = 1;
        }
        if (colunaDireita < 10) {
            tabuleiro[origemLinhaCruz][colunaDireita] = 1;
        }
    }

int alcanceOcta = 1;
int origemLinhaOcta = 7;
int origemColunaOcta = 6;

for (int distancia = 0; distancia <= alcanceOcta; distancia++) {
    int linhaCima = origemLinhaOcta - distancia;
    int colunaCima = origemColunaOcta;
    
    int linhaBaixo = origemLinhaOcta + distancia;
    int colunaBaixo = origemColunaOcta;
    
    int linhaEsquerda = origemLinhaOcta;
    int colunaEsquerda = origemColunaOcta - distancia;
    
    int linhaDireita = origemLinhaOcta;
    int colunaDireita = origemColunaOcta + distancia;
    
    if (linhaCima >= 0) {
        tabuleiro[linhaCima][colunaCima] = 4;
    }
    if (linhaBaixo < 10) {
        tabuleiro[linhaBaixo][colunaBaixo] = 4;
    }
    if (colunaEsquerda >= 0) {
        tabuleiro[linhaEsquerda][colunaEsquerda] = 4;
    }
    if (colunaDireita < 10) {
        tabuleiro[linhaDireita][colunaDireita] = 4;
    }
}

    printf("  ");
    for(int linha = 0; linha < 10; linha++) {
        printf("%c ", colunas[linha]);
    }
    printf("\n"); //Numeração de A - J;
    
    for(int coluna = 0; coluna < 10; coluna++) {
        printf("%d ", coluna + 1);
        for(int linha = 0; linha < 10; linha++) {
            printf("%d ", tabuleiro[coluna][linha]);
        }
        printf("\n"); //Numeração de 1 - 10;
    }
    
    return 0;
}