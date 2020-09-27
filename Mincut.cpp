#include "iostream"
#include "stdio.h"
#include "string.h"

using namespace std;

#define M 1009
#define inf 999999999.0
const double EPS = 1e-9;
struct st {
    int u, v, next;
    double w;
} edge[400009];
int head[M], dis[M], q[M], work[M], cnt[M], use[M], t;
double min(double a, double b) { return (b - a) > EPS ? a : b; }
void DinicInit() {
    t = 0;
    memset(head, -1, sizeof(head));
}
void DinicAdd(int u, int v, double w) {
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
void DinicAddUni(int u, int v, double w) {
    edge[t].u = u;
    edge[t].v = v;
    edge[t].w = w;
    edge[t].next = head[u];
    head[u] = t++;
}
int DinicBfs(int S, int T) {
    int rear = 0;
    memset(dis, -1, sizeof(dis));
    dis[S] = 0;
    q[rear++] = S;
    for (int i = 0; i < rear; i++) {
        for (int j = head[q[i]]; j != -1; j = edge[j].next) {
            int v = edge[j].v;
            if (edge[j].w > 0.0 && dis[v] == -1) {
                dis[v] = dis[q[i]] + 1;
                q[rear++] = v;
                if (v == T) return 1;
            }
        }
    }
    return 0;
}
double DinicDfs(int S, double a, int T) {
    if (S == T) return a;
    for (int &i = work[S]; i != -1; i = edge[i].next) {
        int v = edge[i].v;
        if (edge[i].w > EPS && dis[v] == dis[S] + 1) {
            double tt = dfs(v, min(a, edge[i].w), T);
            if (tt > EPS) {
                edge[i].w -= tt;
                edge[i ^ 1].w += tt;
                return tt;
            }
        }
    }
    return 0;
}
int Dinic(int S, int T) {
    double ans = 0.0;
    while (bfs(S, T)) {
        memcpy(work, head, sizeof(head));
        double tt = dfs(S, inf, T);
        while (tt > EPS) {
            ans += tt;
            double tt = dfs(S, inf, T);
        }
    }
    return ans;
}
void FindCut(int S) {
    use[S] = 1;
    for (int i = head[S]; i != -1; i = edge[i].next) {
        int v = edge[i].v;
        if (!use[v] && edge[i].w > EPS) DFS(v);
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
