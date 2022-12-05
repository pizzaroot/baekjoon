#include <bits/stdc++.h>
using namespace std;
int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	for (int i = 0; i < 8; i++) {
		int tmp; cin >> tmp;
		if (tmp == 9) {cout << "F\n"; return 0;}
	}
	cout << "S\n"; return 0;
}