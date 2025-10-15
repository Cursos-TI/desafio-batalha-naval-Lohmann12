#include <stdio.h>

int main() {
    char colunas[11] = {'A','B','C','D','E','F','G','H','I','J'};
    int tabuleiro[10][10];
    int tamanhoNavio = 3;
    
    for(int coluna = 0; coluna < 10; coluna++) {
        for(int linha = 0; linha < 10; linha++) {
            tabuleiro[coluna][linha] = 0;
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
    
    printf("  ");
    for(int linha = 0; linha < 10; linha++) {
        printf("%c ", colunas[linha]);
    }
    printf("\n");
    
    for(int coluna = 0; coluna < 10; coluna++) {
        printf("%d ", coluna + 1);
        for(int linha = 0; linha < 10; linha++) {
            printf("%d ", tabuleiro[coluna][linha]);
        }
        printf("\n");
    }

    return 0;
}