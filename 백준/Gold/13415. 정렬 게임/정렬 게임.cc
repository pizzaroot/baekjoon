#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	int n; cin >> n; vector<int> a(n);
	for (auto &x: a) cin >> x;
	int k; cin >> k; vector<ll> op(2 * k);
	for (int i = 0; i < k; i++) {
		cin >> op[i * 2] >> op[i * 2 + 1];
		op[i * 2 + 1] *= -1;
	}
	while (true) {
		bool good = true;
		for (int i = 1; i < op.size(); i++) {
			if (op[i] * op[i - 1] > 0 || abs(op[i]) >= abs(op[i - 1])) good = false;
		}
		if (good) break;
		vector<ll> tmp, tmp2;
		for (int i = 1; i < op.size(); i++) {
			if (abs(op[i]) < abs(op[i - 1])) tmp.push_back(op[i - 1]);
		}
		tmp.push_back(op[op.size() - 1]);
		for (int i = 0; i < tmp.size(); i++) {
			if (i == 0) {tmp2.push_back(tmp[0]); continue;}
			if (tmp[i] * tmp2[tmp2.size() - 1] > 0LL) {
				if (abs(tmp[i]) > abs(tmp2[tmp2.size() - 1])) tmp2[tmp2.size() - 1] = tmp[i];
			} else tmp2.push_back(tmp[i]);
		}
		op = tmp2;
	}
	vector<int> ans(a); op.push_back(0);
	sort(a.begin(), a.begin() + abs(op[0]));
	int l = 0, r = abs(op[0]) - 1;
	int cur = r;
	for (int i = 1; i < op.size(); i++) {
		int diff = abs(op[i - 1]) - abs(op[i]);
		while (diff--) {
			if (op[i - 1] < 0) ans[cur--] = a[l++];
			else ans[cur--] = a[r--];
		}
	}
	for (int i = 0; i < n; i++) cout << ans[i] << " \n"[i == n - 1];
	return 0;
}