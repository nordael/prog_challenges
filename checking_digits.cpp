/**
 * @brief O método da "prova dos noves" é quase equivalente a chamada "raiz digital", que envolve pegar um número e repetir o
 * processo de soma digital várias vezes (por exemplo, a soma digital de 21=2+1=3). Elas só não são equivalentes em
 * relação aos múltiplos de nove, pois a soma digital de um múltiplo de nove não-zero é 9, enquanto que o método da
 * "prova dos noves" iria resultar em 0. De toda forma, ambas são equivalentes (mod 9).
 * É possível provar que a "raiz digital" (mod9) e o método da "prova dos noves" (mod 9) são na verdade equivalentes
 * ao próprio número (mod 9). Isso permite que as propriedades dos números modulares seja extrapolada para esses outros
 * métodos, o que permite que somas, subtrações, multiplicações e divisões sejam verificadas:
 *
 * dr(a1+a2)=dr(dr(a)+dr(b))
 * dr(ab)=dr(dr(a)dr(b))
 *
 * Isso significa que se fizermos uma operação de soma ou de multiplicação, podemos fazer a raiz digital (mod 9) de
 * forma separada nos operandos e na resposta, e o resultado tem que ser idêntico, temos então um dígito verificador.
 *
 * Sabendo de tudo isso, vamos ajudar Nisa a achar os erros nas contas de Kushim usando o método dos
 * "múltiplos de nove". Primeiro, transcrevemos nossas tabelas de multiplicação (assim como nos tablets de Kushim) e
 * números iniciais numa fita contínua para facilitar o reuso dos números e vamos verificar se o resultado da nossa
 * soma ou multiplicação resulta no mesmo dígito verificador que é esperado. Vamos então ir colocando nos tablets os
 * resultados das somas, até chegarmos na resposta final!
 * Input
 * Na primeira linha, é dado o inteiro N (1≤N≤10⁵), o tamanho da fita de números. A linha que vem a seguir contém a
 * fita de números que é uma sequência de dígitos. A próxima linha contém o inteiro Q (1≤N≤10⁵), o número de
 * operações que vamos realizar. Em seguida, seguem Q linhas, cada uma com uma operação. No começo de cada linha há
 * um identificador de operação inteiro O:
 * Para O=1 ou O=2, sendo que 1 representa soma e 2 representa multiplicação, temos dois inteiros A1,B1 (1≤A1≤B1≤N),
 * dois inteiros A2,B2 (1≤A2≤B2≤N) e o dígito de verificação obtido D (0≤D≤8). Os inteiros A1 e B1 representam o
 * início e o fim inclusivo do primeiro operando na fita, enquanto que A2 e B2 representam o início e o fim inclusivo
 * do segundo operando na fita.
 * Para O=3, temos um inteiro P (1≤P≤N) e um inteiro D (0≤D≤9) que representam uma posição na fita e um dígito que
 * será colocado naquela posição. Qualquer dígito previamente naquela posição é apagado.
 *
 * Output
 * Para cada operação O=1 ou O=2, imprima 'YES' se o dígito D informado bate com a raiz digital do resultado da
 * operação (mod9), ou 'NO' se não.
 * @todo Implementar solução e otimizar o algoritmo
 **/

