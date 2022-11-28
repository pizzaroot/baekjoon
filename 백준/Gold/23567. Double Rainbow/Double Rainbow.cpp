#include <bits/stdc++.h>
using namespace std;
int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	int n, k; cin >> n >> k; vector<int> cnt(k + 1), cnt2(k + 1), a(n);
	int l = 0, r = 0, uniq = 1, uniq2 = 0, ans = n + 1;
	for (auto &x: a) {
		cin >> x; if (cnt2[x]++ == 0) uniq2++;
	}
	cnt[a[0]]++;
	if (cnt2[a[0]]-- == 1) uniq2--;
	while (r < n) {
		if (uniq == k) {
			if (uniq2 == k) ans = min(ans, r - l + 1);
			if (cnt[a[l]]-- == 1) uniq--;
			if (cnt2[a[l++]]++ == 0) uniq2++;
		} else {
			if (r + 1 == n) break;
			if (cnt[a[r + 1]]++ == 0) uniq++;
			if (cnt2[a[++r]]-- == 1) uniq2--;
		}
	}
	cout << ((ans <= n) ? ans : 0) << "\n";
	return 0;
}
