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
char g[25][25];
int n, m;
const int dx[] = {1, -1, 0, 0};
const int dy[] = {0, 0, 1, -1};
bool check_x(int x, int y) {
    char ch = g[x][y];
    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        int num = 1;
        while (nx >= 0 && ny >= 0 && nx < n && ny < m) {
            if (g[nx][ny] == g[x][y]) {
                if (num <= 2) {
                    nx += dx[i];
                    ny += dy[i];
                    num++;
                } else {
                    g[nx][ny] = '0';
                    g[nx - dx[i]][ny - dy[i]] = '0';
                }
            }
        }
    }
}
void drop() {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if(g[])
        }
    }
}
int main() {
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; i++) {
        scanf("%s", g[i]);
    }
    int x1, y1, x2, y2;
    scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
    swap(g[x1][y1], g[x2][y2]);
    bool flag = false;
    while (flag == false) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if () check_x(i, j)
            }
        }
    }
}