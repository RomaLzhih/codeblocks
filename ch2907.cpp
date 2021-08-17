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
#define MAXN 100 + 5
///**********************************START*********************************///
char g[MAXN][MAXN];
int N, M, X, Y, tot;
struct NODE {
    int x, y, t;
} S;
int vis[MAXN][MAXN];
int dx[] = {0, 0, 1, -1, 1, 1, -1, -1};
int dy[] = {1, -1, 0, 0, 1, -1, 1, -1};

bool check(int x, int y) {
    return x >= 0 && x < N && y >= 0 && y < M && g[x][y] != '*';
}

int bfs() {
    CLR(vis);
    queue<NODE> q;
    S.t = 0;
    q.push(S);
    vis[S.x][S.y] = 1;
    int cnt = 0;
    while (!q.empty()) {
        NODE now = q.front();
        q.pop();
        int x = now.x, y = now.y, nt = now.t;
        for (int i = 0; i < 8; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (!vis[nx][ny] && check(nx, ny)) {
                cnt++;
                if (cnt == tot) {
                    return nt + 1;
                }
                q.push(NODE{nx, ny, nt + 1});
                vis[nx][ny] = 1;
            }
        }
    }
    return -1;
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
#endif
    M = READ(), N = READ(), X = READ(), Y = READ();
    S.x = N - Y;
    S.y = X - 1;
    rep(i, 0, N - 1) scanf("%s", g[i]);
    rep(i, 0, N - 1) rep(j, 0, M - 1) tot += int(g[i][j] == '.');
    tot -= 1;
    printf("%d", bfs());
    return 0;
}