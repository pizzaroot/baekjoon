#include <bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int n; string s; cin >> n >> s;
    int security = s.size() - 7 * n;
    if (n == security * 2) cout << "bigdata? security!\n";
    else if (n > security * 2) cout << "bigdata?\n";
    else cout << "security!\n";
    return 0;
}