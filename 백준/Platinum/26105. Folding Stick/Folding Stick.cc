#include <bits/stdc++.h>
#define INF 0x7fffffff
#define SIZE 100001
using namespace std;
int seg[SIZE << 1][2];
void update(int id, int idx, int val) {
    seg[SIZE + idx][id] = val;
    for (int i = (SIZE + idx) >> 1; i > 0; i >>= 1) seg[i][id] = min(seg[i << 1][id], seg[i << 1 | 1][id]);
}
int query(int id, int left, int right) {
    int ret = INF;
    for (int l = left + SIZE, r = right + SIZE; l <= r; l >>= 1, r >>= 1) {
        if (l & 1) ret = min(ret, seg[l++][id]);
        if (~r & 1) ret = min(ret, seg[r--][id]);
    }
    return ret;
}
int pos(int val, int right) {
	right += SIZE;
    while (seg[right][0] > val) right = (right - 1) >> 1;
    while (right < SIZE) {
        if (seg[right << 1 | 1][0] <= val) right = right << 1 | 1;
        else right <<= 1;
    }
    return right - SIZE;
}
int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	int n; cin >> n; vector<int> a(n + 1), psum(n + 1); vector<vector<int>> dp(n + 1, vector<int>(2));
	for (int i = 1; i <= n; i++) {
		cin >> a[i]; psum[i] = psum[i - 1] + a[i];
	}
	dp[1][0] = dp[1][1] = a[1]; update(0, 1, a[1]); update(1, 1, a[1]);
	for (int i = 2; i <= n; i++) {
		int lo = pos(psum[i], i - 1);
		dp[i][0] = min(query(1, lo + 1, i - 1), psum[i] - psum[lo - 1]);
		dp[i][1] = max(a[i], psum[i - 1] - psum[pos(psum[i - 1], i - 1) - 1]);
		update(0, i, dp[i][1] + psum[i - 1]);
		update(1, i, dp[i][1]);
	}
	cout << min(dp[n][0], dp[n][1]) << "\n";
	return 0;
}