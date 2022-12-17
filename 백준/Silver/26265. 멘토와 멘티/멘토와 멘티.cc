#include <bits/stdc++.h>
using namespace std;
typedef pair<string, string> ps;
int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	int n; cin >> n; vector<ps> p(n);
	for (auto &x: p) cin >> x.first >> x.second;
	sort(p.begin(), p.end(), [](auto a, auto b) {
		if (a.first == b.first) return a.second > b.second;
		return a.first < b.first;
	});
	for (auto &x: p) cout << x.first << " " << x.second << "\n";
	return 0;
}