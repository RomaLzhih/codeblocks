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

const int MAXV = 1001;
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

//二分图最大匹配，返回最大匹配数
int Bipartite_Matching() {
    int res = 0;
    memset(match, -1, sizeof(match));
    for (int v = 0; v < V; v++) {
        if (match[v] < 0) {
            memset(used, 0, sizeof(used));
            if (dfs(v)) {
                res++;
            }
        }
    }
    return res;
}

const int MAXK = 10000 + 5;
int N, K;
int R[MAXK], C[MAXK];

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
#endif  // !ONLINE_JUDGE
    N = READ(), K = READ();
    REP(i, 1, K) {
        int R = READ(), C = READ();
        add_edge(R - 1, C + N - 1);
    }
    V = N + N;
    printf("%d\n", Bipartite_Matching());
    return 0;
}
