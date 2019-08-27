#pragma GCC optimize(3)
#include <stdio.h>
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
#define MAXN 1000 + 5
///**********************************START*********************************///

int T, W;
int dp[MAXN][30 + 5];  //当前为第i秒还能走j步时能拿到的最大价钱。
int order[MAXN];

int main() {
    freopen("input.txt", "r", stdin);
    T = READ(), W = READ();
    CLR(dp);
    SET(order);
    REP(i, 1, T) order[i] += READ();

    int st = 0;
    REP(i, 1, T) REP(j, 0, W) {
        dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - 1]);
        if (j % 2 == order[i]) dp[i][j]++;
    }

    int ans = -1;
    REP(j, 1, W) ans = max(ans, dp[T][j]);
    cout << dp[T][W] << endl;
    return 0;
}