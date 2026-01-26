#include <stdio.h>

#define TAM_TABULEIRO 10
#define TAM_NAVIO 3
#define AGUA 0
#define NAVIO 3

int main(void) {
    // Declaração e inicialização do tabuleiro (água = 0)
    int tabuleiro[TAM_TABULEIRO][TAM_TABULEIRO];
    
    for (int i = 0; i < TAM_TABULEIRO; i++) {
        for (int j = 0; j < TAM_TABULEIRO; j++) {
            tabuleiro[i][j] = AGUA;
        }
    }

    // Declaração dos navios (vetores unidimensionais)
    int navioHorizontal[TAM_NAVIO] = {NAVIO, NAVIO, NAVIO};
    int navioVertical[TAM_NAVIO]   = {NAVIO, NAVIO, NAVIO};

    // Coordenadas iniciais (linha, coluna)
    int linhaH = 2, colunaH = 3; // navio horizontal
    int linhaV = 5, colunaV = 6; // navio vertical

    // ===== Posicionamento do navio horizontal =====
    if (colunaH + TAM_NAVIO <= TAM_TABULEIRO) {
        int podePosicionar = 1;

        // Verifica sobreposição
        for (int i = 0; i < TAM_NAVIO; i++) {
            if (tabuleiro[linhaH][colunaH + i] != AGUA) {
                podePosicionar = 0;
            }
        }

        // Posiciona o navio
        if (podePosicionar) {
            for (int i = 0; i < TAM_NAVIO; i++) {
                tabuleiro[linhaH][colunaH + i] = navioHorizontal[i];
            }
        }
    }

    // ===== Posicionamento do navio vertical =====
    if (linhaV + TAM_NAVIO <= TAM_TABULEIRO) {
        int podePosicionar = 1;

        // Verifica sobreposição
        for (int i = 0; i < TAM_NAVIO; i++) {
            if (tabuleiro[linhaV + i][colunaV] != AGUA) {
                podePosicionar = 0;
            }
        }

        // Posiciona o navio
        if (podePosicionar) {
            for (int i = 0; i < TAM_NAVIO; i++) {
                tabuleiro[linhaV + i][colunaV] = navioVertical[i];
            }
        }
    }

    // ===== Exibição do tabuleiro =====
    printf("Tabuleiro Batalha Naval:\n\n");

    for (int i = 0; i < TAM_TABULEIRO; i++) {
        for (int j = 0; j < TAM_TABULEIRO; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }

    return 0;
}
