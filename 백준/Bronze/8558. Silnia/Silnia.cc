#include <bits/stdc++.h>
using namespace std;
int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	int n, ans = 1; cin >> n; n++;
	while (--n) (ans *= n) %= 10;
	cout << ans << "\n";
	return 0;
}