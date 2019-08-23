#include <cstdio>
#include <iostream>
#include <queue>
using namespace std;
typedef long long LL;
priority_queue<LL, vector<LL>, greater<LL> > q;

int main() {
    int N;
    LL ans = 0;
    scanf("%d", &N);
    for (int i = 1; i <= N; i++) {
        int tmp;
        cin >> tmp;
        q.push(tmp);
    }
    while (q.size() > 1) {
        LL tmp = q.top();
        q.pop();
        tmp += q.top();
        q.pop();
        ans += tmp;
        q.push(tmp);
    }
    printf("%lld", ans);
    return 0;
}