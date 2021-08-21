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
#define MAXN 5000000 + 10
///**********************************START*********************************///
int n, m;
LL a[MAXN], b[MAXN];

long long gcd(long long a, long long b) { return b ? gcd(b, a % b) : a; }

// segment tree
struct SegmentTree {
    int l, r;
    long long dat;
} t[MAXN * 4];  // struct数组存储线段树

void build(int p, int l, int r) {
    t[p].l = l, t[p].r = r;  // 节点p代表区间[l,r]
    if (l == r) {
        t[p].dat = b[l];
        return;
    }                              // 叶节点
    int mid = (l + r) / 2;         // 折半
    build(p * 2, l, mid);          // 左子节点[l,mid]，编号p*2
    build(p * 2 + 1, mid + 1, r);  // 右子节点[mid+1,r]，编号p*2+1
    t[p].dat = gcd(t[p * 2].dat, t[p * 2 + 1].dat);  // 从下往上传递信息
}

void change(int p, int x, long long v) {
    if (t[p].l == t[p].r) {
        t[p].dat += v;
        return;
    }  // 找到叶节点
    int mid = (t[p].l + t[p].r) / 2;
    if (x <= mid)
        change(p * 2, x, v);  // x属于左半区间
    else
        change(p * 2 + 1, x, v);                     // x属于右半区间
    t[p].dat = gcd(t[p * 2].dat, t[p * 2 + 1].dat);  // 从下往上更新信息
}

long long ask(int p, int l, int r) {
    if (l <= t[p].l && r >= t[p].r) return t[p].dat;  // 完全包含，直接返回
    int mid = (t[p].l + t[p].r) / 2;
    long long val = 0;
    if (l <= mid) val = gcd(val, ask(p * 2, l, r));     // 左子节点有重叠
    if (r > mid) val = gcd(val, ask(p * 2 + 1, l, r));  // 右子节点有重叠
    return abs(val);
}

// * tree array
long long c[MAXN];

//* 树状数组查询前缀和
long long askTree(int x) {
    long long ans = 0;
    for (; x; x -= x & -x) ans += c[x];
    return ans;
}
//* 树状数组单点增加
void add(int x, long long y) {
    for (; x <= n; x += x & -x) c[x] += y;
}
//* 区间增加
void update(int l, int r, long long d) {
    add(l, d);
    add(r + 1, -d);
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
#endif
    scanf("%d%d", &n, &m);
    rep(i, 1, n) {
        scanf("%lld", &a[i]);
        b[i] = a[i] - a[i - 1];
    }
    build(1, 1, n);
    int l, r;
    long long d;
    while (m--) {
        char str[2];
        scanf("%s", str);
        // cout << ch << endl;
        if (str[0] == 'C') {
            scanf("%d%d%lld", &l, &r, &d);
            change(1, l, d);
            if (r < n) change(1, r + 1, -1ll * d);
            update(l, r, d);
        } else if (str[0] == 'Q') {
            scanf("%d%d", &l, &r);
            long long A = askTree(l) + a[l];
            long long B = l < r ? ask(1, l + 1, r) : 0;
            long long ans = gcd(A, B);
            printf("%lld\n", ans);
        }
    }
    return 0;
}