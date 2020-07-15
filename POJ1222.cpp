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
#define MAXN 3 + 5
///**********************************START*********************************///
int g[MAXN][MAXN];
int tmp[MAXN][MAXN];
int ans[MAXN][MAXN];
int first_line[MAXN];
bool flag;

void flip(int i, int j) {
    tmp[i][j] = !tmp[i][j];
    tmp[i - 1][j] = !tmp[i - 1][j];
    tmp[i + 1][j] = !tmp[i + 1][j];
    tmp[i][j - 1] = !tmp[i][j - 1];
    tmp[i][j + 1] = !tmp[i][j + 1];
    return;
}

bool check() {
    rep(i, 1, 5) rep(j, 1, 6) if (tmp[i][j]) return 0;
    return 1;
}

void dfs(int idx) {
    if (flag) return;

    if (idx == 7) {
        MEM(ans, 0);
        memcpy(tmp, g, sizeof(g));
        // flip first line
        rep(j, 1, 6) if (first_line[j]) {
            flip(1, j);
            ans[1][j] = 1;
        }
        // flip other lines
        rep(i, 2, 5) rep(j, 1, 6) if (tmp[i - 1][j]) {
            flip(i, j);
            ans[i][j] = 1;
        }

        if (check()) {
            flag = 1;
        }

        return;
    }

    for (int i = 0; i <= 1; i++) {
        first_line[idx] = i;
        dfs(idx + 1);
        if (flag) return;
    }

    return;
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
#endif
    int T = READ();
    for (int t = 1; t <= T; t++) {
        rep(i, 1, 5) rep(j, 1, 6) g[i][j] = READ();
        flag = false;
        dfs(1);

        printf("PUZZLE #%d\n", t);
        for (int i = 1; i <= 5; i++) {
            for (int j = 1; j <= 6; j++) {
                if (j == 1)
                    printf("%d", ans[i][j]);
                else
                    printf(" %d", ans[i][j]);
            }
            printf("\n");
        }
    }
    return 0;
}