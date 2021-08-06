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
#define MAXN 1000 + 5
#define MAXM 200000 + 5
///**********************************START*********************************///
int N, M, ans;
int p[MAXN];
struct Edge {
    int v, w, next;
} edge[MAXM];
struct Node {
    int u, cost, fuel;
    bool operator<(const Node& a) const { return a.cost < cost; }
};
int head[MAXN], tot;
int d[MAXN][200 + 10];
int vis[MAXN][220];
void add_edge(int u, int v, int w) {
    edge[tot].v = v;
    edge[tot].w = w;
    edge[tot].next = head[u];
    head[u] = tot++;
}
bool RUN(int c, int s, int e) {
    memset(vis, 0, sizeof(vis));
    memset(d, 0x3f, sizeof(d));
    d[s][0] = 0;
    priority_queue<Node> q;
    q.push(Node{s, 0, 0});
    while (!q.empty()) {
        Node now = q.top();
        q.pop();
        int u = now.u, cost = now.cost, fuel = now.fuel;
        Node qq;
        // cout << u << " " << cost << " " << fuel << endl;
        if (u == e) {
            ans = cost;
            return true;
        }
        vis[u][fuel] = 1;
        if (fuel < c && !vis[u][fuel + 1] &&
            d[u][fuel] + p[u] < d[u][fuel + 1]) {
            d[u][fuel + 1] = d[u][fuel] + p[u];
            Node qq = Node{u, d[u][fuel] + p[u], fuel + 1};
            q.push(qq);
        }
        for (int i = head[u]; ~i; i = edge[i].next) {
            int v = edge[i].v, w = edge[i].w;
            if (w <= fuel && !vis[v][fuel - w] && cost < d[v][fuel - w]) {
                d[v][fuel - w] = cost;
                Node qq = Node{v, cost, fuel - w};
                q.push(qq);
            }
        }
    }
    return false;
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
#endif
    SET(head);
    scanf("%d%d", &N, &M);
    rep(i, 1, N) p[i - 1] = READ();
    rep(i, 1, M) {
        int u = READ(), v = READ(), w = READ();
        add_edge(u, v, w);
        add_edge(v, u, w);
    }
    int T = READ();
    while (T--) {
        int c = READ(), s = READ(), e = READ();
        if (RUN(c, s, e)) {
            printf("%d\n", ans);
        } else {
            puts("impossible");
        }
    }
    int a = 0;
    return 0;
}