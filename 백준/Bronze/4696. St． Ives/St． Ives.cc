#include <bits/stdc++.h>
using namespace std;
int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	while (true) {
		double n; cin >> n;
		if (n == 0) return 0;
		cout << fixed << setprecision(2) << 1 + n + n * n + n * n * n + n * n * n * n << "\n";
	}
}