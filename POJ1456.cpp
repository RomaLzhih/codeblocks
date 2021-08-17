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
#define MAXN 10000 + 5
///**********************************START*********************************///
struct NODE {
    int p, d;
    bool operator<(const NODE &a) const { return p == a.p ? d < a.d : p > a.p; }
} g[MAXN];
int fa[MAXN];
void init(int n) {
    for (int i = 0; i <= n; i++) fa[i] = i;
}
int get(int x) {
    if (x == fa[x]) return x;
    return fa[x] = get(fa[x]);
}
// set x's root to be the son of y's root
void merge(int x, int y) { fa[get(x)] = get(y); }

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
#endif
    int N;
    while (scanf("%d", &N) != EOF) {
        for (int i = 1; i <= N; i++) {
            g[i].p = READ();
            g[i].d = READ();
        }
        sort(g + 1, g + N + 1);
        LL ans = 0;
        init(MAXN);
        rep(i, 1, N) {
            int t = get(g[i].d);
            if (t > 0) {
                ans += 1ll * g[i].p;
                merge(t, t - 1);
            }
        }
        printf("%lld\n", ans);
    }

    return 0;
}