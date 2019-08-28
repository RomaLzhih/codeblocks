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
    int x = 0, ch = getchar();
    for (; ch < '0' || ch > '9'; ch = getchar())
        ;
    for (; ch >= '0' && ch <= '9';
         x = (x << 1) + (x << 3) + ch - '0', ch = getchar())
        ;
    return x;
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
#define MAXN 50000 + 5
///**********************************START*********************************///

int p[3 * MAXN];
int r[3 * MAXN];

void init(int n) {
    for (int i = 1; i <= n; i++) {
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

int N, K;

int main() {
    // freopen("input.txt", "r", stdin);
    cin >> N >> K;
    init(N * 3);
    int ans = 0;
    while (K--) {
        int id = READ(), x = READ(), y = READ();
        if (x < 1 || x > N || y < 1 || y > N) {
            ans++;
            continue;
        }
        if (id == 1) {
            if (same(x, y + N) || same(x, y + 2 * N)) {
                ans++;
            } else {
                unite(x, y);
                unite(x + N, y + N);
                unite(x + N + N, y + N + N);
            }
        } else {
            if (same(x, y) || same(x, y + 2 * N)) {
                ans++;
            } else {
                unite(x, y + N);
                unite(x + N, y + N + N);
                unite(x + N + N, y);
            }
        }
    }
    cout << ans << endl;
    return 0;
}