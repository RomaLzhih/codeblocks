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
#define MAXN 2000 + 5
///**********************************START*********************************///
int GCD(int a, int b) { return b ? GCD(b, a % b) : a; }
map<pair<int, int>, int> g;

int x[MAXN], y[MAXN];

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
#endif
    int n = READ();
    rep(i, 1, n) scanf("%d %d", &x[i], &y[i]);
    int ans = 0;
    int gcd;
    int dx, dy;
    int ver, hor, same;
    // cout << GCD(4, -2) << endl;
    rep(i, 1, n) {
        same = 1, ver = 0, hor = 0;
        rep(j, 1, n) {
            if (i == j) continue;
            if (x[i] == x[j] && y[i] == y[j]) {
                same++;
                continue;
            } else if (x[i] == x[j]) {
                ver++;
            } else if (y[i] == y[j]) {
                hor++;
            } else {
                dx = x[i] - x[j];
                dy = y[i] - y[j];
                gcd = GCD(dx, dy);
                // cout << dx / gcd << " " << dy / gcd << endl;
                g[make_pair(dx / gcd, dy / gcd)]++;
            }
        }

        int cnt = max(ver, hor);
        for (auto i : g) {
            cnt = max(cnt, i.second);
        }
        ans = max(ans, cnt + same);
        g.clear();
    }
    if (n <= 2)
        printf("%d", n);
    else
        printf("%d", ans);
    return 0;
}