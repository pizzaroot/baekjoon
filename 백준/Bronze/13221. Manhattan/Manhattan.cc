#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pi;
int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	int x, y, n; cin >> x >> y >> n; vector<pi> a(n);
	for (int i = 0; i < n; i++) cin >> a[i].first >> a[i].second;
	int ans = abs(a[0].first - x) + abs(a[0].second - y);
	for (int i = 1; i < n; i++) ans = min(ans, abs(a[i].first - x) + abs(a[i].second - y));
	for (int i = 0; i < n; i++) {
		if (abs(a[i].first - x) + abs(a[i].second - y) == ans) cout << a[i].first << " " << a[i].second << "\n";
	}
	return 0;
}