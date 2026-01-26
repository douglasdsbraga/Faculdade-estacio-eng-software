#include <stdio.h>

/**
 * Super Trunfo: Países - Nível Novato
 * Objetivo: Cadastro e exibição de duas cartas sem uso de loops ou condicionais.
 */

int main() {
    // Variáveis para a Carta 1
    char estado1;
    char codigo1[4];
    char nomeCidade1[50];
    int populacao1;
    float area1;
    float pib1;
    int pontosTuristicos1;

    // Variáveis para a Carta 2
    char estado2;
    char codigo2[4];
    char nomeCidade2[50];
    int populacao2;
    float area2;
    float pib2;
    int pontosTuristicos2;

    // --- CADASTRO DA CARTA 1 ---
    printf("--- Cadastro da Carta 1 ---\n");
    printf("Estado (A-H): ");
    scanf(" %c", &estado1); // O espaço antes de %c limpa o 'enter' do buffer
    
    printf("Código da Carta (ex: A01): ");
    scanf("%s", codigo1);
    
    printf("Nome da Cidade: ");
    scanf(" %[^\n]", nomeCidade1); // Lê a string inclusive com espaços até o 'enter'
    
    printf("População: ");
    scanf("%d", &populacao1);
    
    printf("Área (km²): ");
    scanf("%f", &area1);
    
    printf("PIB (bilhões de reais): ");
    scanf("%f", &pib1);
    
    printf("Número de Pontos Turísticos: ");
    scanf("%d", &pontosTuristicos1);

    // --- CADASTRO DA CARTA 2 ---
    printf("\n--- Cadastro da Carta 2 ---\n");
    printf("Estado (A-H): ");
    scanf(" %c", &estado2);
    
    printf("Código da Carta: ");
    scanf("%s", codigo2);
    
    printf("Nome da Cidade: ");
    scanf(" %[^\n]", nomeCidade2);
    
    printf("População: ");
    scanf("%d", &populacao2);
    
    printf("Área (km²): ");
    scanf("%f", &area2);
    
    printf("PIB (bilhões de reais): ");
    scanf("%f", &pib2);
    
    printf("Número de Pontos Turísticos: ");
    scanf("%d", &pontosTuristicos2);

    // --- EXIBIÇÃO DOS DADOS ---
    printf("\n============================\n");
    printf("      CARTAS CADASTRADAS     \n");
    printf("============================\n");

    printf("\nCarta 1:\n");
    printf("Estado: %c\n", estado1);
    printf("Código: %s\n", codigo1);
    printf("Nome da Cidade: %s\n", nomeCidade1);
    printf("População: %d\n", populacao1);
    printf("Área: %.2f km²\n", area1);
    printf("PIB: %.2f bilhões de reais\n", pib1);
    printf("Pontos Turísticos: %d\n", pontosTuristicos1);

    printf("\nCarta 2:\n");
    printf("Estado: %c\n", estado2);
    printf("Código: %s\n", codigo2);
    printf("Nome da Cidade: %s\n", nomeCidade2);
    printf("População: %d\n", populacao2);
    printf("Área: %.2f km²\n", area2);
    printf("PIB: %.2f bilhões de reais\n", pib2);
    printf("Pontos Turísticos: %d\n", pontosTuristicos2);

    return 0;
}