#include <bits/stdc++.h>
using namespace std;
vector<int> solution(string s) {
    int n = s.size();
    vector<int> answer(n), last(128, n);
    for (int i = 0; i < n; i++) {
        answer[i] = max(-1, i - last[s[i]]);
        last[s[i]] = i;
    }
    return answer;
}