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
#define MAXN 1000 + 5
///**********************************START*********************************///
struct Edge {
    int from, to, w, next;
} e[10001];
int head[MAXN], vis[MAXN];
int dist[MAXN], sum[MAXN];
int n, m, w, tot;

void add_edge(int i, int j, int w) {
    e[tot].from = i, e[tot].to = j, e[tot].w = w;
    e[tot].next = head[i];
    head[i] = tot++;
}

int SPFA(int s) {
    queue<int> q;
    for (int i = 1; i <= n; i++) dist[i] = INF, sum[i] = 0;
    memset(vis, false, sizeof(vis));
    q.push(s);
    dist[s] = 0;
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        vis[u] = false;
        for (int i = head[u]; i != -1; i = e[i].next) {
            int v = e[i].to;
            if (dist[v] > dist[u] + e[i].w) {
                dist[v] = dist[u] + e[i].w;
                if (!vis[v]) {
                    vis[v] = true;
                    if (++sum[v] > n) return false;
                    q.push(v);
                }
            }
        }
    }
    return true;
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
#endif
    int F = READ();
    while (F--) {
        memset(head, -1, sizeof(head));
        tot = 0;
        scanf("%d%d%d", &n, &m, &w);
        int u, v, cost;
        REP(i, 1, m) {
            scanf("%d%d%d", &u, &v, &cost);
            add_edge(u, v, cost);
            add_edge(v, u, cost);
        }
        REP(i, 1, w) {
            scanf("%d%d%d", &u, &v, &cost);
            add_edge(u, v, -cost);
        }
        if (SPFA(1)) {
            printf("NO\n");
        } else {
            printf("YES\n");
        }
    }
    return 0;
}