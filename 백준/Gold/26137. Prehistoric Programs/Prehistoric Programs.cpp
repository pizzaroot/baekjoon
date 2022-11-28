#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pi;
int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int n, tot = 0; cin >> n; vector<pair<pi, int>> pf, pb;
    for (int i = 0; i < n; i++) {
        string x; cin >> x;
        int cost = 0, val = 0;
        for (int j = 0; j < x.size(); j++) {
            val += (x[j] == '(') - (x[j] == ')');
            cost = min(cost, val);
        }
        tot += val;
        if (val >= 0) pf.push_back({{-cost, val}, i});
        else pb.push_back({{val - cost, -val}, i});
    }
    if (tot) {cout << "impossible\n"; return 0;}
    sort(pf.begin(), pf.end()); sort(pb.begin(), pb.end());
    for (int i = 0, cur = 0; i < pf.size(); i++) {
        if (cur < pf[i].first.first) {cout << "impossible\n"; return 0;}
        cur += pf[i].first.second;
    }
    for (int i = 0, cur = 0; i < pb.size(); i++) {
        if (cur < pb[i].first.first) {cout << "impossible\n"; return 0;}
        cur += pb[i].first.second;
    }
    reverse(pb.begin(), pb.end());
    for (auto x: pf) cout << x.second + 1 << "\n";
    for (auto x: pb) cout << x.second + 1 << "\n";
    return 0;
}
