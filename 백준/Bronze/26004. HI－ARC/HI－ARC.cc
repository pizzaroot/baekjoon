#include <bits/stdc++.h>
using namespace std;
char d[5] = {'H', 'I', 'A', 'R', 'C'};
int cnt[6];
int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	int n; string s; cin >> n >> s;
	for (int i = 0; i < n; i++) {
		cnt[find(d, d + 5, s[i]) - d]++;
	}
	cout << *min_element(cnt, cnt + 5) << "\n";
	return 0;
}