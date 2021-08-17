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
#define MAXN 100 + 5
///**********************************START*********************************///
string a[MAXN], b[MAXN];
int n, ans;
string A, B;
map<string, int> ma;
map<string, int> mb;

int bfs() {
    queue<string> qa, qb;
    qa.push(A), qb.push(B);
    ma[A] = 0;
    mb[B] = 0;
    while (!qa.empty() && !qb.empty()) {
        int t;
        if (qa.size() <= qb.size()) {
            string s = qa.front();
            qa.pop();
            for (int i = 0; i < s.size(); i++) {
                for (int j = 0; j < n; j++) {
                    if (s.substr(i, a[j].size()) == a[j]) {
                        string ns =
                            s.substr(0, i) + b[j] + s.substr(i + a[j].size());
                        if (mb.count(ns)) {
                            int deep = ma[s] + 1 + mb[ns];
                            if (deep <= 10) return deep;
                        }
                        qa.push(ns);
                        ma[ns] = ma[s] + 1;
                    }
                }
            }
        } else {
            string s = qb.front();
            qb.pop();
            for (int i = 0; i < s.size(); i++) {
                for (int j = 0; j < n; j++) {
                    if (s.substr(i, b[j].size()) == b[j]) {
                        string ns =
                            s.substr(0, i) + a[j] + s.substr(i + b[j].size());
                        if (ma.count(ns)) {
                            int deep = mb[s] + 1 + ma[ns];
                            if (deep <= 10) return deep;
                        }
                        qb.push(ns);
                        mb[ns] = mb[s] + 1;
                    }
                }
            }
        }
    }
    return 11;
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
#endif
    cin >> A >> B;
    while (cin >> a[n] >> b[n]) n++;
    int ans = bfs();
    if (ans <= 10) {
        printf("%d", ans);
    } else {
        printf("NO ANSWER!");
    }
    return 0;
}