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
const long long LLINF = 0x3f3f3f3f3f3f3f3f;
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
#define MAXN 1000 + 5
///**********************************START*********************************///
LL N, M;

LL cal(LL i, LL j) { return i * i + 100000 * i + j * j - 100000 * j + i * j; }

bool C(LL x) {
    LL sum = 0;
    for (int j = 1; j <= N; j++) {
        LL ub = N + 1, lb = 0;
        LL ans = 0;
        while (ub - lb > 1) {
            LL mid = (ub + lb) >> 1;
            if (cal(mid, j) <= x) {
                ans = mid;
                lb = mid;
            } else {
                ub = mid;
            }
        }
        sum += ans;
    }
    return sum >= M;
}

void solve() {
    LL ub = LLINF, lb = -LLINF;
    while (ub - lb > 1) {
        LL mid = (ub + lb) >> 1;
        if (C(mid)) {
            ub = mid;
        } else {
            lb = mid;
        }
    }
    cout << ub << endl;
    return;
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
#endif  // !ONLINE_JUDGE
    int T = READ();
    while (T--) {
        getchar();
        scanf("%lld%lld", &N, &M);
        solve();
    }
    return 0;
}