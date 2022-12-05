#include <bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    while (true) {
        string _n, _m; cin >> _n;
        if (_n == "END") return 0;
        cin >> _m;
        int n = stoi(_n), m = stoi(_m), ans = 0;
        n = abs(n); m = abs(m);
        if (n > m) swap(n, m);
        if (m == 0 && n == 0) {cout << "0\n"; continue;}
        if (m == 1 && n == 0) {cout << "3\n"; continue;}
        if (m == 2 && n == 2) {cout << "4\n"; continue;}
        if (2 * n <= m) ans = (m - 1) / 2 + 1;
        else ans = (m + n - 1) / 3 + 1;
        if (ans % 2 != (m + n) % 2) ans++;
        cout << ans << "\n";
    }
}