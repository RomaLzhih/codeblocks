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

#define REP(i, a, b) for (int i = (a); i <= (b); i++)
#define PER(i, a, b) for (int i = (a); i >= (b); i--)
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
#define MAXN 10000 + 5
///**********************************START*********************************///

struct Edge {
    int from, to, cap, flow;
};
struct Dinic {
    int n, m, s, t;
    vector<Edge> edges;
    vector<int> G[MAXN];
    bool vis[MAXN];
    int d[MAXN];
    int cur[MAXN];
    void init() {
        for (int i = 0; i < MAXN; i++) G[i].clear();
        edges.clear();
        memset(d, 0, sizeof(d));
    }
    void AddEdge(int from, int to, int cap) {
        edges.push_back({from, to, cap, 0});
        edges.push_back({to, from, 0, 0});
        m = edges.size();
        G[from].push_back(m - 2);
        G[to].push_back(m - 1);
    }
    bool BFS() {
        int x, i;
        memset(vis, 0, sizeof(vis));
        queue<int> Q;
        Q.push(s);
        d[s] = 0;
        vis[s] = 1;
        while (!Q.empty()) {
            x = Q.front(), Q.pop();
            for (i = 0; i < G[x].size(); i++) {
                Edge &e = edges[G[x][i]];
                if (!vis[e.to] && e.cap > e.flow) {
                    vis[e.to] = 1;
                    d[e.to] = d[x] + 1;
                    Q.push(e.to);
                }
            }
        }
        return vis[t];
    }
    int DFS(int x, int a) {
        if (x == t || a == 0) return a;
        int flow = 0, f;
        for (int &i = cur[x]; i < G[x].size(); i++) {
            Edge &e = edges[G[x][i]];
            if (d[x] + 1 == d[e.to] &&
                (f = DFS(e.to, min(a, e.cap - e.flow))) > 0) {
                e.flow += f;
                edges[G[x][i] ^ 1].flow -= f;
                flow += f;
                a -= f;
                if (a == 0) break;
            }
        }
        return flow;
    }
    int Maxflow(int s, int t) {
        this->s = s, this->t = t;
        int flow = 0;
        while (BFS()) {
            memset(cur, 0, sizeof(cur));
            flow += DFS(s, INF);
        }
        return flow;
    }
} Men;

int N, F, D;
int cnt;
vector<int> food[102];
vector<int> drink[102];
map<int, int> fd, cow1, cow2, dk;

void encode() {
    cnt = 0;
    REP(i, 1, F) fd[i] = ++cnt;
    REP(i, 1, N) cow1[i] = ++cnt;
    REP(i, 1, N) cow2[i] = ++cnt;
    REP(i, 1, D) dk[i] = ++cnt;
    ++cnt;
}

void solve() {
    encode();

    Men.init();
    int s = 0, t = cnt;

    // source to food
    for (int i = 1; i <= F; i++) {
        Men.AddEdge(s, fd[i], 1);
    }

    // food to cow1
    for (int i = 1; i <= F; i++) {
        for (int j = 0; j < food[i].size(); j++) {
            Men.AddEdge(fd[i], cow1[food[i][j]], 1);
        }
    }

    // cow1 to cow2
    for (int i = 1; i <= N; i++) {
        Men.AddEdge(cow1[i], cow2[i], 1);
        // cow2 to drink
        for (int j = 0; j < drink[i].size(); j++) {
            Men.AddEdge(cow2[i], dk[drink[i][j]], 1);
        }
    }

    // cow2 to target
    for (int i = 1; i <= D; i++) {
        Men.AddEdge(dk[i], t, 1);
    }

    cout << Men.Maxflow(s, t) << endl;

    return;
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
#endif  // !ONLINE_JUDGE
    N = READ(), F = READ(), D = READ();
    REP(i, 1, N) {
        int f = READ(), d = READ();
        REP(j, 1, f) {
            int o = READ();
            food[o].push_back(i);
        }
        REP(j, 1, d) {
            int o = READ();
            drink[i].push_back(o);
        }
    }
    solve();
    return 0;
}