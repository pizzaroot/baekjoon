#include <bits/stdc++.h>
using namespace std;
int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	int n, parity[2] = {0, }; cin >> n;
	while (n--) {
		int tmp; cin >> tmp;
		parity[tmp & 1]++;
	}
	if (parity[0] == parity[1] || parity[0] + 1 == parity[1]) cout << "1\n";
	else cout << "0\n";
	return 0;
}