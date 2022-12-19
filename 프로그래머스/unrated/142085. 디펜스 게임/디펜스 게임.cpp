#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int solution(int n, int k, vector<int> enemy) {
    int sz = enemy.size();
    if (k >= sz) return sz;
    priority_queue<int, vector<int>, greater<int>> pq;
    for (int i = 0; i < k; i++) {
        pq.push(enemy[i]);
    }
    ll extra = 0;
    for (int i = k; i < sz; i++) {
        pq.push(enemy[i]);
        extra += pq.top(); pq.pop();
        if (extra > n) return i;
    }
    return sz;
}