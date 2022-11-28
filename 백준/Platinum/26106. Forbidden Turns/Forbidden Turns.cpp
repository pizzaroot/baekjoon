#include <bits/stdc++.h>
#define INF 0x3f3f3f3f
using namespace std;
typedef pair<int, int> pi;
int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	int m, n, k; cin >> m >> n >> k;
	int v, w; cin >> v >> w; vector<pi> tmp[n], adj[m];
	vector<pair<pi, int>> vert(m); vector<int> goal(m, -1);
	map<pair<pi, int>, bool> forb; map<pi, int> mp;
	for (int i = 0; i < m; i++) {
		int x, y, c; cin >> x >> y >> c;
		mp[{x, y}] = i;
		if (w == y) goal[i] = c;
		tmp[x].push_back({y, c});
		vert[i] = {{x, y}, c};
	}
	for (int i = 0; i < k; i++) {
		int x, y, z; cin >> x >> y >> z;
		forb[{{x, y}, z}] = true;
	}
	for (int i = 0; i < m; i++) {
		int x = vert[i].first.first, y = vert[i].first.second;
		for (auto u: tmp[y]) {
			if (forb.find({{x, y}, u.first}) == forb.end()) {
				adj[i].push_back({mp[{y, u.first}], vert[i].second + u.second});
			}
		}
	}
	if (v == w) {cout << "0\n"; return 0;}
	int ans = INF;
	for (auto u: tmp[v]) {
		int start = mp[{v, u.first}];
		vector<int> d(m, INF); d[start] = 0;
		priority_queue<pi> pq;
		pq.push({0, start});
		while (!pq.empty()) {
			int cost = -pq.top().first, cur = pq.top().second; pq.pop();
			for (int i = 0; i < adj[cur].size(); i++) {
				int nxt = adj[cur][i].first, cst = adj[cur][i].second;
				if (d[nxt] > cost + cst) {
					d[nxt] = cost + cst;
					pq.push({-d[nxt], nxt});
				}
			}
		}
		for (int i = 0; i < m; i++) {
			if (goal[i] >= 0) ans = min(ans, u.second + d[i] + goal[i]);
		}
	}
	if (ans == INF) cout << "-1\n";
	else cout << ans / 2 << "\n";
	return 0;
}
