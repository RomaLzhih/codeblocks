#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;
const int maxn = 400;
int N;
int f[maxn][maxn];
int dp[maxn][maxn];

int main() {
    scanf("%d", &N);
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= i; j++) {
            scanf("%d", &f[i][j]);
        }
    }
    memset(dp, 0, sizeof(dp));
    dp[1][1] = f[1][1];
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= i; j++) {
            if (j == 1)
                dp[i][j] = dp[i - 1][j] + f[i][j];
            else if (j > 1 && j < N)
                dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - 1]) + f[i][j];
            else
                dp[i][j] = dp[i - 1][j - 1] + f[i][j];
        }
    }
    int ans = -1;
    for (int j = 1; j <= N; j++) {
        ans = max(ans, dp[N][j]);
    }
    printf("%d", ans);
    return 0;
}