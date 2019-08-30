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
#define MAXN 100000 + 5
///**********************************START*********************************///
int N, C, F;
int l[MAXN], r[MAXN];
pii cow[MAXN];
priority_queue<int> q;

int main() {
    // freopen("input.txt", "r", stdin);
    N = READ(), C = READ(), F = READ();
    REP(i, 1, C) cow[i].first = READ(), cow[i].second = READ();
    sort(cow + 1, cow + 1 + C);
    int sum = 0, half = N >> 1;
    REP(i, 1, C) {
        l[i] = q.size() == half ? sum : INF;
        sum += cow[i].second;
        q.push(cow[i].second);
        if (q.size() > half) {
            sum -= q.top();
            q.pop();
        }
    }
    sum = 0;
    while (!q.empty()) q.pop();
    PER(i, C, 1) {
        r[i] = q.size() == half ? sum : INF;
        sum += cow[i].second;
        q.push(cow[i].second);
        if (q.size() > half) {
            sum -= q.top();
            q.pop();
        }
    }
    int flag = 0;
    PER(i, C, 1) {
        if (l[i] == INF || r[i] == INF) continue;
        if (l[i] + r[i] + cow[i].second <= F) {
            flag ^= 1;
            cout << cow[i].first << endl;
            break;
        }
    }
    if (!flag) cout << -1 << endl;
    return 0;
}