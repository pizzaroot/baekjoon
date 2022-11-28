#include <bits/stdc++.h>
using namespace std;
typedef tuple<int, int, int> ti;
int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	int m, n; cin >> m >> n; vector<ti> sat(m);
	while (m--) {
		int a, b, c; cin >> a >> b >> c;
		sat[m] = make_tuple(a, b, c);
	}
	bool ans = false;
	for (int i = 0; i < (1 << n); i++) {
		bool good = true;
		for (int j = 0; j < sat.size(); j++) {
			int a, b, c; tie(a, b, c) = sat[j];
			int x = ((i >> (abs(a) - 1)) & 1) ^ (int)(a < 0);
			int y = ((i >> (abs(b) - 1)) & 1) ^ (int)(b < 0);
			int z = ((i >> (abs(c) - 1)) & 1) ^ (int)(c < 0);
			if ((x | y | z) == 0) good = false;
		}
		if (good) ans = true;
	}
	cout << (sat.size() < 8 ? "unsatisfactory\n" : "satisfactory\n");
	return 0;
}