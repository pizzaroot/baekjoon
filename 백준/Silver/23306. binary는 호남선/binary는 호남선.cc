#include <bits/stdc++.h>
using namespace std;
int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	int n, start, end; cin >> n;
	cout << "? " << 1 << endl; cin >> start;
	cout << "? " << n << endl; cin >> end;
	cout << "! " << end - start << endl;
	return 0;
}