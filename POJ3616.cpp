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
#define PER(i, a, b) for (int i = (a); i >= (b); i--)
#define FOREACH(i, t) for (typeof(t.begin()) i = t.begin(); i != t.end(); i++)
#define MP(x, y) make_pair(x, y)
#define PB(x) push_back(x)
#define SET(a) memset(a, -1, sizeof(a))
#define CLR(a) memset(a, 0, sizeof(a))
#define MEM(a, x) memset(a, (x), sizeof(a))
#define ALL(x) begin(x), end(x)
#define LL long long
#define Lson (index * 2)
#define Rson (index * 2 + 1)
#define pii pair<int, int>
#define pll pair<LL, LL>
#define MOD ((int)1000000007)
#define MAXN 1000 + 5
///**********************************START*********************************///
struct COW {
    int l, r, len;
    bool operator<(COW &rhs) const {
        return l == rhs.l ? r < rhs.r : l < rhs.l;
    }
} cow[MAXN];
int N, M, R, ans = -1;
int f[MAXN];
int main() {
    // freopen("input.txt", "r", stdin);
    scanf("%d %d %d", &N, &M, &R);
    rep(i, 1, M) scanf("%d %d %d", &cow[i].l, &cow[i].r, &cow[i].len);
    sort(cow + 1, cow + 1 + M);
    rep(i, 1, M) {
        f[i] = cow[i].len;
        rep(j, 1, i - 1) if (cow[j].r + R <= cow[i].l) {
            f[i] = max(f[i], f[j] + cow[i].len);
        }
    }
    rep(i, 1, M) ans = max(ans, f[i]);
    printf("%d", ans);
    return 0;
}