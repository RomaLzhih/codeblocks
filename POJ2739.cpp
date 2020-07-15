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
bool visit[10100000];
int prime[10000000];
int T;

int prime_num = 0;
void generate_prim(int n) {
    memset(visit, true, sizeof(visit));
    for (int i = 2; i <= n; ++i) {
        if (visit[i] == true) prime[++prime_num] = i;
        for (int j = 1; ((j <= prime_num) && (i * prime[j] <= n)); ++j) {
            visit[i * prime[j]] = false;
            if (i % prime[j] == 0) break;
        }
    }
    return;
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
#endif
    generate_prim(10000 + 1);
    while (scanf("%d", &T) && T) {
        int cnt = 0;
        int s = 1, t = 1, sum = 0;
        for (;;) {
            while (t <= prime_num && sum < T) {
                sum += prime[t++];
            }
            if (sum < T) break;
            if (sum == T) cnt++;
            sum -= prime[s++];
            if (prime[s] > T) break;
        }
        printf("%d\n", cnt);
    }
    return 0;
}