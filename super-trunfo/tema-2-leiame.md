# tema 2: fundamentos

Fiz todos os desafios, e todos eles estão aqui na pasta "Super Trunfo". Sobre o desafio level metre ( /super-trunfo/level-3-a-batalha-final.c ), fui um pouquinho além do enunciado pois levei em consideração algumas coisas:

1) Segurança Contra Divisão por Zero: Os blocos if (area1 > 0) e if (populacao1 > 0) evitam que o programa quebre se o usuário digitar dados inválidos.

2) Tratamento de Empates: No nível mestre, os desafios costumam ignorar empates, mas na vida real eles existem. Adicionar o else { printf("Empate"); } deixa o jogo completo.

3) Precisão (double): Usar %lf com double para dar de fato "Super Poderes" para o cálculos, onde pequenas casas decimais podem decidir o vencedor.

4) Limitação de String: O %3s no código da carta evita o famoso buffer overflow (quando o usuário digita mais do que a memória aguenta).


