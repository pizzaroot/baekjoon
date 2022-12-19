#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	ll n, m, k; cin >> n >> m; k = n - m;
	ll p2n = 0, p5n = 0, p2m = 0, p5m = 0;
	for (ll i = 2; i <= n; i <<= 1) p2n += n / i;
	for (ll i = 5; i <= n; i *= 5) p5n += n / i;
	for (ll i = 2; i <= m; i <<= 1) p2m += m / i;
	for (ll i = 5; i <= m; i *= 5) p5m += m / i;
	for (ll i = 2; i <= k; i <<= 1) p2m += k / i;
	for (ll i = 5; i <= k; i *= 5) p5m += k / i;
	cout << min(p2n - p2m, p5n - p5m) << "\n";
	return 0;
}