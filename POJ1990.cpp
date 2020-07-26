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
#include <typeinfo>
#include <utility>
#include <vector>
using namespace std;
using namespace std;
const double EPS = 1e-9;
const int INF = 2147483647;
const long long LLINF = 9223372036854775807;

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
#define MAXN 20000 + 5
///**********************************START*********************************///
int N;
struct COW {
    LL v, x;
    bool operator<(const COW& rhs) const {
        return v == rhs.v ? x < rhs.x : v < rhs.v;
    }
} cow[MAXN];

LL cnt_bit[MAXN], dis_bit[MAXN];
LL sum(LL* bit, int i) {
    LL s = 0;
    while (i > 0) {
        s += bit[i];
        i -= i & -i;
    }
    return s;
}

void add(LL* bit, int i, LL x) {
    // 注意由于我们之前用距离做下标，所以这里的上界应该是MAXN，就是最远距离
    while (i <= MAXN) {
        bit[i] += x;
        i += i & -i;
    }
}

// [from, to)
LL cal_sum(LL* bit, int from, int to) {
    return sum(bit, to - 1) - sum(bit, from - 1);
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
#endif
    CLR(cnt_bit), CLR(dis_bit);
    scanf("%d", &N);
    rep(i, 1, N) scanf("%lld %lld", &cow[i].v, &cow[i].x);
    sort(cow + 1, cow + N + 1);
    LL ans = 0;
    for (int i = 1; i <= N; i++) {
        int v = cow[i].v, x = cow[i].x;
        LL LeftCow = cal_sum(cnt_bit, 1, x);
        LL RightCow = cal_sum(cnt_bit, x + 1, MAXN + 1);
        // cout << LeftCow << " " << RightCow << endl;
        ans += v * (LeftCow * x - cal_sum(dis_bit, 1, x) +
                    cal_sum(dis_bit, x + 1, MAXN + 1) - RightCow * x);
        add(cnt_bit, x, 1);
        add(dis_bit, x, x);
    }
    printf("%lld\n", ans);
    return 0;
}