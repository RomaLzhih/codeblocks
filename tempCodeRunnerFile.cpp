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
#define MAXN 1000 + 5
///**********************************START*********************************///
const int N = 10006;
int n, k, s[N], Ans;
bool v[N], w[N];
int Head[N], Edge[N << 1], Leng[N << 1], Next[N << 1], t;
int ans, pos;
int d[N], b[N], a[N], tot, cnt[N];

// find gravity
void dfs_find(int S, int x) {
    v[x] = 1;
    s[x] = 1;  // tree size rooted as x
    int max_part = 0;
    for (int i = Head[x]; i; i = Next[i]) {
        int y = Edge[i];
        if (v[y] || w[y]) continue;
        dfs_find(S, y);
        s[x] += s[y];
        max_part = max(max_part, s[y]);
    }
    max_part = max(max_part, S - s[x]);
    if (max_part < ans) {
        ans = max_part;  // ans 记录重心下子树大小的最大值
        pos = x;         // pos 记录重心的位置
    }
}

void dfs(int x) {
    v[x] = 1;
    for (int i = Head[x]; i; i = Next[i]) {
        int y = Edge[i], z = Leng[i];
        if (v[y] || w[y]) continue;
        // three meanings: 1. b[y]=b[x] 2. a[++tot]=y 3. ++cnt[b[x]]
        ++cnt[b[a[++tot] = y] = b[x]];
        d[y] = d[x] + z;
        dfs(y);
    }
}

bool cmp(int i, int j) { return d[i] < d[j]; }

void work(int S, int x) {
    CLR(v);
    ans = S;
    dfs_find(S, x);
    CLR(d);
    CLR(cnt);
    CLR(v);
    w[a[tot = 1] = b[pos] = pos] = 1;
    ++cnt[pos];
    for (int i = Head[pos]; i; i = Next[i]) {
        int y = Edge[i], z = Leng[i];
        if (v[y] || w[y]) continue;
        ++cnt[a[++tot] = b[y] = y];
        d[y] = z;
        dfs(y);
    }
    sort(a + 1, a + 1 + tot, cmp);
    int l = 1, r = tot;
    --cnt[b[a[1]]];
    while (l < r) {
        while (d[a[l]] + d[a[r]] > k) {
            --cnt[b[a[r--]]];
        }
        Ans += r - l - cnt[b[a[l]]];
        --cnt[b[a[++l]]];
    }
    int now = pos;
    for (int i = Head[now]; i; i = Next[i]) {
        int y = Edge[i];
        if (w[y]) continue;
        work(s[y], y);
    }
    return;
}

void add(int x, int y, int z) {
    Edge[++t] = y;
    Leng[t] = z;
    Next[t] = Head[x];
    Head[x] = t;
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
#endif
    while (scanf("%d %d", &n, &k) && n && k) {
        t = 0;
        CLR(Head);
        for (int i = 1; i < n; i++) {
            int x, y, z;
            scanf("%d %d %d", &x, &y, &z);
            add(x, y, z);
            add(y, x, z);
        }
        CLR(w);
        Ans = 0;
        work(n, 1);
        printf("%d\n", Ans);
    }
    return 0;
}