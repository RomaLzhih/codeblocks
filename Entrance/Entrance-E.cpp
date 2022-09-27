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
int g[MAXN][MAXN], vis[MAXN][MAXN];
int dx[] = {1, 1, 2, 2, -1, -1, -2, -2};
int dy[] = {2, -2, 1, -1, 2, -2, 1, -1};

struct NODE {
    int x, y;
};

NODE st, ed;

int bfs() {
    queue<NODE> q;
    q.push(st);
    vis[st.x][st.y] = 1;
    while (!q.empty()) {
        NODE now = q.front();
        q.pop();
        if (now.x == ed.x && now.y == ed.y) {
            return g[now.x][now.y];
        }
        for (int i = 0; i < 8; i++) {
            int nx = now.x + dx[i];
            int ny = now.y + dy[i];
            if (!vis[nx][ny] && g[nx][ny] != -1 && nx >= 1 && nx <= 8 &&
                ny >= 1 && ny <= 8) {
                g[nx][ny] = g[now.x][now.y] + 1;
                vis[nx][ny] = 1;
                q.push(NODE{nx, ny});
            }
        }
    }
    return -1;
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
#endif
    int T, N = 0;
    while (scanf("%d\n", &T) && T != -1) {
        N++;
        char a, b;
        rep(i, 0, 10) rep(j, 0, 10) g[i][j] = 0, vis[i][j] = 0;

        rep(i, 1, T) {
            scanf("%c%c", &a, &b);
            getchar();
            // printf("%c%c", a, b);
            g[a - 'a' + 1][b - '0'] = -1;
        }
        scanf("%c%c", &a, &b);
        getchar();
        st.x = a - 'a' + 1, st.y = b - '0';
        scanf("%c%c", &a, &b);
        getchar();
        ed.x = a - 'a' + 1, ed.y = b - '0';

        if (st.x == ed.x && st.y == ed.y) {
            printf("Board %d: 0 moves\n", N);
            continue;
        } else if (g[st.x][st.y] == -1 || g[ed.x][ed.y] == -1) {
            printf("Board %d: not reachable\n", N);
            continue;
        }

        // rep(i, 1, 8) {
        //     cout << endl;
        //     rep(j, 1, 8) printf("%d ", g[i][j]);
        // }

        int ans = bfs();

        if (ans == -1)
            printf("Board %d: not reachable\n", N);
        else
            printf("Board %d: %d moves\n", N, ans);
    }
    return 0;
}