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
#define MAXN 5000 + 5
///**********************************START*********************************///

int N;
int dir[MAXN];  // 牛的方向（0：F，1：B）
int f[MAXN];    //区间（i，i-K+1）是否进行反转

//固定K，求对应的最小操作回数
//无解返回-1
int calc(int K) {
    MEM(f, 0);
    int res = 0;
    int sum = 0;  // f的和
    for (int i = 0; i + K <= N; i++) {
        if ((dir[i] + sum) % 2 != 0) {
            // 前端的牛朝后方
            res++;
            f[i] = 1;
        }
        sum += f[i];
        if (i - K + 1 >= 0) sum -= f[i - K + 1];
    }
    //检查剩下的牛是否有朝后方的情况
    for (int i = N - K + 1; i < N; i++) {
        if ((dir[i] + sum) % 2 != 0) return -1;  //无解
        if (i - K + 1 >= 0) sum -= f[i - K + 1];
    }
    return res;
}

void solve() {
    int K = 1, M = N;
    for (int k = 1; k <= N; k++) {
        int m = calc(k);
        if (m > 0 && M > m) {
            M = m;
            K = k;
        }
    }
    printf("%d %d\n", K, M);
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
#endif
    scanf("%d", &N);
    REP(i, 0, N - 1) {
        char c[2];
        scanf("%s", c);
        dir[i] = (c[0] == 'F') ? 0 : 1;
    }
    solve();
    return 0;
}