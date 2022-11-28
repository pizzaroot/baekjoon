#include <bits/stdc++.h>
using namespace std;
int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	int t; cin >> t;
	for (int tc = 1; tc <= t; tc++) {
		cout << "Data Set " << tc << ":\n";
		int n, s, d, ans = 0; cin >> n >> s >> d;
		while (n--) {
			int a, b; cin >> a >> b;
			if (a <= d * s) ans += b;
		}
		cout << ans << "\n\n";
	}
	return 0;
}