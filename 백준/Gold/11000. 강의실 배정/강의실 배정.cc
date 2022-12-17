#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pi;
int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	int n; cin >> n; vector<pi> a;
	for (int i = 0; i < n; i++) {
		int s, t; cin >> s >> t;
		a.push_back({s, 1}); a.push_back({t, -1});
	}
	sort(a.begin(), a.end());
	int ans = 0, cur = 0;
	for (int i = 0; i < a.size(); i++) {
		cur += a[i].second;
		ans = max(ans, cur);
	}
	cout << ans << "\n";
	return 0;
}