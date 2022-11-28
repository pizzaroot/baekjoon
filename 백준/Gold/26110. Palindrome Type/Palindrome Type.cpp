#include <bits/stdc++.h>
#define INF 0x3f3f3f3f
using namespace std;
int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	string s, t; cin >> s; t = s; int n = s.size();
	reverse(t.begin(), t.end()); s.push_back(' '); t.push_back(' ');
	if (s == t) {cout << "0\n"; return 0;}
	int ans = INF;
	for (int b = 0; b < 64; b++) {
		int skip = 0, i = 0, j = 0;
		while ((i < n || j < n) && skip <= 6 && abs(i - j) <= 3) {
			if (s[i] == t[j]) i++, j++;
			else if ((b >> skip++) & 1) i++;
			else j++;
		}
		if (i == n && j == n) ans = min(ans, skip >> 1);
	}
	cout << (ans == INF ? -1 : ans) << "\n";
	return 0;
}
