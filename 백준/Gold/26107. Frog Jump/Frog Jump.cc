#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	int n, k, rightmax; cin >> n >> k; vector<ll> dp(n);
	cin >> rightmax >> rightmax;
	for (int i = 1; i < n; i++) {
		int a, b; cin >> a >> b;
		if (rightmax < a) dp[i] = dp[i - 1] + a - rightmax;
		else dp[i] = dp[i - 1];
		rightmax = max(rightmax, b);
	}
	int last = 0; ll ans = 0;
	while (k--) {
		int tmp; cin >> tmp; tmp--;
		ans += abs(dp[tmp] - dp[last]);
		last = tmp;
	}
	cout << ans << "\n";
	return 0;
}