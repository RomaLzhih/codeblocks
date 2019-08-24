/*
给你若干个开始和结束的线段，你需要的是把这些线段覆盖起来，使其能完整地盖住一段区间

问题是贪心，首先做的是排除那些无用的线段（起始点相同但是长度较短），
然后维护一个临时的上界，注意只有当现在线段的下一个线段不能覆盖住整个区间的时候才增加下一个。
*/
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
#include <typeinfo>
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
//#define FOREACH(i, t) for (decltype(t.begin()) i = t.begin(); i != t.end();
// i++)
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

int N, T, cnt;
struct cow {
    int l, r;
    cow(int x, int y) : l(x), r(y) {}
    bool operator<(const cow &rhs) const {
        return l == rhs.l ? r > rhs.r : l < rhs.l;
    }
};
set<cow> s;
map<int, int> mp;

int main() {
    // freopen("input.txt", "r", stdin);
    N = READ(), T = READ();
    pii a;
    REP(i, 1, N) {
        a.first = READ(), a.second = READ();
        if (mp[a.first] < a.second) mp[a.first] = a.second;
    }
    /*  cout << endl;
     for (auto i : mp) cout << i.first << " " << i.second << endl; */
    int up = 0, tmp = 0, flag = 0;
    for (map<int, int>::iterator i = mp.begin(); i != mp.end(); i++) {
        int l = (*i).first, r = (*i).second;
        if (l <= up + 1) {
            if (r > tmp) {
                tmp = r;
                flag = 1;
            }
            map<int, int>::iterator it = i;
            it++;
            if ((it == mp.end() && up < T && tmp >= T) ||
                ((*it).first > up + 1 && flag)) {
                up = tmp;
                cnt++;
                flag = 0;
            }
        }
    }
    if (up >= T)
        printf("%d", cnt);
    else
        printf("-1");
    return 0;
}
