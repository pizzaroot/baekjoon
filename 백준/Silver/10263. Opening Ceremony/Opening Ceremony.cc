#include <bits/stdc++.h>
using namespace std;
int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	int n; cin >> n; vector<int> h(n + 1);
	for (int i = 1; i <= n; i++) cin >> h[i];
	sort(h.begin(), h.end());
	int ans = n;
	for (int i = 1; i <= n; i++) ans = min(ans, n - i + h[i]);
	cout << ans << "\n";
	return 0;
}