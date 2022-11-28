#include <bits/stdc++.h>
using namespace std;
int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	int x, y, z; cin >> x >> y >> z;
	int a, b, c; cin >> a >> b >> c;
	if (2 * b < y) cout << "E";
	else if (b < y) cout << "D";
	else if (2 * a < x) cout << "C";
	else if (a < x) cout << "B";
	else cout << "A";
	cout << "\n";
	return 0;
}