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
#define MAXN 100000 + 5
///**********************************START*********************************///
int n, m;
struct NODE {
    int l, r, w;
} a[MAXN];
bool cmp(NODE a, NODE b) { return a.w > b.w; }
int vis[MAXN];

int p[MAXN];
int r[MAXN];
void init(int n) {
    for (int i = 1; i <= n; i++) {
        p[i] = i, r[i] = 0;
    }
}
int find(int x) { return p[x] == x ? x : p[x] = find(p[x]); }
bool same(int x, int y) { return find(x) == find(y); }
void unite(int x, int y) {
    x = find(x);
    y = find(y);
    if (x == y) return;
    if (r[x] < r[y]) {
        p[x] = y;

    } else {
        p[y] = x;
        if (r[x] == r[y]) r[x]++;
    }
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
#endif
    scanf("%d %d", &n, &m);
    rep(i, 1, m) { scanf("%d %d %d", &a[i].l, &a[i].r, &a[i].w); }
    sort(a + 1, a + m + 1, cmp);
    init(2 * n);

    int ans = 0;
    for (int i = 1; i <= m; i++) {
        int l = a[i].l, r = a[i].r, w = a[i].w;
        if (same(l, r)) {
            ans = a[i].w;
            break;
        } else {
            unite(l, r + n);
            unite(r, l + n);
        }
    }
    printf("%d", ans);
    return 0;
}