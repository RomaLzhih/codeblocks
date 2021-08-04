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
#include <fstream>
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
const int Ysize = 3;
const int Xsize = 469;
float g[Xsize][Ysize + 1];
map<float, float> mp[Ysize + 1];

int main() {
    freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdin);
    float x = 0.0, y = 0.0;
    float maxX = -1.0 * 1e5, minX = 1.0 * 1e5;

    for (int i = 0; i < Xsize; i++) {
        cin >> g[i][0];
        maxX = max(maxX, g[i][0]);
        minX = min(minX, g[i][0]);
        for (int j = 1; j <= Ysize; j++) {
            cin >> g[i][j];
        }
    }
    cout << maxX << endl << minX << endl;

    float maxY = -1.0 * 1e5, minY = 1.0 * 1e5;
    for (int j = 1; j <= Ysize; j++) {
    }
    float M = (maxX + minX) / 2;
    cout << "M " << M << endl;
    for (int i = 0; i < Xsize; i++) {
        float newX = 2 * M - g[i][0];
        for (int j = 1; j <= Ysize; j++) {
            mp[j].insert(make_pair(newX, g[i][j]));
        }
    }
    string filename =
        "D:\\aMain\\codeblocks\\codeblocks\\xuedan\\4.25\\output.txt";
    ofstream flow(filename);
    for (auto i : mp[1]) {
        flow << i.first;
        for (int j = 1; j <= Ysize; j++) {
            flow << " " << mp[j][i.first];
        }
        flow << endl;
    }
    return 0;
}