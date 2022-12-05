#include <bits/stdc++.h>
using namespace std;
int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	for (int tc = 1; ; tc++) {
		string a, b; cin >> a >> b;
		if (a == "END" && b == "END") return 0;
		sort(a.begin(), a.end()); sort(b.begin(), b.end());
		if (a == b) cout << "Case " << tc << ": same\n";
		else cout << "Case " << tc << ": different\n";
	}
}