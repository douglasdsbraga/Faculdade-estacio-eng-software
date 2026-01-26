#include <stdio.h>

#define TAM_TAB 10
#define TAM_HAB 5
#define AGUA 0
#define NAVIO 3
#define HABILIDADE 5

// Função para exibir o tabuleiro com caracteres legíveis
void exibirTabuleiro(int tabuleiro[TAM_TAB][TAM_TAB]) {
    printf("   ");
    for (int i = 0; i < TAM_TAB; i++) printf("%d ", i);
    printf("\n");

    for (int i = 0; i < TAM_TAB; i++) {
        printf("%d  ", i);
        for (int j = 0; j < TAM_TAB; j++) {
            if (tabuleiro[i][j] == AGUA) printf(". ");
            else if (tabuleiro[i][j] == NAVIO) printf("N ");
            else if (tabuleiro[i][j] == HABILIDADE) printf("X "); // Área de efeito
        }
        printf("\n");
    }
}

// Aplica a matriz de habilidade no tabuleiro principal com validação de bordas
void aplicarHabilidade(int tabuleiro[TAM_TAB][TAM_TAB], int habilidade[TAM_HAB][TAM_HAB], int origL, int origC) {
    int offset = TAM_HAB / 2; // Centraliza a matriz 5x5 no ponto escolhido

    for (int i = 0; i < TAM_HAB; i++) {
        for (int j = 0; j < TAM_HAB; j++) {
            if (habilidade[i][j] == 1) {
                int destinoL = origL + (i - offset);
                int destinoC = origC + (j - offset);

                // Validação: Garante que a habilidade não "vaze" para fora do tabuleiro
                if (destinoL >= 0 && destinoL < TAM_TAB && destinoC >= 0 && destinoC < TAM_TAB) {
                    // Não sobrescreve navios, apenas marca a área (ou conforme regra de negócio)
                    if (tabuleiro[destinoL][destinoC] == AGUA) {
                        tabuleiro[destinoL][destinoC] = HABILIDADE;
                    }
                }
            }
        }
    }
}

int main(void) {
    int tabuleiro[TAM_TAB][TAM_TAB] = {0};

    // --- 1. POSICIONAMENTO DOS NAVIOS (Mesmo do nível anterior) ---
    for (int j = 1; j <= 3; j++) tabuleiro[2][j] = NAVIO; // Horizontal
    for (int i = 5; i <= 7; i++) tabuleiro[i][8] = NAVIO; // Vertical

    // --- 2. DEFINIÇÃO DAS MATRIZES DE HABILIDADE (Lógica Dinâmica) ---
    int cone[TAM_HAB][TAM_HAB] = {0};
    int cruz[TAM_HAB][TAM_HAB] = {0};
    int octaedro[TAM_HAB][TAM_HAB] = {0};

    for (int i = 0; i < TAM_HAB; i++) {
        for (int j = 0; j < TAM_HAB; j++) {
            // Lógica do CONE (Triângulo para baixo)
            if (i == 0 && j == 2) cone[i][j] = 1;
            if (i == 1 && j >= 1 && j <= 3) cone[i][j] = 1;
            if (i == 2) cone[i][j] = 1;

            // Lógica da CRUZ
            if (i == 2 || j == 2) cruz[i][j] = 1;

            // Lógica do OCTAEDRO (Losango)
            // Distância de Manhattan: |x1-x2| + |y1-y2| <= raio
            if ( (i == 2 && (j >= 1 && j <= 3)) || (j == 2 && (i >= 1 && i <= 3)) ) {
                octaedro[i][j] = 1;
            }
        }
    }

    // --- 3. APLICAÇÃO NO TABULEIRO ---
    // Aplicando Cone na posição (2, 6)
    aplicarHabilidade(tabuleiro, cone, 2, 6);
    
    // Aplicando Cruz na posição (8, 2)
    aplicarHabilidade(tabuleiro, cruz, 8, 2);

    // --- 4. EXIBIÇÃO FINAL ---
    printf("--- BATALHA NAVAL: NÍVEL MESTRE  ---\n");
    printf("Legenda: . (Água) | N (Navio) | X (Habilidade)\n\n");
    exibirTabuleiro(tabuleiro);

    return 0;
}
