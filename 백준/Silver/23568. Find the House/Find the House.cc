#include <bits/stdc++.h>
using namespace std;
int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	int n; cin >> n; map<int, int> mp;
	for (int rep = 0; rep < n; rep++) {
		int i, k; char j; cin >> i >> j >> k;
		if (j == 'L') k = -k;
		mp[i] = k;
	}
	int cur; cin >> cur;
	while (n--) cur += mp[cur];
	cout << cur << "\n";
	return 0;
}