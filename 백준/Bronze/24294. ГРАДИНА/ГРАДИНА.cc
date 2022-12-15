#include <bits/stdc++.h>
using namespace std;
int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	int w1, h1, w2, h2; cin >> w1 >> h1 >> w2 >> h2;
	cout << (max(w1, w2) + h1 + h2 + 2) * 2 << "\n";
	return 0;
}