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
#define Lson(k) (k * 2 + 1)
#define Rson(k) (k * 2 + 2)
#define pii pair<int, int>
#define pll pair<LL, LL>
#define MOD ((int)1000000007)
#define MAXN 100000 + 10
#define DAT_SIZE (1 << 18) - 1
///**********************************START*********************************///
int N, Q;
int A[MAXN];
int L[MAXN], R[MAXN], X[MAXN];
char T[MAXN];

LL Data[DAT_SIZE], Datb[DAT_SIZE];

void add(int a, int b, int x, int k, int l, int r) {
    if (a <= l && r <= b) {
        Data[k] += x;
    } else if (l < b && r > a) {
        Datb[k] += (min(b, r) - max(a, l)) * x;
        add(a, b, x, Lson(k), l, (l + r) / 2);
        add(a, b, x, Rson(k), (l + r) / 2, r);
    }
}

LL sum(int a, int b, int k, int l, int r) {
    if (b <= l || r <= a) {
        return 0;
    } else if (a <= l && r <= b) {
        return Data[k] * (r - l) + Datb[k];
    } else {
        LL res = (min(b, r) - max(a, l)) * Data[k];
        // cout << k << " " << Lson(k) << " " << Rson(k) << endl;
        res += sum(a, b, Lson(k), l, (l + r) / 2);
        res += sum(a, b, Rson(k), (l + r) / 2, r);
        return res;
    }
}

void solve() {
    for (int i = 0; i < N; i++) {
        add(i, i + 1, A[i], 0, 0, N);
    }
    for (int i = 0; i < Q; i++) {
        if (T[i] == 'C') {
            add(L[i] - 1, R[i], X[i], 0, 0, N);
        } else {
            cout << sum(L[i] - 1, R[i], 0, 0, N) << endl;
        }
    }
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
#endif
    scanf("%d %d", &N, &Q);
    for (int i = 0; i < N; i++) {
        scanf("%d", &A[i]);
    }
    for (int i = 0; i < Q; i++) {
        getchar();
        scanf("%c", &T[i]);
        if (T[i] == 'C') {
            scanf("%d%d%d", &L[i], &R[i], &X[i]);
        } else {
            scanf("%d%d", &L[i], &R[i]);
        }
    }
    solve();
    return 0;
}