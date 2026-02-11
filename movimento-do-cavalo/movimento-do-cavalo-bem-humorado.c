#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#ifdef _WIN32
    #include <windows.h>
    #define PAUSA(s) Sleep((s) * 1000)
#else
    #include <unistd.h>
    #define PAUSA(s) sleep(s)
#endif

#define TAM 8
char matriz[TAM][TAM];
char nome[] = "douglasdesouzabraga";
int letraIdx = 0, rastroContador = 0;

void limparMatriz() {
    for (int i = 0; i < TAM; i++)
        for (int j = 0; j < TAM; j++) matriz[i][j] = '.';
    rastroContador = 0;
}

void renderizar(int cx, int cy) {
    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif
    printf("Rastro: %d/10 | DouglasDeSouzaBraga\n", rastroContador);
    printf("      0 1 2 3 4 5 6 7\n    +-----------------+\n");
    for (int i = 0; i < TAM; i++) {
        printf("  %d | ", i);
        for (int j = 0; j < TAM; j++) {
            if (i == cy && j == cx) printf("C ");
            else printf("%c ", matriz[i][j]);
        }
        printf("|\n");
    }
    printf("    +-----------------+\n");
}

int carimbar(int x, int y) {
    if (rastroContador >= 10) return 1;
    matriz[y][x] = nome[letraIdx];
    letraIdx = (letraIdx + 1) % strlen(nome);
    rastroContador++;
    return 0;
}

void moverCavaloBobo(int *px, int *py) {
    // --- DEBUG: CRISE DE MEMÓRIA ---
    if (rastroContador >= 10) {
        printf("\n[Cavalo]: Eita! Minha cauda ta enorme, to parecendo um pavao! 🦚\n");
        printf("[Cavalo]: Vou apagar tudo pra nao tropecar... pera ai!\n");
        PAUSA(3);
        limparMatriz();
        return;
    }

    int dx[] = {1, 2, 2, 1, -1, -2, -2, -1}, dy[] = {-2, -1, 1, 2, 2, 1, -1, -2};
    int nX = -1, nY = -1;

    printf("\n[Cavalo]: Hm... deixa eu ver pra onde eu vou... 🐴\n");
    PAUSA(1);

    // --- DEBUG: PENSANDO NAS OPÇÕES ---
    for (int i = 0; i < 8; i++) {
        int tx = *px + dx[i], ty = *py + dy[i];
        if (tx >= 0 && tx < TAM && ty >= 0 && ty < TAM) {
            if (matriz[ty][tx] == '.') {
                nX = tx; nY = ty;
                printf("[Cavalo]: Achei! Vou pra (%d, %d), parece limpinho!\n", nX, nY);
                PAUSA(1);
                break;
            } else {
                printf("[Cavalo]: Posicao (%d, %d) tem cheiro de rastro... passo!\n", tx, ty);
            }
        } else {
            printf("[Cavalo]: OPA! (%d, %d) eh abismo! Quase caio da matriz!\n", tx, ty);
        }
    }

    // --- DEBUG: SEM SAÍDA ---
    if (nX == -1) {
        printf("\n[Cavalo]: SOCORRO! To cercado! Nao tem buraquinho livre! 😰\n");
        printf("[Cavalo]: Vou dar um reset na mente pra nao bugar...\n");
        PAUSA(2);
        limparMatriz();
        return;
    }

    // Execução do Movimento
    int sY = (nY > *py) ? 1 : -1, sX = (nX > *px) ? 1 : -1;
    for (int i = 0; i < 2; i++) {
        if (carimbar(*px, *py)) break;
        *py += sY;
        renderizar(*px, *py);
        for(long d = 0; d < 10000000; d++);
    }
    if (rastroContador < 10) {
        carimbar(*px, *py);
        *px += sX;
        renderizar(*px, *py);
    }
}

int main(void) {
    int x = 4, y = 4, op;
    limparMatriz();
    while(1) {
        renderizar(x, y);
        printf("\n1 - Saltar (Ouvir o Cavalo)\n0 - Sair\nEscolha: ");
        if(scanf("%d", &op) != 1 || op == 0) break;
        if(op == 1) moverCavaloBobo(&x, &y);
    }
    return 0;
}
