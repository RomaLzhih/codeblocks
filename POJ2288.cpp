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
#define MAXN 13 + 1
///**********************************START*********************************///

int N, M;
LL f[1 << MAXN][MAXN][MAXN];
int mp[MAXN][MAXN];
int a[MAXN];
LL path[1 << MAXN][MAXN][MAXN];
void CLEAR_INPUT() {
    N = 0, M = 0;
    SET(f);
    CLR(a);
    CLR(mp);
    CLR(path);
    return;
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
#endif
    int T = READ();
    while (T--) {
        CLEAR_INPUT();
        scanf("%d%d", &N, &M);
        rep(i, 1, N) a[i - 1] = READ();
        rep(i, 1, M) {
            int u = READ(), v = READ();
            u--, v--;
            // cout << u << " " << v << endl;
            mp[u][v] = 1;
            mp[v][u] = 1;
        }
        if (N == 1) {  //特判省时间。
            printf("%d 1\n", a[0]);
            continue;
        }
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                if (i == j || !mp[i][j]) continue;
                f[(1 << i) | (1 << j)][i][j] = 1ll * a[i] + a[j] + a[i] * a[j];
                path[(1 << i) | (1 << j)][i][j] = 1;
            }
        }
        // f(s,i,j) 表示：当前点的遍历状况为 s，前一个为 i，前前个为 j
        for (int s = 1; s < (1 << N); s++) {
            for (int i = 0; i < N; i++)
                if ((s >> i) & 1)
                    for (int j = 0; j < N; j++)
                        if ((s >> j) & 1 && mp[i][j] && i != j) {
                            for (int k = 0; k < N; k++)
                                if ((s >> k) & 1 && i != k && j != k &&
                                    mp[j][k] && f[s ^ (1 << i)][j][k] != -1) {
                                    LL t = f[s ^ (1 << i)][j][k] + a[i] +
                                           a[i] * a[j];
                                    if (mp[k][i]) t += a[i] * a[j] * a[k];

                                    if (t > f[s][i][j]) {
                                        f[s][i][j] = t;
                                        path[s][i][j] =
                                            path[s ^ (1 << i)][j][k];
                                    } else if (t == f[s][i][j]) {
                                        path[s][i][j] +=
                                            path[s ^ (1 << i)][j][k];
                                    }
                                }
                        }
        }
        LL ans = -1, num = 0;
        rep(i, 0, N - 1) rep(j, 0, N - 1) {
            if (i == j) continue;
            if (f[(1 << N) - 1][i][j] > ans) {
                ans = f[(1 << N) - 1][i][j];
                num = path[(1 << N) - 1][i][j];
            } else if (ans == f[(1 << N) - 1][i][j]) {
                num += path[(1 << N) - 1][i][j];
            }
        }
        if (ans == -1)
            printf("0 0\n");
        else
            printf("%lld %lld\n", ans, num >> 1);
    }
    return 0;
}