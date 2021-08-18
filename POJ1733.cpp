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
struct {
    int l, r, ans;
} query[MAXN];
int a[2 * MAXN], fa[2 * MAXN], d[2 * MAXN], n, m, t;

void discrete() {  // read and discrete
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        char str[5];
        scanf("%d%d%s", &query[i].l, &query[i].r, str);
        query[i].ans = str[0] == 'o' ? 1 : 0;
        a[++t] = query[i].l - 1;
        a[++t] = query[i].r;
    }
    sort(a + 1, a + t + 1);
    n = unique(a + 1, a + t + 1) - a - 1;
    return;
}

void init() {
    for (int i = 1; i <= n; i++) {
        fa[i] = i;
    }
}

int get(int x) {
    if (x == fa[x]) return x;
    int root = get(fa[x]);
    d[x] ^= d[fa[x]];
    return fa[x] = root;
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
#endif
    discrete();
    init();
    for (int i = 1; i <= m; i++) {
        int x = lower_bound(a + 1, a + n + 1, query[i].l - 1) - a;
        int y = lower_bound(a + 1, a + n + 1, query[i].r) - a;
        int p = get(x), q = get(y);
        if (p == q) {
            if ((d[x] ^ d[y]) != query[i].ans) {
                cout << i - 1 << endl;
                return 0;
            }
        } else {
            fa[p] = q, d[p] = d[x] ^ d[y] ^ query[i].ans;
        }
    }
    cout << m << endl;
    return 0;
}