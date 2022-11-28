#include <bits/stdc++.h>
using namespace std;
int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	cout << fixed << setprecision(2);
	while (true) {
		double x; cin >> x;
		if (x < 0) return 0;
		cout << "Objects weighing " << x << " on Earth will weigh " << x * 0.167 << " on the moon.\n";
	}
}