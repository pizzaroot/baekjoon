#include <bits/stdc++.h>
using namespace std;
int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	int n; double v = 0; cin >> n; cout << setprecision(7);
	while (n--) {
		double tmp; cin >> tmp; tmp /= 100;
		v = 1 - (1 - v) * (1 - tmp);
		cout << v * 100<< "\n";
	}
	return 0;
}