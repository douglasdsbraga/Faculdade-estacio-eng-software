#include <stdio.h>
#include <string.h>

int main(void) {
    // Variáveis das Cartas
    char cidade1[50], cidade2[50];
    char pontosLista1[100], pontosLista2[100]; // Buffer maior para a lista por vírgulas
    unsigned long long int pop1, pop2;        // Suporta números muito grandes
    float area1, area2, pib1, pib2, dens1, dens2;
    int pontosQtd1, pontosQtd2;               // Valor numérico para o duelo técnico

    int escolhaCaminho = 0;
    int continuar = 0;

    do {
        printf("\n==============================================\n");
        printf("       SUPER TRUNFO - NIVEL MESTRE UX       \n");
        printf("==============================================\n");
        printf("1. Usar cartas pre-definidas (Modo Teste)\n");
        printf("2. Cadastrar novas cartas (Modo Personalizado)\n");
        printf("Escolha o seu caminho: ");
        scanf("%d", &escolhaCaminho);
        while(getchar() != '\n'); // Limpa o buffer após ler o número

        if (escolhaCaminho == 1) {
            // --- CENÁRIO A: DADOS FIXOS ---
            strcpy(cidade1, "Sao Paulo");
            strcpy(pontosLista1, "Av. Paulista, Parque Ibirapuera, MASP");
            pop1 = 12325000; area1 = 1521.11; pib1 = 711.28; pontosQtd1 = 50;

            strcpy(cidade2, "Buenos Aires");
            strcpy(pontosLista2, "Obelisco, Casa Rosada, Caminito");
            pop2 = 3120000; area2 = 203.00; pib2 = 450.50; pontosQtd2 = 35;
            
            printf("\n> MODO TESTE: %s vs %s carregados.\n", cidade1, cidade2);
        } else {
            // --- CENÁRIO B: CADASTRO DINÂMICO (Foco em UX) ---
            printf("\n--- CADASTRO DA CARTA 1 ---\nNome da Cidade: ");
            scanf(" %[^\n]s", cidade1);
            printf("Liste pontos turisticos (sep. por virgula): ");
            scanf(" %[^\n]s", pontosLista1);
            printf("Populacao: "); scanf("%llu", &pop1);
            printf("Area (km2): "); scanf("%f", &area1);
            printf("PIB (bilhoes): "); scanf("%f", &pib1);
            printf("Qtd. Pontos Turisticos (para o duelo): "); scanf("%d", &pontosQtd1);

            printf("\n--- CADASTRO DA CARTA 2 ---\nNome da Cidade: ");
            scanf(" %[^\n]s", cidade2);
            printf("Liste pontos turisticos (sep. por virgula): ");
            scanf(" %[^\n]s", pontosLista2);
            printf("Populacao: "); scanf("%llu", &pop2);
            printf("Area (km2): "); scanf("%f", &area2);
            printf("PIB (bilhoes): "); scanf("%f", &pib2);
            printf("Qtd. Pontos Turisticos (para o duelo): "); scanf("%d", &pontosQtd2);
        }

        // Processamento (Densidade)
        dens1 = (float)pop1 / area1;
        dens2 = (float)pop2 / area2;

        // --- CONTEXTO ANTES DO DUELO ---
        printf("\n==============================================\n");
        printf("PREPARANDO DUELO: %s VS %s\n", cidade1, cidade2);
        printf("Atrações de %s: %s\n", cidade1, pontosLista1);
        printf("Atrações de %s: %s\n", cidade2, pontosLista2);
        printf("==============================================\n");

        // --- MOTOR DE COMPARAÇÃO ---
        int opt1, opt2;
        float v1_c1, v1_c2, v2_c1, v2_c2;
        char nomeAt1[30], nomeAt2[30];

        printf("\nEscolha os atributos para comparar:\n");
        printf("1. Populacao | 2. Area | 3. PIB | 4. Qtd Pontos | 5. Densidade\n");
        printf("Atributo 1: ");
        scanf("%d", &opt1);

        switch (opt1) {
            case 1: v1_c1 = (float)pop1; v1_c2 = (float)pop2; strcpy(nomeAt1, "Populacao"); break;
            case 2: v1_c1 = area1; v1_c2 = area2; strcpy(nomeAt1, "Area"); break;
            case 3: v1_c1 = pib1; v1_c2 = pib2; strcpy(nomeAt1, "PIB"); break;
            case 4: v1_c1 = (float)pontosQtd1; v1_c2 = (float)pontosQtd2; strcpy(nomeAt1, "Qtd Pontos"); break;
            case 5: v1_c1 = dens1; v1_c2 = dens2; strcpy(nomeAt1, "Densidade"); break;
            default: printf("Invalido.\n"); continue;
        }

        printf("Atributo 2 (exceto %s): ", nomeAt1);
        scanf("%d", &opt2);
        if(opt1 == opt2) { printf("Atributos iguais! Reiniciando...\n"); continue; }

        switch (opt2) {
            case 1: v2_c1 = (float)pop1; v2_c2 = (float)pop2; strcpy(nomeAt2, "Populacao"); break;
            case 2: v2_c1 = area1; v2_c2 = area2; strcpy(nomeAt2, "Area"); break;
            case 3: v2_c1 = pib1; v2_c2 = pib2; strcpy(nomeAt2, "PIB"); break;
            case 4: v2_c1 = (float)pontosQtd1; v2_c2 = (float)pontosQtd2; strcpy(nomeAt2, "Qtd Pontos"); break;
            case 5: v2_c1 = dens1; v2_c2 = dens2; strcpy(nomeAt2, "Densidade"); break;
            default: printf("Invalido.\n"); continue;
        }

        // Aplicando lógica de decisão concisa, similar ao que utilizamos em ES6+
        int win1 = (opt1 == 5) ? (v1_c1 < v1_c2) : (v1_c1 > v1_c2);
        int win2 = (opt2 == 5) ? (v2_c1 < v2_c2) : (v2_c1 > v2_c2);

        // Normalização: Se for densidade, usamos 1/valor para que o menor some mais
        float peso1_c1 = (opt1 == 5) ? (1.0f / v1_c1) : v1_c1;
        float peso1_c2 = (opt1 == 5) ? (1.0f / v1_c2) : v1_c2;
        float peso2_c1 = (opt2 == 5) ? (1.0f / v2_c1) : v2_c1;
        float peso2_c2 = (opt2 == 5) ? (1.0f / v2_c2) : v2_c2;

        float somaLógica1 = peso1_c1 + peso2_c1;
        float somaLógica2 = peso1_c2 + peso2_c2;

        // --- EXIBIÇÃO DO RESULTADO ---
        printf("\n>>> RESULTADO FINAL: %s vs %s <<<\n", cidade1, cidade2);
        printf("- %s: %.2f vs %.2f (Vence: %s)\n", nomeAt1, v1_c1, v1_c2, win1 ? "Carta 1" : "Carta 2");
        printf("- %s: %.2f vs %.2f (Vence: %s)\n", nomeAt2, v2_c1, v2_c2, win2 ? "Carta 1" : "Carta 2");
        printf("- SOMA REAL DOS ATRIBUTOS: %.2f vs %.2f\n", (v1_c1 + v2_c1), (v1_c2 + v2_c2));

        if (somaLógica1 == somaLógica2) {
            printf("\n### STATUS: EMPATE TECNICO! ###\n");
        } else {
            printf("\n### VENCEDOR FINAL: %s ###\n", (somaLógica1 > somaLógica2) ? "CARTA 1" : "CARTA 2");
        }

        printf("\n------------------------------------------\n");
        printf("Deseja jogar novamente?\n1. Sim\n0. Sair\nEscolha: ");
        scanf("%d", &continuar);
        while(getchar() != '\n');

    } while (continuar == 1);

    printf("\nObrigado por utilizar o sistema Super Trunfo Mestre!\n");
    return 0;
}
