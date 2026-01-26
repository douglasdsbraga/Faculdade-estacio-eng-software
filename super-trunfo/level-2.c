#include <stdio.h>

/**
 * Super Trunfo: Países - Nível Aventureiro
 * Objetivo: Calcular Densidade Populacional e PIB per Capita.
 */

int main(void) {
    // Variáveis Carta 1
    char estado1, codigo1[4], nomeCidade1[50];
    unsigned long int populacao1; // Usando unsigned long para populações grandes
    float area1, pib1, densidade1, pibPerCapita1;
    int pontos1;

    // Variáveis Carta 2
    char estado2, codigo2[4], nomeCidade2[50];
    unsigned long int populacao2;
    float area2, pib2, densidade2, pibPerCapita2;
    int pontos2;

    // --- ENTRADA DE DADOS CARTA 1 ---
    printf("Cadastro Carta 1:\n");
    printf("Estado: "); scanf(" %c", &estado1);
    printf("Código: "); scanf("%s", codigo1);
    printf("Nome: "); scanf(" %[^\n]", nomeCidade1);
    printf("População: "); scanf("%lu", &populacao1);
    printf("Área (km²): "); scanf("%f", &area1);
    printf("PIB: "); scanf("%f", &pib1);
    printf("Pontos Turísticos: "); scanf("%d", &pontos1);

    // --- CÁLCULOS CARTA 1 ---
    // Densidade = Habitantes / Área
    densidade1 = (float)populacao1 / area1;
    // PIB per Capita = PIB / População (convertendo bilhões para reais se necessário)
    pibPerCapita1 = (pib1 * 1000000000) / (float)populacao1;

    // --- ENTRADA DE DADOS CARTA 2 ---
    printf("\nCadastro Carta 2:\n");
    printf("Estado: "); scanf(" %c", &estado2);
    printf("Código: "); scanf("%s", codigo2);
    printf("Nome: "); scanf(" %[^\n]", nomeCidade2);
    printf("População: "); scanf("%lu", &populacao2);
    printf("Área (km²): "); scanf("%f", &area2);
    printf("PIB: "); scanf("%f", &pib2);
    printf("Pontos Turísticos: "); scanf("%d", &pontos2);

    // --- CÁLCULOS CARTA 2 ---
    densidade2 = (float)populacao2 / area2;
    pibPerCapita2 = (pib2 * 1000000000) / (float)populacao2;

    // --- EXIBIÇÃO ---
    printf("\n====================================\n");
    printf("CARTA 1 - %s\n", nomeCidade1);
    printf("Densidade Populacional: %.2f hab/km²\n", densidade1);
    printf("PIB per Capita: %.2f reais\n", pibPerCapita1);

    printf("\nCARTA 2 - %s\n", nomeCidade2);
    printf("Densidade Populacional: %.2f hab/km²\n", densidade2);
    printf("PIB per Capita: %.2f reais\n", pibPerCapita2);
    printf("====================================\n");

    return 0;
}
