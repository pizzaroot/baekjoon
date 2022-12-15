#include <bits/stdc++.h>
using namespace std;
int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	int k; cin >> k; k += 2500; k = min(max(10000, k), 200000);
	cout << k / 100 << "." << k % 100 / 10 << k % 10 << "\n";
	return 0;
}