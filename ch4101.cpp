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
#define MAXN 30000 + 5
///**********************************START*********************************///

int fa[MAXN], d[MAXN], Size[MAXN];
void init() {
    rep(i, 1, MAXN - 1) fa[i] = i, Size[i] = 1;
    CLR(d);
}
int get(int x) {
    if (x == fa[x]) return x;
    int root = get(fa[x]);
    d[x] += d[fa[x]];
    return fa[x] = root;
}
void merge(int x, int y) {
    x = get(x), y = get(y);
    fa[x] = y;
    d[x] = Size[y];
    Size[y] += Size[x];
    return;
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
#endif
    int T = READ();
    init();
    char ch;
    int x, y;
    rep(i, 1, T) {
        scanf("%c %d %d\n", &ch, &x, &y);
        if (ch == 'M') {
            merge(x, y);
        } else {
            int nx = get(x), ny = get(y);
            // cout << nx << " " << ny << endl;
            if (nx != ny) {
                printf("-1\n");
            } else {
                if (x == y)
                    printf("0\n");
                else {
                    printf("%d\n", abs(d[x] - d[y]) - 1);
                }
            }
        }
    }
    return 0;
}