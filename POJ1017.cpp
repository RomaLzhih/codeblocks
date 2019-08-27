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
#define MAXN 1000 + 5
///**********************************START*********************************///
int a[8];
int ans;
int main() {
    freopen("input.txt", "r", stdin);
    while (scanf("%d%d%d%d%d%d", &a[1], &a[2], &a[3], &a[4], &a[5], &a[6]) !=
           EOF) {
        if (a[1] == 0 && a[2] == 0 && a[3] == 0 && a[4] == 0 && a[5] == 0 &&
            a[6] == 0)
            break;
        ans = 0;
        ans += a[6];
        ans += a[5];
        if (a[5]) a[1] -= a[5] * 11;

        ans += a[4];
        if (a[4] && a[2]) {
            if (a[2] <= a[4] * 5) {
                a[1] -= a[4] * 20 - a[2] * 4;
                a[2] = 0;
            } else
                a[2] -= a[4] * 5;
        } else
            a[1] -= a[4] * 20;

        ans += a[3] / 4;

        if (a[3] && a[3] % 4 != 0) {
            ans += 1;
            int kind = a[3] % 4;
            if (kind == 1) {
                if (a[2] > 0) {
                    if (a[2] <= 5) {
                        a[1] -= 27 - a[2] * 4;
                        a[2] = 0;
                    } else
                        a[2] -= 5, a[1] -= 7;
                } else
                    a[1] -= 27;
            } else if (kind == 2) {
                if (a[2] > 0) {
                    if (a[2] <= 3) {
                        a[1] -= 18 - a[2] * 4;
                        a[2] = 0;
                    } else
                        a[2] -= 3, a[1] -= 6;
                } else
                    a[1] -= 18;
            } else if (kind == 3) {
                if (a[2] > 0) {
                    if (a[2] <= 1) {
                        a[1] -= 9 - a[2] * 4;
                        a[2] = 0;
                    } else
                        a[2] -= 1, a[1] -= 5;
                } else
                    a[1] -= 9;
            }
        }

        if (a[2] > 0) {
            ans += a[2] / 9;
            if (a[2] % 9 != 0) {
                ans += 1;
                a[1] -= (9 - a[2] % 9) * 4;
            }
        }

        if (a[1] > 0) {
            ans += a[1] / 36;
            if (a[1] % 36 != 0) {
                ans += 1;
            }
        }
        printf("%d\n", ans);
    }
    return 0;
}