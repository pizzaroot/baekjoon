#include <bits/stdc++.h>
using namespace std;
int heap[100001], _size_ = 0;
void heapinsert(int);
int heappop();
int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int n, m; cin >> n >> m; vector<int> w(m + 1);
    for (int i = 1; i <= n; i++) {
        int tmp; cin >> tmp;
        heapinsert(tmp);
    }
    for (int i = 1; i <= m; i++) cin >> w[i];
    for (int i = 1; i <= m; i++) {
        int maxval = heappop();
        if (maxval >= w[i]) heapinsert(maxval - w[i]);
        else {cout << "0"; return 0;}
    } 
    cout << "1"; return 0;
}
void heapinsert(int x) {
    heap[++_size_] = x;
    int cur = _size_;
    while (cur > 1) {
        if (heap[cur] > heap[cur / 2]) {
            int tmp = heap[cur];
            heap[cur] = heap[cur / 2];
            heap[cur / 2] = tmp; cur /= 2;
        } else {
            break;
        }
    }
}
int heappop() {
    if (_size_ == 0) return 0;
    int ret = heap[1], cur = 1;
    heap[1] = heap[_size_--];
    while (cur <= _size_ / 2) {
        int better = heap[cur * 2] < heap[cur * 2 + 1] ? cur * 2 + 1 : cur * 2;
        if (heap[cur] < heap[better]) {
            int tmp = heap[cur];
            heap[cur] = heap[better];
            heap[better] = tmp; cur = better;
        } else {
            break;
        }
    }
    return ret;
}