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
#define N 1000 + 5
///**********************************START*********************************///
#define semaphore int
void P(semaphore) {}
void V(semaphore) {}
const int buffer_size = 1;

semaphore buffer_A_empty = 1;  //缓冲区A可放入的水果数目
semaphore buffer_B_empty = 1;
semaphore buffer_C_empty = 1;
semaphore mutex_A = 1;
semaphore mutex_B = 1;
semaphore mutex_C = 1;

void p1() {
    while (true) {
        P(buffer_A_empty);
        P(mutex_A);
        // generate random number
        V(mutex_A);
    }
}

void p2() {
    while (true) {
        P(mutex_A);
        // calculate squre result
        V(mutex_A);
        V(buffer_A_empty);

        P(buffer_B_empty);
        P(mutex_B);
        // put result
        V(mutex_B);
    }
}

void p3() {
    while (true) {
        P(mutex_A);
        // calculate cube result
        V(mutex_A);
        V(buffer_A_empty);

        P(buffer_C_empty);
        P(mutex_C);
        // put result
        V(mutex_C);
    }
}

void p4() {
    while (true) {
        P(mutex_B);
        P(mutex_C);
        // read square result
        // read cube result
        // add above two numbers together
        // output the result
        V(mutex_B);
        V(mutex_C);
        V(buffer_B_empty);
        V(buffer_C_empty);
    }
}

semaphore _empty = N;
semaphore mutex = 1;

void reader_sign() {
    while (true) {
        P(_empty);
        P(mutex);
        // sign and get the number
        V(mutex);
    }
}

void reader_return() {
    while (true) {
        P(mutex);
        // return the number
        V(mutex);
        V(_empty);
    }
}

int prepare_fruit() {}
int result;

semaphore plate_empty = 1;
semaphore apple = 0;
semaphore orange = 0;
semaphore mutex = 1;

void father() {
    result = prepare_fruit();
    P(plate_empty);
    P(mutex);
    // put the fruit on the plate
    V(mutex);

    if (result == apple) {
        V(apple);
    } else {
        V(orange);
    }
}

void son() {
    P(apple);
    P(mutex);
    // take the apple away
    V(mutex);
    V(plate_empty);
}

void daughter() {
    P(orange);
    P(mutex);
    // take the orange away
    V(mutex);
    V(plate_empty);
}

int countA = 0, countB = 0;
semaphore x = 1, mutexA = 1, mutexB = 1;

void east_to_west() {
    P(mutexA);
    countA++;
    if (countA == 1) P(x);
    V(mutexA);
    // drive across the road
    P(mutexA);
    countA--;
    if (countA == 0) V(x);
    V(mutexA);
}

void west_to_east() {
    P(mutexB);
    countB++;
    if (countB == 1) P(x);
    V(mutexB);
    // drive across the road
    P(mutexB);
    countB--;
    if (countB == 0) V(x);
    V(mutexB);
}

semaphore tank_empty = 10;
semaphore bottle_empty = 3;
semaphore tank_mutex = 1;
semaphore bottle_mutex = 1;
semaphore tank_full = 0;

void old_monk() {
    while (true) {
        P(tank_full);
        P(bottle_empty);

        P(bottle_mutex);
        // take water from home
        V(bottle_mutex);

        V(bottle_empty);
        V(tank_empty);
    }
}

void little_monk() {
    while (true) {
        P(tank_empty);
        P(bottle_empty);

        P(tank_mutex);
        // get water from tank
        V(tank_mutex);

        P(bottle_mutex);
        // pour water to home
        V(bottle_mutex);

        V(bottle_empty);
        V(tank_full);
    }
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
#endif  // !ONLINE_JUDGE

    return 0;
}