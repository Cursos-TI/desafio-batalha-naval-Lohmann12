#include <stdio.h>

int main() {
    char linha[11] = {' ','A','B','C','D','E','F','G','H','I','J'};
    
    int tabuleiro[10][11];

    for(int a = 0; a < 10; a++) {
        for(int j = 0; j < 11; j++) {
            if (j == 0)
                tabuleiro[a][j] = a + 1;
            else
                tabuleiro[a][j] = 0;
        }
    }

    printf("%c %c %c %c %c %c %c %c %c %c %c\n", linha[0], linha[1], linha[2], linha[3], linha[4], linha[5], linha[6], linha[7], linha[8], linha[9], linha[10]);
    
    tabuleiro[4][2] = 3;
    tabuleiro[4][3] = 3;
    tabuleiro[4][4] = 3;

    tabuleiro[6][5] = 3;
    tabuleiro[7][5] = 3;
    tabuleiro[8][5] = 3;

    for(int a = 0; a < 10; a++) {
        for(int j = 0; j < 11; j++) {
            printf("%d ", tabuleiro[a][j]);
        }
        printf("\n");
    }

    return 0;
}