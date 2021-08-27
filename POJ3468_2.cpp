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
#define ll long long
#define lson(index) (index * 2)
#define rson(index) (index * 2 + 1)
#define pii pair<int, int>
#define pll pair<LL, LL>
#define MOD ((int)1000000007)
#define MAXN 500000 + 10
///**********************************START*********************************///
int a[MAXN];
struct Segmentree {
    int l, r;
    ll sum, add;
} tree[MAXN * 4];

void build(int p, int l, int r) {
    tree[p].l = l, tree[p].r = r;
    if (l == r) {
        tree[p].sum = a[l];
        return;
    }
    int mid = (l + r) >> 1;
    build(lson(p), l, mid);
    build(rson(p), mid + 1, r);
    tree[p].sum = tree[lson(p)].sum + tree[rson(p)].sum;
}

void spread(int p) {
    if (tree[p].add) {
        tree[lson(p)].sum +=
            tree[p].add * (tree[lson(p)].r - tree[lson(p)].r + 1);
        tree[rson(p)].sum +=
            tree[p].add * (tree[rson(p)].r - tree[rson(p)].r + 1);
        tree[lson(p)].add += tree[p].add;
        tree[rson(p)].add += tree[p].add;
        tree[p].add = 0;
    }
}

void change(int p, int l, int r, int d) {
    if (l <= tree[p].l && r >= tree[p].r) {
        tree[p].sum += 1ll * d * (tree[p].r - tree[p].l + 1);
        tree[p].add += d;
        return;
    }
    spread(p);
    int mid = (tree[p].r + tree[p].l) >> 1;
    if (l <= mid) change(lson(p), l, r, d);
    if (r > mid) change(rson(p), l, r, d);
    tree[p].sum = tree[lson(p)].sum + tree[rson(p)].sum;
}

ll ask(int p, int l, int r) {
    if (l <= tree[p].l && r >= tree[p].r) {
        return tree[p].sum;
    }
    spread(p);
    int mid = (tree[p].r + tree[p].l) >> 1;
    ll val = 0;
    if (l <= mid) val += ask(lson(p), l, r);
    if (r > mid) val += ask(rson(p), l, r);
    return val;
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
#endif
    int n = READ(), m = READ();
    rep(i, 1, n) scanf("%d", &a[i]);
    build(1, 1, n);
    while (m--) {
        char str[2];
        scanf("%s", str);
        int l = READ(), r = READ();
        if (str[0] == 'Q') {
            printf("%lld\n", ask(1, l, r));
        } else if (str[0] == 'C') {
            ll v;
            scanf("%lld", &v);
            change(1, l, r, v);
        }
    }
    return 0;
}