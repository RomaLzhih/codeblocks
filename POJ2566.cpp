#pragma GCC optimize(3)
#include <math.h>
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

#define REP(i, a, b) for (int i = (a); i <= (b); i++)
#define PER(i, a, b) for (int i = (a); i >= (b); i--)
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

int n, m, k;
pair<LL, int> sum[MAXN];

LL myabs(LL x) { return x >= 0 ? x : -x; }

void solve() {
    while (m--) {
        int s = 0, t = 1;
        LL ans = LLINF, th, tmpans = LLINF;
        int l, r;
        scanf("%lld", &th);

        while (t <= n) {
            LL diff = sum[t].first - sum[s].first;
            if (myabs(diff - th) < tmpans) {
                tmpans = myabs(diff - th);
                ans = diff;
                l = sum[s].second;
                r = sum[t].second;
            }
            if (diff == th) {
                break;
            } else {
                diff > th ? s++ : t++;
            }
            if (s == t) t++;
        }
        if (l > r) swap(l, r);
        printf("%lld %d %d\n", ans, l + 1, r);
    }
    return;
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
#endif
    while (scanf("%d %d", &n, &m), n + m) {
        sum[0].first = 0;
        sum[0].second = 0;
        for (int i = 1; i <= n; i++) {
            LL x;
            scanf("%lld", &x);
            sum[i].first = sum[i - 1].first + x;
            sum[i].second = i;
        }
        sort(sum, sum + n + 1);
        solve();
    }
    return 0;
}