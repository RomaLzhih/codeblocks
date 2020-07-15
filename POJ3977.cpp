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
#define MAXN 32 + 5
///**********************************START*********************************///
int N;
map<LL, set<LL>> mp;
LL a[MAXN];
LL vis[MAXN];
int p;

LL absL(LL x) { return x < 0 ? -x : x; }

int main() {
    while (cin >> N && N) {
        rep(i, 0, N - 1) cin >> a[i];
        if (N == 1) {
            cout << a[0] << " " << 1 << endl;
            continue;
        }

        p = N >> 1;
        for (int x = 0; x < (1 << p); x++) {
            MEM(vis, 0);

            LL cnt = 0;
            for (int i = 0; i < p; i++) {
                if ((x >> i) & 1) {
                    vis[i] = 1;
                    cnt++;
                }
            }
            LL sum = 0;
            for (int i = 0; i < p; i++) {
                sum += vis[i] * a[i];
            }
            if (cnt == 0) cnt == LLINF;
            mp[sum].insert(cnt);
        }

        LL ans = LLINF, anscnt = 0;
        for (int x = 0; x < (1 << N - p); x++) {
            MEM(vis, 0);
            LL cnt = 0;
            for (int i = 0; i < N - p; i++) {
                if ((x >> i) & 1) {
                    vis[i + p] = 1;
                    cnt++;
                }
            }
            LL sum = 0;
            for (int i = p; i < N; i++) {
                sum += vis[i] * a[i];
            }

            map<LL, set<LL>>::iterator it = mp.lower_bound(sum);
            if (it == mp.begin()) {
                if (cnt != 0) {
                    ans = 0;
                    anscnt = cnt;
                } else {
                    continue;
                }
            } else if (it == mp.end()) {
                map<LL, set<LL>>::iterator pre = --it;
                LL diff1 = absL((*pre).first - sum);
                LL num = *mp[(*pre).first].begin();
                if (diff1 < ans) {
                    ans = diff1;
                    anscnt = num + cnt;
                } else if (diff1 == ans) {
                    anscnt = min(num + cnt, anscnt);
                }
            } else {
                map<LL, set<LL>>::iterator pre = --it;
                it++;
                LL diff1 = absL((*pre).first - sum);
                LL diff2 = absL((*it).first - sum);
                if (diff1 < diff2) {
                    LL num = *mp[(*pre).first].begin();
                    if (diff1 < ans) {
                        ans = diff1;
                        anscnt = *mp[(*pre).first].begin();
                        anscnt += cnt;
                    } else if (diff1 == ans) {
                        anscnt = min(num + cnt, anscnt);
                    }
                } else if (diff1 == diff2) {
                    LL num = *mp[(*pre).first].begin();
                    if (diff1 < ans) {
                        ans = diff1;
                        anscnt = min(*mp[(*pre).first].begin(),
                                     *mp[(*it).first].begin());
                        anscnt += cnt;
                    } else if (diff1 == ans) {
                        anscnt = min(num + cnt, anscnt);
                    }
                } else if (diff2 < diff1) {
                    LL num = *mp[(*it).first].begin();
                    if (diff2 < ans) {
                        ans = diff2;
                        anscnt = *mp[(*it).first].begin();
                        anscnt += cnt;
                    } else if (diff2 == ans) {
                        anscnt = min(num + cnt, anscnt);
                    }
                }
            }
        }

        printf("%lld %lld\n", ans, anscnt);
    }
    return 0;
}