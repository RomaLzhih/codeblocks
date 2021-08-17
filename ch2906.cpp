#pragma GCC optimize(3)
#include <time.h>

#include <algorithm>
#include <bitset>
#include <cctype>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <deque>
#include <functional>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <utility>
#include <vector>
using namespace std;
const double EPS = 1e-9;
const int INF = 2147483647;
const long long LLINF = 9223372036854775807;
const double PI = acos(-1.0);

inline int READ() {
    char ch;
    while ((ch = getchar()) < 48 || 57 < ch)
        ;
    int ans = ch - 48;
    while (48 <= (ch = getchar()) && ch <= 57)
        ans = (ans << 3) + (ans << 1) + ch - 48;
    return ans;
}

#define rep(i, a, b) for (int i = (a); i <= (b); i++)
#define per(i, a, b) for (int i = (a); i >= (b); i--)
#define FOREACH(i, t) for (typeof(t.begin()) i = t.begin(); i != t.end(); i++)
#define MP(x, y) make_pair(x, y)
#define PB(x) push_back(x)
#define SET(a) memset(a, -1, sizeof(a))
#define CLR(a) memset(a, 0, sizeof(a))
#define MEM(a, x) memset(a, x, sizeof(a))
#define ALL(x) begin(x), end(x)
#define LL long long
#define Lson (index * 2)
#define Rson (index * 2 + 1)
#define pii pair<int, int>
#define pll pair<LL, LL>
#define MOD ((int)1000000007)
#define MAXN 200
///**********************************START*********************************///
char g[MAXN][MAXN];
int N, M;
int vis[MAXN][MAXN];
int dx[] = {1, 2, 2, 1, -1, -2, -2, -1};
int dy[] = {2, 1, -1, -2, -2, -1, 1, 2};
struct NODE {
    int x, y, t;
} K, H;

bool check(int x, int y) {
    return x >= 0 && x < N && y >= 0 && y < M && g[x][y] != '*';
}

int bfs() {
    int ans = 0;
    CLR(vis);
    queue<NODE> q;
    q.push(K);
    vis[K.x][K.y] = 1;
    while (!q.empty()) {
        NODE now = q.front();
        q.pop();
        int x = now.x, y = now.y, nt = now.t;
        for (int i = 0; i < 8; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (nx == H.x && ny == H.y) {
                return nt + 1;
            }
            if (!vis[nx][ny] && check(nx, ny)) {
                vis[nx][ny] = 1;
                q.push(NODE{nx, ny, nt + 1});
            }
        }
    }
    return ans;
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
#endif
    scanf("%d%d", &M, &N);
    rep(i, 0, N - 1) scanf("%s", g[i]);
    rep(i, 0, N - 1) rep(j, 0, M - 1) {
        if (g[i][j] == 'K') {
            K.x = i, K.y = j, K.t = 0;
        } else if (g[i][j] == 'H') {
            H.x = i, H.y = j, H.t = 0;
        }
    }
    printf("%d", bfs());
    return 0;
}