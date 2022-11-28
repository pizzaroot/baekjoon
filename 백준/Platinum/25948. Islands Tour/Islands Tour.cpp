#include <bits/stdc++.h>
using namespace std;
bool v[1000000]; int dp[1000000];
int cycle(int x, vector<int> &p) {
    int start = x;
    int cnt = 1;
    while (p[x] != start) cnt++, x = p[x];
    for (int i = 0; i < cnt; i++) {dp[x] = cnt; x = p[x];}
    return cnt;
}
int dfs(int x, vector<int> &p) {
    if (x == -1) return 0;
    if (v[x]) return dp[x];
    if (v[p[x]] && dp[p[x]] == 0) return cycle(x, p);
    v[x] = true;
    int tmp = dfs(p[x], p) + 1;
    if (dp[x] == 0) dp[x] = tmp;
    return dp[x];
}
int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int m, n; cin >> m >> n; vector<int> p(n, -1);
    while (m--) {
        int v, w; cin >> v >> w;
        p[v] = w;
    }
    for (int i = 0; i < n; i++) dfs(i, p);
    cout << *max_element(dp, dp + n) << "\n";
    return 0;
}
