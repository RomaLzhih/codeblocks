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
LL T;
vector<vector<LL>> ans;

LL poww(LL num) { return num * num; }

bool cmp(const vector<LL>& v1, const vector<LL>& v2) {
    return v1.size() > v2.size();
}

int main() {
    while (cin >> T) {
        // T = 2030;
        LL s = 1, t = 1;
        LL sum = 0;
        LL len = (int)sqrt(T * 1.0) + 1;
        ans.clear();
        for (;;) {
            while (poww(t) <= T && sum < T) {
                sum += poww(t++);
            }
            if (sum < T) break;
            if (sum == T) {
                vector<LL> v;
                for (int i = s; i < t; i++) {
                    v.push_back(i);
                }
                ans.push_back(v);
            }
            sum -= poww(s++);
            if (poww(s) > T) break;
        }

        sort(ans.begin(), ans.end(), cmp);
        printf("%d\n", ans.size());
        for (int i = 0; i < ans.size(); i++) {
            printf("%d", ans[i].size());
            // sort(ans[i].begin(), ans[i].end());
            for (int j = 0; j < ans[i].size(); j++) {
                printf(" %lld", ans[i][j]);
            }
            printf("\n");
        }
    }
    return 0;
}