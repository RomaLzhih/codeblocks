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
#define MAXN 20 + 5
///**********************************START*********************************///
string ss, sn;

char s[MAXN], ns[MAXN];
int nex[MAXN];

void get_next(char* p, int next[]) {
    int pLen = strlen(p) + 1;  //要求循环节长度时这里才+1
    next[0] = -1;
    int k = -1;
    int j = 0;
    while (j < pLen - 1) {
        if (k == -1 || p[j] == p[k]) {
            ++j;
            ++k;
            if (p[j] != p[k])
                next[j] = k;
            else
                next[j] = next[k];
        } else {
            k = next[k];
        }
    }
}

int gcd(int a, int b) { return b > 0 ? gcd(b, a % b) : a; }

void cal_cal(int len) {
    int up = 0, down = 0;
    for (int i = len - 1; i >= 0; i--)
        up += int(s[i] - '0') * pow(10, len - i - 1);
    for (int i = 0; i < len; i++) down += 9 * pow(10, i);
    int g = gcd(up, down);
    printf("%d/%d\n", up / g, down / g);
    return;
}

void cal_cal2(int st, int len) {
    char tmp[20];
    int up = 0, down = 0;
    int a, b;

    for (int i = 0; i < st; i++) tmp[i] = s[i];
    tmp[st] = '\0';
    a = atoi(tmp);
    for (int i = st; i < st + len; i++) tmp[i - st] = s[i];
    tmp[len] = '\0';
    b = atoi(tmp);

    up = a * pow(10, len) + b - a;
    int pos = 0;
    for (int i = 0; i < len; i++) tmp[pos++] = '9';
    for (int i = 0; i < st; i++) tmp[pos++] = '0';
    down = atoi(tmp);
    int g = gcd(up, down);
    printf("%d/%d\n", up / g, down / g);
    return;
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
#endif  // !ONLINE_JUDGE
    while (cin >> ss) {
        if (ss.size() == 1) break;
        int pos = 0;
        for (int i = 2; ss[i] != '.'; i++) s[pos++] = ss[i];
        s[pos] = '\0';
        int flag = 0;  // 1为全循环，2为混合循环
        get_next(s, nex);
        int len = pos - nex[pos];
        if (len != pos) {
            cal_cal(len);
        } else {
            int st;
            for (st = 1; st < pos; st++) {
                int nlen = 0;
                for (int i = st; i < pos; i++) {
                    ns[nlen++] = s[i];
                }
                CLR(nex);
                get_next(ns, nex);
                if (nlen - nex[nlen] != nlen) {
                    cal_cal2(st, nlen);
                    break;
                } else
                    continue;
            }
        }
    }
    return 0;
}