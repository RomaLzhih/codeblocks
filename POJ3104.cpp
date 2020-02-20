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
LL N, K;
LL a[MAXN];
LL mx = -1;

bool C(LL t) {
    int i = lower_bound(a, a + N, t) - a;
    LL sum = 0;
    for (; i < N; i++) {
        if ((a[i] - t) % (K - 1) == 0) {
            sum += (a[i] - t) / (K - 1);
        } else {
            sum += ((a[i] - t) / (K - 1) + 1);
        }
    }
    if (sum > t) {
        return false;
    } else {
        return true;
    }
}

void solve() {
    sort(a, a + N);
    if (K == 1) {
        printf("%lld\n", mx);
        return;
    }
    LL ub = LLINF, lb = 0;
    while (ub - lb > 1) {
        LL mid = (ub + lb) >> 1;
        if (C(mid)) {
            ub = mid;
        } else {
            lb = mid;
        }
    }
    printf("%lld\n", ub);
    return;
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
#endif  // !ONLINE_JUDGE
    scanf("%lld", &N);
    for (int i = 0; i < N; i++) {
        scanf("%lld", &a[i]);
        mx = max(a[i], mx);
    }
    scanf("%lld", &K);
    solve();
    return 0;
}