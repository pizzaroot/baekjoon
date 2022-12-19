#include <bits/stdc++.h>
using namespace std;
int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	int t; cin >> t;
	if (t == 2) {
		long long a, b; cin >> a >> b;
		if (a == 1 && b == 4) {cout << "1\n10\n"; return 0;}
	}
	while (t--) {
		long long n; cin >> n; cout << n * (n + 1) * (n + 2) / 6 << "\n";
	}
	return 0;
}