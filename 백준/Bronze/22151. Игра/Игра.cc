#include <bits/stdc++.h>
using namespace std;
int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	int t; cin >> t;
	while (t--) {
		int m, a, b, x, y; cin >> m >> a >> b >> x >> y;
		int dist = abs(a - x) + abs(b - y);
		if (dist > m) cout << "Infinity\n";
		else cout << "First 1\n";
	}
	return 0;
}