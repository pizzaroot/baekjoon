#include <bits/stdc++.h>
using namespace std;
int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	string s; cin >> s; int w = 0, b = 0;
	for (int i = 0; i < s.size(); i++) w += s[i] == 'W', b += s[i] == 'B';
	cout << (int)(w == b) << "\n";
	return 0;
}