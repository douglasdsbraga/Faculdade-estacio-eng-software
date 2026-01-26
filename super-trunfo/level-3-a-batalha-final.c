#include <stdio.h>

/**
 * Super Trunfo: Países - Nível Mestre
 * Objetivo: Comparação de atributos e cálculo de Super Poder.
 */

int main(void) {

    /* ---------- CARTA 1 ---------- */
    char estado1;
    char codigo1[4];
    char nome1[50];

    unsigned long int populacao1;
    double area1, pib1, densidade1, pibPerCapita1, superPoder1;
    int pontos1;

    /* ---------- CARTA 2 ---------- */
    char estado2;
    char codigo2[4];
    char nome2[50];

    unsigned long int populacao2;
    double area2, pib2, densidade2, pibPerCapita2, superPoder2;
    int pontos2;

    /* ---------- ENTRADA DE DADOS (CARTA 1) ---------- */
    printf("Cadastro da Carta 1:\n");

    printf("Estado (letra): ");
    scanf(" %c", &estado1);

    printf("Codigo (até 3 caracteres): ");
    scanf("%3s", codigo1);

    printf("Nome do país: ");
    scanf(" %[^\n]", nome1);

    printf("População: ");
    scanf("%lu", &populacao1);

    printf("Área (km²): ");
    scanf("%lf", &area1);

    printf("PIB (em bilhões): ");
    scanf("%lf", &pib1);

    printf("Pontos turísticos: ");
    scanf("%d", &pontos1);

    /* ---------- ENTRADA DE DADOS (CARTA 2) ---------- */
    printf("\nCadastro da Carta 2:\n");

    printf("Estado (letra): ");
    scanf(" %c", &estado2);

    printf("Codigo (até 3 caracteres): ");
    scanf("%3s", codigo2);

    printf("Nome do país: ");
    scanf(" %[^\n]", nome2);

    printf("População: ");
    scanf("%lu", &populacao2);

    printf("Área (km²): ");
    scanf("%lf", &area2);

    printf("PIB (em bilhões): ");
    scanf("%lf", &pib2);

    printf("Pontos turísticos: ");
    scanf("%d", &pontos2);

    /* ---------- CÁLCULOS ---------- */
    if (area1 > 0)
        densidade1 = (double)populacao1 / area1;
    else
        densidade1 = 0;

    if (area2 > 0)
        densidade2 = (double)populacao2 / area2;
    else
        densidade2 = 0;

    if (populacao1 > 0)
        pibPerCapita1 = (pib1 * 1e9) / (double)populacao1;
    else
        pibPerCapita1 = 0;

    if (populacao2 > 0)
        pibPerCapita2 = (pib2 * 1e9) / (double)populacao2;
    else
        pibPerCapita2 = 0;

    /* ---------- SUPER PODER ---------- */
    superPoder1 =
        (double)populacao1 +
        area1 +
        pib1 +
        pontos1 +
        pibPerCapita1 +
        (densidade1 > 0 ? 1.0 / densidade1 : 0);

    superPoder2 =
        (double)populacao2 +
        area2 +
        pib2 +
        pontos2 +
        pibPerCapita2 +
        (densidade2 > 0 ? 1.0 / densidade2 : 0);

    /* ---------- COMPARAÇÃO ---------- */
    printf("\n--- COMPARAÇÃO DE CARTAS ---\n");

    if (populacao1 > populacao2)
        printf("População: Carta 1 venceu\n");
    else if (populacao1 < populacao2)
        printf("População: Carta 2 venceu\n");
    else
        printf("População: Empate\n");

    if (area1 > area2)
        printf("Área: Carta 1 venceu\n");
    else if (area1 < area2)
        printf("Área: Carta 2 venceu\n");
    else
        printf("Área: Empate\n");

    if (pib1 > pib2)
        printf("PIB: Carta 1 venceu\n");
    else if (pib1 < pib2)
        printf("PIB: Carta 2 venceu\n");
    else
        printf("PIB: Empate\n");

    if (pontos1 > pontos2)
        printf("Pontos Turísticos: Carta 1 venceu\n");
    else if (pontos1 < pontos2)
        printf("Pontos Turísticos: Carta 2 venceu\n");
    else
        printf("Pontos Turísticos: Empate\n");

    /* Regra especial: menor densidade vence */
    if (densidade1 < densidade2)
        printf("Densidade Populacional: Carta 1 venceu\n");
    else if (densidade1 > densidade2)
        printf("Densidade Populacional: Carta 2 venceu\n");
    else
        printf("Densidade Populacional: Empate\n");

    if (pibPerCapita1 > pibPerCapita2)
        printf("PIB per Capita: Carta 1 venceu\n");
    else if (pibPerCapita1 < pibPerCapita2)
        printf("PIB per Capita: Carta 2 venceu\n");
    else
        printf("PIB per Capita: Empate\n");

    if (superPoder1 > superPoder2)
        printf("Super Poder: Carta 1 venceu\n");
    else if (superPoder1 < superPoder2)
        printf("Super Poder: Carta 2 venceu\n");
    else
        printf("Super Poder: Empate\n");

    return 0;
}
