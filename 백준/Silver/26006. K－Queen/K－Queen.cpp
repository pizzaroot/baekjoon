#include <bits/stdc++.h>
using namespace std;
bool threat[3][3];
int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	int n, k, r, c, tot = 0; cin >> n >> k >> r >> c;
	while (k--) {
		int y, x; cin >> y >> x;
		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 3; j++) {
				int cury = r + i - 1, curx = c + j - 1;
				if (cury <= 0 || cury > n || curx <= 0 || curx > n) threat[i][j] = true;
				if (abs(cury - y) == abs(curx- x) || abs(cury - y) * abs(curx- x) == 0) threat[i][j] = true;
			}
		}
	}
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) tot += threat[i][j];
	}
	if (threat[1][1]) {
		if (tot == 9) cout << "CHECKMATE\n";
		else cout << "CHECK\n";
	} else {
		if (tot == 8) cout << "STALEMATE\n";
		else cout << "NONE\n";
	}
	return 0;
}
