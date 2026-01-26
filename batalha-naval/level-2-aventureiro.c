#include <stdio.h>

/**
 * Batalha Naval - Nível Aventureiro
 * Objetivo: Posicionar navios horizontais, verticais e diagonais em uma matriz 10x10.
 */

#define TAMANHO 10
#define NAVIO 3
#define AGUA 0

// Função para exibir o tabuleiro de forma organizada
void exibirTabuleiro(int tabuleiro[TAMANHO][TAMANHO]) {
    printf("   ");
    for (int i = 0; i < TAMANHO; i++) printf("%d ", i); // Cabeçalho de colunas
    printf("\n");

    for (int i = 0; i < TAMANHO; i++) {
        printf("%d  ", i); // Índice da linha
        for (int j = 0; j < TAMANHO; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }
}

int main(void) {
    // 1. Criar e inicializar o tabuleiro 10x10 com 0 (água)
    int tabuleiro[TAMANHO][TAMANHO] = {0};

    // --- POSICIONAMENTO DOS NAVIOS (Tamanho fixo = 3) ---

    // Navio 1: Horizontal (Linha 2, Colunas 1, 2, 3)
    for (int j = 1; j <= 3; j++) {
        tabuleiro[2][j] = NAVIO;
    }

    // Navio 2: Vertical (Linha 5, 6, 7, Coluna 8)
    for (int i = 5; i <= 7; i++) {
        tabuleiro[i][8] = NAVIO;
    }

    // Navio 3: Diagonal Principal (Linha e Coluna aumentam: (1,1), (2,2), (3,3))
    // Nota: Como (2,2) já estaria ocupado pelo Navio 1, vamos mudar a posição
    for (int i = 0; i < 3; i++) {
        // Posicionando em (6,1), (7,2), (8,3)
        tabuleiro[6 + i][1 + i] = NAVIO;
    }

    // Navio 4: Diagonal Secundária (Linha aumenta, Coluna diminui: (1,9), (2,8), (3,7))
    for (int i = 0; i < 3; i++) {
        tabuleiro[1 + i][9 - i] = NAVIO;
    }

    // 2. Exibição do resultado
    printf("--- TABULEIRO BATALHA NAVAL (NÍVEL AVENTUREIRO) ---\n\n");
    exibirTabuleiro(tabuleiro);

    return 0;
}
