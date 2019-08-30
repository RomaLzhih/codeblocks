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
#define MAXN 100 + 5
///**********************************START*********************************///
const int dx[] = {0, 0, 1, -1};
const int dy[] = {1, -1, 0, 0};
int W, H, ans;
int g[MAXN][MAXN];
pii st, ed;
bool legal(int x, int y) { return x >= 1 && x <= H && y >= 1 && y <= W; }
bool reach(int x, int y) { return g[x][y] == 3; }
bool block(int x, int y) { return g[x][y] == 1; }
bool flag;

void dfs(int x, int y, int step) {
    if (reach(x, y) && step <= 10) {
        ans = min(ans, step);
        flag = true;
        return;
    }
    if (step >= 10) return;
    for (int i = 0; i <= 3; i++) {
        int nx = x, ny = y;
        if (block(x + dx[i], y + dy[i])) continue;
        while (!block(nx, ny) && legal(nx, ny) && !reach(nx, ny)) {
            nx += dx[i], ny += dy[i];
        }
        // cout << "nx: " << nx << " ny: " << ny << endl;
        if (!legal(nx, ny)) {
            continue;
        } else if (block(nx, ny)) {
            g[nx][ny] = 0;
            dfs(nx - dx[i], ny - dy[i], step + 1);
            g[nx][ny] = 1;
        } else if (reach(nx, ny)) {
            ans = min(ans, step + 1);
            flag = true;
            return;
        }
    }
    return;
}

int main() {
    // freopen("input.txt", "r", stdin);
    while (scanf("%d%d", &W, &H) && W && H) {
        REP(i, 1, H) REP(j, 1, W) {
            g[i][j] = READ();
            if (g[i][j] == 2)
                st.first = i, st.second = j;
            else if (g[i][j] == 3)
                ed.first = i, ed.second = j;
        }
        if (st == ed) {
            cout << ans << endl;
            continue;
        }
        flag = false;
        ans = INF;
        dfs(st.first, st.second, 0);
        if (flag)
            cout << ans << endl;
        else
            cout << -1 << endl;
    }
    return 0;
}
