#include <bits/stdc++.h>
using namespace std;
int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	int n, k; cin >> n >> k; vector<int> t(n), d(n - 1);
	for (auto &x: t) cin >> x;
	for (int i = 1; i < n; i++) d[i - 1] = t[i] - t[i - 1] - 1;
	sort(d.rbegin(), d.rend());
	cout << t[n - 1] + 1 - t[0] - accumulate(d.begin(), d.begin() + k - 1, 0) << "\n";
	return 0;
}