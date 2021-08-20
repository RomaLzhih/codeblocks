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
#define MAXN 200000 + 5
///**********************************START*********************************///
int N;
int c[MAXN], a[MAXN];
int l[MAXN], g[MAXN];
int l1[MAXN], g1[MAXN];

int Lowbit(int x)  // 2^k
{
    return x & (-x);
}
void update(int i, int x)  // i点增量为x
{
    while (i <= N) {
        c[i] += x;
        i += Lowbit(i);
    }
}
int sum(int x)  //区间求和 [1,x],闭区间
{
    int sum = 0;
    while (x > 0) {
        sum += c[x];
        x -= Lowbit(x);
    }
    return sum;
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
#endif
    N = READ();
    rep(i, 1, N) a[i] = READ();

    CLR(c);
    rep(i, 1, N) {
        //在前面已加入树状数组的所有数中统计在区间[1, y - 1]的数字的出现次数
        l[i] = sum(a[i] - 1);
        //在前面已加入树状数组的所有数中统计在区间[y + 1, n]的数字的出现次数
        g[i] = sum(N) - sum(a[i]);
        //将y加入树状数组，即数字y出现1次
        update(a[i], 1);
    }
    CLR(c);
    per(i, N, 1) {
        l1[i] = sum(a[i] - 1);
        g1[i] = sum(N) - sum(a[i]);
        update(a[i], 1);
    }

    LL ansv = 0, ans = 0;
    rep(i, 1, N) {
        ansv += 1ll * g[i] * g1[i];
        ans += 1ll * l[i] * l1[i];
    }
    printf("%lld %lld\n", ansv, ans);
    return 0;
}