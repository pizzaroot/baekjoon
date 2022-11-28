/**
 *    author:  pizzaroot
 *    created: Tue Jul 26 2022 23:27:47 GMT+0900 (한국 표준시)
**/
#include <bits/stdc++.h>
#define SIZE 3001
#define MOD 998244353
using namespace std;
typedef long long ll;
ll dp[SIZE][SIZE];
ll sum[SIZE][SIZE];
int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int n; cin >> n; vector<int> c(n + 1), x(n + 1), y(SIZE);
    for (int i = 1; i <= n; i++) cin >> c[i];
    int init = 1;
    for (int i = 1; i <= n; i++) {
        if (!y[c[i]]) x[i] = 0;
        else x[i] = y[c[i]];
        y[c[i]] = i;
        if (i == n) break;
        if (c[i] == c[i + 1]) init = 0;
    }
    sum[1][1] = dp[1][1] = init;
    for (int i = 1; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            dp[i][j] = (sum[j - 1][i] + sum[x[j + 1]][i - 1] - sum[j - 1][i - 1] - sum[x[j + 1]][i] + MOD * 2) % MOD;
            dp[j][i] = (sum[j - 1][i] + sum[x[j + 1]][i - 1] - sum[j - 1][i - 1] - sum[x[j + 1]][i] + MOD * 2) % MOD;
            sum[i][j] = (sum[i - 1][j] + sum[i][j - 1] + dp[i][j] - sum[i - 1][j - 1] + MOD * 2) % MOD;
            sum[j][i] = (sum[j - 1][i] + sum[j][i - 1] + dp[j][i] - sum[j - 1][i - 1] + MOD * 2) % MOD;
        }
        if (i == n - 1) break;
        dp[i + 1][i + 1] = (sum[i][i] + sum[x[i + 2]][x[i + 2]] - sum[i][x[i + 2]] - sum[x[i + 2]][i] + MOD * 2) % MOD;
        sum[i + 1][i + 1] = (sum[i][i + 1] + sum[i + 1][i] + dp[i + 1][i + 1] - sum[i][i] + MOD * 2) % MOD;
    }
    cout << sum[n - 1][n - 1] << "\n";
    return 0;
}