#include <string.h>
#include <cstdio>
#include <iostream>
using namespace std;
const int maxn = 200;
const int dx[] = {0, 0, 1, -1, 1, 1, -1, -1};
const int dy[] = {1, -1, 0, 0, 1, -1, 1, -1};
int N, M;
int cnt = 0;
int g[maxn][maxn];
int ma[maxn][maxn];
int vis[maxn][maxn];

void dfs(int x, int y, int col) {
    vis[x][y] = 1;
    ma[x][y] = col;
    for (int i = 0; i < 8; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (nx >= 1 && nx <= N && ny >= 1 && ny <= M && g[nx][ny] &&
            !vis[nx][ny])
            dfs(nx, ny, col);
    }
    return;
}

int main() {
    scanf("%d %d", &N, &M);
    getchar();
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= M; j++) {
            char ch = getchar();
            g[i][j] = (ch == 'W');
        }
        getchar();
    }

    memset(vis, 0, sizeof(vis));
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= M; j++) {
            if (!vis[i][j] && g[i][j]) dfs(i, j, ++cnt);
        }
    }

    // for (int i = 1; i <= N; i++) {
    //     for (int j = 1; j <= M; j++) {
    //         cout << ma[i][j] << " ";
    //     }
    //     cout << endl;
    // }

    // for (int i = 1; i <= N; i++) {
    //     for (int j = 1; j <= M; j++) {
    //         cout << g[i][j] << " ";
    //     }
    //     cout << endl;
    // }

    cout << cnt << endl;
    return 0;
}
