# Super Trunfo: pensado na experiência do usuario + Logica

## Descrição
Este projeto é uma implementação avançada do jogo Super Trunfo, focada em cidades. O diferencial desta versão é a união entre os requisitos técnicos de lógica da linguagem C com princípios de Product Design e User Experience (UX). O programa permite comparar atributos de cidades e determinar uma vencedora com base em critérios dinâmicos e somas ponderadas.

## Diferenciais:
1. Arquitetura de Caminho Duplo (UX):
O usuario pode escolher entre duas jornadas ao iniciar o programa:
- Modo Teste: Carrega automaticamente dados reais (São Paulo vs Buenos Aires) para uma validação rápida da lógica.
- Modo Personalizado: Permite o cadastro completo de novas cartas em tempo de execução.

2. Tratamento de Strings e Buffers
Diferente de implementações básicas, este código utiliza:
- Leitura com espaços: scanf(" %[^\n]s", ...) para permitir nomes de cidades e pontos turísticos compostos (ex: "Rio de Janeiro").
- Listagem por vírgulas: O usuario pode listar vários pontos turísticos numa única entrada, enriquecendo a apresentação visual.
- Limpeza de Buffer: Uso de while(getchar() != '\n') para evitar que caracteres residuais do teclado causem saltos indesejados no fluxo do programa.

3. Normalização de Grandezas Inversas
Um desafio técnico em jogos de comparação é a Densidade Demográfica, onde o menor valor vence.
O Problema: Somar um valor de densidade alto (perdedor) a outros atributos criaria uma vitória injusta na soma total.

A Solução: Implementamos uma lógica de pesos. Ao comparar densidade, o sistema utiliza o inverso do valor -(1/valor) para a soma lógica, garantindo que o desempenho superior em densidade contribua positivamente para a vitória final.

## Tecnologias e Lógica Aplicada
- unsigned long long int: Utilizado para suportar grandes populações sem erro de overflow.
- Estruturas de Repetição (do-while): Garante que o jogo possa ser reiniciado sem fechar o terminal.
- Operadores Ternários: Utilizados para tornar a decisão de vitória concisa e elegante.
- Menus Dinâmicos: O segundo menu de atributos filtra automaticamente a primeira escolha, evitando que o utilizador compare um atributo com ele mesmo.

## Como Executar

Certifique-se de ter um compilador C (GCC, Clang) instalado.

Compile o ficheiro:

```
gcc super_trunfo.c -o super_trunfo
```

Execute:
```
./super_trunfo
```

## Sobre minha visão do projeto:

Como UX Engineer com mais de 15 anos de experiência no ecossistema JavaScript, a minha abordagem neste desafio de C foi além da sintaxe básica. Apliquei princípios de arquitetura de interfaces e robustez de dados que utilizo no meu dia a dia profissional. 

O objetivo foi transformar um exercício académico num sistema resiliente, capaz de tratar inputs complexos, gerir buffers de memória de forma eficiente e garantir que a lógica matemática (como a normalização da densidade) esteja sempre alinhada com a experiência do utilizador final.
