#include <bits/stdc++.h>
using namespace std;
int solution(int k, vector<int> tangerine) {
    int answer = 0; map<int, int> mp; vector<int> c;
    for (auto &x: tangerine) mp[x]++;
    for (auto &x: mp) c.push_back(x.second); sort(c.rbegin(), c.rend());
    for (auto &x: c) if (k > 0) answer++, k -= x;
    return answer;
}