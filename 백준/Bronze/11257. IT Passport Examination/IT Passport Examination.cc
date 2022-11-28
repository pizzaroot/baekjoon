#include <bits/stdc++.h>
using namespace std;
int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	int t; cin >> t;
	while (t--) {
		string s; int a, b, c; cin >> s >> a >> b >> c;
		cout << s << " " << a + b + c << " ";
		if (a + b + c >= 55 && a >= 11 && b >= 8 && c >= 12) cout << "PASS\n";
		else cout << "FAIL\n";
	}
	return 0;
}