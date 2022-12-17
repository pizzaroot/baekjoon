#include <bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    while (true) {
        int n; cin >> n;
        if (!n) return 0;
        cout << n * (n + 1) / 2 << "\n";
    }
    return 0;
}