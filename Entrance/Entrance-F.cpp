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
#define MAXN 10000 + 5
#define MAXM 10000 + 5
///**********************************START*********************************///
const int N = 2005, M = 4000010;
int head[N], ver[M], edge[M], Next[M];
double d[N];
int n, m, tot;
queue<int> q;
bool v[N];

void add(int x, int y, int z) {
    ver[++tot] = y, edge[tot] = z, Next[tot] = head[x], head[x] = tot;
}

void spfa(int s) {
    d[s] = 100;
    v[s] = 1;
    q.push(s);
    while (q.size()) {
        int x = q.front();
        // cout << x << endl;
        q.pop();
        v[x] = 0;
        for (int i = head[x]; i; i = Next[i]) {
            int y = ver[i], z = edge[i];
            // cout << y << endl;
            if (d[y] > d[x] / (1.0 - 0.01 * z)) {
                d[y] = d[x] / (1.0 - 0.01 * z);
                if (!v[y]) {
                    q.push(y), v[y] = 1;
                }
            }
        }
    }
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
#endif
    int n = READ(), m = READ();
    rep(i, 1, m) {
        int u = READ(), v = READ(), w = READ();
        add(u, v, w);
        add(v, u, w);
    }
    rep(i, 1, n) {
        v[i] = 0;
        d[i] = 1e9;
    }
    int s = READ(), t = READ();
    spfa(t);
    printf("%.8lf", d[s]);
    return 0;
}