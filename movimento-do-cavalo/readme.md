# Abordagem: UX-First Programming

Como Designer de Produto e UX Engineer, a prioridade deste projeto não foi apenas a lógica matemática do Cavalo, mas a robustez e o feedback do sistema. Abaixo, os pilares da implementação:

## Separação entre Modelo Lógico e Visual:

### A matriz real de processamento é estritamente 8x8.

A interface (render) simula uma moldura 10x10 apenas para conforto visual e affordance das coordenadas. Isso evita confusão de índices por parte do usuário.

### Sistema de Prevenção de Erros (Constraints):

Em vez de permitir que o usuário cometa um erro de movimentação, o sistema possui uma IA Preditiva. Ela escaneia as 8 direções de salto e bloqueia preventivamente qualquer tentativa que rompa os limites da matriz ou colida com o próprio rastro.

### Feedback Heurístico (Arquétipo de Debug):

Utilizei o conceito de "Pensamento em Voz Alta" (Talk-aloud protocol). O programa narra o processo de tomada de decisão do "Cavalo Bobo". Se ele fica preso ou precisa limpar a memória, ele informa o porquê. Isso reduz a carga cognitiva e elimina a incerteza do usuário sobre o que o software está fazendo.

### Gerenciamento de Rastro (Buffer Circular):

O limite de 10 letras é tratado como uma restrição física de "cauda". A limpeza automática (reset) é implementada como uma função de "Garbage Collection" manual, garantindo que o tabuleiro nunca fique ilegível.

## Por que fiz dessa forma?

No desenvolvimento de produtos, um sistema que falha silenciosamente é um sistema ruim. Apliquei os conceitos de Nielsen e Norman (visibilidade do estado do sistema e prevenção de erros) para garantir que, mesmo em uma linguagem de baixo nível como C, a experiência do usuário seja fluida, informativa e, acima de tudo, impossível de quebrar por uso indevido.