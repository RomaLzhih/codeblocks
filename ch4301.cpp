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
#define Lson(index) (index * 2)
#define Rson(index) (index * 2 + 1)
#define pii pair<int, int>
#define pll pair<LL, LL>
#define MOD ((int)1000000007)
#define MAXN 5000000 + 5  // ? 错的就很迷，卡大小
///**********************************START*********************************///
int a[MAXN];
int N, M;
struct SegmentTree {
    int l, r;
    int dat;
    int lmax, rmax, sum;
} t[MAXN * 4];  // struct数组存储线段树

void build(int p, int l, int r) {
    t[p].l = l, t[p].r = r;  // 节点p代表区间[l,r]
    if (l == r) {
        t[p].dat = a[l];
        t[p].lmax = a[l];
        t[p].rmax = a[l];
        t[p].sum = a[l];
        return;
    }                              // 叶节点
    int mid = (l + r) / 2;         // 折半
    build(p * 2, l, mid);          // 左子节点[l,mid]，编号p*2
    build(p * 2 + 1, mid + 1, r);  // 右子节点[mid+1,r]，编号p*2+1
    t[p].sum = t[Lson(p)].sum + t[Rson(p)].sum;
    t[p].lmax = max(t[Lson(p)].lmax, t[Lson(p)].sum + t[Rson(p)].lmax);
    t[p].rmax = max(t[Rson(p)].rmax, t[Rson(p)].sum + t[Lson(p)].rmax);
    t[p].dat = max(max(t[p * 2].dat, t[p * 2 + 1].dat),
                   t[Lson(p)].rmax + t[Rson(p)].lmax);  // 从下往上传递信息
}

void change(int p, int x, int v) {
    if (t[p].l == t[p].r) {
        t[p].dat = v;
        t[p].lmax = v;
        t[p].rmax = v;
        t[p].sum = v;
        return;
    }  // 找到叶节点
    int mid = (t[p].l + t[p].r) / 2;
    if (x <= mid)
        change(p * 2, x, v);  // x属于左半区间
    else
        change(p * 2 + 1, x, v);  // x属于右半区间
    t[p].sum = t[Lson(p)].sum + t[Rson(p)].sum;
    t[p].lmax = max(t[Lson(p)].lmax, t[Lson(p)].sum + t[Rson(p)].lmax);
    t[p].rmax = max(t[Rson(p)].rmax, t[Rson(p)].sum + t[Lson(p)].rmax);
    t[p].dat = max(max(t[p * 2].dat, t[p * 2 + 1].dat),
                   t[Lson(p)].rmax + t[Rson(p)].lmax);  // 从下往上传递信息
}

SegmentTree ask(int p, int x, int y) {
    // ask [x, y] dat
    if (x <= t[p].l && t[p].r <= y) return t[p];

    SegmentTree nl, nr,
        ans;  // * nl:= left node of p. nr:= right node of p
              // * need maintain all information of these three variables
    nl.lmax = nl.rmax = nl.sum = nl.dat = nr.lmax = nr.rmax = nr.dat = nr.sum =
        -(1 << 30);
    ans.sum = 0;

    int mid = (t[p].l + t[p].r) >> 1;
    if (x <= mid) {
        nl = ask(p << 1, x, y);
        ans.sum += nl.sum;
    }
    if (y > mid) {  // * 存在可能是 x>mid && y>mid
        nr = ask(p << 1 | 1, x, y);
        ans.sum += nr.sum;
    }

    ans.dat = max(max(nl.dat, nr.dat), nl.rmax + nr.lmax);
    // * 更新ans.lmax 和 ans.rmax
    ans.lmax = max(nl.lmax, nl.sum + nr.lmax);
    ans.rmax = max(nr.rmax, nr.sum + nl.rmax);

    return ans;
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
#endif
    scanf("%d%d", &N, &M);
    for (int i = 1; i <= N; i++) {
        scanf("%d", &a[i]);
    }
    build(1, 1, N);
    int k, x, y;
    for (int i = 1; i <= M; i++) {
        scanf("%d%d%d", &k, &x, &y);
        if (k == 1) {
            if (x > y) swap(x, y);
            printf("%d\n", ask(1, x, y).dat);
        } else if (k == 2) {
            change(1, x, y);
        }
    }
    return 0;
}