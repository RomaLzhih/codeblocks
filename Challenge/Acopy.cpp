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
#define MAXN 200 + 5
///**********************************START*********************************///
struct NODE {
    LL l, r, c;
    bool operator<(const NODE& b) const { return c < b.c; }
} inv[MAXN];

LL A[MAXN];

int t[4 * MAXN], up[4 * MAXN];

void build(int rt, int l, int r) {
    if (l == r) {
        t[rt] = 0;
        return;
    }
    int mid = (l + r) >> 1;
    build(rt << 1, l, mid);
    build(rt << 1 | 1, mid + 1, r);
    t[rt] = t[rt << 1] + t[rt << 1 | 1];
}
void push_down(int rt, int l, int r) {
    if (up[rt]) {
        int mid = (l + r) >> 1;
        t[rt << 1] = up[rt] * (A[mid] - A[l] + 1);
        t[rt << 1 | 1] = up[rt] * (A[r] - A[mid]);
        up[rt << 1] = up[rt];
        up[rt << 1 | 1] = up[rt];
        up[rt] = 0;
    }
}
void update(int rt, int l, int r, int x, int y, int val) {
    if (x <= l && r <= y) {
        int tmp = val * (A[r] - A[l] + 1);
        if (tmp > t[rt]) t[rt] = tmp;
        up[rt] = val;
        return;
    }
    if (up[rt]) push_down(rt, l, r);
    int mid = (l + r) >> 1;
    if (x <= mid) update(rt << 1, l, mid, x, y, val);
    if (y > mid) update(rt << 1 | 1, mid + 1, r, x, y, val);
    t[rt] = t[rt << 1] + t[rt << 1 | 1];
}
int query(int rt, int l, int r, int x, int y)  //本题中不需要使用这个函数
{
    if (x <= l && r <= y) return t[rt];
    if (up[rt]) push_down(rt, l, r);
    int mid = (l + r) >> 1;
    int sum = 0;
    if (x <= mid) sum += query(rt << 1, l, mid, x, y);
    if (y > mid) sum += query(rt << 1 | 1, mid + 1, r, x, y);
    return sum;
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
#endif
    LL T;
    CLR(up), CLR(t);
    scanf("%lld", &T);
    int N = READ(), M = READ();
    int cnt = 0;
    rep(i, 1, N) {
        scanf("%lld %lld %lld", &inv[i].l, &inv[i].r, &inv[i].c);
        A[++cnt] = inv[i].l;
        A[++cnt] = inv[i].r;
    }
    rep(i, N + 1, N + M) {
        scanf("%lld %lld %lld", &inv[i].l, &inv[i].r, &inv[i].c);
        A[++cnt] = inv[i].l;
        A[++cnt] = inv[i].r;
    }
    sort(A + 1, A + cnt + 1);
    cnt = unique(A + 1, A + cnt + 1) - A - 1;
    // for (int i = 2; i <= t; i++) {
    //     if (A[i] - A[i - 1] > 1) A[++m] = A[i - 1] + 1;
    // }
    sort(A + 1, A + cnt + 1);
    sort(inv + 1, inv + N + M + 1);

    // rep(i, 1, N + M) cout << inv[i].l << " " << inv[i].r << " " << inv[i].c
    //                       << endl;
    rep(i, 1, cnt) cout << i << " " << A[i] << endl;
    cout << cnt << " --- " << endl;
    build(1, 1, cnt);

    for (int i = 1; i <= N + M; i++) {
        int x = lower_bound(A + 1, A + cnt + 1, inv[i].l) - A;
        int y = lower_bound(A + 1, A + cnt + 1, inv[i].r) - A;
        LL z = inv[i].c;
        cout << inv[i].l << " " << inv[i].r << " " << x << " " << y << " " << z
             << endl;
        if (z == 0)
            update(1, 1, cnt, x, y, 1);
        else if (z == 1)
            update(1, 1, cnt, x, y, 3);
        rep(i, 1, 15) cout << i << " " << t[i] << " " << up[i] << endl;
    }

    LL ans = query(1, 1, cnt, 1, cnt);
    printf("%lld", ans);
    return 0;
}