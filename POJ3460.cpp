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
#define MAXN 20
///**********************************START*********************************///

int a[MAXN], b[MAXN], A[MAXN];
int N;

// return number of wrong descent
inline int check() {  //! 错误这里，int写成bool
    int cnt = 0;
    for (int i = 1; i < N; i++) {
        if (a[i + 1] != a[i] + 1) cnt++;
    }
    if (a[N] != N) cnt++;
    return cnt;
}

// [st,ed] insert to [tar
void move(int st, int ed, int tar) {
    int p = 1;
    for (int i = 1; i < st; i++) {
        b[p++] = a[i];
    }
    for (int i = ed + 1; i <= tar; i++) {
        b[p++] = a[i];
    }
    for (int i = st; i <= ed; i++) {
        b[p++] = a[i];
    }
    for (int i = tar + 1; i <= N; i++) {
        b[p++] = a[i];
    }
    memcpy(a, b, sizeof(b));
    // rep(i, 1, N) cout << a[i] << " ";
    // cout << endl;
    return;
}

bool dfs(int deep, int maxDeep) {
    int cost = check();
    if (cost == 0) {  //!错在这里了，把cost写成check
        return true;
    }
    if (3 * deep + cost > 3 * maxDeep) {
        return false;
    }

    int c[MAXN];
    memcpy(c, a, sizeof(a));
    for (int i = 1; i < N; i++) {
        for (int j = i; j < N; j++) {
            for (int k = j + 1; k <= N; k++) {
                move(i, j, k);
                if (dfs(deep + 1, maxDeep) == true) return true;
                memcpy(a, c, sizeof(c));
            }
        }
    }
    return false;
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
#endif
    int T = READ();
    while (T--) {
        N = READ();
        rep(i, 1, N) a[i] = READ();
        bool flag = false;
        memcpy(A, a, sizeof(a));

        for (int maxDeep = 0; maxDeep <= 4; maxDeep++) {
            // memcpy(a, A, sizeof(A));
            if (dfs(0, maxDeep)) {
                flag = true;
                printf("%d\n", maxDeep);
                break;
            }
        }
        if (!flag) {
            printf("5 or more\n");
        }
    }
    return 0;
}