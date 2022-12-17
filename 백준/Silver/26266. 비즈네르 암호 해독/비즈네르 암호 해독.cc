#include <bits/stdc++.h>
using namespace std;
int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	string s, t; cin >> s >> t; int n = s.size(); string key;
	for (int i = 0; i < n; i++) key.push_back(65 + (t[i] - s[i] + 25) % 26);
	for (int i = 1; i <= n; i++) {
		if (n % i) continue;
		bool good = true;
		for (int idx = i; idx < n; idx++) {
			if (key[idx] != key[idx - i]) good = false;
		}
		if (good) {cout << key.substr(0, i) << "\n"; return 0;}
	}
}