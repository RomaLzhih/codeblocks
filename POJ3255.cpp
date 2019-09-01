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
    int to, weight;
    Edge(int to, int weight) : to(to), weight(weight) {}
};
vector<vector<Edge> > G(MAXN);  //更快
struct Dijkstra {               //打包在Dijkstra中
    int n, m;
    bool done[MAXN];
    int dist[MAXN];   //最短路
    int dist2[MAXN];  //次短路
    int p[MAXN];
    Dijkstra(int n) : n(n) {
        for (int i = 1; i <= n; i++) G[i].clear();
    }
    void AddEdge(int from, int to, int weight) {
        G[from].push_back(Edge(to, weight));  //保存from出发的边
    }
    void dijkstra(int s) {
        priority_queue<pii, vector<pii>, greater<pii> > Q;
        memset(dist, 0x7f, sizeof(dist));  //初始化为无穷大
        memset(dist2, 0x7f, sizeof(dist2));
        memset(done, false, sizeof(done));

        dist[s] = 0;
        Q.push(pii(0, s));  // pii (dist ,u)
        while (!Q.empty()) {
            pii P = Q.top();
            Q.pop();
            int d = P.first, u = P.second;
            // if (dist2[u] < d) continue;
            for (int i = 0; i < G[u].size(); i++) {
                Edge& e = G[u][i];
                int v = e.to, w = e.weight;
                int d2 = d + w;
                if (dist[v] > d2) {
                    swap(dist[v], d2);  // d2此时为次短路
                    Q.push(pii(dist[v], v));
                }
                if (dist2[v] > d2 && dist[v] < d2) {
                    dist2[v] = d2;
                    Q.push(pii(dist2[v], v));
                }
            }
        }
    }
};
int N, R;
int main() {
    // freopen("input.txt", "r", stdin);
    N = READ(), R = READ();
    Dijkstra Men(N);
    int u, v, w;
    REP(i, 1, R) {
        u = READ(), v = READ(), w = READ();
        Men.AddEdge(u, v, w);
        Men.AddEdge(v, u, w);
    }
    Men.dijkstra(1);
    cout << Men.dist2[N] << endl;
    return 0;
}