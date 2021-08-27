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
LL a[MAXN], sum[MAXN], add[MAXN];
int L[MAXN], R[MAXN];  // * start of block and its end
int pos[MAXN];         // * whick block l belongs
int n, m, t;

void change(int l, int r, int d) {
    int p = pos[l], q = pos[r];
    if (p == q) {
        for (int i = l; i <= r; i++) {
            a[i] += d;
        }
        sum[p] += 1ll * d * (r - l + 1);
        return;
    }
    // * update middle block
    for (int i = p + 1; i <= q - 1; i++) {
        add[i] += d;
    }
    // * update left
    for (int i = l; i <= R[p]; i++) {
        a[i] += d;
    }
    sum[p] += 1ll * d * (R[p] - l + 1);
    // * update right
    for (int i = r; i >= L[q]; i--) {
        a[i] += d;
    }
    sum[q] += 1ll * d * (r - L[q] + 1);
    return;
}

long long ask(int l, int r) {
    int p = pos[l], q = pos[r];
    long long ans = 0;
    if (p == q) {
        for (int i = l; i <= r; i++) {
            ans += a[i];
        }
        ans += 1ll * add[p] * (r - l + 1);
        return ans;
    }
    for (int i = p + 1; i <= q - 1; i++) {
        ans += sum[i] + 1ll * add[i] * (R[i] - L[i] + 1);
    }
    // * update left ans
    for (int i = l; i <= R[p]; i++) {
        ans += a[i];
    }
    ans += 1ll * add[p] * (R[p] - l + 1);
    // * update right ans
    for (int i = r; i >= L[q]; i--) {
        ans += a[i];
    }
    ans += 1ll * add[q] * (r - L[q] + 1);
    return ans;
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
#endif
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++) {
        scanf("%lld", &a[i]);
    }
    // * 分块
    t = sqrt(n);
    for (int i = 1; i <= t; i++) {
        L[i] = (i - 1) * sqrt(n) + 1;
        R[i] = i * sqrt(n);
    }
    if (R[t] < n) {
        t++;
        L[t] = R[t - 1] + 1;
        R[t] = n;
    }
    // * 预处理
    for (int i = 1; i <= t; i++) {
        for (int j = L[i]; j <= R[i]; j++) {
            pos[j] = i;
            sum[i] += a[j];
        }
    }
    // * 开始
    while (m--) {
        char op[3];
        int l, r, d;
        scanf("%s%d%d", op, &l, &r);
        // cout << l << " " << r << endl;
        if (op[0] == 'C') {
            scanf("%d", &d);
            change(l, r, d);
        } else {
            printf("%lld\n", ask(l, r));
        }
    }
    return 0;
}