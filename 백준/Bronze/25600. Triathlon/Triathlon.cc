#include <bits/stdc++.h>
using namespace std;
int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	unsigned int ans = 0; short n; cin >> n;
	while (n--) {
		short a, d, g; cin >> a >> d >> g;
		unsigned int add = a * (d + g);
		if (a == d + g) add <<= 1;
		ans = max(ans, add);
	}
	cout << ans << "\n";
	return 0;
}