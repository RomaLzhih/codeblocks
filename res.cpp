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

int main() {
#ifndef ONLINE_JUDGE
    // freopen("input.txt","r", stdin);
#endif  // !ONLINE_JUDGE
    double gap = 0.0, time = 0.0;
    int obj = 0, nodes = 0, cut = 0;
    int n = 10;
    for (int i = 0; i < n; i++) {
        double _gap, _time;
        int _obj, _nodes, _cut;
        scanf("%lf %lf %d %d %d", &_gap, &_time, &_obj, &_nodes, &_cut);
        // cin >> _gap >> _time >> _obj >> _nodes >> _cut;
        gap += _gap;
        time += _time;
        obj += _obj;
        nodes += _nodes;
        cut += _cut;
    }
    cout << time << endl;
    printf("Gap: %lf\nTime: %lf\nObj: %d\nNodes: %d\nCut: %d\n",
           gap / (1.0 * n), time / (1.0 * n), obj / n, nodes / n, cut / n);
    return 0;
}