#include <bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int n; cin >> n; vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 1; i < n; i++) a[i] = max(a[i] + a[i - 1], a[i]);
    cout << *max_element(a.begin(), a.end());
    return 0;
}