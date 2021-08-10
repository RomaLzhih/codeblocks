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
#define MAXN 30
///**********************************START*********************************///
int N;
int q[MAXN], b[MAXN], c[MAXN];
int ans[MAXN];
char g[3][MAXN];
bool vis[MAXN], visAlpha[MAXN];

bool check() {
    for (int i = N - 1, t = 0; i >= 0; i--) {
        int a = ans[g[0][i] - 'A'], b = ans[g[1][i] - 'A'],
            c = ans[g[2][i] - 'A'];
        if (a != -1 && b != -1 && c != -1) {
            if (t == -1) {
                if ((a + b) % N != c && (a + b + 1) % N != c) return false;
                if (!i && a + b >= N) return false;  // 最高位有进位
            } else {
                if ((a + b + t) % N != c) return false;
                if (!i && a + b + t >= N) return false;
                t = (a + b + t) / N;
            }
        } else
            t = -1;
    }
    return true;
}

bool dfs(int alpha) {
    if (alpha == N) return 1;

    for (int i = 0; i < N; i++) {
        if (vis[i]) continue;
        vis[i] = true;
        ans[q[alpha]] = i;
        if (check() && dfs(alpha + 1)) {
            return 1;
        }
        ans[q[alpha]] = -1;
        vis[i] = false;
    }
    return 0;
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
#endif
    N = READ();
    for (int i = 0; i < 3; i++) {
        scanf("%s", g[i]);
        // reverse(g[i], g[i] + N);
    }

    for (int i = N - 1, k = 0; i >= 0; i--)
        for (int j = 0; j < 3; j++) {
            int c = g[j][i] - 'A';
            if (!vis[c]) {
                vis[c] = true;
                q[k++] = c;
            }
        }

    for (int i = 0; i < N; i++) {
        ans[i] = -1;
        vis[i] = 0;
    }
    dfs(0);

    printf("%d", ans[0]);
    rep(i, 1, N - 1) printf(" %d", ans[i]);
    return 0;
}