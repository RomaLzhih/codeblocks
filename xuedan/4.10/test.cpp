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
#define MAXN 1000 + 5
///**********************************START*********************************///
multimap<int, int> mp;

int main() {
    //#ifndef ONLINE_JUDGE
    freopen("input4-5-2.txt", "r", stdin);
    //#endif
    float label, val;
    float mx = -1, mn = LLINF;
    float ave = 0.0;
    for (int i = 0; i < 100; i++) {
        cin >> label >> val;
        mx = max(mx, val);
        mn = min(mn, val);
        mp.insert(make_pair(val, label));
        ave += val;
    }
    ave /= 100;
    float sum = 0.0;
    for (auto i : mp) {
        float val = i.first * 1.0;
        float mid = val - ave;
        sum += mid * mid;
    }
    sum = sqrt(sum / 100);
    cout << "ave is " << ave << endl;
    cout << "delta " << sum << endl;
    /* for (auto i : mp) {
        cout << i.second << " " << i.first << endl;
    } */
    cout << "max is " << mx << " min is " << mn << endl;
    // 481.065 1168.79
    map<int, int> store;
    store.clear();
    int step = 50;
    int Start = 400, End = 1300;
    for (int i = Start; i <= End; i += step) {
        store.insert(make_pair(i, 0));
    }
    for (auto i : mp) {
        int val = i.first;
        // cout << val << endl;
        for (auto j : store) {
            if (j.first >= End) {
                break;
            }
            int L = j.first;
            int R = L + step;
            if (val >= L && val < R) {
                store[L] += 1;
                break;
            }
        }
    }
    int a = 0;
    for (auto i : store) {
        cout << i.first << " " << i.second << endl;
        a += i.second;
    }
    cout << a << endl;
    return 0;
}