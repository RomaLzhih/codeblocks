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
#define MAXN 8000 + 5
///**********************************START*********************************///
//! 好题！
int a[MAXN], b[MAXN], ans[MAXN];
int c[MAXN];
int n;
int lowbit(int x) { return x & -x; }
void add(int x, int k) {
    while (x <= n) {  // 不能越界
        c[x] = c[x] + k;
        x = x + lowbit(x);
    }
}
int getsum(int x) {  // a[1]..a[x]的和
    int ans = 0;
    while (x >= 1) {
        ans = ans + c[x];
        x = x - lowbit(x);
    }
    return ans;
}
// O(n)建树
void init() {
    for (int i = 1; i <= n; ++i) {
        c[i] += b[i];
        int j = i + lowbit(i);
        if (j <= n) c[j] += c[i];
    }
}
//权值树状数组查询第k小
int kth(int k) {
    int cnt = 0, ret = 0;
    for (int i = log2(n); ~i; --i) {        // i与上文depth含义相同
        ret += 1 << i;                      // 尝试扩展
        if (ret >= n || cnt + c[ret] >= k)  // 如果扩展失败
            ret -= 1 << i;
        else
            cnt += c[ret];  // 扩展成功后 要更新之前求和的值
    }
    return ret + 1;
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
#endif
    n = READ();
    a[1] = 0;
    b[1] = 1;
    for (int i = 2; i <= n; i++) {
        a[i] = READ();
        b[i] = 1;
    }
    init();
    per(i, n, 1) {
        ans[i] = kth(a[i] + 1);
        add(ans[i], -1);
    }
    rep(i, 1, n) { printf("%d\n", ans[i]); }
    return 0;
}