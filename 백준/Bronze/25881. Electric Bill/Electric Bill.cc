#include <bits/stdc++.h>
using namespace std;
int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	int r, e, t; cin >> r >> e >> t;
	while (t--) {
		int c; cin >> c;
		cout << c << " " << r * min(c, 1000) + e * max(0, c - 1000) << "\n";
	}
	return 0;
}