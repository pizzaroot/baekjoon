#include <bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    string s; cin >> s;
    int t; cin >> t;
    while (t--) {
        int a, b; cin >> a >> b;
        swap(s[a], s[b]);
    }
    cout << s << "\n";
    return 0;
}