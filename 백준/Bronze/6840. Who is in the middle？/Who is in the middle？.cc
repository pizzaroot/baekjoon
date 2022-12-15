#include <bits/stdc++.h>
using namespace std;
int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	int w[3]; cin >> w[0] >> w[1] >> w[2]; sort(w, w + 3);
	cout << w[1] << "\n";
	return 0;
}