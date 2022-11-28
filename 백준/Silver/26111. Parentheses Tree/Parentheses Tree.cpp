#include <bits/stdc++.h>
using namespace std;
int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	string s; cin >> s; int n = s.size();
	int level = 0; long long ans = 0;
	for (int i = 0; i < n; i++) {
		level += (s[i] == '(') * 2 - 1;
		if (s[i] == ')' && s[i - 1] == '(') ans += level;
	}
	cout << ans << "\n";
	return 0;
}
