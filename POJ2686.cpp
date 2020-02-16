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
#define MAXN 11
#define MAXM 31
///**********************************START*********************************///

int n, m, a, b, p;
int t[MAXN];
int d[MAXM][MAXM];
double dp[1 << 12][MAXM];

void solve() {
    for (int i = 0; i < 1 << n; i++) {
        fill(dp[i], dp[i] + m, INF);
    }
    dp[(1 << n) - 1][a - 1] = 0;
    double res = INF;
    for (int S = (1 << n) - 1; S >= 0; S--) {
        res = min(res, dp[S][b - 1]);
        for (int v = 0; v < m; v++) {
            for (int i = 0; i < n; i++) {
                if (S >> i & 1) {
                    for (int u = 0; u < m; u++) {
                        if (d[v][u] >= 0) {
                            dp[S & ~(1 << i)][u] =
                                min(dp[S & ~(1 << i)][u],
                                    dp[S][v] + (double)d[v][u] / t[i]);
                        }
                    }
                }
            }
        }
    }
    if (res == INF) {
        printf("Impossible\n");
    } else {
        printf("%.3f\n", res);
    }
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
#endif  // !ONLINE_JUDGE
    while (scanf("%d%d%d%d%d", &n, &m, &p, &a, &b) != EOF) {
        if (p == 0 && m == 0 && n == 0 && a == 0 && b == 0) break;
        MEM(t, 0), MEM(d, 0), MEM(dp, 0);
        REP(i, 0, n - 1) scanf("%d", &t[i]);
        REP(i, 0, MAXM - 1) REP(j, 0, MAXM - 1) d[i][j] = -1;
        REP(i, 1, p) {
            int u = READ(), v = READ(), w = READ();
            u--, v--;
            d[u][v] = d[v][u] = w;
        }
        solve();
    }
    return 0;
}
