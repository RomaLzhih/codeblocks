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
};
int head[MAXN], vis[MAXN];
int dist[MAXN];
int rev_head[MAXN];
int rev_dist[MAXN];
Edge e[100005], rev_e[100005];
int N, M, tot, X, rev_tot;

void add_edge(int i, int j, int w) {
    e[tot].from = i, e[tot].to = j, e[tot].w = w;
    e[tot].next = head[i];
    head[i] = tot++;
}

void add_rev_edge(int i, int j, int w) {
    rev_e[rev_tot].from = i, rev_e[rev_tot].to = j, rev_e[rev_tot].w = w;
    rev_e[rev_tot].next = rev_head[i];
    rev_head[i] = rev_tot++;
}

void SPFA(int s) {
    queue<int> q;
    for (int i = 1; i <= N; i++) dist[i] = INF;
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
                    q.push(v);
                }
            }
        }
    }
}

void rev_SPFA(int s) {
    queue<int> q;
    for (int i = 1; i <= N; i++) rev_dist[i] = INF;
    memset(vis, 0, sizeof(vis));
    q.push(s);
    rev_dist[s] = 0;
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        vis[u] = false;
        for (int i = rev_head[u]; i != -1; i = rev_e[i].next) {
            int v = rev_e[i].to;
            if (rev_dist[v] > rev_dist[u] + rev_e[i].w) {
                rev_dist[v] = rev_dist[u] + rev_e[i].w;
                if (!vis[v]) {
                    vis[v] = true;
                    q.push(v);
                }
            }
        }
    }
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
#endif
    scanf("%d%d%d", &N, &M, &X);
    tot = 0, rev_tot = 0;
    memset(head, -1, sizeof(head));
    memset(rev_head, -1, sizeof(rev_head));
    int u, v, w;
    for (int i = 1; i <= M; i++) {
        scanf("%d%d%d", &u, &v, &w);
        add_edge(u, v, w);
        add_rev_edge(v, u, w);
    }
    SPFA(X);
    rev_SPFA(X);
    int ans = -1;
    for (int i = 1; i <= N; i++) ans = max(ans, dist[i] + rev_dist[i]);
    printf("%d\n", ans);
    return 0;
}