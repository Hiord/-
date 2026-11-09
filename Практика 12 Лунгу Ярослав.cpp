#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

// === ЗАХАРдкоженные данные лабиринта ===
const int N = 5;
const int M = 5;

vector<string> maze = {
    "S0P0P",
    "11110",
    "0P0P0",
    "01110",
    "000PE"
};
// =======================================

vector<vector<bool>> visited;
int max_pdfs = -1; // -1 означает, что выход не найден

// Направления: вверх, вниз, влево, вправо
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};

void dfs(int x, int y, int current_pdfs) {
    if (x < 0 || x >= N || y < 0 || y >= M) return;
    if (maze[x][y] == '1' || visited[x][y]) return;

    if (maze[x][y] == 'E') {
        max_pdfs = max(max_pdfs, current_pdfs);
        return;
    }

    visited[x][y] = true;

    int new_pdfs = current_pdfs;
    if (maze[x][y] == 'P') {
        new_pdfs++;
    }

    for (int i = 0; i < 4; ++i) {
        dfs(x + dx[i], y + dy[i], new_pdfs);
    }

    visited[x][y] = false; // backtracking
}

int main() {
    visited.assign(N, vector<bool>(M, false));

    int start_x = 0, start_y = 0;
    bool start_found = false;

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            if (maze[i][j] == 'S') {
                start_x = i;
                start_y = j;
                start_found = true;
            }
        }
    }

    if (!start_found) {
        cout << "Стартовая позиция 'S' не найдена!" << endl;
        return 0;
    }

    int initial_pdfs = (maze[start_x][start_y] == 'P') ? 1 : 0;

    dfs(start_x, start_y, initial_pdfs);

    if (max_pdfs == -1) {
        cout << "Выход не найден!" << endl;
    } else {
        cout << "Максимальное количество PDF: " << max_pdfs << endl;
    }

    return 0;
}