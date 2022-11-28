#include <bits/stdc++.h>
using namespace std;
int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	int n, ans = 0; cin >> n;
	while (n--) {
		string x; cin >> x;
		ans += stoi(x.substr(2)) <= 90;
	}
	cout << ans << "\n";
	return 0;
}