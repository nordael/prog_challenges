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

#include<bits/stdc++.h>
using namespace std;

const int MAX_N = 1000;
char grid[MAX_N][MAX_N];
bool visited[MAX_N][MAX_N];
pair<int, int> start, _end;
pair<int, int> parent[MAX_N][MAX_N];
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};
char dir[] = {'U', 'R', 'D', 'L'};
int n, m;

bool isValid(int x, int y) {
    return x >= 0 && x < n && y >= 0 && y < m && grid[x][y] != '#';
}

void bfs() {
    queue<pair<int, int>> q;
    q.push(start);
    visited[start.first][start.second] = true;

    while(!q.empty()) {
        pair<int, int> node = q.front();
        q.pop();

        for(int i = 0; i < 4; i++) {
            int nx = node.first + dx[i];
            int ny = node.second + dy[i];

            if(isValid(nx, ny) && !visited[nx][ny]) {
                visited[nx][ny] = true;
                parent[nx][ny] = node;
                q.push({nx, ny});
            }
        }
    }
}

int main() {
    cin >> n >> m;

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin >> grid[i][j];
            if(grid[i][j] == 'A') {
                start = {i, j};
            }
            if(grid[i][j] == 'B') {
                _end = {i, j};
            }
        }
    }

    bfs();

    if(!visited[_end.first][_end.second]) {
        cout << "NO" << endl;
        return 0;
    }

    vector<char> path;
    for(pair<int, int> v = _end; v != start; v = parent[v.first][v.second]) {
        int px = parent[v.first][v.second].first;
        int py = parent[v.first][v.second].second;

        for(int i = 0; i < 4; i++) {
            if(px + dx[i] == v.first && py + dy[i] == v.second) {
                path.push_back(dir[i]);
            }
        }
    }

    reverse(path.begin(), path.end());

    cout << "YES" << endl;
    cout << path.size() << endl;
    for(char c : path) {
        cout << c;
    }
    cout << endl;

    return 0;
}
