#include <bits/stdc++.h>
using namespace std;
vector<int> solution(vector<string> operations) {
    multiset<int> q;
    for (auto &op: operations) {
        if (op == "D -1" && !q.empty()) q.erase(q.begin());
        else if (op == "D 1" && !q.empty()) q.erase(--q.end());
        else if (op[0] == 'I') q.insert(stoi(op.substr(2)));
    }
    if (q.empty()) return {0, 0};
    return {*--q.end(), *q.begin()};
}