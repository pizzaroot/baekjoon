#include <bits/stdc++.h>
using namespace std;
int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	int a, x, b, y, t; cin >> a >> x >> b >> y >> t;
	cout << max(t - 30, 0) * 21 * x + a << " " << max(t - 45, 0) * 21 * y + b << "\n";
	return 0;
}