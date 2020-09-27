#include "iostream"
#include "stdio.h"
#include "string.h"
#define M 1009
#define inf 999999999
using namespace std;
const double EPS = 1e-9;
struct st {
    int u, v, w, next;
} edge[400009];
int head[M], dis[M], q[M], work[M], cnt[M], use[M], t;
int min(int a, int b) { return a < b ? a : b; }
void init() {
    t = 0;
    memset(head, -1, sizeof(head));
}
void add(int u, int v, int w) {
    edge[t].u = u;
    edge[t].v = v;
    edge[t].w = w;
    edge[t].next = head[u];
    head[u] = t++;

    edge[t].u = v;
    edge[t].v = u;
    edge[t].w = 0;
    edge[t].next = head[v];
    head[v] = t++;
}
int bfs(int S, int T) {
    int rear = 0;
    memset(dis, -1, sizeof(dis));
    dis[S] = 0;
    q[rear++] = S;
    for (int i = 0; i < rear; i++) {
        for (int j = head[q[i]]; j != -1; j = edge[j].next) {
            int v = edge[j].v;
            if (edge[j].w && dis[v] == -1) {
                dis[v] = dis[q[i]] + 1;
                q[rear++] = v;
                if (v == T) return 1;
            }
        }
    }
    return 0;
}
int dfs(int S, int a, int T) {
    if (S == T) return a;
    for (int &i = work[S]; i != -1; i = edge[i].next) {
        int v = edge[i].v;
        if (edge[i].w && dis[v] == dis[S] + 1) {
            int tt = dfs(v, min(a, edge[i].w), T);
            if (tt) {
                edge[i].w -= tt;
                edge[i ^ 1].w += tt;
                return tt;
            }
        }
    }
    return 0;
}
int Dinic(int S, int T) {
    int ans = 0;
    while (bfs(S, T)) {
        memcpy(work, head, sizeof(head));
        int tt = dfs(S, inf, T);
        while (tt) {
            ans += tt;
            tt = dfs(S, inf, T);
        }
    }
    return ans;
}
void DFS(int S) {
    use[S] = 1;
    for (int i = head[S]; i != -1; i = edge[i].next) {
        int v = edge[i].v;
        if (!use[v] && edge[i].w) DFS(v);
    }
}
int main() {
    int T, m, k, n, a, b, c, kk = 1, i;
    scanf("%d", &T);
    while (T--) {
        scanf("%d%d%d", &n, &m, &k);
        init();
        int sum = 0;
        while (m--) {
            scanf("%d%d%d", &a, &b, &c);
            add(a, b, c);
        }
        while (k--) {
            scanf("%d%d", &a, &c);
            add(a, n + 1, c);
            sum += c;
        }
        printf("Case %d: ", kk++);
        int ans = Dinic(1, n + 1);
        printf("%d\n", sum - ans);
        memset(use, 0, sizeof(use));
        DFS(1);
        int r = 0;
        for (i = 0; i < t; i += 2) {
            int u = edge[i].u;
            int v = edge[i].v;
            if (use[u] && !use[v] && v != n + 1) cnt[r++] = i / 2 + 1;
        }
        printf("%d", r);
        for (i = 0; i < r; i++) printf(" %d", cnt[i]);
        printf("\n");
    }
    return 0;
}
