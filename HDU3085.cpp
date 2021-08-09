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
char G[MAXN][MAXN];
int N, M;
int K;
struct NODE {
    int x, y;
} boy, girl, g1, g2;

const int dx[4] = {0, 1, 0, -1};
const int dy[4] = {1, 0, -1, 0};
int vis[MAXN][MAXN];

bool valid(int x, int y) {
    if (x < 0 || x >= N || y < 0 || y >= M || G[x][y] == 'X') return false;
    if (abs(x - g1.x) + abs(y - g1.y) <= 2 * K) return false;
    if (abs(x - g2.x) + abs(y - g2.y) <= 2 * K) return false;

    return true;
}

bool solve() {
    K = 0;
    CLR(vis);
    vis[boy.x][boy.y] = 1;
    vis[girl.x][girl.y] = 2;
    queue<NODE> q1, q2;
    q1.push(boy), q2.push(girl);
    while (!q1.empty() && !q2.empty()) {
        K++;
        // Boy
        for (int time = 0; time < 3; time++) {
            for (int t = 0, len = q1.size(); t < len; t++) {
                NODE now = q1.front();
                q1.pop();
                int x = now.x, y = now.y;
                if (!valid(x, y)) {
                    continue;
                }
                for (int dir = 0; dir < 4; dir++) {
                    int nx = x + dx[dir];
                    int ny = y + dy[dir];
                    if (!valid(nx, ny) || vis[nx][ny] == 1) {
                        continue;
                    }
                    if (vis[nx][ny] == 2) {
                        return true;
                    }
                    vis[nx][ny] = 1;
                    q1.push(NODE{nx, ny});
                }
            }
        }
        // Girl
        for (int t = 0, len = q2.size(); t < len; t++) {
            NODE now = q2.front();
            q2.pop();
            int x = now.x, y = now.y;
            if (!valid(x, y)) {
                continue;
            }
            for (int dir = 0; dir < 4; dir++) {
                int nx = x + dx[dir];
                int ny = y + dy[dir];
                if (!valid(nx, ny) || vis[nx][ny] == 2) {
                    continue;
                }
                if (vis[nx][ny] == 1) {
                    return true;
                }
                vis[nx][ny] = 2;
                q2.push(NODE{nx, ny});
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
        scanf("%d%d", &N, &M);
        rep(i, 0, N - 1) {
            scanf("%s", G[i]);
            // cout << G[i] << endl;
        }
        bool findGhost = false;
        rep(i, 0, N - 1) rep(j, 0, M - 1) {
            if (G[i][j] == 'M') {
                boy.x = i, boy.y = j;
            } else if (G[i][j] == 'G') {
                girl.x = i, girl.y = j;
            } else if (G[i][j] == 'Z') {
                if (!findGhost) {
                    g1.x = i, g1.y = j;
                    findGhost = true;
                } else {
                    g2.x = i, g2.y = j;
                }
            } else {
                continue;
            }
        }
        if (solve()) {
            printf("%d\n", K);
        } else {
            printf("-1\n");
        }
    }
    return 0;
}