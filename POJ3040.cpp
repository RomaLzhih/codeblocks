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
#define MAXN 2000 + 5
///**********************************START*********************************///
struct COIN {
    int val, num;
    bool operator<(const COIN& rhs) const { return val > rhs.val; }
} a[MAXN];
int N, c;
int main() {
    // freopen("input.txt", "r", stdin);
    scanf("%d%d", &N, &c);
    for (int i = 1; i <= N; i++) scanf("%d%d", &a[i].val, &a[i].num);
    sort(a + 1, a + 1 + N);
    int ans = 0, pos;
    for (int i = 1; i <= N; i++) {
        if (a[i].val >= c) {
            ans += a[i].val / c * a[i].num;
        } else {
            pos = i;
            break;
        }
    }
    while (1) {
        int now = 0;
        for (int i = pos; i <= N; i++) {
            while (a[i].num && a[i].val + now <= c) {
                now += a[i].val;
                a[i].num--;
            }
        }
        for (int i = N; i >= pos; i--) {
            while (a[i].num && now < c) {
                now += a[i].val;
                a[i].num--;
            }
        }
        if (now < c) break;
        ans++;
    }
    printf("%d\n", ans);
    return 0;
}