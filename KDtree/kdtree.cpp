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
#define Lson(index) (index * 2)
#define Rson(index) (index * 2 + 1)
#define pii pair<int, int>
#define pll pair<LL, LL>
#define MOD ((int)1000000007)
#define MAXN 1000 + 5
///**********************************START*********************************///

struct point {
    int x, y;
};

struct kdtree {
    vector<point> ps;
} kd[MAXN];

bool cmpx(point const& l, point const& r) {
    return l.x < r.x;
}

bool cmpy(point const& l, point const& r) {
    return l.y < r.y;
}

//* even deep divide by x; odd deep divide by y
void build(int r, int deep) {
    if (kd[r].ps.size() == 1) return;
    if (!(deep & 1)) {  // even
        sort(kd[r].ps.begin(), kd[r].ps.end(), cmpx);
    } else if (deep & 1) {
        sort(kd[r].ps.begin(), kd[r].ps.end(), cmpy);
    }
    for (int i = 0; i < kd[r].ps.size() / 2; i++) {
        kd[Lson(r)].ps.push_back(kd[r].ps[i]);
    }
    for (int i = kd[r].ps.size() / 2; i < kd[r].ps.size(); i++) {
        kd[Rson(r)].ps.push_back(kd[r].ps[i]);
    }
    build(Lson(r), deep + 1);
    build(Rson(r), deep + 1);
    return;
}

int n;

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
#endif
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> kd[1].ps[i].x >> kd[1].ps[i].y;
    }
    build(1, 1);
    return 0;
}