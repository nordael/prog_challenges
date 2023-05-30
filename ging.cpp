/** Ĝames gosta de ir a bingos beneficentes para passar o tempo. Num jogo clássico de Bingo, cada jogador recebe uma
 * cartela de tamanho 5×5, com uma seleção de números que não se repetem (menos o centro que é coringa, permitindo a
 * vitória com menos números na linha ou coluna). Cada coluna tem uma letra do nome do jogo, ou seja, a primeira coluna
 * é associada a letra B, a segunda a I, e assim por diante. Isso porquê o sorteio do jogo é feito com uma 75 bolinhas,
 * sendo que as 15 primeiras são para a letra B (1 a 15), outras 15 para a letra I (16 a 30), e etc. O sorteio é feito
 * com essas bolas que são retiradas quando são sorteadas, e ganha quem "acertar" um número de linhas ou colunas da sua
 * cartela, isto é, ter a sorte de serem sorteados os números que permitem fazer essa disposição.
 *
 * Porém, Ĝames ficou curioso em testar outras disposições. Ele inventou uma variação do Bingo chamada de Ĝing' que é
 * composta de uma cartela 4×4 e tem 13 bolas pra primeira coluna (1 a 13), 16 para a segunda (14 a 29), 17 para a
 * terceira (30 a 46) e 10 para a quarta (47 a 56). Além disso, na cartela existem dois espaços coringa: Um na linha 2
 * e coluna 2 e outro na linha 2 e coluna 3. Olhe como ficou uma cartela de Ĝing':
 *
 *      5  14  31  47
 *     11   *   *  55
 *     13  16  33  50
 *      1  29  40  56
 *
 * Mas essa é só uma das possíveis. Ĝames então agora quer saber quantas cartelas das suas variações de Bingo existem.
 * Como podem ser muitas, calcule a resposta (mod10⁹+7)
 *
 * Input
 *         A primeira linha da entrada é composta dos inteiros N (1≤N≤10⁴), a dimensão da cartela que é quadrada e
 *         C (0≤C≤min(10⁴,N2)), o número de coringas. Em seguida seguem N números Bi (1≤Bi≤10⁴) correspondentes a
 *         quantidade de bolas para cada uma das colunas do jogo. É garantido que há bolas suficientes para encher uma
 *         coluna. Em seguida seguem C linhas, cada uma descrevendo um coringa. A descrição do coringa é composta de dois
 *         inteiros I e J (1≤I,J≤N), correspondentes a linha I e colunas J da cartela. É garantido que todos os coringas
 *         são distintos.
 *
 * Output
 *         Imprima a quantidade de cartelas do Bingo descrito (mod10⁹+7)
**/

#include <bits/stdc++.h>

#define ullong unsigned long long

using namespace std;

int main() {
    ullong t;
    cin >> t;
    while (t--) {
        ullong n, k;
        cin >> n >> k;

        vector<pair<ullong, ullong>> factors(k);
        for (ullong i = 0; i < k; i++) {
            cin >> factors[i].first >> factors[i].second;
        }

        // Calculate (n-1) in terms of prime factors
        vector<pair<ullong, ullong>> ans(k);
        for (ullong i = 0; i < k; i++) {
            ullong p = factors[i].first;
            ullong e = factors[i].second;
            if (e == 1) {
                ans[i].first = p - 1;
                ans[i].second = 1;
            } else {
                ans[i].first = p;
                ans[i].second = e - 1;
            }
        }

        // Sort the factors by their prime values in decreasing order
        sort(ans.rbegin(), ans.rend());

        // Print the factors
        for (ullong i = 0; i < k; i++) {
            cout << ans[i].first << " " << ans[i].second << "\n";
        }
    }
    return 0;
}

