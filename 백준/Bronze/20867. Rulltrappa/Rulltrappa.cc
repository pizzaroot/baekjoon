#include <bits/stdc++.h>
using namespace std;
int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	int m, s, g; cin >> m >> s >> g;
	double a, b; cin >> a >> b;
	int l, r; cin >> l >> r;
	if (g * b * s * l + a * b * s * m < g * a * s * r + b * a * g * m) cout << "friskus\n";
	else cout << "latmask\n";
	return 0;
}