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

#define REP(i, a, b) for (int i = (a); i < (b); i++)
#define PER(i, a, b) for (int i = (a); i > (b); i--)
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
#define MAXN 12 + 5
///**********************************START*********************************///
const int dx[4] = {0, 1, 0, -1};
const int dy[4] = {1, 0, -1, 0};

int X, Y;
char field[MAXN][MAXN];

vector<int> dX, dY;
vector<int> pX, pY;
int dist[MAXN][MAXN][MAXN][MAXN];

const int MAXV = 10001;
int V;                //顶点数
vector<int> G[MAXV];  //图的邻接表表示
int match[MAXV];      //所匹配的定点
bool used[MAXV];      // DFS中用到的访问标记

//添加无向边，注意顶点编号从0开始
void add_edge(int u, int v) {
    G[u].push_back(v);
    G[v].push_back(u);
}

//通过DFS寻找增广路
bool dfs(int v) {
    used[v] = true;
    for (int i = 0; i < G[v].size(); i++) {
        int u = G[v][i], w = match[u];
        if (w < 0 || !used[w] && dfs(w)) {
            match[v] = u;
            match[u] = v;
            return true;
        }
    }
    return false;
}

void bfs(int x, int y, int d[MAXN][MAXN]) {
    queue<int> qx, qy;
    d[x][y] = 0;
    qx.push(x);
    qy.push(y);
    while (!qx.empty()) {
        x = qx.front(), qx.pop();
        y = qy.front(), qy.pop();
        REP(i, 0, 4) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (nx >= 0 && nx < X && ny >= 0 && ny < Y &&
                field[nx][ny] == '.' && d[nx][ny] < 0) {
                d[nx][ny] = d[x][y] + 1;
                qx.push(nx);
                qy.push(ny);
            }
        }
    }
}

void solve() {
    int n = X * Y;

    //跑最短路
    REP(i, 0, dX.size()) bfs(dX[i], dY[i], dist[dX[i]][dY[i]]);

    // 加边
    int d = dX.size(), p = pX.size();
    V = X * Y * d + p;
    for (int v = 0; v < V; ++v) G[v].clear();
    REP(i, 0, d) REP(j, 0, p) {
        int o = dist[dX[i]][dY[i]][pX[j]][pY[j]];
        if (o >= 0) REP(k, o, n + 1) add_edge((k - 1) * d + i, n * d + j);
    }

    // 匹配
    if (p == 0) {
        printf("0\n");
        return;
    }
    int num = 0;  // 匹配数
    memset(match, -1, sizeof(match));
    for (int v = 0; v < n * d; v++) {
        // n*d是节点总数，每个门一个，把所有情况都跑一遍
        memset(used, 0, sizeof(used));
        if (dfs(v)) {
            if (++num == p) {
                printf("%d\n", v / d + 1);
                return;
            }
        }
    }
    printf("impossible\n");
}

int main() {
#ifndef ONLINE_JUDGE
    // freopen("input.txt", "r", stdin);
#endif  // !ONLINE_JUDGE
    int T = READ();
    while (T--) {
        dX.clear(), dY.clear();
        pX.clear(), pY.clear();
        CLR(field), SET(dist);
        X = READ();
        Y = READ();
        REP(i, 0, X) cin >> field[i];
        REP(i, 0, X) REP(j, 0, Y) {
            if (field[i][j] == 'D') {
                dX.push_back(i);
                dY.push_back(j);
            } else if (field[i][j] == '.') {
                pX.push_back(i);
                pY.push_back(j);
            }
        }
        solve();
    }
    return 0;
}