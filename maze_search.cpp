/**
 * Te é dado o mapa de um labirinto, e sua tarefa é achar um caminho do começo ao fim. Você pode andar para
 * esquerda, direita, pra cima ou para baixo.
 *
 * Input
 * A primeira linha da entrada contém os inteiros N e M (1≤N,M≤1000): a altura e largura do mapa. Então seguem
 * N linhas com M caracteres descrevendo o labirinto. Cada caractere é '.' (chão), '#' (parede), 'A' (começo),
 * ou 'B' (final). EXiste exatamente um 'A' e um 'B' na entrada.
 *
 * Output
 * Primeiro imprima 'YES', se existe um caminho, ou 'NO' se não existe. Se existe um caminho, imprima o tamanho
 * do menor caminho e sua descrição como uma string consistindo dos caracteres 'L' (esquerda), 'R' (direita),
 * 'U' (cima), e 'D' (baixo). Você pode imprimir qualquer solução válida.
 *
 * TODO: Precisa ser otimizado. Muito lento
 **/

#include <bits/stdc++.h>

using namespace std;

struct Point {
    int x, y;
};

// Função para verificar se uma posição (x, y) está dentro dos limites do labirinto
bool isValid(int x, int y, int N, int M) {
    return (x >= 0 && x < N && y >= 0 && y < M);
}

// Função para encontrar o caminho no labirinto usando busca em largura (BFS)
string findPath(vector<vector<char>>& maze, Point start, Point end) {
    int N = maze.size();
    int M = maze[0].size();

    // Vetor de visitados para evitar loops infinitos
    vector<vector<bool>> visited(N, vector<bool>(M, false));

    // Vetor de distâncias para armazenar a distância mínima de cada célula até o ponto de partida
    vector<vector<int>> distance(N, vector<int>(M, 0));

    // Vetor de direções possíveis (esquerda, direita, cima, baixo)
    vector<string> directions = {"U", "D", "L", "R"};
    vector<int> dx = {-1, 1, 0, 0};
    vector<int> dy = {0, 0, -1, 1};

    // Fila para BFS
    queue<Point> q;

    // Marcar o ponto de partida como visitado e adicioná-lo à fila
    visited[start.x][start.y] = true;
    q.push(start);

    // Executar BFS
    while (!q.empty()) {
        Point curr = q.front();
        q.pop();

        // Verificar se chegamos ao ponto de destino
        if (curr.x == end.x && curr.y == end.y) {
            // Construir a sequência de direções percorridas para alcançar o destino
            string path = "";
            int x = curr.x;
            int y = curr.y;
            while (x != start.x || y != start.y) {
                int d = distance[x][y];
                x -= dx[d];
                y -= dy[d];
                path = directions[d] + path;
            }
            return path;
        }

        // Explorar as direções possíveis (esquerda, direita, cima, baixo)
        for (int i = 0; i < 4; i++) {
            int newX = curr.x + dx[i];
            int newY = curr.y + dy[i];

            // Verificar se a nova posição é válida e ainda não foi visitada
            if (isValid(newX, newY, N, M) && maze[newX][newY] != '#' && !visited[newX][newY]) {
                visited[newX][newY] = true;
                distance[newX][newY] = i;
                q.push({newX, newY});
            }
        }
    }

    // Se chegamos aqui, não foi encontrado um caminho válido
    return "NO";
}

int main() {
    int N, M;
    cin >> N >> M;

    vector<vector<char>> maze(N, vector<char>(M));

    Point start, end;

    // Ler o labirinto
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> maze[i][j];
            if (maze[i][j] == 'A') {
                start = {i, j};
            } else if (maze[i][j] == 'B') {
                end = {i, j};
            }
        }
    }

    // Encontrar o caminho no labirinto
    string path = findPath(maze, start, end);

    if (path != "NO") {
        cout << "YES" << endl;
        cout << path.size() << endl;
        cout << path << endl;
    } else {
        cout << "NO" << endl;
    }

    return 0;
}