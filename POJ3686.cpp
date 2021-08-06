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
#define MAXN 5000 + 5
///**********************************START*********************************///
struct Edge {
    int from, to, cap, flow, cost;
    Edge(int u, int v, int c, int f, int w)
        : from(u), to(v), cap(c), flow(f), cost(w) {}
};

struct MCF {
    int n, m;
    vector<Edge> edges;
    vector<int> G[MAXN];
    int inq[MAXN];  // 是否在队列中
    int d[MAXN];    // Bellman-Ford
    int p[MAXN];    // 上一条弧
    int a[MAXN];    // 可改进量
    void init(int n) {
        this->n = n;
        for (int i = 0; i < n; i++) G[i].clear();
        edges.clear();
    }
    void AddEdge(int from, int to, int cap, int cost) {
        edges.push_back(Edge(from, to, cap, 0, cost));
        edges.push_back(Edge(to, from, 0, 0, -cost));
        m = edges.size();
        G[from].push_back(m - 2);
        G[to].push_back(m - 1);
    }
    bool BellmanFord(int s, int t, int flow_limit, int& flow, int& cost) {
        for (int i = 0; i < n; i++) d[i] = INF;
        memset(inq, 0, sizeof(inq));
        d[s] = 0;
        inq[s] = 1;
        p[s] = 0;
        a[s] = INF;

        queue<int> Q;
        Q.push(s);
        while (!Q.empty()) {
            int u = Q.front();
            Q.pop();
            inq[u] = 0;
            for (int i = 0; i < G[u].size(); i++) {
                Edge& e = edges[G[u][i]];
                if (e.cap > e.flow && d[e.to] > d[u] + e.cost) {
                    d[e.to] = d[u] + e.cost;
                    p[e.to] = G[u][i];
                    a[e.to] = min(a[u], e.cap - e.flow);
                    if (!inq[e.to]) {
                        Q.push(e.to);
                        inq[e.to] = 1;
                    }
                }
            }
        }
        if (d[t] == INF) return false;
        if (flow + a[t] > flow_limit) a[t] = flow_limit - flow;
        flow += a[t];
        cost += d[t] * a[t];
        for (int u = t; u != s; u = edges[p[u]].from) {
            edges[p[u]].flow += a[t];
            edges[p[u] ^ 1].flow -= a[t];
        }
        return true;
    }
    // 最小费用流（流量确定）
    // 需要保证初始网络中没有负权圈
    int MincostFlow(int s, int t, int flow_limit, int& cost) {
        int flow = 0;
        cost = 0;
        while (flow < flow_limit && BellmanFord(s, t, flow_limit, flow, cost))
            ;
        return flow;
    }
} Men;

int N, M;
int Z[550][550];

void solve() {
    // 0~N-1     玩具
    // N~2N-1    0号工厂
    // 2N~3N-1   1号工厂
    //..
    // MN~(M+1)N-1 M-1号工厂
    int s = N + N * M, t = s + 1;
    Men.init(t + 1);
    for (int i = 0; i < N; i++) {
        Men.AddEdge(s, i, 1, 0);
    }
    for (int j = 0; j < M; j++) {
        for (int k = 0; k < N; k++) {
            Men.AddEdge(N + j * N + k, t, 1, 0);
            for (int i = 0; i < N; i++) {
                Men.AddEdge(i, N + j * N + k, 1, Z[i][j] * (k + 1));
            }
        }
    }
    int cost;
    Men.MincostFlow(s, t, N, cost);
    printf("%.6f\n", (double)cost / N);
    return;
}

int main() {
#ifndef ONLINE_JUDGE
    FILE* stream1;
    freopen_s(&stream1, "input.txt", "r", stdin);
#endif  // !ONLINE_JUDGE
    int T = READ();
    while (T--) {
        getchar();
        memset(Z, 0, sizeof(Z));
        N = READ(), M = READ();
        REP(i, 0, N - 1) REP(j, 0, M - 1) Z[i][j] = READ();
        solve();
    }
    return 0;
}