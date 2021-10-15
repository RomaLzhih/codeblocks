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
int n, m;

int ans[2];
int man, id, flag;

struct NODE {
    int l, r, op;
} a[2 * MAXN];

int p[3 * MAXN];
int r[3 * MAXN];
void init(int n) {
    for (int i = 0; i < n; i++) {
        p[i] = i, r[i] = 0;
    }
}

int find(int x) { return p[x] == x ? x : p[x] = find(p[x]); }
bool same(int x, int y) { return find(x) == find(y); }
void unite(int x, int y) {
    x = find(x);
    y = find(y);
    if (x == y) return;
    if (r[x] < r[y]) {
        p[x] = y;

    } else {
        p[y] = x;
        if (r[x] == r[y]) r[x]++;
    }
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
#endif
    while (scanf("%d %d", &n, &m) != EOF) {
        char ch;
        for (int i = 0; i < m; i++) {
            scanf("%d%c%d", &a[i].l, &ch, &a[i].r);
            a[i].op = (ch == '=') ? 0 : (ch == '>' ? 1 : 2);
        }

        int cnt = 0;
        man = id = -1;
        for (int k = 0; k < n; k++) {
            init(3 * n);
            bool flag = 1;
            for (int i = 0; i < m; i++) {
                int l = a[i].l, r = a[i].r, op = a[i].op;
                if (l == k || r == k) continue;
                // printf("for %d %d %d\n", l, r, op);
                if (op == 0) {
                    if (same(l, r + n) || same(l + n, r)) {  // * wrong
                        id = max(id, i + 1);
                        flag = 0;
                        break;
                    } else {
                        unite(l, r);
                        unite(l + n, r + n);
                        unite(l + n + n, r + n + n);
                    }
                } else {
                    if (op == 2) swap(l, r);             // * change l > r
                    if (same(l, r) || same(l + n, r)) {  // * wrong
                        id = max(id, i + 1);
                        flag = 0;
                        break;
                    } else {
                        unite(l, r + n);
                        unite(l + n, r + n + n);
                        unite(l + n + n, r);
                    }
                }
            }
            if (flag) {
                // cout << "add for " << k << endl;
                man = k;
                cnt++;
            }
        }
        //* output
        if (cnt == 0) {
            printf("Impossible\n");
        } else if (cnt >= 2) {
            printf("Can not determine\n");
        } else {
            printf(
                "Player %d can be determined to be the judge after %d lines\n",
                man, id);
        }
    }

    return 0;
}