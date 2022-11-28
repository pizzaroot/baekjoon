#include <bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int n; string s; cin >> n >> s;
    vector<bool> ans(n + 2);
    for (int i = 0; i < n; i++) {
        if (s[i] == '1') ans[i] = ans[i + 1] = ans[i + 2] = true;
    }
    cout << accumulate(ans.begin(), ans.begin() + n, 0) << "\n";
    return 0;
}