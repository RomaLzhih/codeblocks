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
int v[106], num[106];
int dp[MAXN];
int n, m;
int main() {
    // freopen("input.txt", "r", stdin);
    while (scanf("%d%d", &n, &m) && n && m) {
        CLR(v), CLR(num);
        SET(dp);
        REP(i, 1, n) v[i] = READ();
        REP(i, 1, n) num[i] = READ();
        dp[0] = 0;
        int ans = 0;
        REP(i, 1, n) REP(j, 0, m) {
            if (dp[j] >= 0)
                dp[j] = num[i];
            else if (j < v[i] || dp[j - v[i]] < 0)
                dp[j] = -1;
            else
                dp[j] = dp[j - v[i]] - 1;
            if (i == n && j > 0) ans += dp[j] >= 0;
        }
        int a = 1;
        cout << ans << endl;
    }

    return 0;
}