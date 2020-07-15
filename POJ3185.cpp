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
#define MAXN 20 + 5
///**********************************START*********************************///
int N = 20;
int dir[MAXN];
int f[MAXN];

// 0, 1
bool CanFlip(int i, int sum) { return (dir[i] + sum) & 1; }

int solve() {
    MEM(f, 0);
    int res = 0, sum = 0;
    int K = 3;
    // 在开关问题的时候，这里是 i+K<=N，为什么？
    // 假如 K=3，那么当 i=18
    // 的时候，他就不能翻了，(这也是为什么在判断最后几位的时候没有sum+=f[i]).
    // 但是这里当 i=18 的时候还可以翻， 所以往前推一位
    for (int i = 0; i + K <= N + 1; i++) {
        if (CanFlip(i, sum)) {
            res++;
            f[i] = 1;
        }
        sum += f[i];
        if (i - K + 1 >= 0) sum -= f[i - K + 1];
    }
    for (int i = N - K + 1 + 1; i < N; i++) {
        if (CanFlip(i, sum)) return INF;  //无解
        if (i - K + 1 >= 0) sum -= f[i - K + 1];
    }
    return res;
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
#endif
    for (int i = 0; i < 20; i++) {
        scanf("%d", &dir[i]);
    }
    int ans1 = solve();
    reverse(dir, dir + 20);
    int ans2 = solve();
    // cout << ans1 << " " << ans2 << endl;
    printf("%d", min(ans1, ans2));
    return 0;
}