#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	ll p[3], ans = 0; cin >> p[0] >> p[1] >> p[2];
	int idx[3] = { 0, 1, 2 };
	sort(p, p + 3);
	do {
		ll a = p[idx[0]], b = p[idx[1]], c = p[idx[2]];
		for (ll x = 1; x <= min(a, (min(b, c) - 1) / 2); x++) {
			ans += max(0LL, min(a, min(b, c) - x) - x);
		}
	} while (next_permutation(idx, idx + 3));
	cout << ans * 8 << "\n";
	return 0;
}