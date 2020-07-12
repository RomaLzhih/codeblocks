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
#define MAXN 100000 + 5
///**********************************START*********************************///
int N, K;
vector<int> ans;
struct node {
    int v, w, id;
} a[MAXN];

struct NODE {
    int tot, id;
    bool operator<(NODE &rhs) const { return tot > rhs.tot; }
} V[MAXN];

bool C(int x) {
    ans.clear();
    for (int i = 0; i < N; i++) {
        V[i].tot = a[i].v - x * a[i].w;
        V[i].id = a[i].id;
    }
    sort(V, V + N);
    int sum = 0;
    for (int i = 0; i < K; i++) {
        sum += V[i].tot;
        ans.push_back(V[i].id);
    }
    return sum >= 0;
}

void solve() {
    int ub = INF, lb = 0;
    while (ub - lb > 1) {
        int mid = (ub + lb) >> 1;
        if (C(mid)) {
            lb = mid;
        } else {
            ub = mid;
        }
    }
    sort(ans.begin(), ans.end());
    for (int i = 0; i < ans.size(); i++) {
        if (i == 0) {
            printf("%d", ans[i]);
        } else {
            printf(" %d", ans[i]);
        }
    }
    return;
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
#endif  // !ONLINE_JUDGE
    N = READ(), K = READ();
    for (int i = 0; i < N; i++) {
        a[i].v = READ(), a[i].w = READ();
        a[i].id = i + 1;
    }
    solve();
    return 0;
}