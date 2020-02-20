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

#define REP(i, a, b) for (int i = (a); i < (b); i++)
#define PER(i, a, b) for (int i = (a); i > (b); i--)
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
int L, M, N;
int pos[MAXN];

bool C(int x) {
    int sum = 0, last = 0;
    for (int i = 1; i <= N + 1; i++) {
        if (pos[i] - pos[last] < x) {
            sum++;
            if (sum > M) {
                return false;
            }
        } else {
            last = i;
        }
    }
    return true;
}

void jojo() {
    sort(pos, pos + N + 1);
    int lb = 0, ub = L + 1;
    while (ub - lb > 1) {
        int mid = (ub + lb) / 2;
        if (C(mid)) {
            // cout << "true: " << mid << endl;
            lb = mid;
        } else {
            // cout << "false: " << mid << endl;
            ub = mid;
        }
    }
    cout << lb << endl;
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
#endif  // !ONLINE_JUDGE
    L = READ(), N = READ(), M = READ();
    for (int i = 1; i <= N; i++) pos[i] = READ();
    pos[0] = 0;
    pos[N + 1] = L;
    jojo();
    return 0;
}