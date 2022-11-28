#include <bits/stdc++.h>
using namespace std;
int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	int n; cin >> n; vector<set<int>> adj(n + 1); vector<bool> v(n + 1); vector<int> dist(n + 1), par(n + 1), nxt(n + 1);
	int from = 1;
	for (int i = 0; i < 2 * n - 3; i++) {
		int a, b; cin >> a >> b;
		adj[a].insert(b);
		adj[b].insert(a);
	}
    for (int i = 2; i <= n; i++) {
        if (adj[i].size() > adj[from].size()) from = i;
    }
	queue<int> q;
	q.push(from); v[from] = true; nxt[from] = from;
	while (!q.empty()) {
		int s = q.front(); q.pop();
		vector<int> rmv;
		for (auto x: adj[s]) {
			if (v[x]) continue;
			v[x] = true;
			if (adj[s].size() == 1) dist[x] = dist[s] + 1, nxt[x] = nxt[s];
			else dist[x] = 1, nxt[x] = s;
			q.push(x);
			rmv.push_back(x);
			par[x] = s;
		}
		for (auto x: rmv) {
			adj[s].erase(x);
			adj[x].erase(s);
		}
	}
	map<pair<int, int>, pair<int, int>> edge;
	vector<int> p(n + 1);
	for (int i = 1; i <= n; i++) {
		for (auto x: adj[i]) {
			if (nxt[i] == 0 || nxt[x] == 0) continue;
			if (edge.find({min(i, x), max(i, x)}) != edge.end()) continue;
			vector<int> tmp, tmpdist;
			int start1 = x, start2 = i;
			int lca, tot = 1, cnt = 0;
			while (start1 != nxt[start1]) {tmp.push_back(nxt[start1]); tmpdist.push_back(dist[start1]); start1 = nxt[start1];}
			while (start2 != nxt[start2]) {
				tot += dist[start2];
				start2 = nxt[start2];
				auto loc = find(tmp.begin(), tmp.end(), start2);
				if (loc != tmp.end()) {
					lca = start2;
					tot += accumulate(tmpdist.begin(), tmpdist.begin() + (loc - tmp.begin() + 1), 0);
					break;
				}
				cnt++;
			}
			edge[{min(i, x), max(i, x)}] = {tot, lca};
			p[tot]++;	
		}
	}
	int pcnt = 0;
	for (int i = 3; i <= n; i++) {
		if (p[i] >= 2) {
			cout << i << "\n";
			for (int j = 1; j <= n; j++) {
				vector<int> rmv;
				for (auto x: adj[j]) {
					if (nxt[j] == 0 || nxt[x] == 0) continue;
					pair<int, int> prop = edge[{min(j, x), max(j, x)}];
					if (prop.first == i) {
						vector<int> p1, p2;
						int s1 = j, s2 = x;
						while (par[s1] != 0 && s1 != prop.second) {
							p1.push_back(par[s1]);
							s1 = par[s1];
						}
						reverse(p1.begin(), p1.end());
						while (par[par[s2]] != 0 && par[s2] != prop.second) {
							p2.push_back(par[s2]);
							s2 = par[s2];
						}
						for (auto k: p2) cout << k << " ";
						for (auto k: p1) cout << k << " ";
						cout << j << " " << x << "\n";
						if (++pcnt == 2) return 0;
						rmv.push_back(x);
					}
				}
				for (auto x: rmv) {
					adj[j].erase(x);
					adj[x].erase(j);
				}
			}
		}
	}
	cout << "3\n";
	set<int> st;
	for (int i = 1; i <= n; i++) {
		for (auto x: adj[i]) {
			if (nxt[i] == 0 || nxt[x] == 0) continue;
			if (edge[{min(i, x), max(i, x)}].first == 3) {
				cout << i << " " << from << " " << x << "\n";
				adj[i].erase(x);
				adj[x].erase(i);
				break;
			}
			if (dist[i] + dist[x] + 1 >= n - 1) {
				st.insert(i); st.insert(x);
			}
		}
	}
	int cnt = 0;
	for (auto x: st) {
		cout << x << " \n"[cnt == 2];
		cnt++;
	}
	return 0;
}