#include <bits/stdc++.h>
using namespace std;
int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	int r, c; cin >> r >> c; vector<vector<int>> image(r, vector<int>(c));
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) cin >> image[i][j];
	}
	int t, ans = 0; cin >> t;
	for (int i = 1; i < r - 1; i++) {
		for (int j = 1; j < c - 1; j++) {
			vector<int> tmp;
			for (int dy = -1; dy <= 1; dy++) {
				for (int dx = -1; dx <= 1; dx++) tmp.push_back(image[i + dy][j + dx]);
			}
			sort(tmp.begin(), tmp.end());
			if (tmp[4] >= t) ans++;
		}
	}
	cout << ans << "\n";
	return 0;
}