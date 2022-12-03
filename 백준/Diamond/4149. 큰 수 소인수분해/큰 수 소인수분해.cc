#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;
ull fexp(ull a, ull b, ull mod) {
    ull res = 1;
    for (; b > 0; b >>= 1) {
        if (b & 1) res = (__int128_t)res * a % mod;
        a = (__int128_t)a * a % mod;
    }
    return res;
}
bool isprime(ull d) {
    if (d <= 1) return false;
    int a[9] = {2, 3, 5, 7, 11, 13, 17, 19, 23};
    ull n = d, s = 0; d--;
    while (~d & 1) d >>= 1, s++;
    for (int i = 0; i < 9; i++) {
        if (a[i] >= n) break;
        bool composite = true;
        for (int j = 0; j < s; j++) {
            if (fexp(a[i], d, n) == 1 || fexp(a[i], (1ULL << j) * d, n) == n - 1) composite = false;
        }
        if (composite) return false;
    }
    return true;
}
ull f(ull x, ull c, ull m) {
    return ((__int128_t)x * x % m + c) % m;
}
ull rho(ull n, mt19937_64 &rng) {
    if (!(n & 1ULL)) return 2;
    if (isprime(n)) return n;
    ull x = uniform_int_distribution<ull>(0, n - 2)(rng), y = x, c = uniform_int_distribution<ull>(1, 11)(rng), g = 1;
    while (g == 1) {
        x = f(x, c, n);
        y = f(y, c, n);
        y = f(y, c, n);
        g = gcd(llabs(x - y), n);
        if (g == n) return rho(n, rng);
    }
    if (isprime(g)) return g;
    return rho(g, rng);
}
int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
    ull n; cin >> n;
    vector<ull> ans;
    while (n > 1) {
        ull div = rho(n, rng);
        ans.push_back(div);
        n /= div;
    }
    sort(ans.begin(), ans.end());
    for (auto x: ans) cout << x << "\n";
    return 0;
}