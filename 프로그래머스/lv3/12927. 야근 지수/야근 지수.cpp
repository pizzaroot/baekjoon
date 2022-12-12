#include <bits/stdc++.h>
using namespace std;
long long solution(int n, vector<int> works) {
    long long answer = 0;
    int limit = max(0LL, accumulate(works.begin(), works.end(), 0LL) - n) / works.size();
    int cur = *max_element(works.begin(), works.end());
    while (cur >= limit) {
        for (int i = 0; i < works.size() && n; i++) {
            if (works[i] > cur) n--, works[i]--;
        }
        cur--;
    }
    for (int i = 0; i < works.size(); i++) answer += (long long)works[i] * works[i];
    return answer;
}