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
#define MAXN 1000 + 5
///**********************************START*********************************///
int p[MAXN];
int r[MAXN];
int posx[MAXN], posy[MAXN];
int dist[MAXN][MAXN];
int fix[MAXN];
set<int> s[MAXN];
int N, D;

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

double dis(int x2, int y2, int x1, int y1) {
    return 1ll * abs(x1 - x2) * abs(x1 - x2) +
           1ll * abs(y1 - y2) * abs(y1 - y2);
}

int main() {
    // freopen("input.txt", "r", stdin);
    scanf("%d%d", &N, &D);
    init(N);
    int x, y;
    REP(i, 1, N) scanf("%d%d", &posx[i], &posy[i]);
    REP(i, 1, N) {
        REP(j, 1, N) {
            dist[i][j] = dis(posx[i], posy[i], posx[j], posy[j]);
            if (dist[i][j] <= 1ll * D * D) s[i].insert(j), s[j].insert(i);
        }
    }
    char ch;
    getchar();
    while (scanf("%c", &ch) != EOF) {
        int a, b;
        if (ch == 'O') {
            scanf("%d", &a);
            fix[a] = 1;
            for (set<int>::iterator i = s[a].begin(); i != s[a].end(); i++) {
                if (fix[*i]) unite(a, *i);
            }
        } else if (ch == 'S') {
            scanf("%d%d", &a, &b);
            if (same(a, b))
                printf("SUCCESS\n");
            else
                printf("FAIL\n");
        }
    }
    return 0;
}